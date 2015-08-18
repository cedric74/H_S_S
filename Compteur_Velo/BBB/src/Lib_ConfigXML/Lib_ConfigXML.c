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

#define MAX_LINE	100

#define SIZE_HEAD	3
#define SIZE_TAIL	2

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
//tab of tag
structag cTabTag[NBE_TAG]={
/* TAG_NAME */	{"name", "/name" , SIZE_NAME ,	DB_NAME  },
/* TAG_TYPE */	{"type", "/type" , SIZE_TYPE ,	DB_TYPE  },
/* TAG_VALUE*/	{"value","/value", SIZE_VALUE, 	DB_VALUE },
};

char  cHead[SIZE_HEAD][MAX_LINE]={
		{"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"},
		{"<config>\n"},
		{"<data>\n"},
};

char cOpenVersion[] 	= "<version>";
char cCLoseVersion[] 	= "</version>";

char  cTail[SIZE_TAIL][MAX_LINE]={
		{"</data>\n<"},
		{"</config>\n"},
};

char cOpenData[] 	= "<db>\n";
char cCloseData[] 	= "</db>\n";

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
int Lib_Config_Load(const char * cPathXMLFile, sData cTable[]){

	// Declarations Variables
	NodeConfigL4	currentNodeL4 = 0;
	char bIn 		=0;
	FILE * 		fConfig;
	char * 		line = NULL;
	size_t 		len = 0;
	ssize_t 	sizeLine;
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

	// Close file
	fclose(fConfig);

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
//TODO , Lib_Config_Save(), Add Version
int Lib_Config_Save(const char * cPathXMLFile,  sData cTable[], int iNbeData){

	// Declarations Variables
	FILE * 		fOuput;
	int 		i, iLength, iIndData;

	// Instructions
	fOuput = fopen (cPathXMLFile, "w");
	if(fOuput == NULL){
		printf("-Error Open File : %s\n", cPathXMLFile);
		return ERROR;
	}

	// Create Head
	for( i=0 ; i <  SIZE_HEAD; i++){
		iLength = getLength(cHead[i], 1000);
		fwrite(cHead[i] , 1 , iLength, fOuput );
	}

	// Add version
	char cBuf[MAX_LINE];
	//snprintf(cBuf , MAX_LINE, "%s%s%s\n", cOpenVersion, START_FILE, cCLoseVersion);
	snprintf(cBuf , MAX_LINE, "%s%s\n", cOpenVersion, cCLoseVersion);
	iLength = getLength(cOpenVersion, 1000);
	fwrite(cBuf, 1 , iLength, fOuput );

	for(iIndData = 0; iIndData < iNbeData ; iIndData++){

		// Open Data
		iLength = getLength(cOpenData, 1000);
		fwrite(cOpenData , 1 , iLength, fOuput );

		// Each Tag
		int iCurrentTag;
		for(iCurrentTag = DB_NAME; iCurrentTag < NBE_TAG; iCurrentTag++){
			char cBuffer[MAX_LINE]={0};

			switch(iCurrentTag){
				case DB_NAME:
					printf("OK DB_NAME \n");
					snprintf(cBuffer , MAX_LINE, "<%s>%s<%s>\n", cTabTag[iCurrentTag].opentag, cTable[iIndData].cName, cTabTag[iCurrentTag].closetag);
				break;
				case DB_TYPE:
					printf("OK DB_TYPE \n");
					snprintf(cBuffer , MAX_LINE, "<%s>%s<%s>\n", cTabTag[iCurrentTag].opentag, cTable[iIndData].cType, cTabTag[iCurrentTag].closetag);
				break;
				case DB_VALUE:
					printf("OK DB_VALUE \n");
					snprintf(cBuffer , MAX_LINE, "<%s>%s<%s>\n", cTabTag[iCurrentTag].opentag, cTable[iIndData].cValue, cTabTag[iCurrentTag].closetag);
				break;
			}
			iLength = getLength(cBuffer, MAX_LINE);
			fwrite(cBuffer , 1 , iLength, fOuput );
		}

		// Close Data 1
		iLength = getLength(cCloseData, 1000);
		fwrite(cCloseData , 1 , iLength, fOuput );

	}

	// Tail
	for( i=0 ; i <  SIZE_TAIL ; i++){
		iLength = getLength(cTail[i] , 1000);
		fwrite(cTail[i] , 1 , iLength, fOuput );
	}

	// Close File
	fclose(fOuput);

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

