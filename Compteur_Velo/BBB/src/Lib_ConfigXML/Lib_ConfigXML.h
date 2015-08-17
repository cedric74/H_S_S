/*
 * Lib_Config.h
 *
 *  Created on: Aug 11, 2015
 *      Author: Cedric.Toncanier
 */

#ifndef LIB_CONFIGXML_H_
#define LIB_CONFIGXML_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "../Lib_Utils/Lib_Utils.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************
*               D E F I N E                *
********************************************/
#define SIZE_DATA	10
#define ERROR		-1

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
typedef enum {
	DB_NAME		= 0,
	DB_TYPE		= 1,
	DB_VALUE	= 2,
}NodeConfigL4;


typedef struct{
	char cName[20];
	char cType[10];
	char cValue[10];
}sData;

typedef enum{
	TAG_NAME	=0,
	TAG_TYPE	=1,
	TAG_VALUE	=2,
	NBE_TAG		=3,
}tagEnum;

typedef struct{
	char			opentag[10];
	char			closetag[10];
	unsigned short 	sizetag;
	NodeConfigL4	tagState;
}structag;

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
int Lib_Config_Load(const char * cPathXMLFile, sData cTable[]);
int Lib_Config_Save(const char * cPathXMLFile, sData cTable[], int iNbeData);


#endif /* IB_CONFIGXML_H_ */
