/* 
 * File:   vend.h
 * Author: Dave Plater
 *
 * Created on May 10, 2018, 4:54 PM
 */

#ifndef VEND_H
#define	VEND_H

#include "buffers.h"

void vend_init(void);

uint8_t credit_check(void);

void credit_subtract(uint8_t credit);

void dispense(void);

void enter_service(void);

void coin_in(void);

bool Read_Sensor(void);

void button_flash(void);

void Set_Timeout(void);

bool switch_read(void);


#endif	/* VEND_H */

