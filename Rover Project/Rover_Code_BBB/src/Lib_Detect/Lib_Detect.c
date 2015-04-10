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


/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *			
********************************************/
unsigned char 	u8DetectOn 			= 0;
int 			iCountInter 		= 0;

/*******************************************
*	 P R O T O T Y P E   F U N C T I O N   *			
********************************************/

/*******************************************
*	          M  A I N    	               *			
********************************************/

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
		Read_Captor(ptrCaptorLine);

		// Delays
		usleep(WAIT_1MS);	// Each 1 ms
	}
	return NULL;
}

/*
 ============================================
 Function     : Read_Captor()
 Parameter    : 
 Return Value : void
 Description  :
 ============================================
 */
void Read_Captor(structCaptor * sCaptor){

	// Declarations Variables
	unsigned char readEntry = 0 ;
	int old_cancel_state;
	
	// Instructions

	// Read Input Captor
	readEntry = beh_BBB_gpio_ReadPin(sCaptor->ePinCaptor);

	// State Machine Captor
	//printf(" Before Inside Captor %d", sCaptor.stateCapt);
	switch(sCaptor->stateCapt){
		case STATE_NO_DETECTION :
			if( readEntry == DETECT_OK){
				// Change State
				pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state);

				sCaptor->stateCapt = STATE_DETECTION ;
				/* Fin de la section critique. */
				pthread_setcancelstate (old_cancel_state, NULL);
				printf(" Press Ok, Captor %s", sCaptor->sMessage);
			} 
		break ;
		
		case STATE_DETECTION :
			if( readEntry == DETECT_OK){
				sCaptor->icountDete++;
			}else{
				// Change State
				sCaptor->stateCapt = STATE_NO_DETECTION;
				if( sCaptor->icountDete >= COUNT_DETECTION){
					printf(" Release Ok, Count: %d, Captor %s",  sCaptor->icountDete , sCaptor->sMessage);
					sCaptor->icountDete = 0;

					pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state);

					u8DetectOn = (unsigned char)sCaptor->ePinCaptor;

					/* Fin de la section critique. */
					pthread_setcancelstate (old_cancel_state, NULL);
				} 
			}	 
		break;
	}

	//return sCaptor;
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

	// Init Captor Line Detection
	ptrCaptorLine = &sCaptorLine;
	ptrCaptorLine->ePinCaptor = CAPTOR_LINE;
	ptrCaptorLine->icountDete = 0;
	ptrCaptorLine->stateCapt = STATE_NO_DETECTION ;
	ptrCaptorLine->sMessage = "LINE\n";
	beh_BBB_gpio_conf_dir(ptrCaptorLine->ePinCaptor, INPUT_PULL_UP_EN);	//INPUT_PULL_UP_EN

	// Thread Execute Read Input
	pthread_create (&thread_id, NULL, &Thread_Read_Input, NULL);

}
