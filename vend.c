/* 
 * File:   vend.c
 * Author: Dave Plater
 *
 * Created on 10 May 2018, 16:56 PM
 */
#include "vend.h"

void vend_init(void)
{
    venflags.bflash = 0;
    venflags.priceset = 0;
    uint8_t *timeval = &timeout;
    timeval[0] = DATAEE_ReadByte(mototime);
    timeval[1] = DATAEE_ReadByte(mototime + 1);
    vendprice = DATAEE_ReadByte(pricestore);
    credit = DATAEE_ReadByte(credmem);
    DAC1CON1 = 0x0C;
    __delay_ms(250);
    if(DATAEE_ReadByte(venderrors) != 0x00)
    {//Disable coin mech permanent.
        CNEN_SetLow();
        venflags.error = 1;
    }
    else
    {// enable coins
        CNEN_SetHigh();
        venflags.error = 0;
    }
}

void coin_in(void)
{//switch_read() returns 1 if coin switch closed.
    TMR5_Initialize();
    venflags.t5time = 0;
    if(switch_read())
    {
        while(switch_read()){}
        credit_add(0x01);
    }
    if(credit_check() >= vendprice)
    {//Turn off coin mech
        //CNEN_SetLow();
        //Turn on button light
        LIGHT1_SetHigh();
    }
}

uint8_t credit_check(void)
{
    cash = DATAEE_ReadByte(credmem);
    return(cash);
}

void credit_add(uint8_t credit)
{
    cash = DATAEE_ReadByte(credmem);
    cash = cash + credit;
    DATAEE_WriteByte(credmem, cash);
    if(cash != 0)
    {
        venflags.iscredit = 1;

    }
}

void credit_subtract(uint8_t credit)
{
    cash = DATAEE_ReadByte(credmem);
    cash = (cash - credit) & 0xFF;
    DATAEE_WriteByte(credmem, cash);
    if(cash == 0)
    {
        venflags.iscredit = 0;
    }
}

//Motor = RC3, Button Light = RC2 and coin enable = RC1
//PIR4bits.TMR1IF set to 1 on timeout.
void dispense(void)
{
    CNEN_SetLow();
    TMR1_Initialize();
    TMR1_StopTimer();
    TMR1_WriteTimer(timeout);
    TMR1_StartTimer();
    DAC1CON1 = 0x0C;
    while(!PIR4bits.TMR1IF && CM1CON0bits.C1OUT)
    {
        MOTOR1_SetHigh();
    }
    MOTOR1_SetLow();
    if(PIR4bits.TMR1IF)
    {//Out of stock keep credit
        DATAEE_WriteByte(venderrors, 0xAA);
        asm("RESET");
    }
    else
    {//End of successful vend
        credit_subtract(vendprice);
        asm("RESET");
    }

}

bool Read_Sensor(void)
{
    //DAC1CON1 value between 0 and 0x1F determine the sensitivity
    // of the opto transistor, 0 is least sensitive and 0x1F most.
    DAC1CON1 = 0x0C;
    uint8_t senval = CMOUT;
    return CM1CON0bits.C1OUT;
}
//PIR6bits.TMR3IF LATCbits.LC2
void button_flash(void)
{
    if(!venflags.bflash)
    {
        venflags.bflash = 1;
        TMR3_Initialize();
        SPARE_SetHigh();
    }
    if(PIR6bits.TMR3IF)
    {
        LATCbits.LC2 = ~LATCbits.LC2;
        TMR3_Initialize();
    }
}

void buzzer(void)
{
    if(!venflags.bflash)
    {
        venflags.bflash = 1;
        TMR4_Initialize();
        SPARE_SetHigh();
    }
    if(PIR7bits.TMR4IF)
    {
        LATCbits.LC2 = ~LATCbits.LC2;
        TMR4_Initialize();
    }
}

void led_flash(void)
{
    if(!venflags.bflash)
    {
        venflags.bflash = 1;
        TMR4_Initialize();
        SPARE_SetHigh();
    }
    if(PIR7bits.TMR4IF)
    {
        LATCbits.LC2 = ~LATCbits.LC2;
        TMR4_Initialize();
    }
}

void enter_service(void)
{
    uint8_t credshad;
    SPARE_SetHigh();
    //Clear vend errors.
    DATAEE_WriteByte(venderrors, 0x00);
    DATAEE_WriteByte(credmem, 0x00);
    //Clear credit.
    cash = 0x00;
    credit = 0;
    credshad = 0;
    venflags.priceset = 0;
    venflags.settime = 0;
    venflags.chan1 = 0;
    venflags.chan2 = 0;
    CNEN_SetHigh();
    while(!SERVICE_GetValue()){}
    __delay_ms(500);
    SPARE_SetLow();
    while(SERVICE_GetValue())
    {
        button_flash();
        if(!BUTTON1_GetValue() && !venflags.priceset)
        {
            venflags.chan1 = 1;
            CNEN_SetLow();
            Set_Timeout();
            venflags.settime = 1;
        }
        else if(!BUTTON2_GetValue() && !venflags.priceset)
        {
            venflags.chan2 = 1;
        }
        if(switch_read())
        {
            venflags.priceset = 1;
            while(switch_read()){}
            credit_add(1);
            credshad = cash;
            asm("NOP");
        }
        if(PIR7bits.TMR4IF)
        {
            SPARE_SetLow();
        }
        if(cash != credshad)
        {
            led_flash();
            venflags.priceset = 1;
            credshad = cash;
        }
    }
 
    if(venflags.priceset)
    {
        DATAEE_WriteByte(pricestore, cash);
        
    }
    LIGHT1_SetLow();
    __delay_ms(1000);
    asm("RESET");
}

void Set_Timeout(void)
{
    TMR1_Initialize();
    while(!PIR4bits.TMR1IF)
    {
        MOTOR1_SetHigh();
        if(!CM1CON0bits.C1OUT)
        {
            MOTOR1_SetLow();
            TMR1_StopTimer();
            timeout = TMR1_ReadTimer();
            timeout = 0x00 - timeout;
            uint8_t *timeval = &timeout;
            uint8_t readValLow = timeval[0];
            uint8_t readValHigh = timeval[1];
            DATAEE_WriteByte(mototime, readValLow);
            DATAEE_WriteByte(mototime + 1, readValHigh);
            break;
        }
    }
}

bool switch_read(void)
{
    if(COIN_GetValue() == venflags.swclosed)
    {//Switch changed state
        if(venflags.swclosed)
        {//switch transition from closed to open
            __delay_us(2500);
        }
        else
        {//Switch transition from opened to closed
            __delay_ms(15);
        }
    }
    if(COIN_GetValue())
    {//Switch is open
        venflags.swclosed = 0;
        return 0;
    }
    else
    {//Switch is closed
        venflags.swclosed = 1;
        return 1;
    }
}

