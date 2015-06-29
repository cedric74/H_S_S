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
	//printf(" Delay 5 s Before Start Program .... \n");

	// Init
	Init();

	signal(SIGINT, on_sigint);
	while (is_sigint == 0){

		// Call Job Function
		Job_main();

		// Wait 5 Sec
		sleep(DELAY_5_SEC);
	}

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

	// Debug print
	printf("%s \n", START_FILE);

	// Start WatchDog
	watch_dog_start();

	// Init Gpio Lib
	beh_BBB_gpio_init();

	// Init Socket
	Job_init();
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
