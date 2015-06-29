/*
 * Lib_Job.c
 *
 *  Created on: 28 juin 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_Job.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define DEBUG 1
/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
const int SERVER_PORT = 6000;

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
static int socketData;
static int newSockData;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/

/*
 ============================================
 Function     : Job_init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int Job_init(void){

#ifdef 	DEBUG
	// Init Randon Generator
	srand(time(NULL));

#endif

	// Debug print
	printf(" Waiting for Client Connection .... \n");

	socketData 	= create_Socket(SERVER_PORT);
	newSockData = accept_client_connection(socketData);

	return 0;
}

/*
 ============================================
 Function     : Job_main()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int Job_main(void){

	// Declarations Variables
	char iData[2] = {0,0};

	// Instructions

#ifdef 	DEBUG
	iData[0] = rand() % 100;
#endif

	//
	printf(" data : %i \n", iData[0]);

	// Send Socket
	write_socket(newSockData, iData, 1);	// Problem with the size of the message


	return 0;
}

/*
 ============================================
 Function     : Job_End()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int Job_end(){
	close_socket(socketData, newSockData);

	return 0;
}

