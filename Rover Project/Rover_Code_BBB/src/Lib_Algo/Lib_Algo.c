/*
 * Lib_Algo.c
 *
 *  Created on: Mar 09, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_Algo.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define 	MINI_DIST			30	// 30 // in CM

#define 	TIME_ROTATE_90		1000000	// In uS
#define 	TIME_ROTATE_180		4000000 // In uS

#define		DELAYS_200_MS		200000
/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
static float	tabAreaScannig[3]={0};

/*	CENTER 		= 0,
	FULL_LEFT 	= 1,
	FULL_RIGHT 	= 2,
*/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
/*
 ============================================
 Function     : Lib_Algo_Roaming_Rover()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Algo_Roaming_Rover(){

	// Scanning Area At Left, Center and Right Position
	Lib_Algo_Scanning(CENTER);

	// Check Value Center Position
	if(tabAreaScannig[CENTER]  > MINI_DIST)
	{
		// Keep Go Head
		Lib_motor_control(FORWARD);
		printf(" -> FORWARD \n");

	}else{
		// Stop Move
		Lib_motor_control(STOP_MOVE);
		Lib_Algo_All_Area_Scanning();
		printf(" -> STOP_MOVE \n");
	}


	if(tabAreaScannig[CENTER]  > MINI_DIST)
	{
		// Start Go Head
		Lib_motor_control(FORWARD);
		printf(" -> FORWARD \n");
	}else{
		if(tabAreaScannig[FULL_RIGHT]  > MINI_DIST){
			// Rotate 90 to The Right
			Lib_motor_control(ROTATE_RIGHT);
			usleep(TIME_ROTATE_90);
			Lib_motor_control(STOP_MOVE);
			// Start Go Head
			Lib_motor_control(FORWARD);

			printf(" -> Rotate 90 to The Right \n");

		}else{
			if(tabAreaScannig[FULL_LEFT]  > MINI_DIST){
				// Rotate 90 to The Left
				Lib_motor_control(ROTATE_LEFT);
				usleep(TIME_ROTATE_90);
				Lib_motor_control(STOP_MOVE);
				// Start Go Head
				Lib_motor_control(FORWARD);

				printf(" -> Rotate 90 to The Left \n");
			}else{
				// Rotate 180 to The Left OR Right
				Lib_motor_control(ROTATE_LEFT);
				usleep(TIME_ROTATE_180);
				Lib_motor_control(STOP_MOVE);
				// Start Go Head
				Lib_motor_control(FORWARD);
				printf(" -> Rotate 180 to The Left \n");
			}
		}
	}
}


/*
 ============================================
 Function     : Lib_Algo_All_Area_Scanning()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Algo_All_Area_Scanning(){

	// ************  LEFT SCANNING *****************
	Lib_Algo_Scanning(FULL_LEFT);

	// ************  CENTER SCANNING *****************
	Lib_Algo_Scanning(CENTER);

	// ************  RIGHT SCANNING *****************
	Lib_Algo_Scanning(FULL_RIGHT);

	// ********* GO SERVO CENTER POSITION **********

	// Turn Sonar to Center Position
	Lib_Servo_Sonar_Control(CENTER);

}

/*
 ============================================
 Function     : Lib_Algo_Scanning()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Algo_Scanning(eServo_Sonar_Rotate valueRotate){

	// Turn Sonar to Request Position
	Lib_Servo_Sonar_Control(valueRotate);

	// Maybe Need some Delay to be at the right place
	usleep(DELAYS_200_MS);

	// Sonar Scanning
	Lib_Sonar_Ping();

	// Save Value into the Table Area
	tabAreaScannig[valueRotate] = fDistance;

}

