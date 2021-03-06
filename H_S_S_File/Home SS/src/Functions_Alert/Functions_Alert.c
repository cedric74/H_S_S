/*
 * Functiond_Alerte.c
 *
 *  Created on: Feb 28, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Functions_Alert.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define WAIT_1_DAYS		86400	// In Second
#define WAIT_1_MIN		60		// In Second


#define	TRUE			1
#define	FALSE			0


/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
const char * dailyReportFile = "/home/debian/Desktop/dailyReportFile.txt";

const int HourTimeDay 	= 20;
const int MinTimeDay 	= 00;

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	      L O C A L  F U N C T I O N S      *
********************************************/
static int CheckTime(void);

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/

/*
 ============================================
 Function     : CheckTime()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
static int CheckTime(void){

	// Declarations Variables
	time_t rawtime;
	struct tm * timeinfo;

	// Instructions
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	//printf(" %s" , asctime(timeinfo));

	// Check if it's the right time of day
	if( ((timeinfo->tm_hour) == HourTimeDay) && ((timeinfo->tm_min) == MinTimeDay)){
		return	TRUE;
	}

	return	FALSE;
}

/*
 ============================================
 Function     : Report_File_To_Supervisor()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Report_File_To_Supervisor(){
	int socketFile 	= create_Socket(PORT_FILE);
	int newSockFile = accept_client_connection(socketFile);
	send_binary(newSockFile, dailyReportFile);
	close_socket(socketFile, newSockFile);
}

/*
 ============================================
 Function     : Thread_DailyReport()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void * Thread_DailyReport(){
	int iret;

	while(1){
		sleep(WAIT_1_MIN);
		if(CheckTime()){
			iret = Connection_OK();
			if( iret == ERROR){
				File_Log("PROBLEM_SEND_DAILY RAPPORT, ", 28);
				File_Log("NO_CONNECTION, ", 15);
			}else{
				Send_Report_File_Log();
			}

			// Sleep 1 minutes to avoid to send several report the same day
			sleep(WAIT_1_MIN);
		}
	}

//	while(1){
//		sleep(WAIT_1_DAYS);
//		int iret = Connection_OK();
//		if( iret == ERROR){
//			File_Log("PROBLEM_SEND_DAILY RAPPORT, ", 28);
//			File_Log("NO_CONNECTION, ", 15);
//		}else{
//			Send_Report_File_Log();
//		}
//	}

	return NULL;
}
/*
 ============================================
 Function     : Send_Report_File_Log()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void Send_Report_File_Log(){
	char buffer[200];
	snprintf(buffer , 200, "mpack -s \"Daily Report\" /home/debian/Desktop/dailyReportFile.txt ");
	strcat(buffer,tabUser[MAIN_USER].sAddress);
	int iReturn =system(buffer);

	if(iReturn == ERROR){
    	 //perror("Failed to invoke mpack");
    }else{
    	system("rm /home/debian/Desktop/dailyReportFile.txt");

    	// Create File Log With Version
    	File_Log(START_FILE, SIZE_STRING);
     }
}

/*
 ============================================
 Function     : File_Log()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void File_Log(char string[50], int iLength){

	// Instructions
	fpLog = fopen ( dailyReportFile, "a");

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	fwrite(string , 1 , iLength , fpLog );
	fwrite(asctime (timeinfo) , 1 , 25 , fpLog );

	fclose(fpLog);
}

/*
 ============================================
 Function     : Ping_Phone()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int Ping_Phone(){

	// Declarations Variables
	int iValue = NO_PHONE;

	// Ping Cedric
	int iret = system("ping -c1  192.168.0.200");			//system("ping -c1 192.168.0.200");
	if(iret !=0 ){
		iValue = NO_PHONE;
		File_Log("Cedric No Here, ", 16);
		//printf("\n Cedric No Here \n");
	}else{
		iValue = PHONE_CEDRIC;
		File_Log("Cedric Here, ", 12);
		//printf("\n Cedric Here\n\n");
	}

	return iValue;
}

/*
 ============================================
 Function     : Connection_OK()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int Connection_OK(){
	int iret = system("ping -c1 google.com");
	if(iret !=0 ){
		//printf("\n No Network Connection \n");
		return ERROR;
	}

	//printf("\n Network Connection OK\n\n");
	return OK;
}

/*
 ============================================
 Function     : send_Alert()
 Parameter    : int iSmsok
 Return Value : int
 Description  :
 ============================================
 */
int send_Alert(int iSmsok, char strCaptor[5]){

	// Declarations Variables
	int iVal;

	// Instructions
	iVal = Connection_OK();
	if( iVal == ERROR){
		File_Log("PROBLEM_SEND_ALERT, ", 20);
		File_Log("NO_CONNECTION, ", 15);
		return ERROR;
	}

	// Send Alerte by mail
	iVal = sendEmail(strCaptor);
	if( iVal == ERROR){
		File_Log("PROBLEM_SEND_ALERT, ", 20);
		File_Log("FAILED_SEND_MAIL, ", 18);

		//return ERROR;
	}else{
		File_Log("Send Mail Ok, ", 14);
	}

	if(iSmsok == SMS_OK){
		// Send Alerte by sms
		iVal = sendSMS();
		if( iVal == ERROR){
			File_Log("PROBLEM_SEND_ALERT, ", 20);
			File_Log("FAILED_SEND_SMS, ", 17);
			return ERROR;
		}
		File_Log("Send SMS, ", 13);
	}

	return OK;

}

/*
 ============================================
 Function     : sendSMS()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int sendSMS(){
	int iLoop;
	for(iLoop = 0 ; iLoop < u8NbUSer; iLoop++){
		char buffer[200];
		snprintf(buffer , 200, "ssmtp -s \"ALERT Email\" ");
		strcat(buffer,tabUser[iLoop].sNumPhone);
		strcat(buffer,"@sms.fido.ca");
		int iReturn =system(buffer);
		if(iReturn == ERROR){
			//perror("Failed to invoke mpack");
		    return ERROR;
		}
	}

    return OK;
}


/*
 ============================================
 Function     : sendmail()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int sendEmail(char strCaptor[5])
{
	int iLoop;
	if(strcmp(strCaptor, "MAIN\n")){
		for(iLoop = 0 ; iLoop < u8NbUSer; iLoop++){
			char buffer[200];
			snprintf(buffer , 200, "mpack -s \"Alert Intrusion Main Door\"  /home/debian/Desktop/Intrusion.jpeg");
			strcat(buffer,tabUser[iLoop].sAddress);
			int iReturn =system(buffer);
			if(iReturn == ERROR){
				//perror("Failed to invoke mpack");
			    return ERROR;
			}
		}
	}else{
		for(iLoop = 0 ; iLoop < u8NbUSer; iLoop++){
			char buffer[200];
			snprintf(buffer , 200, "mpack -s \"Alert Intrusion Main Door\"  /home/debian/Desktop/Intrusion.jpeg");
			strcat(buffer,tabUser[iLoop].sAddress);
			int iReturn =system(buffer);
			if(iReturn == ERROR){
				//perror("Failed to invoke mpack");
				return ERROR;
			}
		}
	}

	return OK;
}
