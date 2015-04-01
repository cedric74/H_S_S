/*
 * Functions_State_Machine.h
 *
 *  Created on: Mar 4, 2015
 *      Author: cedric
 */

#ifndef FUNCTIONS_STATE_MACHINE_H_
#define FUNCTIONS_STATE_MACHINE_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <pthread.h>

#include 	"../Lib_Gpio/beh_BBB_gpio.h"
#include	"../Lib_Servo/Lib_Servo.h"
#include 	"../Lib_Sonar/Lib_Sonar.h"

/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void 			Init_State_Machine();
unsigned char	state_machine(void);
void * 			Thread_State_Machine();


#endif /* FUNCTIONS_STATE_MACHINE_H_ */
