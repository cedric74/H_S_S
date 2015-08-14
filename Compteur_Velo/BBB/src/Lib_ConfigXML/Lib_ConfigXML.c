/*
 * Lib_Config.c
 *
 *  Created on: Created on: Aug 11, 2015,
 *      Author: Cedric.Toncanier
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_ConfigXML.h"

/*******************************************
*               D E F I N E                *
********************************************/
#define SIZE_NAME	6
#define	SIZE_TYPE	6
#define	SIZE_VALUE	7

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

//tab of tag
structag cTabTag[NBE_TAG]={
/* TAG_NAME */	{"name", "/name" , SIZE_NAME ,	DB_NAME  },
/* TAG_TYPE */	{"type", "/type" , SIZE_TYPE ,	DB_TYPE  },
/* TAG_VALUE*/	{"value","/value", SIZE_VALUE, 	DB_VALUE },
};

/*******************************************
*   P R O T O T Y P E   F U N C T I O N S  *
********************************************/
int  getInsideTag(tagEnum tagE, char line[], char cBuffer[], int iLen);

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*			F U N C T I O N S 				*
********************************************/

/*
 ============================================
 Function     : Lib_Config_Load()
  @Parameter  : Path of Xml File
 Return Value : void
 Description  :
 ============================================
 */
int Lib_Config_Load(const char * cPathXMLFile, sNodeL4 cTable[]){

	// Declarations Variables
	NodeConfigL4	currentNodeL4 = 0;
	char bIn 		=0;
	FILE * 		fConfig;
	char * 		line = NULL;
	size_t 		len = 0;
	ssize_t 	sizeLine;
	//sNodeL4     cTable[SIZE_DATA];
	char 		cBuffer[20]={0};
	int 		iIndex = 0;

	// Instructions
	// Open File
	fConfig = fopen ( cPathXMLFile, "r");
	if(fConfig == NULL){
		printf("-Error Open File : %s\n", cPathXMLFile);
		return ERROR;
	}

	//	Seek to the beginning of the file
	fseek(fConfig, SEEK_SET, 0);

	// Read Line by Line
	while ((sizeLine = getline(&line, &len, fConfig)) != -1) {

		if(strstr(line, "<db>") != NULL) {
			bIn = 1;
		}
		if(strstr(line, "</db>") != NULL) {
			if(bIn == 1){
				iIndex++;
				if(iIndex == SIZE_DATA){
					printf("Lib_ConfigXML, -Error Too Much Data in XML File, %s\n", cPathXMLFile);
					return ERROR;
				}
			}
			bIn = 0;
		}
		if(bIn == 1){
			int iLength = ERROR;
			int iCurrentTag;
			for(iCurrentTag = 0; iCurrentTag < NBE_TAG; iCurrentTag++){
				iLength = getInsideTag( iCurrentTag, line, cBuffer, sizeLine);
				if(iLength != ERROR){
					currentNodeL4 = cTabTag[iCurrentTag].tagState;
					break;
				}
			}

			switch(currentNodeL4){
				case DB_NAME:
					snprintf( cTable[iIndex].cName , iLength, cBuffer);
				break;
				case DB_TYPE:
					snprintf( cTable[iIndex].cType,  iLength, cBuffer);
				break;
				case DB_VALUE:
					snprintf( cTable[iIndex].cValue,  iLength, cBuffer);
				break;
			}
		}
	}

//	// Print All Data
//	int i;
//	for(i =0 ; i < iIndex ; i++){
//		printf("cTable[%i].cName  : %s\n", i, cTable[i].cName);
//		printf("cTable[%i].cType  : %s\n", i, cTable[i].cType);
//		printf("cTable[%i].cValue : %s\n", i, cTable[i].cValue);
//	}

	return iIndex;
}

/*
 ============================================
 Function     : Lib_Config_Save()
 Parameter    : Path of Xml File
 Return Value : void
 Description  :
 ============================================
 */
int Lib_Config_Save(const char * cPathXMLFile){

	// Declarations Variables
	FILE * 		fConfig;
	char * 		line = NULL;
	size_t 		len = 0;
	ssize_t 	sizeLine;

	fConfig = fopen ( cPathXMLFile, "a");
		if(fConfig == NULL){
			printf("-Error Open File : %s\n", cPathXMLFile);
			return ERROR;
		}

		//	Seek to the beginning of the file
		fseek(fConfig, SEEK_SET, 0);

		// Read Line by Line
		while ((sizeLine = getline(&line, &len, fConfig)) != -1) {
			// Write all the line with open & close tag
			//TODO, Lib_Config_Save(), misssing implemetation
		}

	return 0;
}

/*
 ============================================
 Function     : getInsideTag()
 Parameter    :
 Return Value :
 Description  :
 ============================================
 */
int getInsideTag(tagEnum tagE, char line[], char cBuffer[], int iLen){
	int iRetSize = ERROR;
	if( strstr(line, cTabTag[tagE].opentag) != NULL){
		if( strstr(line, cTabTag[tagE].closetag) != NULL){
			int iP;
			iP = findChar(line, iLen, '/');
			if( iP == ERROR){
				return iRetSize;
			}
			strncpy(cBuffer, &line[cTabTag[tagE].sizetag], iP- cTabTag[tagE].sizetag);
			iRetSize = iP- cTabTag[tagE].sizetag+1;
		}
	}
	return iRetSize;
}

