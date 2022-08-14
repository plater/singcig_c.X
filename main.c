/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.
 Author:
 * Dave Plater
 Date:
 * 9 May 2018

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F25K42
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "vend.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    //Check if a power on reset has occurred
    if((PCON0 == 0x3C | 0x3D) & PCON1bits.MEMV)
    {
        DATAEE_WriteByte(venderrors, 0x00);
        DATAEE_WriteByte(credmem, 0x00);
    }
    SYSTEM_Initialize();
    LIGHT1_SetHigh();
    vend_init();
    LIGHT2_SetHigh();
    mdb_init();
    LIGHT1_SetLow();
    LIGHT2_SetLow();
   
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    while (1)
    {
        if(!SERVICE_GetValue())
        {
            enter_service();
        }
        
        while(!CMP1_GetOutputStatus())
        {
            LIGHT2_SetLow();
            LIGHT1_SetHigh();
            __delay_ms(100);
            LIGHT2_SetHigh();
            LIGHT1_SetLow();
            __delay_ms(100);
            
        }
        if(venflags.error)
        {
            CNEN_SetLow();
        }
        else
        {
            CNEN_SetHigh();
        }
        
        if(!COIN_GetValue())
        {
            coin_in();
        }
        
        if(venflags.error)
        {
            button_flash();
        }
        
        if(credit_check() >= vendprice)
        {
            venflags.crednuff = 1;
        }
        else
        {
            venflags.crednuff = 0;
        }
        
        if(PIR8bits.TMR5IF)
        {
            venflags.t5time = 1;
        }
        
        if(venflags.crednuff && venflags.t5time)
        {
            if(!venflags.error)
            {
                CNEN_SetLow();
                LIGHT1_SetHigh();
            }
            if(!BUTTON1_GetValue() &&  !venflags.error)
            {
                dispense();
            }
        }
    }
}
/**
 End of File
*/