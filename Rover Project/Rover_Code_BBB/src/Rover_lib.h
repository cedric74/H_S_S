/*
 ============================================================================
 Name        : Rover_lib.h
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 31/03/2015
 Description :
 ============================================================================
 */
#ifndef _ROVER_LIB_H
#define _ROVER_LIB_H

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include    "Lib_Algo/Lib_Algo.h"


#include 	"Functions_WatchDog/Functions_WatchDog.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define START_FILE			"ROVER,  1.4, 23 april, "
#define SIZE_STRING			24

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void 			Init(void);


#endif // _ROVER_LIB_H
