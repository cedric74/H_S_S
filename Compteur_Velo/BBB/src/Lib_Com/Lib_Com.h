/*
 * Lib_Com.h
 *
 *  Created on: August 17, 2015
 *      Author: cedric.toncanier
 */

#ifndef LIB_COM_H_
#define LIB_COM_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include <stdio.h>
#include <stdlib.h>

/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
typedef struct{
	unsigned char	bType;
	unsigned char	bLength;
	unsigned char 	bChecksum;
	void *          value;
}strMsg;

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
int 		libcom_SetMsg(char buffer[], unsigned char bType, unsigned char bLength, int iSize,  void * value);
int 		libcom_GetMsg(char buffer[],  strMsg * mMesg);

#endif /* LIB_COM_H_ */
