/*
 * Lib_Motor.c
 *
 *  Created on: Mar 4, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include	"Lib_Motor.h"

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
 Function     : Init_Motor()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Init_Motor(){

	// Init Siren Ouput
	beh_BBB_gpio_conf_dir(MOTOR_CAMERA, OUTPUT);

}
