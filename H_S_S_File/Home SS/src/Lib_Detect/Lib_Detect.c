/*
 ============================================================================
 Name        : Lib_Detect.c
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 29/01/2015
 Description : 
 ============================================================================
 */

/*******************************************
*			  I N C L U D E 			   *			
********************************************/
#include "Lib_Detect.h"

/*******************************************
*               D E F I N E                *			
********************************************/
#define DETECT_OK			0
#define INTRUSION_OK		1

#define STATE_NO_DETECTION	0
#define STATE_DETECTION		1

#define	STATE_OFF			0
#define STATE_ON			1

#define COUNT_DETECTION		100

#define COUNT_INTERRUPTER	500

#define OFF					0
#define ON					1

#define OFF_INTERRUPT		1
#define ON_INTERRUPT		0

#define DELAYS_TO_DISABLE	30		// 30 Sec
#define DELAYS_TO_ENABLE	(60*2)	// 2 MIN

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *			
********************************************/
unsigned char 	u8DetectOn 			= 0;
int 			iCount 				= 0;
int 			iCountInter 		= 0;
	
/*******************************************
*	 P R O T O T Y P E   F U N C T I O N   *			
********************************************/

/*******************************************
*	          M  A I N    	               *			
********************************************/

/*
 ============================================
 Function     : main_Detect()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void main_Detect(){
	// Declarations Variables
	int old_cancel_state;
	int iSystemOn = ON;

	// Process Father
	if( u8DetectOn == INTRUSION_OK){

		//printf("\n Detect OK");
		File_Log("Detect OK, ", 11);

		// Ping_Phone
		//iSystemOn = Ping_Phone();

		// Read State interrupter
		if (stateInterrupter == STATE_OFF){
			iSystemOn = OFF;
		}else{
			iSystemOn = ON;
		}

		// Check If System Is ON
		if(iSystemOn == ON){

			// Take A pic
			File_Log("Take A Pic, ", 12);
			Take_Picture();

			// Sound Alerte that System ON
			// ....

			// Delays to Disable System with Interrupter
			printf(" DELAYS_TO_DISABLE\n");
			sleep(DELAYS_TO_DISABLE);
			if (stateInterrupter == STATE_OFF){
				iSystemOn = OFF;
			}else{
				iSystemOn = ON;
			}

			if(iSystemOn == OFF){
				// Disable System
				printf(" System OFF \n");
				File_Log("System OFF, ", 12);
			}else{
				// Alerte OK
				printf(" Alerte OK \n");
				// Send Alerte By Mail & Sms
				send_Alerte(NO_SMS);

				// Siren ON.
				File_Log("Siren  ON , ", 12);
				Start_Siren();
			}

		}else{
			printf(" System OFF \n");
			File_Log("System OFF, ", 12);
		}

	}else{
		//printf("\n No Detect ");
		File_Log("No Detect, ", 11);
	}

	// Start Section critic
	pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state);

	// Reset Flag Detection
	u8DetectOn = 0;

	// End Section critic
	pthread_setcancelstate (old_cancel_state, NULL);
}

/*
 ============================================
 Function     : Thread_Read_Captor()
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
void* Thread_Read_Input(){
	while(1){
		
		// Read Captor
		Read_Captor();

		// Read Interrupter
		Read_Interrupter();

		// Delays
		usleep(1000);	// Each 1 ms
	}
	return NULL;
}

/*
 ============================================
 Function     : Read_Interrupter()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Read_Interrupter(){

	// Declarations Variables
	unsigned char readEntry = OFF_INTERRUPT ;

	// Instructions

	// Read Input Captor
	readEntry = beh_BBB_gpio_ReadPin(INTER_ON_OFF);

	switch(stateInterrupter){
		case STATE_OFF :
			if( readEntry == ON_INTERRUPT){
				iCountInter++;
				if( iCountInter >= COUNT_INTERRUPTER){

					// Delays 2 MIN before system switch to ON
					printf(" DELAYS_TO_ENABLE \n");
					sleep(DELAYS_TO_ENABLE);

					printf(" System ON, INTERRUPTER \n");
					File_Log("System switch to ON, ", 23);

					// Change State
					stateInterrupter = STATE_ON ;

					// Init iCountInter
					iCountInter = 0;
				}
			}else{
				if(iCountInter > 0 ){
					iCountInter--;
				}
			}

		break ;

		case STATE_ON :
			if( readEntry == OFF_INTERRUPT){
				iCountInter++;
				if( iCountInter >= COUNT_INTERRUPTER){
					//printf(" System OFF, INTERRUPTER \n");
					File_Log("System switch to OFF, ", 24);

					// Change State
					stateInterrupter = STATE_OFF ;
				}

			}else{
				if(iCountInter > 0 ){
					iCountInter--;
				}
			}

		break;
	}
}

/*
 ============================================
 Function     : Read_Captor()
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
void Read_Captor(){

	// Declarations Variables
	unsigned char readEntry = 0 ;
	int old_cancel_state;
	
	// Instructions

	// Read Input Captor
	readEntry = beh_BBB_gpio_ReadPin(CAPTOR);

	// State Machine Captor
	switch(stateCapteur){
		case STATE_NO_DETECTION :
			if( readEntry == DETECT_OK){
				// Change State
				stateCapteur = STATE_DETECTION ;
				printf(" press Ok, ");
			} 
		break ;
		
		case STATE_DETECTION :
			if( readEntry == DETECT_OK){
				iCount++; 
			}else{
				// Change State
				stateCapteur = STATE_NO_DETECTION;
				if( iCount >= COUNT_DETECTION){
					printf(" Release Ok nb %d",  iCount);
					iCount = 0;
					pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state);
					u8DetectOn = 1;

					/* Fin de la section critique. */
					pthread_setcancelstate (old_cancel_state, NULL);
				} 
			}	 
		break;
	}
}

/*
 ============================================
 Function     : Init_Captor()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Init_Lib_Detect(){

	// Declarations Variables
	pthread_t thread_id;

	// Init Global Variables
	stateCapteur = STATE_NO_DETECTION ;
	stateInterrupter = STATE_OFF;

	// Thread Execute Read Captor
	pthread_create (&thread_id, NULL, &Thread_Read_Input, NULL);

	// Thread Execute Send Daily Raport
	pthread_create (&thread_id_Daily, NULL, &Thread_DailyRaport, NULL);

	// Init Captor Input
	beh_BBB_gpio_conf_dir(CAPTOR, INPUT_PULL_UP_EN);	//INPUT_PULL_UP_EN

	// Init Interrupter	Input
	beh_BBB_gpio_conf_dir(INTER_ON_OFF, INPUT_PULL_UP_EN );  //INPUT_PULL_UP_EN

}
