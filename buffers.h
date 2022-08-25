/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.
#include "mcc_generated_files/mcc.h"

//This location is the value of cash to be added or
//subtracted from credit memory
volatile uint8_t credit;
volatile uint8_t credmdb;
volatile uint8_t cash;
volatile uint8_t buttons;
volatile uint8_t vendprice;
volatile uint16_t timeout;
//32 bytes allowed location 32 should always be zero
uint8_t mdbdata[33];
uint8_t slvadd;
uint8_t mcount = 0;
uint8_t notebyte;
uint8_t chkbyte;
uint16_t dbcount=0;
uint8_t notenum = 0xFF;
uint16_t * motimead;

//Timer values for vend motor timing
const uint16_t second1 = 0xF0DD ;
//Subtract this to increase by 1 second
const uint16_t second_5 = 0x0F23 ;
//Subtract this to increase by 2 second
const uint16_t secondadd = 0x1E46 ;

//NVRAM address location definitions
//This location holds the value of cash in hand
const uint16_t credmem = 0x00;
//Prices per vend 2 x uint8_t
const uint16_t pricestore = 0x01;
const uint16_t pricestore2 = 0x02;
//Vend error flags bits 0 to 7 uint8_t
const uint16_t venderrors = 0x03;
const uint16_t venderror2 = 0x04;
//Motor timeout values 2x8bits
const uint16_t mototime = 0x05;
const uint16_t mototime2 = 0x07;

/*vend flags bit 0=still credit bit 1=error bit 2=display insert coin
  bit 3=no change bit4=credit display bit5=Buy another?*/
struct
{
   unsigned iscredit : 1;
   unsigned error : 1;
   unsigned initialrun : 1;
   unsigned service : 1;
   unsigned priceset : 1;
   unsigned setprice : 1;
   unsigned mottime : 1;
   unsigned settime : 1;
   unsigned swclosed : 1;
   unsigned bflash : 1;
   unsigned crednuff : 1;
   unsigned t5time : 1;
   unsigned chan1 : 1;
   unsigned chan2 : 1;
   unsigned settime2 : 1;
   unsigned beep : 1;
} venflags;

void note_disable(void);

void mdb_noten(void);

void credit_add(uint8_t credit);

void poll_mdb(void);

void InterruptTMR2(void);

void buzzer(void);
#endif	/* XC_HEADER_TEMPLATE_H */

