/*
 ============================================================================
 Name        : CompteurVelo_main.c
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 28/06/2015
 Description : 
 ============================================================================
 */
 /*******************************************
*			  I N C L U D E 			   *			
********************************************/
// Standard header files
#include <signal.h>

// Driver header file
#include "CompteurVelo_lib.h"

/*******************************************
*               D E F I N E                *			
********************************************/
#define	TICK_LOOP_MAIN		100000	// In us
#define DELAY_5_SEC			5		// In s

/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *			
********************************************/
static void on_sigint(int x);

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
	// Debug print
	printf(" Delay 5 s Before Start Program .... \n");

	// Init
	Init();


	///printf(" ******* Start Socket ******* \n\n");
	// Create Socket Server
	int socketData 	= create_Socket(6000);
	int newSockData = accept_client_connection(socketData);
	char iData[]="coucou";
	//iData[0] = 0x55;
	//iData[1] = 0x22;


		//signal(SIGINT, on_sigint);
		//while (is_sigint == 0){
			write_socket(newSockData, iData, 6);	// Problem with the size of the message

			sleep(DELAY_5_SEC);
	//	}

//
//	// Thread Execute Read Command
//	pthread_create (&threadId_ReadCommand, NULL, &Thread_Read_Command, NULL);



	close_socket(socketData, newSockData);

	printf("END %s \n", START_FILE);
	return 0;
}

/*
 ============================================
 Function     : Init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Init(){

	// Start WatchDog
	watch_dog_start();

	// Init Gpio Lib
	beh_BBB_gpio_init();

	// Debug print
	printf("%s \n", START_FILE);

	// Init State Machine
	//Init_State_Machine();
}


/*
 ============================================
 Function     : on_sigint()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
static void on_sigint(int x)
{
  is_sigint = 1;
}
