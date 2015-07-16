package com.cedric.toncanier.compteurvelo;

import java.io.IOException;
import java.io.InputStream;
import java.net.InetAddress;
import java.net.Socket;

public class SocketCom {
	  // Socket
    private InetAddress serverAddr;
    public Socket clientSocket = null;
    public InputStream inputStream;

    public SocketCom(String sServer_IP, int iServer_Port) {
        try {
            serverAddr = InetAddress.getByName(sServer_IP);
            clientSocket = new Socket(serverAddr, iServer_Port);
            inputStream = clientSocket.getInputStream();
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }

    public void read_Bytes() {
//            byte[] buffer = new byte[1024];
//            // do {
//            try {
//                ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream(1024);
//                int bytesRead;
//                while ((bytesRead = inputStream.read(buffer)) != -1) {
//                    byteArrayOutputStream.write(buffer, 0, bytesRead);
//                    //textsocket.setText(textsocket.getText() + String.valueOf(buffer[0]));
//
//                    if (bytesRead == 3) {
//                        iCtRound = (buffer[0] * 10000) + (buffer[1] * 100) + (buffer[2]);
//                    }
//
//                    // Add Distance
//                    data.addDataCycle(iCtRound);
//                }
//            } catch (IOException e1) {
//                e1.printStackTrace();
//            }
    }
}
