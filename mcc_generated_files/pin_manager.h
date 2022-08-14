/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F25K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSELA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set BEEP aliases
#define BEEP_TRIS                 TRISAbits.TRISA1
#define BEEP_LAT                  LATAbits.LATA1
#define BEEP_PORT                 PORTAbits.RA1
#define BEEP_WPU                  WPUAbits.WPUA1
#define BEEP_OD                   ODCONAbits.ODCA1
#define BEEP_ANS                  ANSELAbits.ANSELA1
#define BEEP_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BEEP_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BEEP_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BEEP_GetValue()           PORTAbits.RA1
#define BEEP_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BEEP_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BEEP_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define BEEP_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define BEEP_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define BEEP_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define BEEP_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define BEEP_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA2
#define LED_LAT                  LATAbits.LATA2
#define LED_PORT                 PORTAbits.RA2
#define LED_WPU                  WPUAbits.WPUA2
#define LED_OD                   ODCONAbits.ODCA2
#define LED_ANS                  ANSELAbits.ANSELA2
#define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GetValue()           PORTAbits.RA2
#define LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set s1 aliases
#define s1_TRIS                 TRISAbits.TRISA3
#define s1_LAT                  LATAbits.LATA3
#define s1_PORT                 PORTAbits.RA3
#define s1_WPU                  WPUAbits.WPUA3
#define s1_OD                   ODCONAbits.ODCA3
#define s1_ANS                  ANSELAbits.ANSELA3
#define s1_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define s1_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define s1_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define s1_GetValue()           PORTAbits.RA3
#define s1_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define s1_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define s1_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define s1_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define s1_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define s1_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define s1_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define s1_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set s2 aliases
#define s2_TRIS                 TRISAbits.TRISA4
#define s2_LAT                  LATAbits.LATA4
#define s2_PORT                 PORTAbits.RA4
#define s2_WPU                  WPUAbits.WPUA4
#define s2_OD                   ODCONAbits.ODCA4
#define s2_ANS                  ANSELAbits.ANSELA4
#define s2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define s2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define s2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define s2_GetValue()           PORTAbits.RA4
#define s2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define s2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define s2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define s2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define s2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define s2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define s2_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define s2_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set s3 aliases
#define s3_TRIS                 TRISAbits.TRISA5
#define s3_LAT                  LATAbits.LATA5
#define s3_PORT                 PORTAbits.RA5
#define s3_WPU                  WPUAbits.WPUA5
#define s3_OD                   ODCONAbits.ODCA5
#define s3_ANS                  ANSELAbits.ANSELA5
#define s3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define s3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define s3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define s3_GetValue()           PORTAbits.RA5
#define s3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define s3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define s3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define s3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define s3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define s3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define s3_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define s3_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set COUNT1 aliases
#define COUNT1_TRIS                 TRISAbits.TRISA6
#define COUNT1_LAT                  LATAbits.LATA6
#define COUNT1_PORT                 PORTAbits.RA6
#define COUNT1_WPU                  WPUAbits.WPUA6
#define COUNT1_OD                   ODCONAbits.ODCA6
#define COUNT1_ANS                  ANSELAbits.ANSELA6
#define COUNT1_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define COUNT1_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define COUNT1_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define COUNT1_GetValue()           PORTAbits.RA6
#define COUNT1_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define COUNT1_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define COUNT1_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define COUNT1_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define COUNT1_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define COUNT1_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define COUNT1_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define COUNT1_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set COUNT2 aliases
#define COUNT2_TRIS                 TRISAbits.TRISA7
#define COUNT2_LAT                  LATAbits.LATA7
#define COUNT2_PORT                 PORTAbits.RA7
#define COUNT2_WPU                  WPUAbits.WPUA7
#define COUNT2_OD                   ODCONAbits.ODCA7
#define COUNT2_ANS                  ANSELAbits.ANSELA7
#define COUNT2_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define COUNT2_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define COUNT2_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define COUNT2_GetValue()           PORTAbits.RA7
#define COUNT2_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define COUNT2_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define COUNT2_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define COUNT2_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define COUNT2_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define COUNT2_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define COUNT2_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define COUNT2_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set COIN aliases
#define COIN_TRIS                 TRISBbits.TRISB0
#define COIN_LAT                  LATBbits.LATB0
#define COIN_PORT                 PORTBbits.RB0
#define COIN_WPU                  WPUBbits.WPUB0
#define COIN_OD                   ODCONBbits.ODCB0
#define COIN_ANS                  ANSELBbits.ANSELB0
#define COIN_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define COIN_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define COIN_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define COIN_GetValue()           PORTBbits.RB0
#define COIN_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define COIN_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define COIN_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define COIN_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define COIN_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define COIN_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define COIN_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define COIN_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set BUTTON1 aliases
#define BUTTON1_TRIS                 TRISBbits.TRISB1
#define BUTTON1_LAT                  LATBbits.LATB1
#define BUTTON1_PORT                 PORTBbits.RB1
#define BUTTON1_WPU                  WPUBbits.WPUB1
#define BUTTON1_OD                   ODCONBbits.ODCB1
#define BUTTON1_ANS                  ANSELBbits.ANSELB1
#define BUTTON1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BUTTON1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BUTTON1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define BUTTON1_GetValue()           PORTBbits.RB1
#define BUTTON1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BUTTON1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BUTTON1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BUTTON1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BUTTON1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define BUTTON1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define BUTTON1_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define BUTTON1_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set SERVICE aliases
#define SERVICE_TRIS                 TRISBbits.TRISB2
#define SERVICE_LAT                  LATBbits.LATB2
#define SERVICE_PORT                 PORTBbits.RB2
#define SERVICE_WPU                  WPUBbits.WPUB2
#define SERVICE_OD                   ODCONBbits.ODCB2
#define SERVICE_ANS                  ANSELBbits.ANSELB2
#define SERVICE_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SERVICE_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SERVICE_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SERVICE_GetValue()           PORTBbits.RB2
#define SERVICE_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SERVICE_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SERVICE_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SERVICE_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SERVICE_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SERVICE_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SERVICE_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define SERVICE_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set SEN aliases
#define SEN_TRIS                 TRISBbits.TRISB3
#define SEN_LAT                  LATBbits.LATB3
#define SEN_PORT                 PORTBbits.RB3
#define SEN_WPU                  WPUBbits.WPUB3
#define SEN_OD                   ODCONBbits.ODCB3
#define SEN_ANS                  ANSELBbits.ANSELB3
#define SEN_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SEN_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SEN_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SEN_GetValue()           PORTBbits.RB3
#define SEN_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SEN_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SEN_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SEN_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SEN_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SEN_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SEN_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define SEN_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSELB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set LIGHT2 aliases
#define LIGHT2_TRIS                 TRISCbits.TRISC0
#define LIGHT2_LAT                  LATCbits.LATC0
#define LIGHT2_PORT                 PORTCbits.RC0
#define LIGHT2_WPU                  WPUCbits.WPUC0
#define LIGHT2_OD                   ODCONCbits.ODCC0
#define LIGHT2_ANS                  ANSELCbits.ANSELC0
#define LIGHT2_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LIGHT2_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LIGHT2_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LIGHT2_GetValue()           PORTCbits.RC0
#define LIGHT2_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LIGHT2_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LIGHT2_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LIGHT2_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LIGHT2_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define LIGHT2_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define LIGHT2_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define LIGHT2_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set CNEN aliases
#define CNEN_TRIS                 TRISCbits.TRISC1
#define CNEN_LAT                  LATCbits.LATC1
#define CNEN_PORT                 PORTCbits.RC1
#define CNEN_WPU                  WPUCbits.WPUC1
#define CNEN_OD                   ODCONCbits.ODCC1
#define CNEN_ANS                  ANSELCbits.ANSELC1
#define CNEN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define CNEN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define CNEN_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define CNEN_GetValue()           PORTCbits.RC1
#define CNEN_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define CNEN_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define CNEN_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define CNEN_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define CNEN_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define CNEN_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define CNEN_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define CNEN_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set LIGHT1 aliases
#define LIGHT1_TRIS                 TRISCbits.TRISC2
#define LIGHT1_LAT                  LATCbits.LATC2
#define LIGHT1_PORT                 PORTCbits.RC2
#define LIGHT1_WPU                  WPUCbits.WPUC2
#define LIGHT1_OD                   ODCONCbits.ODCC2
#define LIGHT1_ANS                  ANSELCbits.ANSELC2
#define LIGHT1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LIGHT1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LIGHT1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LIGHT1_GetValue()           PORTCbits.RC2
#define LIGHT1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LIGHT1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LIGHT1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LIGHT1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LIGHT1_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LIGHT1_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LIGHT1_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define LIGHT1_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set MOTOR1 aliases
#define MOTOR1_TRIS                 TRISCbits.TRISC3
#define MOTOR1_LAT                  LATCbits.LATC3
#define MOTOR1_PORT                 PORTCbits.RC3
#define MOTOR1_WPU                  WPUCbits.WPUC3
#define MOTOR1_OD                   ODCONCbits.ODCC3
#define MOTOR1_ANS                  ANSELCbits.ANSELC3
#define MOTOR1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define MOTOR1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define MOTOR1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define MOTOR1_GetValue()           PORTCbits.RC3
#define MOTOR1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define MOTOR1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define MOTOR1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define MOTOR1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define MOTOR1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define MOTOR1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define MOTOR1_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define MOTOR1_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/