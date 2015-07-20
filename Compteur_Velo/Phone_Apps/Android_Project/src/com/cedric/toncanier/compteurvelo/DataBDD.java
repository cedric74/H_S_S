package com.cedric.toncanier.compteurvelo;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class DataBDD {
	private static final int VERSION_BDD 		= 2;
	private static final String NOM_BDD 		= "Data_Trip.db";
	private static final String TABLE_TRIP 		= "table_trips";
	private static final String COL_ID 			= "Id";
	private static final int NUM_COL_ID 		= 0;
	private static final String COL_SPEED 		= "Speed";
	private static final int NUM_COL_SPEED 		= 1;
	private static final String COL_DISTANCE 	= "Distance";
	private static final int NUM_COL_DISTANCE 	= 2;
	private static final String COL_TIME 		= "Time";
	private static final int NUM_COL_TIME 		= 3;
	private static final String COL_DATE 		= "Date";
	private static final int NUM_COL_DATE 		= 4;
	
	private SQLiteDatabase bdd; 
	private DatabaseHandler maBaseSQLite;
 
	public DataBDD(Context context){
		//On créer la BDD et sa table
		maBaseSQLite = new DatabaseHandler(context, NOM_BDD, null, VERSION_BDD);
	}
 
	public void open(){
		//on ouvre la BDD en écriture
		bdd = maBaseSQLite.getWritableDatabase();
	}
 
	public void close(){
		//on ferme l'accès à la BDD
		bdd.close();
	}
 
	public SQLiteDatabase getBDD(){
		return bdd;
	}
 
	public long insertTrip(Data dData){
		//Création d'un ContentValues (fonctionne comme une HashMap)
		ContentValues values = new ContentValues();
		//on lui ajoute une valeur associé à une clé (qui est le nom de la colonne dans laquelle on veut mettre la valeur)
		//values.put(COL_ID, dData.getlId());
		values.put(COL_SPEED, dData.getfSpeed());
		values.put(COL_DISTANCE, dData.getfDistance());
		values.put(COL_TIME, dData.getsTime());
		values.put(COL_DATE, dData.getsDate());
		//on insère l'objet dans la BDD via le ContentValues
		
		return bdd.insert(TABLE_TRIP, null, values);
	}
 
	public int updateData(int id, Data dData){
		//TODO
		//La mise à jour d'un livre dans la BDD fonctionne plus ou moins comme une insertion
		//il faut simple préciser quelle livre on doit mettre à jour grâce à l'ID
		/*ContentValues values = new ContentValues();
		values.put(COL_ISBN, livre.getIsbn());
		values.put(COL_TITRE, livre.getTitre());
		return bdd.update(TABLE_TRIP, values, COL_ID + " = " +id, null);*/
		
		return 0;
	}
 
	public int removeTripWithID(int id){
		return bdd.delete(TABLE_TRIP, COL_ID + " = " +id, null);
	}
 
	public Data getTripWithDate(String sDate){
		Cursor c = bdd.query(TABLE_TRIP, new String[] {COL_ID, COL_SPEED, COL_DISTANCE, COL_TIME, COL_DATE}, COL_DATE + " LIKE \"" + sDate +"\"", null, null, null, null);
		return cursorToData(c);
	}
 
	//Cette méthode permet de convertir un cursor en un livre
	private Data cursorToData(Cursor c){
		//si aucun élément n'a été retourné dans la requête, on renvoie null
		if (c.getCount() == 0)
			return null;
 
		//Sinon on se place sur le premier élément
		c.moveToFirst();
		//On créé un livre
		Data dData = new Data();
		//on lui affecte toutes les infos grâce aux infos contenues dans le Cursor
		dData.setlId(c.getInt(NUM_COL_ID));
		dData.setfSpeed(c.getFloat(NUM_COL_SPEED));
		dData.setfDistance(c.getFloat(NUM_COL_DISTANCE));
		//dData.setsTime();
		//dData.setsDate();
		
		//On ferme le cursor
		c.close();
 
		//On retourne le livre
		return dData;
	}
}
