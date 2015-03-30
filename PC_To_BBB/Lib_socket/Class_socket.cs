/*<#======================================================================#>*/
/*   Lib Socket, 28/01/2015													*/
/*   Ced.T.                                                                 */
/*<#======================================================================#>*/

/*==========================================================================*/
/*                               U S I N G                                  */
/*==========================================================================*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Net;
using System.Net.Sockets;

/*==========================================================================*/
/*                            N A M E S P A C E                             */
/*==========================================================================*/
namespace Lib_socket
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
    public class Class_socket
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
        // Receiving byte array  
        byte[] bytes = new byte[1024];

        private Socket clientSocket;

        static string ipAdress;			//= "192.168.7.2";
        static int iPort;				// = 51717;

        #endregion

        #region CONSTRUCTOR
        /*==========================================================================*/
        /*                       C O N S T R U C T O R                              */
        /*==========================================================================*/
        public Class_socket(string sIPAdress, int iPortNum)
        {
            // Get Value
            ipAdress = sIPAdress;
            iPort = iPortNum;
        }
        #endregion

        #region CONNECT
        /*==========================================================================*/
        /*							C O N N E C T									*/
        /*==========================================================================*/
        public bool Connect()
        {
            try
            {
                // Create one SocketPermission for socket access restrictions 
                SocketPermission permission = new SocketPermission(
                    NetworkAccess.Connect,    // Connection permission 
                    TransportType.Tcp,        // Defines transport types 
                    "",                       // Gets the IP addresses 
                    SocketPermission.AllPorts // All ports 
                    );

                // Ensures the code to have permission to access a Socket 
                permission.Demand();

                IPAddress ipAddr = IPAddress.Parse(ipAdress);
                IPEndPoint ipEndPoint = new IPEndPoint(ipAddr, iPort);


                clientSocket = new Socket(ipAddr.AddressFamily,	// Specifies the addressing scheme 
                                          SocketType.Stream,	// The type of socket  
                                          ProtocolType.Tcp);	// Specifies the protocols  

                // Establishes a connection to a remote host 
                clientSocket.Connect(ipEndPoint);

            }
            catch (Exception exc)
            {
                //Console.WriteLine("\n----- ERROR ---- \n");
                return false;
            }

            return true;

        }

        #endregion

        #region DISCONNECT
        /*==========================================================================*/
        /*							D I S C O N N E C T								*/
        /*==========================================================================*/
        public bool Disconnect()
        {
            try
            {
                // Disables sends and receives on a Socket. 
                clientSocket.Shutdown(SocketShutdown.Both);

                //Closes the Socket connection and releases all resources 
                clientSocket.Close();
            }

            catch (Exception exc)
            {
                //MessageBox.Show(exc.ToString());
                return false;
            }
            return true;

        }

        #endregion

        #region SEND
        /*==========================================================================*/
        /*								S E N D 									*/
        /*==========================================================================*/
        public bool Send(string sMessage)
        {
            try
            {
                byte[] msg = Encoding.UTF8.GetBytes(sMessage + "\n");
                int bytesSend = clientSocket.Send(msg);
            }

            catch (Exception exc)
            {
                return false;
            }
            return true;
        }

        public bool Send_Bytes(byte[] bMessage, int iLength)
        {
            try
            {
                byte[] msg = new byte[iLength];
                int bytesSend = clientSocket.Send(bMessage);
            }

            catch (Exception )
            {
                return false;
            }
            return true;
        }

        #endregion

        #region RECEIVE DATA
        /*==========================================================================*/
        /*							R E C E I V E	D A T A							*/
        /*==========================================================================*/
        public int ReceiveDataFromServer(byte[] bByte)
        {
            int iCount = 0;

            try
            {
                while (clientSocket.Available > 0)
                {
                    iCount = clientSocket.Receive(bByte);
                }
            }
            catch (Exception )
            {
                //MessageBox.Show(exc.ToString());
                return 0;
            }

            return iCount;
        }

        #endregion

    }
}
