package com.cedric.toncanier.compteurvelo;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHandler extends SQLiteOpenHelper{

	private static final String COL_ID 			= "Id";
	private static final String COL_SPEED 		= "Speed";
	private static final String COL_DISTANCE 	= "Distance";
	private static final String COL_TIME 		= "Time";
	private static final String COL_DATE 		= "Date";
	public static final String TABLE_TRIP 		= "Table_trips";
	
	
	public static final String TRIP_TABLE_CREATE =
	    "CREATE TABLE " + TABLE_TRIP + " (" +
	    		COL_ID 		+ " INTEGER PRIMARY KEY AUTOINCREMENT, " +
	    		COL_SPEED 		+ "REAL, " +
	    		COL_DISTANCE 	+ "REAL"   +
	    		COL_TIME		+ "TEXT"   +
	    		COL_DATE		+ "TEXT);";
	  
	public DatabaseHandler(Context context, String name, CursorFactory factory,
			int version) {
		super(context, name, factory, version);
	}

	@Override
	  public void onCreate(SQLiteDatabase db) {
	    db.execSQL(TRIP_TABLE_CREATE);
	  }

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
		//comme ça lorsque je change la version les id repartent de 0
		db.execSQL("DROP TABLE " + TABLE_TRIP + ";");
		onCreate(db);
		
	}
	
}
