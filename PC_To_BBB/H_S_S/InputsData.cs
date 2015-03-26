using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace H_S_S
{
    class InputsData
    {
          #region CONSTANTES
        /*==========================================================================*/
        /*                        C O N S T A N T E S                               */
        /*==========================================================================*/
        #endregion

        #region VARIABLES
        /*==========================================================================*/
        /*                          V A R I A B L E S                               */
        /*==========================================================================*/
        public byte     bCaptor_Main_Door;
        public byte     bCaptor_Back_Door;
        public byte     bInterrupter;
        public float    fTemp;
        public float    fHum;


        #endregion

        #region CONSTRUCTOR
        /*==========================================================================*/
        /*                       C O N S T R U C T O R                              */
        /*==========================================================================*/
        public InputsData( InputsStatus sStatus)
        {
            bCaptor_Main_Door   =   (byte)(sStatus.bInputs &0x01);
            bCaptor_Back_Door   =   (byte)((sStatus.bInputs >> 1) & 0x01);
            bInterrupter        =   (byte)((sStatus.bInputs >> 2) & 0x01);
            fTemp               =   sStatus.fTemp;
            fHum                =   sStatus.fHum;   
        }

        #endregion


    }
}
