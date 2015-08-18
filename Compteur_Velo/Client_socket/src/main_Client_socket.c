/*
 * main_Client_socket.c
 *
 *  Created on: Aug 18, 2015
 *      Author: ctoncanier
 */
 /*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include	"Lib_socket/Lib_socket.h"
/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *
********************************************/
void on_sigint(int x);

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
static volatile unsigned int is_sigint = 0;

/*******************************************
*          F U N C T I O N S    		   *
********************************************/
/*
 ============================================
 Function     : main()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int main(int argc, char *argv[])
{
	// Declarations Variables
	static int socketData;
	unsigned char u8Tab[10]={0};

	// Debug print
	printf(" Create Client and try to Connect to the server \n");


	// Create socket Client
	socketData = create_Socket_Client( "127.0.0.1", 6000);

	signal(SIGINT, on_sigint);
	while (is_sigint == 0){
		int iret = read_socket( socketData,  10, u8Tab);
		if(iret > 0){
			int i;
			printf("read_socket : nbe data : %i\n", iret);
			for(i =0 ; i < iret ; i++){
				printf("%02i ", u8Tab[i]);
			}
			printf("\n------\n\n");
		}

		// Wait
		sleep(1);
	}

	 close(socketData);

	 return 0;
}

/*
 ============================================
 Function     : on_sigint()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void on_sigint(int x)
{
  is_sigint = 1;
}
