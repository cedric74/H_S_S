/*
 * Lib_Siren.h
 *
 *  Created on: Mar 4, 2015
 *      Author: cedric
 */

#ifndef LIB_SIREN_H_
#define LIB_SIREN_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <pthread.h>

#include "../Lib_Gpio/beh_BBB_gpio.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define SIREN_ON		0
#define SIREN_OFF		1

#define SIREN			P9_15

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void* 	Thread_Siren();
void 	Start_Siren();
void 	Stop_Siren();
void 	Init_Siren();


#endif /* LIB_SIREN_H_ */