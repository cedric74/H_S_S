/*
 * Lib_Servo.h
 *
 *  Created on: Mar 31, 2015
 *      Author: cedric
 */

#ifndef LIB_SERVO_H_
#define LIB_SERVO_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "../Lib_Gpio/beh_BBB_gpio.h"
#include "../Lib_PWM/Lib_PWM.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define 	SERVO_SONAR			P9_14
#define		PERIOD_20_MS		20000000

// duty Value for Servo Sonar
#define     SERVO_CENTER		1400000
#define    	SERVO_FULL_LEFT		400000
#define    	SERVO_FULL_RIGHT	2400000
#define		SERVO_STEP			50000


/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
typedef enum{
	CENTER 		= 0,
	FULL_LEFT 	= 1,
	FULL_RIGHT 	= 2,
	STEP_RIGHT	= 3,
	STEP_LEFT	= 4,
}eServo_Sonar_Rotate;


/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
int iCurrentPosSonar;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void 	Lib_Servo_Sonar_Control(eServo_Sonar_Rotate);
void 	Lib_Servo_init();

#endif /* LIB_SERVO_H_ */
