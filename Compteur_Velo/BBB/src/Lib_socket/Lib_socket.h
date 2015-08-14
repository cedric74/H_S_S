/*
 ============================================================================
 Name        : Lib_socket.h
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 03/02/2015
 Description : 
 ============================================================================
 */


#ifndef LIB_SOCKET_H_
#define LIB_SOCKET_H_

/*******************************************
*			  I N C L U D E 			   *			
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../Lib_Param/Lib_Param.h"
/*******************************************
*               D E F I N E                *			
********************************************/
#define ERROR_SOCKET	-1

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *			
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *			
********************************************/
/*******************************************
*	        F U N C T I O N S   	       *			
********************************************/
int 			create_Socket(int iPort);
int 			accept_client_connection(int sockfd);
int 			write_socket(int  newsockfd, char * sMessage, int iSize);
int 			read_socket(int newsockfd, int iLength , unsigned char * bData);
void 			send_binary(int  newsockfd, char *file_name);

void 			close_socket(int sockfd, int newsockfd);
void 			error(const char *msg);


#endif /* LIB_SOCKET_H_ */
