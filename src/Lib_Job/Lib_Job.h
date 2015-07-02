/*
 * Lib_Job.h
 *
 *  Created on: 28 juin 2015
 *      Author: cedric
 */

#ifndef SRC_LIB_JOB_LIB_JOB_H_
#define SRC_LIB_JOB_LIB_JOB_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include	"../Lib_socket/Lib_socket.h"

/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
int Job_init(void);
int Job_main(void);
int Job_end(void);

#endif /* SRC_LIB_JOB_LIB_JOB_H_ */
