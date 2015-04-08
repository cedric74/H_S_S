/*
 * Functions_State_Machine.c
 *
 *  Created on: Mar 4, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Functions_State_Machine.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define SLEEP_500_MS			500000
#define SLEEP_100_MS			100000
#define SLEEP_10_MS				10000

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
eCtrlDirection 	CmdDirection 		;
int 			ret_thread 			= 0;
int 			thread_Send_Data 	= 0;
int 			iStopthread         = 0;
int 			iStopCommand		= 0;

int 			socketCmd;
int				newSockCmd;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void test_program();
/*
 ============================================
 Function     : Init_State_Machine()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Init_State_Machine(){

	pthread_t threadId_StateMachine;

	// Init Motor
	Lib_motor_init();
	CmdDirection = NO_CMD;

	// Init Servo Motor
	Lib_Servo_init();

	// Thread Execute StateMachine
	pthread_create (&threadId_StateMachine, NULL, &Thread_State_Machine, NULL);

}

/*
 ============================================
 Function     : Thread_State_Machine()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void * Thread_State_Machine(){

	// Declarations Variables
	pthread_t threadId_ReadCommand;

	test_program();

//	do{
//		///printf(" ******* Start Socket ******* \n\n");
//		// Create Socket Server
//		socketCmd 	= create_Socket(PORT_NUM);
//		newSockCmd = accept_client_connection(socketCmd);
//
//		// Thread Execute Read Command
//		pthread_create (&threadId_ReadCommand, NULL, &Thread_Read_Command, NULL);
//
//		// Loop State Machine
//		do{
//			// State Machine
//			state_machine();
//
//			// Sleep 500 ms
//			usleep(SLEEP_500_MS);
//
//		}while(iStopCommand != 1);
//
//		// close Thread Read Command
//		pthread_join(threadId_ReadCommand, NULL);
//
//		// Close Socket Data
//		close_socket(socketCmd, newSockCmd);
//
//		//printf("\n\n ******* End Main Socket ******* \n\n");
//
//		// Clear Stop Command
//		iStopCommand = 0;
//
//	}while(1);

	return NULL;
}

/*
 ============================================
 Function     : state_machine()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
unsigned char state_machine(void){

	switch(CmdDirection){
		case ROTATE_LEFT:
			printf(" ROTATE_LEFT CMD\n");
		break;
		case ROTATE_RIGHT:
			printf(" ROTATE_RIGHT CMD\n");
		break;
		case FORWARD:
			printf(" FORWARD CMD\n");
		break;
		case BACKWARD:
			printf(" BACKWARD CMD\n");
		break;
		case STOP_MOVE:
			printf(" STOP_MOVE CMD\n");
		break;

		default:
			break;

	}
	Lib_motor_control(CmdDirection);
	CmdDirection = NO_CMD;

	return 0;
}

/*
 ============================================
 Function     : test_program()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void test_program(){
	//  ------  -------- ---- DEBUG TEST SERVO MOTEUR PWM
	printf(" Sens 1 \n");
	Lib_motor_control(FORWARD);
	sleep(2);
	Lib_Servo_Sonar_Control(FULL_LEFT);
	printf(" Stop \n");
	Lib_motor_control(STOP_MOVE);
	//sleep(2);
	printf(" Sens 2 \n");
	Lib_motor_control(BACKWARD);
	sleep(2);
	//sleep(2);
	printf(" ROTATE_LEFT \n");
	Lib_motor_control(ROTATE_LEFT);
	Lib_Servo_Sonar_Control(FULL_RIGHT);
	sleep(2);
	printf(" ROTATE_RIGHT \n");
	Lib_motor_control(ROTATE_RIGHT);

	sleep(2);
	printf(" Stop \n");
	Lib_motor_control(STOP_MOVE);

	//Lib_pwm_stop();

	Lib_Servo_Sonar_Control(CENTER);
	sleep(3);


	printf(" End Test\n");
	//------------------------ DEBUG TEST SONAR PING

	//Lib_Sonar_Ping();

	Lib_pwm_stop();
}

/*
 ============================================
 Function     : Thread_Read_Command()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void* Thread_Read_Command(){

	//printf(" ******* Start Thread_Read_Command ******* \n");
//	while(1){
//		unsigned char bData[2]= {0};
//		int n =read_socket(newSockCmd , 2, bData);
//		//if(n == SIZE_CMD_MESSAGE){
//		CmdDirection = bData[0];
//		//}
//		// Sleep
//		usleep(SLEEP_10_MS)	;
//	}
//	//printf(" ******* End Thread_Read_Command ******* \n");
//
//	pthread_exit(&ret_thread);

	return NULL;
}
