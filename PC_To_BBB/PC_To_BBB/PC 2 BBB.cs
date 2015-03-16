/*<#======================================================================#>*/
/*   PC 2 BBB , version 1.0, 28/01/2015                                     */
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
using System.Windows.Forms.DataVisualization.Charting;

using Lib_socket;

/*==========================================================================*/
/*                            N A M E S P A C E                             */
/*==========================================================================*/
namespace PC_To_BBB
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
	public partial class Form1 : Form
	{
		#region CONSTANTES
		/*==========================================================================*/
		/*                        C O N S T A N T E S                               */
		/*==========================================================================*/
        // Label Test
        const string LABEL_ADRESS_SERVER  = "Adress : "; 
        const string LABEL_PORT_SERVER    = "Port : ";

        // Message Info
        const string ERROR_CONNECTION = "Error Connection with BBB socket" ;
        
        // Socket Data
        const string ipAdress = "192.168.7.2";
        const int iPort = 51717;

        // State Connection
        const bool CONNECTED    =   true;
        const bool DISCONNECTED = false;

        // State Start Stop
        const bool START = true;
        const bool STOP = false;
        
        // Data Bike
        const float RADIUS_BIKE = 356.00F; // Diameter 712 mm
        const int STEP_TIMER = 10 ;
        
        
		#endregion 

		#region VARIABLES
		/*==========================================================================*/
		/*                          V A R I A B L E S                               */
		/*==========================================================================*/
       // Flags
        bool bStateConnection;
        bool bStartStop;

        // Object
        Lib_socket.Class_socket sock;
        Thread t = null;

        // Variables 
        float fDistanceCurrent = 0;
        float fSpeed = 0;
        Int64 iTime = 0 ;

		#endregion 

		#region CONSTRUCTOR
		/*==========================================================================*/
		/*                       C O N S T R U C T O R                              */
		/*==========================================================================*/
		public Form1()
		{
			InitializeComponent();

            // Set flag to Default value , disconnected
            bStateConnection = DISCONNECTED;

            // Set flag to Default value , disconnected
            bStartStop = STOP;

            // Init Print Data
            printData();

            groupBoxButton.Enabled = false;
            groupBoxSpeed.Enabled = false;
            groupBoxDistance.Enabled = false;
            groupBoxTime.Enabled = false;
            groupBoxGraphe.Enabled = false;
		}
		
		#endregion 

        #region TIMER TICK

        private void timerSecond_Tick(object sender, EventArgs e)
        {
            printData();
            iTime++;
        }

        private void timerReadsocket_Tick(object sender, EventArgs e)
        {
            byte[] bData = new byte[2];
            sock.ReceiveDataFromServer(bData);
            conveOperation(bData[0]);
            printData();
        }
        
        #endregion 

        #region BUTTON CLICK EVENT

        private void buttonConnection_Click(object sender, EventArgs e)
        {
            swithConnectionState();
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {

            
            if (bStateConnection == CONNECTED)
            {
                // Request that oThread be stopped
                //oThread_Time.Abort();

                // Wait until oThread finishes. Join also has overloads
                // that take a millisecond interval or a TimeSpan object.
                //oThread_Time.Join();
                
                // Close Connection
                sock.Disconnect();
            }
        }

        private void buttonStart_Stop_Click(object sender, EventArgs e)
        {
            swithStart_Stop();
        }

        private void buttonReset_Click(object sender, EventArgs e)
        {
            fSpeed = 0;
            fDistanceCurrent = 0;
            iTime = 0;
            printData();
        }

        #endregion

        #region FUNCTIONS

        private void swithConnectionState()
        {
        
            if(bStateConnection == DISCONNECTED){
                // Create Object socket 
                sock = new Class_socket(ipAdress, iPort);

                // Connection
                if (sock.Connect() == false)
                {
                    printTextBoxInfo(ERROR_CONNECTION);
                    this.LightStatusConnection.BackColor = System.Drawing.Color.Red;
                    return;
                }
                // Change the Connection State
                bStateConnection = CONNECTED;

                // Visual Form Modification
                groupBoxButton.Enabled = true;
                groupBoxSpeed.Enabled = true;
                groupBoxDistance.Enabled = true;
                groupBoxTime.Enabled = true;
                groupBoxGraphe.Enabled = true;
                labelAdressIPServer.Text = LABEL_ADRESS_SERVER + ipAdress ;
                labelPortServer.Text = LABEL_PORT_SERVER + iPort;        
                printTextBoxInfo("Connected OK");
                buttonConnection.Text = "Disconnect";
                this.LightStatusConnection.BackColor = System.Drawing.Color.Green;

                // Create Speed Graphe 
                createSpeedGraph();

            }else{
                // Stop Timer
                //timerReadsocket.Enabled = false;
                // Close the thread 
                if (t != null) {
                    t.Abort();
                }
                

                // Close Connection
                sock.Disconnect();

                // Change the Connection State
                bStateConnection = DISCONNECTED;

                // Visual Form Modification
                groupBoxButton.Enabled = false;
                groupBoxSpeed.Enabled = false;
                groupBoxDistance.Enabled = false;
                groupBoxTime.Enabled = false;
                groupBoxGraphe.Enabled = false;
                labelAdressIPServer.Text = LABEL_ADRESS_SERVER ;
                labelPortServer.Text = LABEL_PORT_SERVER ;
                printTextBoxInfo("Disconneted OK");
                buttonConnection.Text = "Connect";
                this.LightStatusConnection.BackColor = System.Drawing.Color.Red;
            }
        }

        private void swithStart_Stop()
        {
            if (bStartStop == STOP)
            {
                // Change the Start Stop State
                bStartStop = START;

                // Launch Timer
                timerSecond.Enabled = true;

                // Create My Thread
                t = new Thread(new ParameterizedThreadStart(MyThread));
                // Launch Thread
                t.Start();

                // Visual Form Modification
                buttonStart_Stop.Text = "Stop";
                this.LightRunning.BackColor = System.Drawing.Color.Green;
                printTextBoxInfo("Running ...");

            }
            else
            {   
                // Close the thread 
                t.Abort();

                // Change the Start Stop State
                bStartStop = STOP;
               
                // Stop Timer
                //timerReadsocket.Enabled = false;
                timerSecond.Enabled = false;

                // Visual Form Modification
                buttonStart_Stop.Text = "Start";
                this.LightRunning.BackColor = System.Drawing.Color.Red;
                printTextBoxInfo("Stopped ...");
            }
        }

        private void printTextBoxInfo(string sMessage)
        {
            textBoxInfo.Text = " " + sMessage;
        }

        private void printData()
        {
            labelSpeed.Text = string.Format("{0:#.##} km/h ", fSpeed);                //" " + fSpeed + " km/h";
            labelDistance.Text = string.Format("{0:#.##} km ", fDistanceCurrent);   // " " + fDistanceCurrent + " Km";

            TimeSpan ts = TimeSpan.FromSeconds(iTime);
            string answer = string.Format("{0:D2}h:{1:D2}m:{2:D2}s",
                ts.Hours,
                ts.Minutes,
                ts.Seconds);
            labelTime.Text = " " + answer;


            // Add a point 
            //series.Points.Add(iTime, fSpeed);
            chartSpeed.Series["Speed"].Points.AddXY(iTime, fSpeed);
        }


        private void createSpeedGraph(){

        }

        #endregion

        #region MATHS OPERATIONS

        private void conveOperation(byte bCount)
        {

            float fDistanceLastTick = 0;

            // Distance
            fDistanceLastTick = (float)(((2*RADIUS_BIKE * Math.PI) * bCount));
            fDistanceCurrent = fDistanceCurrent + (fDistanceLastTick/  1000000 ); 

            // Speed
            // en metre
            fDistanceLastTick = (fDistanceLastTick / 1000);
            // Kilomettre
            fDistanceLastTick = (fDistanceLastTick / 1000);



            fSpeed = (fDistanceLastTick * 3600) ;

        }

        #endregion

        #region MY THREAD 

        public void MyThread(Object buf) 
        { 
             while (true)
            {
                byte[] bData = new byte[2];
                sock.ReceiveDataFromServer(bData);
                if (bData[1] == 1)
                {
                    conveOperation(bData[0]);
                }   
            }
        } 

        #endregion


    }

}
