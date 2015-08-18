/*
 * Lib_Com.c
 *
 *  Created on: August 17, 2015
 *      Author: cedric.toncanier
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_Com.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define OFFSET_HEAD		3


#define OF_TYPE   	  0
#define OF_LENGTH	(OF_TYPE+1)
#define OF_CHKSUM	(OF_LENGTH+1)
#define OF_VALUE	(OF_CHKSUM+1)
/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *
********************************************/
int libcom_Checksum(strMsg * pMesg);

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/

/*
 ============================================
 Function     : libcom_CreateMsg()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
strMsg libcom_CreateMsg(unsigned char bType, unsigned char bLength, int iSize,  void * value){
	// TODO, libcom_CreateMsg(), missing implementation

	// Declaration Variables
	strMsg mMesg;

	// Instructions
	mMesg.bType 	= bType;
	mMesg.bLength 	= bLength;
	mMesg.value 	= value;

	return mMesg;
}

/*
 ============================================
 Function     : libcom_SetMsg()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int libcom_SetMsg(char buffer[], unsigned char bType, unsigned char bLength, int iSize,  void * value){

	// TODO, libcom_SetMsg(), modify behavior , and char buffer[]
	// Declaration Variables
	strMsg mMesg;
	strMsg * pMesg = &mMesg;

	// Instructions
	pMesg->bType 		= bType;
	pMesg->bLength		= bLength;
	pMesg->bChecksum	= 0;

	// Copy Data
	buffer[0] = pMesg->bType;
	buffer[1] = pMesg->bLength;

	if(iSize == sizeof(int)){
		pMesg->value = (int *)value;
		int i;
		for(i =0 ; i < bLength ; i++){
			buffer[i+OFFSET_HEAD] = (int)*(int*)(pMesg->value);
			pMesg->value += sizeof(int);
		}
	}else if(iSize == sizeof(char)){
		pMesg->value = (char* )value;
		int i;
		for(i =0 ; i < bLength ; i++){
			buffer[i+OFFSET_HEAD] = (char)*(char*)(pMesg->value);
			pMesg->value += sizeof(char);
		}
	}

	// Calcul Checksum
	//libcom_Checksum(pMesg , bLength , iSize);

	return (bLength+OFFSET_HEAD);
}

/*
 ============================================
 Function     : libcom_GetMsg()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int libcom_GetMsg(char buffer[],  strMsg * mMesg){

	// Copy Data
	mMesg->bType   = buffer[OF_TYPE];
	mMesg->bLength = buffer[OF_LENGTH];
	mMesg->value   = &(buffer[OF_VALUE]);

	return 0;
}

/*
 ============================================
 Function     : libcom_Checksum()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int libcom_Checksum(strMsg * pMesg){
	// TODO, libcom_Checksum(), missing implementation
	return 0;
}
