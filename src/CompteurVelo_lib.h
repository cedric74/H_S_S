/*
 ============================================================================
 Name        : CompteurVelo_lib.h
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 28/06/2015
 Description :
 ============================================================================
 */
#ifndef _COMPTEURVELO_LIB_H
#define _COMPTEURVELO_LIB_H

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include 	"Functions_WatchDog/Functions_WatchDog.h"
#include	"Lib_socket/Lib_socket.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define START_FILE			"Compteur Velo, 1.0, 28 June, "
#define SIZE_STRING			30

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
