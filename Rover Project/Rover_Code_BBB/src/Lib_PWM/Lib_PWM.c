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
char cPath_P9_14[BUFFER_SIZE];
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
	int iTry = 0;

	// Instructions

	// Add Cape inside Slots
	system("echo  bone_pwm_P9_14 	> /sys/devices/bone_capemgr.9/slots");
	printf( " Added Cape Pwm Into Slots OK \n");

	// Wait Time to Load The Cape Into The Slots
	usleep(500000);

	// Find Value Offset
	do{
		snprintf(cPath_P9_14, BUFFER_SIZE, PATH_P9_14);
		switch(iTry){
			case 0:
				strcat(cPath_P9_14,Offset_11);
				break;
			case 1:
				strcat(cPath_P9_14,Offset_12);
				break;
			case 2:
				strcat(cPath_P9_14,Offset_13);
			break;
			case 3:
				strcat(cPath_P9_14,Offset_14);
			break;
			case 4:
				strcat(cPath_P9_14,Offset_15);
			break;
			case 5:
				strcat(cPath_P9_14,Offset_16);
			break;
			case 6:
				strcat(cPath_P9_14,Offset_17);
			break;
			case 7:
				strcat(cPath_P9_14,Offset_18);
			break;

			default:
				printf("\n Error Open File : %s \n", buffer);

				// Stop Program
				exit(0);
				//return ERROR_PWM_OPEN;
			break;
		}

		// Copy  Path
		snprintf(buffer , BUFFER_SIZE, cPath_P9_14);
		strcat(buffer,PATH_RUN);

		//printf("\n Test Open File : %s  , try : %d\n", buffer, iTry);
		iTry++;
		fd = open(buffer, O_WRONLY);
	}while(fd < 0);


	sprintf(buffer, "%d", 0);
	printf("run : %s, \n", buffer);
	write(fd, buffer, BUFFER_SIZE);

	// Close descriptor File
	close (fd);


	printf(" Init Pwm Ok \n");
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
	snprintf(buffer, BUFFER_SIZE, cPath_P9_14);
	strcat(buffer,PATH_RUN);

	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n Error Open File : %s \n", buffer);
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
	// ----- Echo value > PERIOD
	snprintf(buffer, BUFFER_SIZE, cPath_P9_14);
	strcat(buffer,PATH_PERIOD);
	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n Error Open File : %s \n", buffer);
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", iPeriod);
	printf("iPeriod : %s, ", buffer);
	write(fd, buffer, BUFFER_SIZE);

	// Close descriptor File
	close (fd);

	// ----- Echo value > DUTY
	snprintf(buffer, BUFFER_SIZE, cPath_P9_14);
	strcat(buffer,PATH_DUTY);

	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n Error Open File : %s \n", buffer);
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
	strcat(buffer,PATH_DUTY);

	fd = open(buffer, O_WRONLY);
	if (fd < 0) {
		printf("\n Error Open File : %s \n", buffer);
		return ERROR_PWM_OPEN;
	}

	sprintf(buffer, "%d", 0);
	printf("run : %s\n", buffer);
	write(fd, buffer, BUFFER_SIZE);
	// Close descriptor File
	close (fd);

	return 0;
}

