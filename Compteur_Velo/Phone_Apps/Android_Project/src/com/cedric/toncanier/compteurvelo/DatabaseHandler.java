package com.cedric.toncanier.compteurvelo;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHandler extends SQLiteOpenHelper{

	  public static final String TRIP_KEY 		= "id";
	  public static final String TRIP_SPEED 	= "speed";
	  public static final String TRIP_DISTANCE 	= "distance";
	  public static final String TRIP_TIME 		= "time";
	  public static final String TRIP_DATE 		= "date";
	    
	  public static final String TRIP_TABLE_NAME = "trip";
	  public static final String TRIP_TABLE_CREATE =
	    "CREATE TABLE " + TRIP_TABLE_NAME + " (" +
	    		TRIP_KEY 		+ " INTEGER PRIMARY KEY AUTOINCREMENT, " +
	    		TRIP_SPEED 		+ "REAL, " +
	    		TRIP_DISTANCE 	+ "REAL"   +
	    		TRIP_TIME		+ "TEXT"   +
	    		TRIP_DATE		+ "TEXT);";
	  
	public DatabaseHandler(Context context, String name, CursorFactory factory,
			int version) {
		super(context, name, factory, version);
		// TODO Auto-generated constructor stub
	}

	@Override
	  public void onCreate(SQLiteDatabase db) {
	    db.execSQL(TRIP_TABLE_CREATE);
	  }

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
		// TODO Auto-generated method stub
		
	}
}
