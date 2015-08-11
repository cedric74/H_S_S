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
	DB_NAME		= 5,
	DB_TYPE		= 6,
	DB_VALUE	= 7,
}NodeConfigL3;

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
	NodeConfigL2    currentNodeL2;
	NodeConfigL3	currentNodeL3;

	FILE * 		fConfig;
	char * 		line = NULL;
	size_t 		len = 0;
	ssize_t 	sizeLine;

	// Open File
	fConfig = fopen ( cPathXMLFile, "r");
	if(fConfig == NULL){
		printf("-Error Open File : %s", cPathXMLFile);
		return -1;
	}
	//	Seek to the beginning of the file
	fseek(fConfig, SEEK_SET, 0);

	// Read Line by Line
	while ((sizeLine = getline(&line, &len, fConfig)) != -1) {

		// Print XML
		//printf("%s\n", line);

		//TODO, Parse XML

		switch(currentNodeL1){
			case HEAD:
				if( compare_strings( line, "<config>")){
					currentNodeL1 = CONFIG;
				}
			break;
			case CONFIG:
				if( compare_strings( line, 	"<data>")){
					currentNodeL2 = DATA;
				}
				if( compare_strings( line, 	"<version>")){
					currentNodeL2 = VERSION;
				}
				switch(currentNodeL2){
					case DATA:
						if( compare_strings( line, 	"<name>")){
							currentNodeL3 = DB_NAME;
						}
						if( compare_strings( line, 	"<version>")){
							currentNodeL3 = DB_TYPE;
						}
						if( compare_strings( line, 	"<value>")){
							currentNodeL3 = DB_VALUE;
						}
						switch(currentNodeL3){
							case DB_NAME:
								// Copy Name
								// Debug
								printf("Copy Name: %s\n", line);
							break;
							case DB_TYPE:
								// Copy Type
								// Debug
								printf("Copy Type: %s\n", line);
							break;
							case DB_VALUE:
								// Copy Value
								// Debug
								printf("Copy Value: %s\n", line);
							break;
						}

					break;
					case VERSION:

					break;
				}
			break;

			/*
			case VERSION:
				//
			break;
			case DATA:
				//
			break;
			case DB:
				//
			break;

			*/
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


