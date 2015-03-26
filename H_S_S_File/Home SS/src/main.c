/*
 ============================================================================
 Name        : lib_uart_main.c
 Author      : Cedric T.
 Version     : 1.0
 Date		 : 10/02/2015
 Description : 
 ============================================================================
 */
 /*******************************************
*			  I N C L U D E 			   *			
********************************************/
#include "Lib_main.h"

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
		main_Detect();

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

	// Wait to Let BBB Start
	sleep(5);

	// Start WatchDog
	watch_dog_start();

	// Create File Log With Version
	File_Log(START_FILE, SIZE_STRING);

	// Init Gpio Lib
	beh_BBB_gpio_init();

	// Init  Detect Lib
	Init_Lib_Detect();

	// Init Siren
	Init_Siren();

	// Init State Machine
	Init_State_Machine();

}
