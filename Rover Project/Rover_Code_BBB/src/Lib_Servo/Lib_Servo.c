/*
 * Lib_Servo.c
 *
 *  Created on: Mar 31, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include	"Lib_Servo.h"

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
 Function     : Lib_Servo_Control_Pwm()
 Parameter    :
 Return Value :
 Description  :
 ============================================
 */
int Lib_Servo_Control_Pwm(int iPeriod, int iDuty )
{
	// Declaration Variables
	int fd;
	char buffer[BUFFER_SIZE];

	// Instructions
	snprintf(buffer, BUFFER_SIZE, PATH_PERIOD);
	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n ERROR \n");
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", iPeriod);
	printf("iPeriod : %s, ", buffer);
	write(fd, buffer, BUFFER_SIZE);

	// Close descriptor File
	close (fd);

	snprintf(buffer, BUFFER_SIZE, PATH_DUTY);
	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n ERROR \n");
		return ERROR_PWM_OPEN;
	}
	sprintf(buffer, "%d", iDuty);
	printf("duty : %s\n", buffer);
	write(fd, buffer, BUFFER_SIZE);

	// Close descriptor File
	close (fd);

	return NO_ERROR_PWM;
}
/*
 ============================================
 Function     : Lib_Servo_init()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Lib_Servo_init(){
}
