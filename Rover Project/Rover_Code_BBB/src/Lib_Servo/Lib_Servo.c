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
		// Position
		case LEFT_0:
			Lib_pwm_control(PERIOD_20_MS, SERVO_0_LEFT);
			iCurrentPosSonar = SERVO_0_LEFT;
		break;
		case RIGHT_0:
			Lib_pwm_control(PERIOD_20_MS, SERVO_0_RIGHT);
			iCurrentPosSonar = SERVO_0_RIGHT;
		break;

		case LEFT_22_5:
			Lib_pwm_control(PERIOD_20_MS, SERVO_22_5_LEFT);
			iCurrentPosSonar = SERVO_22_5_LEFT;
		break;

		case RIGHT_22_5:
			Lib_pwm_control(PERIOD_20_MS, SERVO_22_5_RIGHT);
			iCurrentPosSonar = SERVO_22_5_RIGHT;
		break;

		case LEFT_45:
			Lib_pwm_control(PERIOD_20_MS, SERVO_45_LEFT);
			iCurrentPosSonar = SERVO_45_LEFT;
		break;

		case RIGHT_45:
			Lib_pwm_control(PERIOD_20_MS, SERVO_45_RIGHT);
			iCurrentPosSonar = SERVO_45_RIGHT;
		break;


		case LEFT_67_5:
			Lib_pwm_control(PERIOD_20_MS, SERVO_67_5_LEFT);
			iCurrentPosSonar = SERVO_67_5_LEFT;
		break;

		case RIGHT_67_5:
			Lib_pwm_control(PERIOD_20_MS, SERVO_67_5_RIGHT);
			iCurrentPosSonar = SERVO_67_5_RIGHT;
		break;


		case RIGHT_STEP:
			if(iCurrentPosSonar < SERVO_0_RIGHT){
				iCurrentPosSonar += SERVO_STEP;
				Lib_pwm_control(PERIOD_20_MS, iCurrentPosSonar);
			}

		break;

		case LEFT_STEP:
			if(iCurrentPosSonar > SERVO_0_LEFT){
				iCurrentPosSonar -= SERVO_STEP;
				Lib_pwm_control(PERIOD_20_MS, iCurrentPosSonar);
			}
		break;

		default :
			//... Nothing To Do
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
