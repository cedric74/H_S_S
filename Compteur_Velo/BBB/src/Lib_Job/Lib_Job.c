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
typedef enum{
	DATA	= 0x10,
	CMD		= 0x20,
}typeMessageEnum;

// Formula distance from count of round and radius of the wheel
#define DISTANCE(x,y) ((2 * 3.14 * y * x))
//#define DISTANCE(x,y) ((2 * 3.14 * RADIUS_BIKE * x))

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

	// Create Socket Server
	socketData = create_Socket_Server(iPortSocket);
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
	char iData[3] ={0};

	// Instructions

#ifdef 	DEBUG
	// Simulate Detection
	iData[0] = rand() % 30;
#else
	// Detection with Captor
	//....
#endif

	// Get Distance
	int iDist = DISTANCE(iData[0], fRadius);

	// Print Debug
	printf(" Count : %02i , Distance : %05i ", iData[0], iDist);

	// Convert Binary To BCD
	int iRt = convertToBCD( iData, iDist, 3);
	if(iRt < 0 ){
		printf("Error, Convert To BCD\n");
		return -1;
	}
	printf(" Value : %02i %02i %02i\n", iData[0], iData[1], iData[2]);

	// Set Message af DATA, and the data is composed of tab of 3 Char
	char buffer[10] = {0};
	int iLen  = libcom_SetMsg(buffer, DATA, 3, sizeof(char) , iData);

	// DEBUG OK
//	strMsg mMesg1= {0};
//	strMsg *p = &mMesg1;
//	libcom_GetMsg(buffer, p);
//	printf("bType : %i \n",mMesg1.bType);
//	printf("bLength : %i \n",mMesg1.bLength);
//	printf("data : %i \n", (char)*(char*)(mMesg1.value));
//	(mMesg1.value)++;
//	printf("data : %i \n", (char)*(char*)(mMesg1.value));
//	(mMesg1.value)++;
//	printf("data : %i \n", (char)*(char*)(mMesg1.value));

	// Send Socket
	write_socket(newSockData, buffer, iLen);

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


