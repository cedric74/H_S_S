/*
 * Lib_Param.h
 *
 *  Created on: Aug 13, 2015
 *      Author: ctoncanier
 */

#ifndef LIB_PARAM_H_
#define LIB_PARAM_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "../Lib_Utils/Lib_Utils.h"
#include 	"../Lib_ConfigXML/Lib_ConfigXML.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
#define NBE_VARIABLE_XML_TO_LOAD	3

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

// Variables From XML
int 	iTickLoop;
int 	iPortSocket;
float 	fRadius;


sData tabData[SIZE_DATA];

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
int 	getData(sData tabData[], int iLen);
int 	setData(sData tabData[], int iLen);
void 	setDefaultData();


#endif /* LIB_PARAM_H_ */
