using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace H_S_S
{
    class InputsStatus
    {
        #region CONSTANTES
        /*==========================================================================*/
        /*                        C O N S T A N T E S                               */
        /*==========================================================================*/
        public enum enumTypeMess
        {
            CMD_APPLI = 0,
            INPUTS_STATUS = 1,
        };

        #endregion

        #region VARIABLES
        /*==========================================================================*/
        /*                          V A R I A B L E S                               */
        /*==========================================================================*/
        public enumTypeMess    bType;
        public byte            bInputs;
        public float           fTemp;
        public float           fHum;
        public byte            bSize;
        public byte            bChecksum;

        public bool            bCHKSUM;

        #endregion

        #region CONSTRUCTOR
        /*==========================================================================*/
        /*                       C O N S T R U C T O R                              */
        /*==========================================================================*/
        public InputsStatus(byte[] sData) { 

            bType = (enumTypeMess)(sData[0] - 0x30);
            bInputs = (byte)(sData[1] - 0x30);
            fTemp = (byte)(sData[2] - 0x30);
            fHum = (byte)(sData[6] - 0x30);
            bSize = (byte)(((sData[10] - 0x30)*10) + (sData[11] - 0x30));
            bChecksum = (byte)(((sData[12] - 0x30)*10) + (sData[13] - 0x30));

            // Calcul checksum
            byte Chk = (byte)(bType + bInputs + ((byte)fTemp) + (byte)(fHum) + bSize);

            // Check if checksum OK
            if (bChecksum == Chk)
            {
                bCHKSUM = true;
            }
            else {
                bCHKSUM = false;
            }
        }

        #endregion


    }
}
