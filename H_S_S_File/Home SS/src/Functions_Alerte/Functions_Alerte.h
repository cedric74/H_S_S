/*
 * Functions_Alerte.h
 *
 *  Created on: Feb 28, 2015
 *      Author: cedric
 */

#ifndef FUNCTIONS_ALERTE_H_
#define FUNCTIONS_ALERTE_H_


/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stddef.h>
#include <pthread.h>

/*******************************************
*               D E F I N E                *
********************************************/
#define PHONE_CEDRIC		2
#define PHONE_AURELIE		1
#define NO_PHONE			0

#define NO_SMS				0
#define SMS_OK				1

#define ERROR				-1
#define OK					0
/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
int 	isystemON;
FILE * 	fpLog;
pthread_t thread_id_Daily;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void * Thread_DailyRaport();
void Send_Report_File_Log();
void File_Log(char * string, int iLength);
int Ping_Phone();
int Connection_OK();
int send_Alerte(int iSmsok);
int sendmail(const char *to, const char *from, const char *subject, const char *message);


#endif /* FUNCTIONS_ALERTE_H_ */
