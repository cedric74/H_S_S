/*
 * Lib_Sonar.c
 *
 *  Created on: 2015-03-31
 *      Author: cedric
 */


/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <stdlib.h>

#include "Lib_Sonar.h"
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
/*
 ============================================
 Function     : Lib_Sonar_Init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Sonar_Init(){

	// Init Sonar
	//beh_BBB_gpio_conf_dir(SONAR_PIN, OUTPUT);
}
/*
 ============================================
 Function     : Lib_Sonar_Ping()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Sonar_Ping(){
	printf( " Test Sonar Ping \n");

	beh_BBB_gpio_conf_dir(SONAR_PIN, OUTPUT);
	beh_BBB_gpio_WritePin(SONAR_PIN, 0);
	usleep(2);

	// Input Trigger Pulse
	beh_BBB_gpio_WritePin(SONAR_PIN, 1);
	usleep(5);
	beh_BBB_gpio_WritePin(SONAR_PIN, 0);
	beh_BBB_gpio_conf_dir(SONAR_PIN, INPUT);


	//beh_BBB_gpio_ReadPin

}
