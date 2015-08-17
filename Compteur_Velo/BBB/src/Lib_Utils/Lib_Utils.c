/*
 * Lib_Utils.c
 *
 *  Created on: Aug 11, 2015
 *      Author: ctoncanier
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_Utils.h"

/*******************************************
*               D E F I N E                *
********************************************/

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/
/*
 ============================================
 Function     : compare_strings()
 @Parameter   :
 Return Value : void
 Description  :
 ============================================
 */
int compare_strings(char a[], char b[])
{
   int c = 0;

   while (a[c] == b[c]) {
      if (a[c] == '\0' || b[c] == '\0')
         break;
      c++;
   }

   if (a[c] == '\0' && b[c] == '\0')
      return 0;
   else
      return -1;
}

/*
 ============================================
 Function     : findChar()
 @Parameter   :
 Return Value : void
 Description  :
 ============================================
 */
int findChar( char cBuff[], int iLen, char c){
	int iP = -1 , i;

	for( i =0; i < iLen ; i++){
		if(cBuff[i]== c){
			iP =i-1;
			break;
		}
	}
	return iP;
}

/*
 ============================================
 Function     : convertToBCD()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int convertToBCD(char cBuff[], int iValue, int iLen){
	//TODO, More Generic
	int iRet = 0;
	cBuff[0] = (char)(iValue/10000);
	cBuff[1] = (char)((iValue - (cBuff[0] *10000))/100);
	cBuff[2] = (char)(iValue - (cBuff[1]*100 + cBuff[0]*10000));

	return iRet;
}

/*
 ============================================
 Function     : getLength()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int getLength(char cBuff[], int iMax){
	return (findChar(cBuff, iMax, '\n')+2);
}
