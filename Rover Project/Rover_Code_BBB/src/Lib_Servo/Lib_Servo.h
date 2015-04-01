/*
 * Lib_Servo.h
 *
 *  Created on: Mar 31, 2015
 *      Author: cedric
 */

#ifndef LIB_MOTOR_H_
#define LIB_MOTOR_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "../Lib_Gpio/beh_BBB_gpio.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define 	BUFFER_SIZE 	128
#define 	SERVO_SONAR		P9_14

#define 	PATH_PERIOD  "/sys/devices/ocp.3/pwm_test_P9_14.12/period"
#define 	PATH_DUTY    "/sys/devices/ocp.3/pwm_test_P9_14.12/duty"

#define 	NO_ERROR_PWM	 0
#define 	ERROR_PWM_OPEN	-1
#define 	ERROR_PWM_WRITE	-2

#define		PERIOD_20_MS	20000000

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
int 	Lib_Servo_Control_Pwm(int iPeriod, int iDuty);
void 	Lib_Servo_init();

#endif /* LIB_MOTOR_H_ */
