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
strMsg mMesg;

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
/*
 ============================================
 Function     : libcom_SetMsg()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
strMsg * libcom_SetMsg(unsigned char bType, unsigned char bLength, int iSize,  void * value){

	// Declaration Variables
	strMsg * pMesg = &mMesg;

	// Instructions
	pMesg->bType 		= bType;
	pMesg->bLength		= bLength;
	pMesg->bChecksum	= 0;

	if(iSize == sizeof(int)){
		pMesg->value = (int*)value;
	}
	else if(iSize == sizeof(char)){
		pMesg->value = (char*)value;
	}

	// Calcul Checksum
	//libcom_Checksum(pMesg , bLength , iSize);

	return pMesg;
}

/*
 ============================================
 Function     : libcom_GetMsg()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int libcom_GetMsg(){
	// TODO, libcom_GetMsg(), missing implementation
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
