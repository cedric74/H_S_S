package com.cedric.toncanier.compteurvelo;

import android.content.ContentValues;
import android.content.Context;

public class DataDAO extends DAOBase{
	
	public DataDAO(Context pContext) {
		super(pContext);
		// TODO Auto-generated constructor stub
	}

	public static final String TABLE_NAME 		= "trip";
	public static final String KEY 				= "id";
	public static final String TRIP_SPEED 		= "speed";	
	public static final String TRIP_DISTANCE 	= "distance";
	public static final String TRIP_TIME 		= "time";
	public static final String TRIP_DATE 		= "date";
	
	public static final String TABLE_CREATE = "CREATE TABLE " + TABLE_NAME + " (" + 
			KEY 		+ " INTEGER PRIMARY KEY AUTOINCREMENT, " + 
			TRIP_SPEED 	+ " REAL, " + TRIP_DISTANCE + " REAL, " +  
			TRIP_TIME  	+ " TEXT, " + TRIP_DATE + " TEXT);";

	public static final String TABLE_DROP =  "DROP TABLE IF EXISTS " + TABLE_NAME + ";";
	
	
	/**
	 * @param d , Data to add into the DB
	 */
	public void add(Data d){
		//TODO , Add add() code here		
		//INSERT INTO d (speed, distance, time, date)VALUE(d.getfSpeed(), d.getfDistance(), d.)
		
		ContentValues value = new ContentValues();
		value.put(TRIP_SPEED,d.getfSpeed());
		value.put(TRIP_DISTANCE, d.getfDistance());
		value.put(TRIP_TIME, d.getsTime());
		value.put(TRIP_DATE, d.getsDate());
		mDb.insert(TABLE_NAME, null, value);
		
	}
	
	/**
	 * @param id , identifier of the trip that you want to delete 
	 */	
	public void delete(long id){
		//TODO , Add delete() code here
	}

	/**
	 * @param d , Data that you want to modify
	 */	
	public void modify(Data d){
		//TODO , Add modify() code here
	}
	
	/**
	 * @param id , identifier of the data to get
	 */	
	public Data select(long id){
		//TODO , Add modify() code here
		
		return null;
	}
}
