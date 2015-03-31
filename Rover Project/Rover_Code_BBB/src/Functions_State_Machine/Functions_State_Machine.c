/*
 * Functions_State_Machine.c
 *
 *  Created on: Mar 4, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Functions_State_Machine.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define SLEEP_100_MS			100000
#define SLEEP_10_MS				10000

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
 Function     : Init_State_Machine()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Init_State_Machine(){

	pthread_t threadId_StateMachine;

	// Thread Execute StateMachine
	pthread_create (&threadId_StateMachine, NULL, &Thread_State_Machine, NULL);

}

/*
 ============================================
 Function     : Thread_State_Machine()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void * Thread_State_Machine(){

	do{

		// State Machine
		state_machine();

		// Sleep 100 ms
		usleep(SLEEP_100_MS);

	}while(1);

	return NULL;
}

/*
 ============================================
 Function     : state_machine()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
unsigned char state_machine(void){

	return 0;
}




