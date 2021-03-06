/*
 ============================================================================
 Name        : Lib.h
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 29/01/2015
 Description : 
 ============================================================================
 */
#ifndef _LIB_DETECT_H
#define _LIB_DETECT_H

/*******************************************
*			  I N C L U D E 			   *			
********************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "../Lib_Gpio/beh_BBB_gpio.h"


/*******************************************
*               D E F I N E                *			
********************************************/
#define CAPTOR_LINE				P9_16

#define	STATE_OFF				0
#define STATE_ON				1

#define DETECT_OK				0
#define INTRUSION_OK			1
#define INTRUSION_NO			0

#define COUNT_DETECTION			100

#define OFF						0
#define ON						1

#define SIZE_MESS_CAPTOR		4

#define WAIT_1MS	1000
/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *			
********************************************/
typedef enum {STATE_NO_DETECTION = 0, STATE_DETECTION  = 1}stateCaptor;

typedef struct {
	stateCaptor stateCapt;
	int 		icountDete;
	GPIO_Pins	ePinCaptor;
	char*		sMessage;
}structCaptor;

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *			
********************************************/
structCaptor 	sCaptorLine;
structCaptor 	* ptrCaptorLine;

/*******************************************
*	        F U N C T I O N S   	       *			
********************************************/
void 	Read_Captor(structCaptor * sCaptor);
void 	Init_Lib_Detect();

void * 	Thread_Read_Input();



#endif /*_LIB_DETECT_H */
