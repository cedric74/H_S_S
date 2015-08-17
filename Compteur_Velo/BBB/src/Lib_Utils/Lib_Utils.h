/*
 * Lib_Utils.h
 *
 *  Created on: Aug 11, 2015
 *      Author: ctoncanier
 */

#ifndef LIB_UTILS_H_
#define LIB_UTILS_H_

/*******************************************
*			  I N C L U D E 			   *
********************************************/

/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
int compare_strings(char a[], char b[]);
int findChar(char cBuff[], int iLen, char c);
int convertToBCD(char cBuff[], int iValue, int iLen);
int getLength(char cBuff[], int iMax);

#endif /* LIB_UTILS_H_ */
