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
#define SLEEP_100_MS			100000

#define STOP_THREAD				1

#define	SEND_INFO_EACH_SEC		5	// In Second

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
unsigned char 	u8Command 			= NO_CMD;
int 			ret_thread 			= 0;
int 			thread_Send_Data 	= 0;
int 			iStopthread         = 0;
int 			iStopCommand		= 0;

int 			socketData;
int 			socketVideo;
int				newSockData;
int				newSockVideo;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
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

	// Thread Execute Read Command
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
void Thread_State_Machine(){

	// Declarations Variables
	//unsigned char	u8StMachine;
	pthread_t threadId_ReadCommand;

	do{
		printf(" ******* Start Socket ******* \n\n");
		// Create Socket Server
		socketData 	= create_Socket();
		newSockData = accept_client_connection(socketData);

		// Thread Execute Read Command
		pthread_create (&threadId_ReadCommand, NULL, &Thread_Read_Command, NULL);

		// Thread Execute Send Data
		StartThread_Send_Data();

		// Thread Execute Read Sensor
		//StartThread_ReadSensor();

		// Loop State Machine
		do{
			// State Machine
			state_machine();

			// Sleep 100 ms
			usleep(SLEEP_100_MS);

		}while(iStopCommand != 1);

		// close Thread Read Command
		pthread_join(threadId_ReadCommand, NULL);

		// close Thread Send Data
		pthread_join(thread_Send_Data, NULL);

		// Close Thread Read Sensor
		//pthread_join(threadId_Sensor, NULL);


		// Close Socket
		close_socket(socketData, newSockData);

		printf("\n\n ******* End Socket ******* \n\n");

		// Clear Stop Command
		iStopCommand = 0;

	}while(1);
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

	// Get Command From Monitoring Applications
	switch(u8Command){

		case SOUND_CMD:
			printf( " SOUND CMD \n");
			Start_Siren();

		break;

		case VIDEO_CMD:
			printf( " VIDEO CMD \n");
			Take_Picture();
			//send_binary(newSockData, "/home/debian/Desktop/Intrusion.jpeg");
			iStopthread = STOP_THREAD;
			sleep(10);

			StartThread_Send_Data();

		break;

		case DISCONN_CMD:
			printf( " DISCONNECT CMD \n");
			iStopCommand = 1;
			//return STOP_CMD;
		break ;
	}

	// Clear Command
	u8Command = NO_CMD;

	return u8Command;
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
	printf(" ******* Start Thread_Read_Command ******* \n");
	while(u8Command != DISCONN_CMD){
		u8Command = read_socket(newSockData);
	}
	printf(" ******* End Thread_Read_Command ******* \n");

	pthread_exit(&ret_thread);

	return NULL;
}

/*
 ============================================
 Function     : Thread_Send_Data_PC()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void* Thread_Send_Data_PC(){

	//char sMess[15] = {0};
	//readSensor();
	//temperature;
	//humidity;

	while(iStopCommand != 1){

		if(iStopthread == STOP_THREAD){
			iStopthread = 0;
			StopThread_Send_Data();
		}

		strInputStatus Mess;
		libcom_InputStatus(&Mess, ptrCaptorMainDoor->stateCapt, ptrCaptorBackDoor->stateCapt, stateInterrupter, temperature,humidity);
		printf( " Message : %s , size : %d\n" , Mess.sMess,  Mess.bsize);
		write_socket(newSockData, Mess.sMess, 15);	// Problem with the size of the message

		//write_socket(newSockData, ptrMes->sMess, ptrMes->bsize);
//		sprintf(sMess , "%1d%1d%1d%2.2f%2.2f", ptrCaptorMainDoor->stateCapt, ptrCaptorBackDoor->stateCapt, stateInterrupter,  temperature, humidity);
//		write_socket(newSockData, sMess, 20);
		sleep(SEND_INFO_EACH_SEC);
	}

	pthread_exit(&thread_Send_Data);

	return NULL;
}

/*
 ============================================
 Function     : StopThread_Send_Data()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void StopThread_Send_Data()
{
	printf(" Stop thread Send Data \n");
	//pthread_mutex_lock(&mutex_stock);
    //pthread_cond_wait(&cond_stock, &mutex_stock);

	pthread_exit(&thread_Send_Data);

}

/*
 ============================================
 Function     : StartThread_Send_Data()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void StartThread_Send_Data()
{
	printf(" Start thread Send Data \n");
	// Thread Execute Send Data
	pthread_create (&thread_Send_Data, NULL, &Thread_Send_Data_PC, NULL);

	//pthread_cond_signal(&cond_stock);
    //pthread_mutex_unlock(&mutex_stock);
}

/*
 ============================================
 Function     : StartThread_ReadSensor()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void StartThread_ReadSensor(){

	// Init Value
	temperature = 0;
	humidity = 0;

	// Thread Execute Read Command
	pthread_create (&threadId_Sensor, NULL, &Thread_ReadSensor, NULL);
}

/*
 ============================================
 Function     : Thread_ReadSensor()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void* Thread_ReadSensor(){
	while(iStopCommand != 1){
//		int iret = readSensor();	NO SENSOR AVAIBLE
//		if(iret != DHT_SUCCESS){	NO SENSOR AVAIBLE
			temperature	= 0;
			humidity = 0;
//		}
		sleep(TICK_READ_SENSOR);
	};

	pthread_exit(&threadId_Sensor);

	return NULL;
}


