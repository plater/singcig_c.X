/* 
 * File:   vend.h
 * Author: Dave Plater
 *
 * Created on May 10, 2018, 4:54 PM
 */

#ifndef VEND_H
#define	VEND_H

#undef 8CHANV
#include "mcc_generated_files/mcc.h"
//This location is the value of cash to be added or
//subtracted from credit memory
volatile uint8_t credit;
volatile uint8_t cash;
volatile uint8_t buttons;
volatile uint8_t vendprice;
volatile uint16_t timeout;

//Timer values for vend motor timing
const uint16_t second1 = 0xF0DD ;
//Subtract this to increase by 1 second
const uint16_t second_5 = 0x0F23 ;
//Subtract this to increase by 2 second
const uint16_t secondadd = 0x1E46 ;

//NVRAM address location definitions
//This location holds the value of cash in hand
const uint16_t credmem = 0x00;
//Prices per vend 1 x uint8_t
const uint16_t pricestore = 0x01;
//Vend error flags bits 0 to 7 uint8_t
const uint16_t venderrors = 0x02;
//Motor timeout value 2x8bits
const uint16_t mototime = 0x03;

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
   unsigned spare4 : 1;
   unsigned spare5 : 1;
   unsigned spare6 : 1;
   unsigned spare7 : 1;
} venflags;

void vend_init(void);

uint8_t credit_check(void);

void credit_add(uint8_t credit);

void credit_subtract(uint8_t credit);

void dispense(void);

void enter_service(void);

void coin_in(void);

bool Read_Sensor(void);

void button_flash(void);

void Set_Timeout(void);

bool switch_read(void);


#endif	/* VEND_H */

