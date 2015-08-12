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

/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	        F U N C T I O N S   	       *
********************************************/
/*
 ============================================
 Function     : Lib_Config_Load()
  @Parameter  : Path of Xml File
 Return Value : void
 Description  :
 ============================================
 */
int Lib_Config_Load(const char * cPathXMLFile ){

	// Declarations Variables
	NodeConfigL1 	currentNodeL1 = HEAD;
	NodeConfigL2    currentNodeL2 = 0;
	NodeConfigL3	currentNodeL3 = 0;
	NodeConfigL4	currentNodeL4 = 0;

	FILE * 		fConfig;
	char * 		line = NULL;
	size_t 		len = 0;
	ssize_t 	sizeLine;

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
		switch(currentNodeL1){
			case HEAD:
				if( compare_strings( line, "<config>")){
					currentNodeL1 = CONFIG;
					//continue;
				}
			break;
			case CONFIG:
				if( compare_strings( line, 	"<data>")){
					currentNodeL2 = DATA;
					//continue;
				}
				//				if( compare_strings( line, 	"<version>")){
//					currentNodeL2 = VERSION;
//				}
		}

		switch(currentNodeL2){
			case DATA:
				if( compare_strings( line, 	"<db env>")){
					currentNodeL3 = DB;
					//continue;
				}
				break;

			case VERSION:
				continue;
			break;
		}

		switch(currentNodeL3){
			case DB:
				if( compare_strings( line, 	"<name>")){
					currentNodeL4 = DB_NAME;
					//continue;
				}
				if( compare_strings( line, 	"<version>")){
					currentNodeL4 = DB_TYPE;
					//continue;
				}
				if( compare_strings( line, 	"<value>")){
					currentNodeL4 = DB_VALUE;
					//continue;
				}
			break;
		}

		switch(currentNodeL4){
			case DB_NAME:
				printf("Copy Name: %s", line);
				continue;
			break;
			case DB_TYPE:
				printf("Copy Type: %s", line);
				continue;
			break;
			case DB_VALUE:
				printf("Copy Value: %s", line);
				continue;
			break;
		}
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


