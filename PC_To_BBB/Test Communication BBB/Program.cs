/*<#======================================================================#>*/
/*   Test Communication With BBB, 28/01/2015								*/
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
using System.Windows;


using System.Net; 
using System.Net.Sockets;

using Lib_socket;

/*==========================================================================*/
/*                            N A M E S P A C E                             */
/*==========================================================================*/
namespace Test_Communication_BBB
{
	/*==========================================================================*/
	/*                              E N U M S                                   */
	/*==========================================================================*/
	/*==========================================================================*/
	/*                             S T R U C T S                                */
	/*==========================================================================*/
	/*====cd ..======================================================================*/
	/*                    C L A S S   D E F I N I T I O N S                     */
	/*==========================================================================*/
	class Program
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
		static string ipAdress = "192.168.7.2";
		static int iPort = 51717;

		// Receiving byte array  
		static byte[] bytes = new byte[1024];

		// Create a socket object 
		static Socket sListener;

		// Current Objet
		static Program ob = new Program();

		#endregion 

		#region MAIN
		/*==========================================================================*/
		/*									Main									*/
		/*==========================================================================*/
		static void Main(string[] args)
		{

			#region VERSION_1

			//try
			//{
			//	// Create one SocketPermission for socket access restrictions 
			//	SocketPermission permission = new SocketPermission(
			//		NetworkAccess.Connect,    // Connection permission 
			//		TransportType.Tcp,        // Defines transport types 
			//		"",                       // Gets the IP addresses 
			//		SocketPermission.AllPorts // All ports 
			//		);

			//	// Ensures the code to have permission to access a Socket 
			//	permission.Demand();

			//	IPAddress ipAddr = IPAddress.Parse(ipAdress);
			//	IPEndPoint ipEndPoint = new IPEndPoint(ipAddr, iPort);


			//	sListener = new Socket(ipAddr.AddressFamily,	// Specifies the addressing scheme 
			//							  SocketType.Stream,	// The type of socket  
			//							  ProtocolType.Tcp);	// Specifies the protocols  


			//	// associate our socket with the IpEndPoint   // for the server SIDE
			//	//sListener.Bind(ipEndPoint);  

			//	// Establishes a connection to a remote host 
			//	sListener.Connect(ipEndPoint);

			//	byte[] msg = Encoding.UTF8.GetBytes("\n TEST " + "<Client Quit> \n");
			//	int bytesSend = sListener.Send(msg);
			//	Console.WriteLine("\n	Send Message \n" );

			//}
			//catch (Exception exc) { 
			//	Console.WriteLine("\n----- ERROR ---- \n"); 
			//}

			//try
			//{
			//	// Receives data from a bound Socket. 
			//	int bytesRec = sListener.Receive(bytes);

			//	// Converts byte array to string 
			//	String theMessageToReceive = Encoding.UTF8.GetString(bytes, 0, bytesRec);
			//	Console.WriteLine(theMessageToReceive); 

			//	// Continues to read the data till data isn't available 
			//	while (sListener.Available > 0)
			//	{
			//		bytesRec = sListener.Receive(bytes);
			//		theMessageToReceive += Encoding.Unicode.GetString(bytes, 0, bytesRec);
			//	}
			//}
			//catch (Exception exc) { 
			//	Console.WriteLine("\n----- ERROR ---- \n"); 
			//}

			//// Disables sends and receives on a Socket. 
			//sListener.Shutdown(SocketShutdown.Both);

			////Closes the Socket connection and releases all resources 
			//sListener.Close();


			#endregion

			#region VERSION 2 , WITH LIB_SOCEKT DLL

			Lib_socket.Class_socket sock = new Class_socket(ipAdress, iPort);

			// Connection
			if (sock.Connect() == false)
			{
				Console.WriteLine("\n	- Error Connection\n");
				ob.OutConsole();
				return;
			}

			// Send Message
			if (sock.Send("\n Test message : 0123456789 \n") == false)
			{
				Console.WriteLine("\n	- Error Connection\n");
				ob.OutConsole();
				return;
			}

            //byte sReceiveData = "";
            //if (sock.ReceiveDataFromServer(ref sReceiveData) == false)
            //{
            //    Console.WriteLine("\n	- Error Connection\n");
            //    ob.OutConsole();
            //    return;
            //}

			//Console.WriteLine(sReceiveData + "\n");

			#endregion



			ob.OutConsole();
			return;
		}
		#endregion


		#region OUT_CONSOLE
		/*==========================================================================*/
		/*                        O U T  C O N S O L E                              */
		/*==========================================================================*/
		public void OutConsole()
		{
			#if DEBUG
				Console.WriteLine("\n	- Press enter to close...\n");
				Console.ReadLine();
			#endif
		}

		#endregion

	}
}
