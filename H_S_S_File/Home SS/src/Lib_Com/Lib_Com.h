/*
 * Lib_Com.h
 *
 *  Created on: Mar 25, 2015
 *      Author: cedric.toncanier
 */

#ifndef SRC_LIB_COM_LIB_COM_H_
#define SRC_LIB_COM_LIB_COM_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

/*******************************************
*               D E F I N E                *
********************************************/
typedef enum{
	CMD_APPLI		= 0 ,
	INPUTS_STATUS	= 1 ,
}enumTypeMess;



typedef struct{
	enumTypeMess	bType;
	unsigned char	bInputs;
	float		  	fTemp;
	float		  	fHum;
	unsigned char   bsize;
	unsigned char 	bChecksum;
	char 			sMess[15];
}strInputStatus;

typedef struct{
	enumTypeMess  	bType;
	unsigned char 	bSubType;
	unsigned char 	bParam;
	unsigned char   bsize;
	unsigned char 	bChecksum;
}strCmdAppli;




/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
void libcom_InputStatus(strInputStatus * ptr, unsigned char captor1, unsigned char captor2, unsigned char interrupter, float fTemp,float fHum);
void libcom_NewMessage();
void libcom_ChkSum();


#endif /* SRC_LIB_COM_LIB_COM_H_ */
