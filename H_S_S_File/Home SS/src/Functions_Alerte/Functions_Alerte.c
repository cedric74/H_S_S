/*
 * Functiond_Alerte.c
 *
 *  Created on: Feb 28, 2015
 *      Author: cedric
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Functions_Alerte.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define WAIT_1_DAYS		86400			//86400

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void * Thread_DailyRaport(){

	while(1){
		sleep(WAIT_1_DAYS);
		Send_Report_File_Log();
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

    int iReturn = system("mpack -s \"Daily Raport\" /home/debian/Desktop/outfile.txt cedric.toncanier@gmail.com");
     if(iReturn == ERROR){
    	 perror("Failed to invoke mpack");
     }else{
    	 system("rm /home/debian/Desktop/outfile.txt");

    	 // Create File Log With Version
    	 File_Log("Version 1.6, 16 march, ", 21);
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
	fpLog = fopen ("/home/debian/Desktop/outfile.txt", "a");

	 time_t rawtime;
	 struct tm * timeinfo;

	 time ( &rawtime );
	 timeinfo = localtime ( &rawtime );
	  //printf ( "Current local time and date: %s", asctime (timeinfo) );

	 //string[iLength] = ',';
	  //string[iLength+1] = '\0';

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
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int send_Alerte(int iSmsok){

	// Declarations Variables
	int iVal;

	// Instructions
	iVal = Connection_OK();
	if( iVal == ERROR){
		File_Log("PROBLEM_SEND_ALERTE, ", 21);
		File_Log("NO_CONNECTION, ", 15);
		return ERROR;
	}

	// Send Alerte by mail
	iVal = sendmail("cedric.toncanier@gmail.com", "cedric.toncanier.bbb@gmail.com", "Home Security Alerte", "Test Home Security System\n");
	if( iVal == ERROR){
		File_Log("PROBLEM_SEND_ALERTE, ", 21);
		File_Log("FAILED_SEND_MAIL, ", 18);
		return ERROR;
	}
	File_Log("Send Mail Ok, ", 14);

	if(iSmsok == SMS_OK){
		// Send Alerte by sms
		iVal = sendmail("5145749606@sms.fido.ca", "cedric.toncanier.bbb@gmail.com", "Home Security Alerte", "Coucou\n");
		if( iVal == ERROR){
			File_Log("PROBLEM_SEND_ALERTE, ", 21);
			File_Log("FAILED_SEND_SMS, ", 17);
			return ERROR;
		}
		File_Log("Send SMS, ", 13);
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
int sendmail(const char *to, const char *from, const char *subject, const char *message)
{
     int iReturn = system("mpack -s \"Alerte Intrusion\" /home/debian/Desktop/Intrusion.jpeg cedric.toncanier@gmail.com");
     if(iReturn == ERROR){
    	 perror("Failed to invoke mpack");
     }
//	int retval = ERROR;
//    FILE *mailpipe = popen("/usr/lib/sendmail -t", "w");
//    if (mailpipe != NULL) {
//        fprintf(mailpipe, "To: %s\n", to);
//        fprintf(mailpipe, "From: %s\n", from);
//        fprintf(mailpipe, "Subject: %s\n\n", subject);
//        fprintf(mailpipe, "Subject: %s\n\n", subject);
//        fwrite(message, 1, strlen(message), mailpipe);
//        fwrite(".\n", 1, 2, mailpipe);
//        pclose(mailpipe);
//        retval = 0;
//
//        //printf("\n\n Send mail OK\n");
//     }
//     else {
//         perror("Failed to invoke sendmail");
//     }

     //return retval;

     return 0;
}