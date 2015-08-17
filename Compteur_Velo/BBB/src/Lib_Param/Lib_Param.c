/*
 * Lib_Param.c
 *
 *  Created on: Aug 13, 2015
 *      Author: ctoncanier
 */

/*******************************************
*			  I N C L U D E 			   *
********************************************/
#include "Lib_Param.h"

/*******************************************
*               D E F I N E                *
********************************************/

// Nbe Variable to Load from XML
#define DELAY_2_SEC					2		// In s
#define SERVER_PORT					6000
#define RADIUS_CYCLE				340

/*******************************************
*   T Y P E D E F   &  C O N S T A N T E   *
********************************************/

// Parameter name
const char TAG_TICK[]=			"tick_main_loop";
const char TAG_PORT_SOCKET[]=	"port_socket_server";
const char TAG_RADIUS[]=		"radius_cycle";

typedef enum{
	TYPE_INT	=0,
	TYPE_STRING	=1,
	TYPE_FLOAT	=2,
	TYPE_BOOL	=3,
	TYPE_CHAR	=4,
	NBE_TYPE	=5,
}typeEnum;

typedef struct{
	char			name[7];
	unsigned short 	sValue;
}structtype;

//tab of tag
structtype cTabType[NBE_TYPE]={
/* TYPE_INT 	*/	{"int"	 , 0 },
/* TYPE_STRING 	*/	{"string", 0 },
/* TYPE_FLOAT	*/	{"float" , 0 },
/* TYPE_BOOL 	*/	{"bool"	 , 0 },
/* TYPE_CHAR 	*/	{"char"  , 0 },
};


/*******************************************
*	 G L O B A L   V A R I A B L E S  	   *
********************************************/

/*******************************************
*	   L O C A L   F U N C T I O N S   	   *
********************************************/

/*******************************************
*			F U N C T I O N S 				*
********************************************/

/*
 ============================================
 Function     : getData()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int getData(sData tabData[], int iLen){

	int iType, iCheck =0;
	int iDxData = 0;
	for(iDxData = 0; iDxData < iLen; iDxData++){
		for( iType =0 ;iType < NBE_TYPE; iType++){
			if(strstr(tabData[iDxData].cType, cTabType[iType].name) != NULL) {
				switch(iType){
					case TYPE_INT:
						if(strstr( tabData[iDxData].cName, TAG_TICK) != NULL) {
							iTickLoop = atoi(tabData[iDxData].cValue);
							iCheck++;
						}
						if(strstr( tabData[iDxData].cName, TAG_PORT_SOCKET) != NULL) {
							iPortSocket = atoi(tabData[iDxData].cValue);
							iCheck++;
						}
					break;
					case TYPE_FLOAT:
							if(strstr( tabData[iDxData].cName, TAG_RADIUS) != NULL) {
								fRadius = atof(tabData[iDxData].cValue);
								iCheck++;
							}
					break;
					default:
						return -1;
					break;
				}
			}
		}
	}

	// Test if All Config are set
	if(iCheck != NBE_VARIABLE_XML_TO_LOAD){
		return -1;
	}
	return 0;
}

/*
 ============================================
 Function     : setData()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
int setData(sData tabData[], int iLen){

	// Declarations Variables
	int iType, iCheck =0;
	int iDxData = 0;
	char cBuffer[10]= {0};

	// Instructions
	for(iDxData = 0; iDxData < iLen; iDxData++){
		for( iType =0 ;iType < NBE_TYPE; iType++){
			if(strstr(tabData[iDxData].cType, cTabType[iType].name) != NULL) {
				switch(iType){
					case TYPE_INT:
						if(strstr( tabData[iDxData].cName, TAG_TICK) != NULL) {
							snprintf( cBuffer, 10, "%i\n", iTickLoop);
							int iInde = getLength( cBuffer, 10);
							snprintf( tabData[iDxData].cValue, iInde, "%s", cBuffer);
							printf("iTickLoop : %s...\n", tabData[iDxData].cValue);
							iCheck++;
						}
						if(strstr( tabData[iDxData].cName, TAG_PORT_SOCKET) != NULL) {
							snprintf( cBuffer, 10, "%i\n", iPortSocket);
							int iInde = getLength( cBuffer, 10);
							snprintf( tabData[iDxData].cValue, iInde, "%s", cBuffer);
							printf("iPortSocket : %s...\n", tabData[iDxData].cValue);
							iCheck++;
						}
					break;
					case TYPE_FLOAT:
						if(strstr( tabData[iDxData].cName, TAG_RADIUS) != NULL) {
							snprintf( cBuffer, 10, "%3.2f\n", fRadius);
							int iInde = getLength( cBuffer, 10);
							snprintf( tabData[iDxData].cValue, iInde, "%s", cBuffer);
							printf("fRadius : %s...\n", tabData[iDxData].cValue);
							iCheck++;
						}
					break;
					default:
						return -1;
					break;
				}
			}
		}
	}

	return 0;
}


/*
 ============================================
 Function     : setDefaultData()
 Parameter    :
 Return Value : void
 Description  :
 ============================================
 */
void setDefaultData(){

	// Set Default Tick Main Loop
	iTickLoop = DELAY_2_SEC;

	//Set Default Socket Server Port Com
	iPortSocket = SERVER_PORT;

	// Set Default Radius
	fRadius = RADIUS_CYCLE;

	// Set Data on the tabData
	setData( tabData,  NBE_VARIABLE_XML_TO_LOAD);
}
