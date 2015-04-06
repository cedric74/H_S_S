/*
 * Lib_PWM.c
 *
 *  Created on: 2015-04-01
 *      Author: cedric
 */


/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_PWM.h"

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
 Function     : Lib_pwm_init()
 Parameter    :
 Return Value : int
 Description  :
 ============================================
 */
int Lib_pwm_init(){
	// Declaration Variables
	int fd;
	char buffer[BUFFER_SIZE];

	// Instructions

	// ----- Echo 0 > POLARITY -----
	snprintf(buffer, BUFFER_SIZE, PATH_POLARITY);
	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n ERROR \n");
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", 0);
	printf("run : %s, \n", buffer);
	write(fd, buffer, BUFFER_SIZE);

	// Close descriptor File
	close (fd);

	return 0;
}
/*
 ============================================
 Function     : Lib_pwm_start()
 Parameter    :
 Return Value : int
 Description  :
 ============================================
 */
int Lib_pwm_start(){
	// Declaration Variables
	int fd;
	char buffer[BUFFER_SIZE];


	// Instructions
	// ----- Echo 1 > RUN
	snprintf(buffer, BUFFER_SIZE, PATH_RUN);
	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n ERROR \n");
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", 1);
	printf("run : %s, \n", buffer);
	write(fd, buffer, BUFFER_SIZE);
	// Close descriptor File
	close (fd);

	return 0;
}

/*
 ============================================
 Function     : Lib_pwm_control()
 Parameter    :
 Return Value : int
 Description  :
 ============================================
 */
int Lib_pwm_control(int iPeriod, int iDuty )
{
	// Declaration Variables
	int fd;
	char buffer[BUFFER_SIZE];


	// Instructions
	// ----- Echo 1 > RUN
//	snprintf(buffer, BUFFER_SIZE, PATH_RUN);
//	fd = open(buffer, O_WRONLY);
//	if (fd < 0) {
//		printf("\n ERROR \n");
//		return ERROR_PWM_OPEN;
//	}
//
//	sprintf(buffer, "%d", 1);
//	printf("run : %s, \n", buffer);
//	write(fd, buffer, BUFFER_SIZE);
//	// Close descriptor File
//	close (fd);

	// ----- Echo value > PERIOD
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

	// ----- Echo value > DUTY
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

	// ----- Echo 0 > RUN
/*	snprintf(buffer, BUFFER_SIZE, PATH_RUN);
	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n ERROR \n");
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", 0);
	printf("run : %s\n", buffer);
	write(fd, buffer, BUFFER_SIZE);
	// Close descriptor File
	close (fd);*/

	return NO_ERROR_PWM;
}


/*
 ============================================
 Function     : Lib_pwm_stop()
 Parameter    :
 Return Value : int
 Description  :
 ============================================
 */
int Lib_pwm_stop(){
	// Declaration Variables
	int fd;
	char buffer[BUFFER_SIZE];


	// Instructions
	// ----- Echo 0 > RUN
	snprintf(buffer, BUFFER_SIZE, PATH_RUN);
	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n ERROR \n");
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", 0);
	printf("run : %s\n", buffer);
	write(fd, buffer, BUFFER_SIZE);
	// Close descriptor File
	close (fd);

	return 0;
}
