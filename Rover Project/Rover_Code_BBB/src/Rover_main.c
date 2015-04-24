/*
 ============================================================================
 Name        : Rover_main.c
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 31/03/2015
 Description : 
 ============================================================================
 */
 /*******************************************
*			  I N C L U D E 			   *			
********************************************/
// Standard header files
#include <signal.h>

// Driver header file
#include "Rover_lib.h"

/*******************************************
*               D E F I N E                *			
********************************************/
#define	TICK_LOOP_MAIN		100000	// In us, 500000 too Long

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

	// Delay Before Start
	sleep(DELAY_5_SEC);

	// Init
	Init();

	// Start Algo Thread
	Lib_Algo_Start();

	// Main Loop
	// Wait for Ctrl-C
	signal(SIGINT, on_sigint);
    while (is_sigint == 0){

		// Sleep
		usleep(TICK_LOOP_MAIN);

	}

	// Call Stop Algo to stop motor and to init Servo Position
	Lib_Algo_Stop();


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

	// Init All Libraries
	Lib_Algo_Init();

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
