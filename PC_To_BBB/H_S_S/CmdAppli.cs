using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace H_S_S
{
    class CmdAppli
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

        // COMMAND
        public enum cmd
        {
            NO_CMD          = 0,
            SOUND_CMD       = 1,
            PICTURE_CMD     = 2,
            VIDEO_CMD       = 3,
            REPORT_FILE_CMD = 4,
            TEST_CAPTOR     = 5,
            DISCONNECT_CMD  = 6,
            STOP_CMD        = 7,
        };
        #endregion

        #region VARIABLES
        /*==========================================================================*/
        /*                          V A R I A B L E S                               */
        /*==========================================================================*/
        public enumTypeMess    bType;
        public cmd             bTypeCmd;
        public byte            bParam; 
        public byte            bSize;
        public byte            bChecksum;
        public byte[]          bMessage; 

        #endregion

        #region CONSTRUCTOR
        /*==========================================================================*/
        /*                       C O N S T R U C T O R                              */
        /*==========================================================================*/
        public CmdAppli(cmd Cmd, byte param)
        {          
            bType = enumTypeMess.CMD_APPLI;
            bTypeCmd =  Cmd;
            bParam = param;
            bSize = 5;
            bChecksum = (byte)( (byte)bType + (byte)bTypeCmd + bParam + bSize);
            bMessage = new byte[5];
            bMessage[0] = (byte)bType;
            bMessage[1] = (byte)bTypeCmd;
            bMessage[2] = bParam;
            bMessage[3] = bSize;
            bMessage[4] = bChecksum;
        }

        #endregion


    }
}
