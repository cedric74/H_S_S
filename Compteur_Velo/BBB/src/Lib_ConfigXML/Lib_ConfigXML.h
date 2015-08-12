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
int Lib_Config_Load(const char * cPatchXMLFile );
int Lib_Config_Save(const char * cPathXMLFile  );


#endif /* SRC_LIB_CONFIGXML_LIB_CONFIGXML_H_ */
