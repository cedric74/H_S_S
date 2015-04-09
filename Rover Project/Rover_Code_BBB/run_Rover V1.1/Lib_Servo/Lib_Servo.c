/*
 * Lib_Servo.c
 *
 *  Created on: Mar 31, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include	"Lib_Servo.h"

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
/*
 ============================================
 Function     : Lib_Servo_Control_Pwm()
 Parameter    :
 Return Value :
 Description  :
 ============================================
 */
void Lib_Servo_Sonar_Control(eServo_Sonar_Rotate valueRotate) // Create a typedef Enum
{
	switch(valueRotate){
		case CENTER :
			Lib_pwm_control(PERIOD_20_MS, SERVO_CENTER);
			iCurrentPosSonar = SERVO_CENTER;
		break;
		case FULL_LEFT:
			Lib_pwm_control(PERIOD_20_MS, SERVO_FULL_LEFT);
			iCurrentPosSonar = SERVO_FULL_LEFT;
		break;
		case FULL_RIGHT:
			Lib_pwm_control(PERIOD_20_MS, SERVO_FULL_RIGHT);
			iCurrentPosSonar = SERVO_FULL_RIGHT;
			break;
		case STEP_RIGHT:
			if(iCurrentPosSonar < SERVO_FULL_RIGHT){
				iCurrentPosSonar += SERVO_STEP;
				Lib_pwm_control(PERIOD_20_MS, iCurrentPosSonar);
			}

			break;
		case STEP_LEFT:
			if(iCurrentPosSonar > SERVO_FULL_LEFT){
				iCurrentPosSonar -= SERVO_STEP;
				Lib_pwm_control(PERIOD_20_MS, iCurrentPosSonar);
			}
		break;
	}
}
/*
 ============================================
 Function     : Lib_Servo_init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Servo_init(){

	// Set Polarity to 0
	Lib_pwm_init();

	// Set Run to 1
	Lib_pwm_start();

	// Set Servo Sonar to Center Position
	Lib_pwm_control(PERIOD_20_MS, SERVO_CENTER);
	iCurrentPosSonar = SERVO_CENTER;
}
