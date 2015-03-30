/*<#======================================================================#>*/
/*   H S S  , version 1.0, 23/02/2015                                     */
/*   Ced.T.                                                                 */
/*<#======================================================================#>*/

/*==========================================================================*/
/*                               U S I N G                                  */
/*==========================================================================*/
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Timers;
using System.Xml;
using System.IO;

using Lib_socket;

/*==========================================================================*/
/*                            N A M E S P A C E                             */
/*==========================================================================*/
namespace H_S_S
{
    /*==========================================================================*/
    /*                              E N U M S                                   */
    /*==========================================================================*/
    /*==========================================================================*/
    /*                             S T R U C T S                                */
    /*==========================================================================*/

    /*==========================================================================*/
    /*                    C L A S S   D E F I N I T I O N S                     */
    /*==========================================================================*/
    public partial class H_SS : Form
    {
        #region CONSTANTES
        /*==========================================================================*/
		/*                        C O N S T A N T E S                               */
		/*==========================================================================*/
        // Path Xml file
        const string PATH_XML = "profile.xml";

        // Path Pic Home
        const string PIC_HOME = "Pics/pic_home.jpg";

        //Path Report file
        string PATH_REPORT_FILE = "Report file.txt";

        // Label Test
        const string LABEL_ADRESS_SERVER    = "Adress : "; 
        const string LABEL_PORT_SERVER      = "Port   : ";
        const string LABEL_Captor_1         = "Main Door   : ";
        const string LABEL_Captor_2         = "Back Door   : ";
        const string LABEL_Inter_1          = "Interrupter    : ";
        const string LABEL_Temperature      = "Temperature: ";
        const string LABEL_Humidity         = "Humidity       : ";

        // Message Info
        const string ERROR_CONNECTION       = "Error Connection with BBB socket";
        
        // Socket Data
        public const string IP_ADDRESS_DEFAULT  = "192.168.7.2";
        public const int IP_PORT_DEFAULT        = 51717;
        public const int IP_PORT_VIDEO          = 51222;
        public const int IP_PORT_FILE           = 51223;

        // State Connection
        const bool CONNECTED    =   true;
        const bool DISCONNECTED = false;



        // WAIT BEFORTE EACH READ INPUTS STATUS
        const int WAIT_MS_500       = 500; 

        // SIZE INPUTS STATUS MESSSAGE
        const int SIZE_INPUTS_STATUS = 15;

        const int SIZE_MIN_PIC = 10000;       

		#endregion 

		#region VARIABLES
		/*==========================================================================*/
		/*                          V A R I A B L E S                               */
		/*==========================================================================*/
       // Flags
        bool bStateConnection;

        // Object
        Lib_socket.Class_socket sock;
        Lib_socket.Class_socket sockVideo = null;
        Lib_socket.Class_socket sockFile  = null;
        Thread threadInputsStatus = null;

        // Variables 
        public string ipAdress;
        public int ipPort;
        InputsData sInputsData;
		#endregion 

		#region CONSTRUCTOR
		/*==========================================================================*/
		/*                       C O N S T R U C T O R                              */
		/*==========================================================================*/
        public H_SS()
        {
            InitializeComponent();

            // Get value from XML
            xmlLoadFile();

            // Set flag to Default value , disconnected
            bStateConnection = DISCONNECTED;

            // Init Label
            labelCaptor_1.Text    = LABEL_Captor_1;
            labelCaptor_2.Text    = LABEL_Captor_2;
            labelInterrupter.Text = LABEL_Inter_1;//LABEL_Temperature
            labelTemperature.Text = LABEL_Temperature;
            labelHumidity.Text    = LABEL_Humidity;
        }

        #endregion

        #region TICK TIMER

        private void timer1_Tick(object sender, EventArgs e)
        {
            //// Create My Thread
            //t = new Thread(new ParameterizedThreadStart(MyThread));
            //// Launch Thread
            //t.Start();

            //// Loop until worker thread activates.
            //while (!t.IsAlive) ;

            //// allow the thread to do some work:
            ////Thread.Sleep(5);

            //// Use the Join method to block the current thread 
            //// until the object's thread terminates.
            //t.Join();

            ////timer1.Enabled = false;
            sPrintData();

        }

        #endregion

        #region BUTTON CLICK EVENT

        private void buttonConnection_Click(object sender, EventArgs e)
        {
            swithConnectionState();
        }
        
        private void buttonSetting_Click(object sender, EventArgs e)
        {
            settingForm setFrom = new settingForm( ipAdress , ipPort);
            var result = setFrom.ShowDialog();
            if (result == DialogResult.Cancel)
            {
                ipAdress = setFrom.ipAdress_return;            //values preserved after close
                ipPort = setFrom.ipPort_return;
            }
        }
        
        private void H_SS_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (bStateConnection == CONNECTED){
                swithConnectionState();        
            }

            // XML Save
            xmlSaveFile();
        }
        
        private void buttonSound_Click(object sender, EventArgs e)
        {
            CmdAppli cmd = new CmdAppli(CmdAppli.cmd.SOUND_CMD, 0);

            // Send Cmd
            sock.Send_Bytes(cmd.bMessage, cmd.bSize);
            printTextBoxInfo("Sent SOUND Command");
        }
       
        private void buttonPicture_Click(object sender, EventArgs e)
        {
          
            // Send Command Picture
            CmdAppli cmd = new CmdAppli(CmdAppli.cmd.PICTURE_CMD, 0);
            sock.Send_Bytes(cmd.bMessage, cmd.bSize); 
            printTextBoxInfo("Sent PICTURE Command");

            ReceivePic();
        }

        private void buttonVideo_Click(object sender, EventArgs e)
        {
            CmdAppli cmd = new CmdAppli(CmdAppli.cmd.VIDEO_CMD, 0);
            sock.Send_Bytes(cmd.bMessage, cmd.bSize);
            printTextBoxInfo("Sent VIDEO Command");
        }

        private void buttonReportFile_Click(object sender, EventArgs e)
        {
            // Send Cmd
            CmdAppli cmd = new CmdAppli(CmdAppli.cmd.REPORT_FILE_CMD, 0);
            sock.Send_Bytes(cmd.bMessage, cmd.bSize);
            printTextBoxInfo("Sent REPORT FILE Command");
            Report_FileFunction();
        }

        private void buttonStopCmd_Click(object sender, EventArgs e)
        {
            CmdAppli cmd = new CmdAppli(CmdAppli.cmd.STOP_CMD, 0);
            sock.Send_Bytes(cmd.bMessage, cmd.bSize);
            printTextBoxInfo("Sent STOP Command");
        }
        

        #endregion

        #region FUNCTIONS

        private void swithConnectionState()
        {

            if (bStateConnection == DISCONNECTED)
            {
                // Create Object socket 
                sock = new Class_socket(ipAdress, ipPort);

                // Connection
                if (sock.Connect() == false)
                {
                    printTextBoxInfo(ERROR_CONNECTION);
                    this.LightStatusConnection.BackColor = System.Drawing.Color.Red;
                    return;
                }

                // Launch thread
                Launch_thread();

                // Enable Timer 1
                timer1.Enabled = true;

                // Change the Connection State
                bStateConnection = CONNECTED;

                // Visual Form Modification
                groupBoxInputs.Enabled = true;
                groupBoxControl.Enabled = true;
                labelAdressIPServer.Text = LABEL_ADRESS_SERVER + ipAdress;
                labelPortServer.Text = LABEL_PORT_SERVER + ipPort;
                printTextBoxInfo("Connected OK");
                buttonConnection.Text = "Disconnect";
                this.LightStatusConnection.BackColor = System.Drawing.Color.Green;
            }
            else
            {
                // Stop Thread Read Data
                threadInputsStatus.Abort();

                // Send Stop Command
                CmdAppli cmd = new CmdAppli(CmdAppli.cmd.DISCONNECT_CMD, 0);
                sock.Send_Bytes(cmd.bMessage, cmd.bSize);
                printTextBoxInfo("Sent DISCONNECT Command");

                // Disable Timer 1
                timer1.Enabled = false;
                
                // Close Connection
                sock.Disconnect();
                if (sockVideo != null)
                {
                    sockVideo.Disconnect();
                }
                

                // Change the Connection State
                bStateConnection = DISCONNECTED;

                // Visual Form Modification
                groupBoxInputs.Enabled = false;
                groupBoxControl.Enabled = false;
                labelAdressIPServer.Text = LABEL_ADRESS_SERVER;
                labelPortServer.Text = LABEL_PORT_SERVER;
                printTextBoxInfo("Disconneted OK");
                buttonConnection.Text = "Connect";
                this.LightStatusConnection.BackColor = System.Drawing.Color.Red;
            }
        }

        private void printTextBoxInfo(string sMessage)
        {
            string outputMessage = string.Format("{0:HH:mm:ss tt}", DateTime.Now);
            textBoxInfo.AppendText(outputMessage + ", " + sMessage);
            textBoxInfo.AppendText(Environment.NewLine);
        }

        private void sPrintData()
        {
            if (sInputsData != null)
            {
                if (sInputsData.bCaptor_Main_Door == 1)
                {
                    labelCaptor_1.Text = LABEL_Captor_1 + " ON";
                }
                else
                {
                    labelCaptor_1.Text = LABEL_Captor_1 + " OFF";
                }

                if (sInputsData.bCaptor_Back_Door == 1)
                {
                    labelCaptor_2.Text = LABEL_Captor_2 + " ON";
                }
                else
                {
                    labelCaptor_2.Text = LABEL_Captor_2 + " OFF";
                }

                if (sInputsData.bInterrupter == 1)
                {
                    labelInterrupter.Text = LABEL_Inter_1 + " ON";
                }
                else
                {
                    labelInterrupter.Text = LABEL_Inter_1 + " OFF";
                }

                labelTemperature.Text = LABEL_Temperature + sInputsData.fTemp;

                labelHumidity.Text = LABEL_Humidity + sInputsData.fHum;

            }
      
            //  Char.ConvertFromUtf32(bData[3]) + Char.ConvertFromUtf32(bData[4]) 
            //                                          + Char.ConvertFromUtf32(bData[5] ) + Char.ConvertFromUtf32(bData[6] )  + Char.ConvertFromUtf32(bData[7] ) + " *C";
            //Char.ConvertFromUtf32(bData[8]) + Char.ConvertFromUtf32(bData[9]) 
            //                                    + Char.ConvertFromUtf32(bData[10]) + Char.ConvertFromUtf32(bData[11])  + Char.ConvertFromUtf32(bData[12]) + " %";
        }

        #region FUNCTION SEND BUTTON
        
        private void ReceivePic(){
        
            // Create Object socket Video if Not create 
            if (sockVideo == null)
            {           
                sockVideo = new Class_socket(ipAdress, IP_PORT_VIDEO);
                // Connection
                if (sockVideo.Connect() == false)
                {
                    printTextBoxInfo(ERROR_CONNECTION);
                    return;
                }
            }
                    
            byte[] bPicture = new byte[50000];
                
                // Waiting for The pic
                int iRecv = 0;
                int icount = 0;
                int iSize = 0;
                do{
                    byte[] buffer = new byte[50000];
                    iRecv = sockVideo.ReceiveDataFromServer(buffer);
                    Array.Copy(buffer, 0, bPicture, iSize, iRecv);
                    iSize += iRecv;
                    Thread.Sleep(250);

                     // TimeOut 10s
                    if (iRecv == 0)
                    {
                        icount++;
                        if (icount > 50)
                        {
                            printTextBoxInfo("Error to Receive Picture");
                            return;
                        }
                    }
                } while ((iRecv != 0) || (iSize < SIZE_MIN_PIC)); // 21243
                printTextBoxInfo("Received Pic Success, " + " Size :" + iSize.ToString("D") + " bits");

                // build Image From binary Value
                FileStream fs = File.Create(PIC_HOME);
                fs.Write(bPicture, 0, bPicture.Length);
                fs.Close();

                // Print jpg     
                pictureBox1.ImageLocation = PIC_HOME;
                pictureBox1.Location = new Point(21, 27);

                // GroupBox
                groupBoxOut.Text = "Picture Capture";

                // Set TextBox to not Visibile
                textBoxReportFile.Visible = false;
                pictureBox1.Show();
        
        }

        private void Report_FileFunction(){

            // Remove the previous file
            if (File.Exists(PATH_REPORT_FILE))
            {
                string outputMessage = string.Format("{0:HH_mm_ss tt}", DateTime.Now);
                outputMessage = outputMessage + PATH_REPORT_FILE;
                System.IO.File.Move(PATH_REPORT_FILE, outputMessage);
            }
            textBoxReportFile.Text = "";

            // Create Object socket Video if Not create 
            if (sockFile == null)
            {
                sockFile = new Class_socket(ipAdress, IP_PORT_FILE);
                // Connection
                if (sockFile.Connect() == false)
                {
                    printTextBoxInfo(ERROR_CONNECTION);
                    sockFile = null;
                    return;
                }
            }
            // Waiting for The pic
            int iRecv = 0;
            int icount = 0;
            int iSize = 0;
            byte[] bFile = new byte[50000];
            do
            {
                byte[] buffer = new byte[50000];
                iRecv = sockFile.ReceiveDataFromServer(buffer);
                Array.Copy(buffer, 0, bFile, iSize, iRecv);
                iSize += iRecv;
                Thread.Sleep(250);

                // TimeOut 10s
                if (iRecv == 0)
                {
                    icount++;
                    if (icount > 50)
                    {
                        printTextBoxInfo("Error to Receive Report File");
                        return;
                    }
                }
            } while ((iRecv != 0) || (iSize < 10)); // 21243
            printTextBoxInfo("Received Report File, " + " Size :" + iSize.ToString("D") + " bits");

            // build Image From binary Value
            FileStream fs = File.Create(PATH_REPORT_FILE);
            fs.Write(bFile, 0, iSize);
            fs.Close();
                
            // Print file 
            if (File.Exists(PATH_REPORT_FILE))
            {
                FileStream fsReportFile = File.OpenRead(PATH_REPORT_FILE);
                byte[] b = new byte[10000];
                UTF8Encoding temp = new UTF8Encoding(true);  
                string buffer="";
                while (fsReportFile.Read(b, 0, b.Length) > 0)
                {
                    buffer = temp.GetString(b);
                   
                }
                buffer = buffer.Replace("\n", System.Environment.NewLine);
                textBoxReportFile.AppendText(buffer);
              
                //Close Read File
                fsReportFile.Close();

                // Set TextBox Visibile & Image Off
                textBoxReportFile.Visible = true;
                pictureBox1.Hide();

                // GroupBox
                groupBoxOut.Text = "Report File";

                // Close socket
                if (sockFile != null)
                {
                    sockFile.Disconnect();
                    sockFile = null;
                }

            }else { 
                // Problem
            }    
        }

        #endregion


        #endregion

        #region MY THREAD

        public void Launch_thread(){
            //  Create My Thread
            threadInputsStatus = new Thread(new ParameterizedThreadStart(Thread_Read_InputsStatus));
            // Launch Thread
            threadInputsStatus.Start();

            // Loop until worker thread activates.
            while (!threadInputsStatus.IsAlive) ;
        }

        public void Thread_Read_InputsStatus(Object buf)
        {
            byte[] bData = new byte[20];

            do{
                int iCount = 0;

                while (iCount == 0)
                {
                    iCount = sock.ReceiveDataFromServer(bData);
                }

                // Check If length are OK
                if (iCount != SIZE_INPUTS_STATUS)
                {
                    sInputsData = null;
                    return;
                }

                // Check If Data's are OK
                InputsStatus classInputsStatus = new InputsStatus(bData);
                if (classInputsStatus.bCHKSUM == true)
                {
                    // Get Data   
                    sInputsData = new InputsData(classInputsStatus);
                }
                else { 
                    // Data not Dot
                    sInputsData = null;
                }

                // Sleep
                Thread.Sleep(WAIT_MS_500);  // In MS

            }while(true);
        }

        #endregion

        #region XML_CONFIG

        private void xmlLoadFile()
        {
            XmlTextReader textReader = new XmlTextReader(PATH_XML);
            while (textReader.Read())
            {
                if (textReader.IsStartElement())
                {
                    switch (textReader.Name.ToString())
                    {
                        case "IP_Address":
                            // Set IP adress
                            ipAdress = textReader.ReadString();
                            printTextBoxInfo("Your IP_Address is : " + ipAdress);
                        break;

                        case "IP_Port":
                            // Set IP Port
                            string sipPort = textReader.ReadString();
                            ipPort = Convert.ToInt32(sipPort);
                            printTextBoxInfo("Your IP_Port is : " + sipPort);
                        break;
                    }
                }
            }

            // Close TextReader
            textReader.Close();

        }

        private void xmlSaveFile(){
            XmlTextWriter textWriter = new XmlTextWriter(PATH_XML, null);

            // Write Employee data.
            textWriter.WriteStartDocument();
            textWriter.WriteWhitespace("\n");
            textWriter.WriteStartElement("Network_Data");
            textWriter.WriteWhitespace("\n");
            textWriter.WriteElementString("IP_Address", ipAdress);
            textWriter.WriteWhitespace("\n");
            textWriter.WriteElementString("IP_Port", ipPort.ToString());
            textWriter.WriteWhitespace("\n");
            textWriter.WriteEndElement();
            textWriter.WriteEndDocument();
            // close writer
            textWriter.Close();

        }

        #endregion


    }
}
