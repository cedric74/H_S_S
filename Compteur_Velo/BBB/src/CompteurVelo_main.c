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
#define DELAY_1_SEC			1		// In s
#define DELAY_2_SEC			2		// In s
#define	TICK_500_MS			500000	// In us

/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *			
********************************************/
void on_sigint(int x);
void Init();
int  Load_Data();
void exit_main();

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

	// DEBUG
	printf("Tick Main : %i , iPortSocket : %i, fRadius : %3.2f \n", iTickLoop , iPortSocket , fRadius);

	// DEBUG
	//setData( tabData, NBE_VARIABLE_XML_TO_LOAD);

	// DEBUG
	//Lib_Config_Save(FILE_XML, tabData, NBE_VARIABLE_XML_TO_LOAD);

	// DEBUG
//	int Value[]={ 12345,6789	};
//	unsigned char uB[] = {0,1,2,3,4,5};
//	strMsg  *pMesg = libcom_SetMsg( 1, 2, sizeof(int) , Value);
//	printf(" Type   : 0x%X", pMesg->bType);
//	printf(" Length : 0x%X\n", pMesg->bLength);
//
//	printf(" test :  %d\n", *(char*)pMesg->value);
//	int i=0;

	// Ok pour Char
//	for( i =0; i < 6 ; i++){
//		printf(" data :  %d\n", *(char*)pMesg->value);
//		pMesg->value++;
//	}
	// OK, for int.
//	printf(" test :  %d\n", *(int*)pMesg->value);
//	for( i =0; i < 2 ; i++){
//		printf(" data : %d\n",   (int)*((int*)pMesg->value));
//		pMesg->value +=(sizeof(int));
//	}



	signal(SIGINT, on_sigint);
	while (is_sigint == 0){

		// Call Job Function
		Job_main();

		// Wait
		sleep(iTickLoop);
		//usleep(TICK_500_MS);
	}

	printf("\n\nEND %s \n", START_FILE);
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
	//watch_dog_start();

	// Init Gpio Lib
	beh_BBB_gpio_init();

	// Init Config XML
	if(Load_Data()== -1){
		printf("Error Load XML , Get Default Setting \n");

		// Default Setting
		setDefaultData();

	}else{
		printf("Load XML, OK\n");
	}

	// Init Socket
	Job_init();

}

/*
 ============================================
 Function     : Load_Data()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int Load_Data(){

	// Temp Tab
	//sNodeL4 tabData[SIZE_DATA];

	int iIndex = Lib_Config_Load(FILE_XML, tabData);
	if(iIndex > 0){
		// Load XML Data
		if(getData(tabData , iIndex) != 0){
			return -1;
		}
		// Print All Data
		printf("\n----- Config XML ---- \n");
		int i;
		for(i =0 ; i < iIndex ; i++){
			printf("cTable[%i].cName  : %s\n", i, tabData[i].cName);
			printf("cTable[%i].cType  : %s\n", i, tabData[i].cType);
			printf("cTable[%i].cValue : %s\n", i, tabData[i].cValue);
		}
		printf("\n\n");
	}else{
		return -1;
	}
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

/*
 ============================================
 Function     : exit_main()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void exit_main(int iStatus){
	if(iStatus == 1){
		printf("\n\nError END %s \n", START_FILE);
		exit(0);
	}

	printf("\n\nEND %s \n", START_FILE);
}
