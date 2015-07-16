package com.cedric.toncanier.compteurvelo;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;

public abstract class DAOBase {
	
	// Version DB
	protected final static int VERSION = 1;
	
	// Name of the File of the DB
	protected final static String NOM = "database.db";	

	protected SQLiteDatabase mDb = null;
	protected DatabaseHandler mHandler = null;
	  
	public DAOBase(Context pContext) {
		this.mHandler = new DatabaseHandler(pContext, NOM, null, VERSION);
	}
	
	public SQLiteDatabase open() {
	    // Pas besoin de fermer la dernière base puisque getWritableDatabase s'en charge
	    mDb = mHandler.getWritableDatabase();
	    return mDb;
	  }
	    
	  public void close() {
	    mDb.close();
	  }
	    
	  public SQLiteDatabase getDb() {
	    return mDb;
	  }  
}
