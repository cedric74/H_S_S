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

// Data Bike
const float RADIUS_BIKE = 340.00F; // Diameter 680 mm

// Perimeter of circle formula
//P = 2.Pi.Radius

#define DISTANCE(x) ((2 * 3.14 * RADIUS_BIKE * x))

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
static int socketData;
static int newSockData;

char iData[2] = {0,0};

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


	// Instructions

#ifdef 	DEBUG
	// Simulate Detection
	iData[0] = rand() % 30;
#else
	// Detection with Captor
	//....
#endif

	// Get Distance
	int Dist = DISTANCE(iData[0]);

	// Print Debug
	printf(" Count : %i , Distance : %i ", iData[0], Dist);

	iData[0] = (char)(Dist/10000);
	iData[1] = (char)((Dist - (iData[0] *10000))/100);
	iData[2] = (char)(Dist - (iData[1]*100 + iData[0]*10000));


	printf(" Value : %i %i %i\n", iData[0], iData[1], iData[2]);
	// Send Socket

	write_socket(newSockData, iData, 3);	// Problem with the size of the message

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


