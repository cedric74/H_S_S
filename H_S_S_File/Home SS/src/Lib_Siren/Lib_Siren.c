/*
 * Lib_Siren.c
 *
 *  Created on: Mar 4, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_Siren.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define TIME_SIREN		5

#define TIME_WARNING	10
#define FREQ_BUZZER		1000   // In us , Pas mal 1000

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void WarningSystemOn(){
	int i;

	for(i = 0; i <TIME_WARNING ; i ++){
		beh_BBB_gpio_WritePin(BUZZER, SIREN_ON );
		usleep(FREQ_BUZZER);
		beh_BBB_gpio_WritePin(BUZZER, SIREN_OFF );
		usleep(FREQ_BUZZER);
	}
}

/*
 ============================================
 Function     : Thread_Siren()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void* Thread_Siren(){

	// Delays before Stop siren
	sleep(TIME_SIREN);

	Stop_Siren();

	return NULL;
}

/*
 ============================================
 Function     : Start_Siren()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Start_Siren(){

	// Declarations Variables
	pthread_t thread_id;

	// Set Siren On
	beh_BBB_gpio_WritePin(SIREN, SIREN_ON );

	// Thread Execute Read Captor
	pthread_create (&thread_id, NULL, &Thread_Siren, NULL);

}

/*
 ============================================
 Function     : Stop_Siren()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Stop_Siren(){
	// Set Siren Off
	beh_BBB_gpio_WritePin(SIREN, SIREN_OFF );
}

/*
 ============================================
 Function     : Init_Siren()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Init_Siren(){

	// Init Buzzer
	beh_BBB_gpio_conf_dir(BUZZER, OUTPUT);

	// Init Siren Ouput
	beh_BBB_gpio_conf_dir(SIREN, OUTPUT);

	// Set Siren Off
	Stop_Siren();
}


