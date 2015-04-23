/*
 * Lib_Algo.c
 *
 *  Created on: Apr 09, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_Algo.h"

/*******************************************
*               D E F I N E                *
********************************************/
// Dim Rover :
// Width : 22.5 cm	
// Length: 24.5 cm
#define 	WIDTH_ROVER					22.5	// For Security Calculate distance with 24 cm
#define 	LENGTH_ROVER				24.5

// Trigonometry
// Cos A = Adjacent / Hypo -> Adjacent = Width /2  -> Distance mini X  for 22 cm (10 cm of Security)

// For 22.5' =  22.98 cm
// For 45'   =  26.70 cm
// For 67.5' =  41.35 cm

// Distance
#define 	MINI_DIST_CENTER			(LENGTH_ROVER + 10)		// in CM   (10 cm of Security)
#define		MINI_DIST_67_5				41.35					// in CM
#define		MINI_DIST_45				26.70					// in CM
#define		MINI_DIST_22_5				22.98					// in CM

// Time
#define		DELAYS_1_S					1000000	// in us,
#define		DELAYS_500_MS				500000	// in us,

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
static float	tabAreaScannig[NBE_SONAR_ROTATE]={0};

// Variables to Avoid Infinite Loop
static			eCtrlDirection	iPreviousCmd =  STOP_MOVE;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
/*
 ============================================
 Function     : Lib_Algo_Test()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Algo_Test(){
	// DEBUG SERVO AND SONAR
	Lib_Algo_All_Area_Scanning();
	sleep(2);

	// DEBUG MOTOR
	// Start Go Head
	Lib_motor_control(FORWARD);
	printf(" -> FORWARD \n");
	sleep(2);

	Lib_motor_control(STOP_MOVE);
	printf(" -> STOP \n");
	sleep(1);

	// Rotate 90 to The Right
	Lib_motor_rover_Rotate(ROTATE_RIGHT, TIME_ROTATE_90);
	printf(" -> Rotate 90 to The Right \n");
	sleep(2);

	// U TURN
	Lib_motor_rover_U_Turn();
	printf(" -> U_Turn \n");
}

/*
 ============================================
 Function     : Lib_Algo_Roaming_Rover()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Algo_Roaming_Rover(){

	// ********* CHECK FRONT OF IF IT'S CLEAR	********************* // Maybe need to check for Angle 45 and 22.5 Left and Right
	if((tabAreaScannig[CENTER]  > MINI_DIST_CENTER)&& (tabAreaScannig[RIGHT_67_5]  > MINI_DIST_67_5) && (tabAreaScannig[LEFT_67_5]  > MINI_DIST_67_5) )
	{
		// Go Head
		Lib_motor_control(FORWARD);
		printf(" -> FORWARD \n");
		// Scanning Area At CenterPosition
		Lib_Algo_Scanning(CENTER);

		// Prevent Infinite loop
		iPreviousCmd = FORWARD;
		
		return;

	}else{
		// Stop Move
		Lib_motor_control(STOP_MOVE);
		Lib_Algo_All_Area_Scanning();
		printf(" -> STOP_MOVE \n");

		//iPreviousCmd = STOP_MOVE;
	}

	// ********* CHECK RIGHT SIDE IF IT'S CLEAR	*********************
	if( (tabAreaScannig[RIGHT_0]  > MINI_DIST_CENTER) && (tabAreaScannig[RIGHT_22_5]  > MINI_DIST_CENTER) ){
		//if(tabAreaScannig[RIGHT_45]  > MINI_DIST_CENTER){
			//if(tabAreaScannig[RIGHT_67_5]  > MINI_DIST_CENTER){
				if(iPreviousCmd != ROTATE_LEFT){								
					printf(" -> Rotate 90 to The Right \n");
					// Rotate 90 to The Right
					Lib_motor_rover_Rotate(ROTATE_RIGHT, TIME_ROTATE_90);

					// Scan All Are from new position
					Lib_Algo_All_Area_Scanning();

					// Prevent Infinite loop
					iPreviousCmd = ROTATE_RIGHT;
				}
			//}
		//}
	}else{
		// ********* CHECK LEFT SIDE IF IT'S CLEAR	*********************
		if((tabAreaScannig[LEFT_0]  > MINI_DIST_CENTER) && (tabAreaScannig[LEFT_22_5]  > MINI_DIST_CENTER) ) {
			//if(tabAreaScannig[LEFT_45]  > MINI_DIST_CENTER){
				//if(tabAreaScannig[LEFT_67_5]  > MINI_DIST_CENTER){
					if(iPreviousCmd != ROTATE_RIGHT){								
						printf(" -> Rotate 90 to The Left \n");
						// Rotate 90 to The Left
						Lib_motor_rover_Rotate(ROTATE_LEFT, TIME_ROTATE_90);
						// Scan All Are from new position
						Lib_Algo_All_Area_Scanning();

						// Prevent Infinite loop
						iPreviousCmd = ROTATE_LEFT;
					}
				//}
			//}
		}else{
			// ********* NOT SIDE CLEAR, NEED TO DO U TURN	*********************
			printf(" -> U TURN \n");

			// Rotate 180
			Lib_motor_rover_U_Turn();

			// Scan All Are from new position
			Lib_Algo_All_Area_Scanning();
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

	// ************  LEFT 0 SCANNING *****************
	Lib_Algo_Scanning(LEFT_0);

	// ************  LEFT 22 5 SCANNING **************
	Lib_Algo_Scanning(LEFT_22_5);

	// ************  LEFT 45 SCANNING ****************
	Lib_Algo_Scanning(LEFT_45);

	// ************  LEFT 67 5 SCANNING **************
	Lib_Algo_Scanning(LEFT_67_5);

	// ************  CENTER SCANNING *****************
	Lib_Algo_Scanning(CENTER);

	// ************  RIGHT 67 5 SCANNING *************
	Lib_Algo_Scanning(RIGHT_67_5);

	// ************  RIGHT 45 SCANNING ***************
	Lib_Algo_Scanning(RIGHT_45);

	// ************  RIGHT 22 5 SCANNING *************
	Lib_Algo_Scanning(RIGHT_22_5);

	// ************  RIGHT SCANNING ******************
	Lib_Algo_Scanning(RIGHT_0);

	// ********* GO SERVO CENTER POSITION ************

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
	usleep(DELAYS_500_MS);

	// Sonar Scanning
	Lib_Sonar_Ping();

	// Save Value into the Table Area
	tabAreaScannig[valueRotate] = fDistance;

}

/*
 ============================================
 Function     : Lib_Algo_Stop()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Algo_Stop(){
	// Stop Motor
	Lib_motor_control(STOP_MOVE);

	// Servo Center Position
	Lib_Servo_Sonar_Control(CENTER);

}

/*
 ============================================
 Function     : Lib_Algo_Init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Algo_Init(){

	// Init Gpio Lib
	beh_BBB_gpio_init();

	// Motor
	Lib_motor_init();
	CmdDirection = NO_CMD;

	// Init Servo Motor
	Lib_Servo_init();

	// Init Sonar
	Lib_Sonar_Init();

	// Scanning the All Area at the Init Position
	Lib_Algo_All_Area_Scanning();
}
