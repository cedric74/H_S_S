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
#include "Rover_lib.h"

/*******************************************
*               D E F I N E                *			
********************************************/

/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *			
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *			
********************************************/
#define	TICK_LOOP_MAIN		5
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
	// Init
	Init();

	// Main Loop
	do{
		// Main Function Detect
		//main_Detect();

		// Sleep
		sleep(TICK_LOOP_MAIN);

	}while(1);

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

	// Debug print
	printf("%s \n", START_FILE);

	// Init Gpio Lib
	beh_BBB_gpio_init();

	// Init State Machine
	Init_State_Machine();
}
