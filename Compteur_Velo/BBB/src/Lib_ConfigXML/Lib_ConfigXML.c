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

#define SIZE_DATA	50

#define ERROR		-1

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/
typedef enum {
	HEAD		= 0,
	CONFIG 		= 1,
}NodeConfigL1;


typedef enum {
	VERSION 	= 2,
	DATA		= 3,
}NodeConfigL2;


typedef enum {
	DB			= 4,
}NodeConfigL3;

typedef enum {
	DB_NAME		= 5,
	DB_TYPE		= 6,
	DB_VALUE	= 7,
}NodeConfigL4;


typedef struct{
	char cName[20];
	char cType[20];
	char cValue[20];
}sNodeL4;

typedef enum{
	TAG_NAME	=0,
	TAG_TYPE	=1,
	TAG_VALUE	=2,
	SIZE_TAB,
}tagEnum;

typedef struct{
	char	opentag[10];
	char	closetag[10];
}structag;



//tab de tag
structag cTabTag[SIZE_TAB]={
/* TAG_NAME */	{"name", "/name"},
/* TAG_TYPE */	{"type", "/type"},
/* TAG_VALUE*/	{"value","/value"},
};



/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
int  getInsideTag(tagEnum tagE, char line[], char cBuffer[]);

/*
 ============================================
 Function     : Lib_Config_Load()
  @Parameter  : Path of Xml File
 Return Value : void
 Description  :
 ============================================
 */
int Lib_Config_Load(const char * cPathXMLFile){

	// Declarations Variables
	NodeConfigL4	currentNodeL4 = 0;
	char bIn 		=0;
	FILE * 		fConfig;
	char * 		line = NULL;
	size_t 		len = 0;
	ssize_t 	sizeLine;
	sNodeL4     cTable[SIZE_DATA];
	char 		cBuffer[20]={0};
	int 		iIndex = 0;
	tagEnum		tagCurrent;

	// Instructions
	// Open File
	fConfig = fopen ( cPathXMLFile, "r");
	if(fConfig == NULL){
		printf("-Error Open File : %s\n", cPathXMLFile);
		return -1;
	}

	//	Seek to the beginning of the file
	fseek(fConfig, SEEK_SET, 0);

	// Read Line by Line
	while ((sizeLine = getline(&line, &len, fConfig)) != -1) {

		//TODO, Parse XML
		if(strstr(line, "<db>") != NULL) {
			bIn = 1;
		}
		if(strstr(line, "</db>") != NULL) {
			if(bIn == 1){
				iIndex++;
			}
			bIn = 0;
		}
		if(bIn == 1){
			//------------- BALISE NAME -----------------------
			tagCurrent = TAG_NAME;
			sizeLine = getInsideTag( tagCurrent, line, cBuffer);
			if(sizeLine != ERROR){
				currentNodeL4 = DB_NAME;
			}
			printf("OK 3\n");
			/*
			 *
			if( strstr(line, "<name>") != NULL){
				if( strstr(line, "</name>") != NULL){
					int i;
					int iP;
					for(i =0; i < sizeLine ; i++){
						if(line[i]=='/'){
							iP =i-1;
						}
					}
					currentNodeL4 = DB_NAME;
					strncpy(cBuffer, &line[SIZE_NAME], iP- SIZE_NAME);
					sizeLine = iP- SIZE_NAME+1;
				}
			}
*/
			//------------- BALISE TYPE -----------------------
			/*
			if( strstr(line, "<type>") != NULL){
				if( strstr(line, "</type>") != NULL){
					int i;
					int iP;
					for(i =0; i < sizeLine ; i++){
						if(line[i]=='/'){
							iP =i-1;
						}
					}
					currentNodeL4 = DB_TYPE;
					strncpy(cBuffer, &line[SIZE_TYPE], iP- SIZE_TYPE);
					sizeLine = iP- SIZE_NAME+1;
				}
			}
*/
			//------------- BALISE VALUE -----------------------
			//getInsideTag();
			/*
			if( strstr(line, "<value>") != NULL){
				if( strstr(line, "</value>") != NULL){
					int i;
					int iP;
					for(i =0; i < sizeLine ; i++){
						if(line[i]=='/'){
							iP =i-1;
						}
					}
					currentNodeL4 = DB_VALUE;
					strncpy(cBuffer, &line[SIZE_VALUE], iP-SIZE_VALUE);
					sizeLine = iP- SIZE_VALUE+1;
				}
			}*/
			switch(currentNodeL4){
				case DB_NAME:
					snprintf( cTable[iIndex].cName , sizeLine, cBuffer);
				break;
				case DB_TYPE:
					//snprintf( cTable[iIndex].cType,  sizeLine, cBuffer);
				break;
				case DB_VALUE:
					//snprintf( cTable[iIndex].cValue,  sizeLine, cBuffer);
				break;
			}
		}
	}

	// Print All Data
	printf("OK 4\n");

	int i;
	for(i =0 ; i < iIndex ; i++){
		printf("cTable[%i].cName  : %s\n", i, cTable[i].cName);
		//printf("cTable[%i].cType  : %s\n", i, cTable[i].cType);
		//printf("cTable[%i].cValue : %s\n", i, cTable[i].cValue);
	}

	return 0;
}

/*
 ============================================
 Function     : Lib_Config_Save()
  @Parameter  : Path of Xml File
 Return Value : void
 Description  :
 ============================================
 */
int Lib_Config_Save(const char * cPathXMLFile){
	//TODO, Lib_Config_Save, Implement this function

	return 0;
}


/*
 ============================================
 Function     : getInsideTag()
  @Parameter  : Path of Xml File
 Return Value : void
 Description  :
 ============================================
 */
int  getInsideTag(tagEnum tagE, char line[], char cBuffer[]){

	int iRetSize = ERROR;
	//------------- BALISE NAME -----------------------
	if( strstr(line, cTabTag[tagE].opentag) != NULL){
		if( strstr(line, cTabTag[tagE].closetag) != NULL){
			int i;
			int iP;
			printf("OK\n");
			for(i =0; i < iRetSize ; i++){
				if(line[i]=='/'){
					iP =i-1;
				}
			}
			printf("OK 2\n");
			strncpy(cBuffer, &line[SIZE_NAME], iP- SIZE_NAME);
			iRetSize = iP- SIZE_NAME+1;

			printf("OK 2'\n");
		}
	}

	return iRetSize;
}


