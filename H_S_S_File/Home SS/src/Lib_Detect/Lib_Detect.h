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
#include "../Functions_Alerte/Functions_Alerte.h"
#include "../Lib_Siren/Lib_Siren.h"
#include "../Lib_Camera/Lib_Camera.h"

/*******************************************
*               D E F I N E                *			
********************************************/
#define CAPTOR			P9_12
#define INTER_ON_OFF	P9_13

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *			
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *			
********************************************/
unsigned char 	stateCapteur;
unsigned char   stateInterrupter;

/*******************************************
*	        F U N C T I O N S   	       *			
********************************************/
void	main_Detect();

void 	Read_Captor();
void 	Read_Interrupter();
void 	Init_Lib_Detect();

void * 	Thread_Read_Input();



#endif /*_LIB_DETECT_H */
