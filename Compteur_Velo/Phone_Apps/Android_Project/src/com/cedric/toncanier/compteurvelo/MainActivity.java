package com.cedric.toncanier.compteurvelo;


import android.os.Handler;
import java.io.InputStream;
import java.net.Socket;
import java.net.InetAddress;
import java.text.DecimalFormat;
import android.os.AsyncTask;
import android.os.SystemClock;
import android.os.Bundle;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;
import android.os.Message;
import android.os.Handler.Callback;
import android.support.v7.app.ActionBarActivity;
import android.view.View;
import android.widget.Button;
import android.widget.Chronometer;
import android.widget.TextView;

<<<<<<< .mine
public class MainActivity extends ActionBarActivity implements View.OnClickListener {
=======
@SuppressWarnings("deprecation")
public class MainActivity extends ActionBarActivity {
>>>>>>> .r93

	/**
	 * CONSTANT
	 */
    private final boolean START = true;
    private final boolean STOP  = false;
    private final int TICK_DATA = 2; // 5 Seconds Maybe Too Long
<<<<<<< .mine

    // DEBUG
    /**
     * DEBUG
     */
    private final int MAX_RDM   = 50000;
    private final int MIN_RDM   = 46000;

    /**
     * CLASS OBJECT
     */
    DataCycle             	data;
    Test_Debug_Without_BBB  debug;
    
    DataDAO 				db;
    Data					dataTest;

    /**
     * VARIABLES
     */
    //private int       iCount = 0;
    private Button 		bStart_button;
    
    private TextView    speedText;
    private TextView    textTotalDistance;
    private TextView    textsocket;
    private TextView    textAverageSpeed;
    private Chronometer chrono;
    private boolean 	bFlagStart_Stop;
    private long 		lTime = 0 ;
    private long 		starttime = 0;
    
    Timer timer = new Timer();

    /*
     * Handler
     */
    final Handler h = new Handler(new Callback() {
        @Override
        public boolean handleMessage(Message msg) {

            // Current Speed
            DecimalFormat df = new DecimalFormat("##.# Km/H");
            String sCurrentSpeed=df.format(data.getdCurrentSpeed());
            speedText.setText("Speed : " +  sCurrentSpeed);

            // Average Speed
            df = new DecimalFormat("##.## Km");
            String sAverageSpeed=df.format(data.getdAverageSpeed());
            textAverageSpeed.setText("Average Speed : " + sAverageSpeed);

            // Total Distance
            df = new DecimalFormat("##.## Km");
            String sTotalDistance=df.format(data.getdTotalDistance());
            textTotalDistance.setText("Distance : " + sTotalDistance);

            // DEBUG SOCKET
            textsocket.setText(String.valueOf(data.dStep));

            return false;
        }
    });

    //tells handler to send a message
    class firstTask extends TimerTask {

        @Override
        public void run() {
        	h.sendEmptyMessage(0);
        }
    };

    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        
        // Test Data Base 
        
//        try{
//        	db = new DataDAO(null);
//        	dataTest = new Data(0,1,2,"3", "4");
//        	db.add(dataTest);
//        }
//        
//        catch(Exception ex){
//        	ex.printStackTrace();
//        }
        
        
        // Button
        bStart_button = (Button) findViewById(R.id.Start_button);
        bStart_button.setText("START");
        Button bReset_button = (Button) findViewById(R.id.button_Reset);
        bStart_button.setOnClickListener(this);
        bReset_button.setOnClickListener(this);

        // TextView
        speedText = (TextView)findViewById(R.id.textViewSpeed);
        speedText.setText("Speed :");

        textsocket =(TextView)findViewById(R.id.textsocket);
        textsocket.setText("client :");

        textTotalDistance = (TextView)findViewById(R.id.textViewDistance);
        textTotalDistance.setText("Distance :");

        textAverageSpeed= (TextView)findViewById(R.id.textViewAverageSpeed);
        textAverageSpeed.setText("Average Speed :");

        // Chrono
        chrono = (Chronometer) findViewById(R.id.chronometer);

        // Init Flag
        bFlagStart_Stop = STOP;

        // Thread to Print Value
        starttime = System.currentTimeMillis();
        timer = new Timer();
        timer.schedule(new firstTask(), 0, 500);

        // Class Data
        data = new DataCycle();

        // Class Random Value
        debug = new Test_Debug_Without_BBB(MAX_RDM, MIN_RDM);

        // Socket Connection
        MyClientTask myClient = new MyClientTask();
        myClient.execute();
    }

    private void clickStartButton() {
        // Chrono 	
        bFlagStart_Stop = ! bFlagStart_Stop;
        
        if(bFlagStart_Stop == START){
            chrono.setBase(SystemClock.elapsedRealtime()+lTime);
            chrono.start();
            
            bStart_button.setText("STOP");
        }else{
            chrono.stop();
            lTime = chrono.getBase()- SystemClock.elapsedRealtime();
            
            bStart_button.setText("START");
        }
    }

    private void clickResetButton(){
        lTime = 0;
        chrono.setBase(SystemClock.elapsedRealtime() + lTime);
        data.initDataCycle();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){

            case R.id.Start_button:
                clickStartButton();

                break;

            case R.id.button_Reset:
                clickResetButton();

                break;
        }
    }

    public class MyClientTask extends AsyncTask<Void,Void,Void>{

        // Socket
        InetAddress serverAddr;
        Socket clientSocket = null;
        InputStream inputStream;

        private static final int    SERVERPORT  = 6000;
        private static final String SERVER_IP   = "192.168.0.106";

        @Override
        protected Void doInBackground(Void... params) {
            int iCtRound;
 /* WITHOUT BBB**************
            try {
                serverAddr = InetAddress.getByName(SERVER_IP);
                clientSocket = new Socket(serverAddr, SERVERPORT);
                inputStream = clientSocket.getInputStream();

                byte[] buffer = new byte[1024];
                // do {
                ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream(1024);
                int bytesRead;
                while ((bytesRead = inputStream.read(buffer)) != -1) {
                    byteArrayOutputStream.write(buffer, 0, bytesRead);
                    //textsocket.setText(textsocket.getText() + String.valueOf(buffer[0]));

                    if(bytesRead == 3){
                        iCtRound = (buffer[0]*10000) + (buffer[1]*100)+(buffer[2]);
                    }

                    // Add Distance
                    data.addDataCycle(iCtRound);
                }
            }
            catch (UnknownHostException e1){
                e1.printStackTrace();
            }
            catch (IOException e1){
                e1.printStackTrace();
            }

            finally {
                if (clientSocket != null){
                    try {
                        clientSocket.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
             WITHOUT BBB********* */

            /* DEBUG VERSION */

            // bFlagStart_Stop = STOP
            do {
            	
            	if( bFlagStart_Stop == START){
	                // Generate a Random Value
	                iCtRound = debug.randInt();
	
	                // Add Distance
	                data.addDataCycle(iCtRound);
	
	                // sleep in Ms
	                try{
	                    Thread.sleep(TICK_DATA * 1000);
	                }
	                catch (InterruptedException e) {
	                    e.printStackTrace();
	                }
            	}else{
            		// ... Process Stop
            	}

            }while(true);

            /* END DEBUG VERSION    */

            //return null;
        }


        @Override
        protected void onPostExecute(Void aVoid) {
            timer.cancel();
            textsocket.setText("End Task ");
            super.onPostExecute(aVoid);
        }
    }

    public class Test_Debug_Without_BBB    {
        private int max;
        private int min;

        public Test_Debug_Without_BBB(int iMax, int iMin) {
            this.max = iMax;
            this.min = iMin;
        }

        /**
         * Returns a pseudo-random number between min and max, inclusive.
         * The difference between min and max can be at most
         * <code>Integer.MAX_VALUE - 1</code>.
         *
         /* @param  Minimum value
         /* @param  Maximum value.  Must be greater than min.
         * @return Integer between min and max, inclusive.
         * @see java.util.Random#nextInt(int)
         */

        public int randInt() {
            // NOTE: Usually this should be a field rather than a method
            // variable so that it is not re-seeded every call.
            Random rand = new Random();

            // nextInt is normally exclusive of the top value,
            // so add 1 to make it inclusive
            int randomNum = rand.nextInt((max - min) + 1) + min;
            return randomNum;
        }
    }

    // End MainClass MainActivity
=======
>>>>>>> .r93
}


