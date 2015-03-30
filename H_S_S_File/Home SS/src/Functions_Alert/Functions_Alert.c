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
#define WAIT_1_DAYS		86400

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
const char * dailyReportFile = "/home/debian/Desktop/dailyReportFile.txt";
/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
/*
 ============================================
 Function     : Thread_DailyReport()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void * Thread_DailyReport(){

	while(1){
		sleep(WAIT_1_DAYS);
		int iret = Connection_OK();
		if( iret == ERROR){
			File_Log("PROBLEM_SEND_DAILY RAPPORT, ", 28);
			File_Log("NO_CONNECTION, ", 15);
		}else{
			Send_Report_File_Log();
		}
	}

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

    int iReturn = system("mpack -s \"Daily Report\" /home/debian/Desktop/dailyReportFile.txt cedric.toncanier@gmail.com");
    if(iReturn == ERROR){
    	 perror("Failed to invoke mpack");
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

	// Ping Aurelie
//	int iret = system("ping -c3 ADRESSE_IP_AURELIE");
//	if(iret !=0 ){
//		printf("\n Aurelie No Here \n");
//		iValue = PHONE_CEDRIC;
//	}
//	printf("\n Aurelie Here\n\n");

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
 Function     : send_Alerte()
 Parameter    : int iSmsok
 Return Value : int
 Description  :
 ============================================
 */
int send_Alert(int iSmsok){

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
	iVal = sendEmail();
	if( iVal == ERROR){
		File_Log("PROBLEM_SEND_ALERT, ", 20);
		File_Log("FAILED_SEND_MAIL, ", 18);
		return ERROR;
	}
	File_Log("Send Mail Ok, ", 14);

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
    //int iReturn = system("mpack -s \"Alerte Intrusion\" 5145749606@sms.fido.ca");

    //int iReturn = system("mail -s \"Alert Intrusion\" 5145749606@sms.fido.ca");

    int iReturn = system("ssmtp -s \"Test Email\" 5145749606@sms.fido.ca"); //
    if(iReturn == ERROR){
   	 perror("Failed to invoke mpack");
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
int sendEmail()
{
     int iReturn = system("mpack -s \"Alert Intrusion\"  /home/debian/Desktop/Intrusion.jpeg cedric.toncanier@gmail.com");
     if(iReturn == ERROR){
    	 perror("Failed to invoke mpack");
     }

     iReturn = system("mpack -s \"Alert Intrusion\"  /home/debian/Desktop/Intrusion.jpeg aurelie.leguernic.alg@gmail.com");

     if(iReturn == ERROR){
    	 perror("Failed to invoke mpack");
     }


     return OK;
}
