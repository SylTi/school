package epi.tp2;

import java.sql.*;
import java.io.File;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Vector;
import java.util.ArrayList;


import org.xml.sax.Attributes;

@SuppressWarnings("unused")
public class DBManager {
	//Objects specifiques aux differents appels vers les bases (locales ou distantes).	
	public Connection			myConnect;	
	public Statement			myState;
	public ResultSet			myResultSet;

	//Objects de Meta-Information sur la Database connectee, et sur la requete effectuee.
	public DatabaseMetaData		myDbMetaData;
	public ResultSetMetaData	myResultSetMetaData;
	
	public PreparedStatement 	myPreparedStatement;

	public String 				strConnectURL;
	
	@SuppressWarnings("unchecked")
	public Collection			collectionElt;

	public String 				fileName;

	public Object				currentObject;
	
	@SuppressWarnings("unchecked")
	public Collection			currentCollection;
	
	public ArrayList<Object> list	= new ArrayList<Object>();


	public String 				STR_PACKAGE_PREFIX	= "epi.tp2"; 
	

	public DBManager()
	{
		
	}

	//////////////////
	//SQL
	/////////////////
	
	public void dbConnect()
	{
		try
		{	
			//1ere etape: Chargement de la classe de driver, responsable - par contrat d'interfaces - de la connection vers le SGBD
			//Il existe 4 types de driver (I, II, III, IV): 2 locaux, et 2 remote. More infos: http://java.sun.com/jdbc/drivers.html
 			//Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Class.forName("com.mysql.jdbc.Driver");
			
 			//2eme etape: Definition de l'URL de connection
 			//strConnectURL			= "jdbc:odbc:java";
			strConnectURL			= "jdbc:mysql://localhost:3306/epimarket";
 			//ex d'URL permettant le connection distante: "jdbc:JDataConnect://www.domain.com/db-dsn"; 
 			
 			//3eme etape: Creation de l'object de connection
			myConnect 				= DriverManager.getConnection(strConnectURL, "root", "270489");//login & password
		
			//Option: Acces a un jeu de meta information sur la base avec laquelle on dialogue.
			myDbMetaData 			= myConnect.getMetaData();

			
			//4eme etape: creation d'une instruction/formule, socle pour executer des requetes
			myState					= myConnect.createStatement();

			//affmetadatabaseinfo();
			//doquery();
			//affmetabaseinfo();

			//Stockage de l'historique des requetes dans un fichier, histoire d'avoir un backup
			//IoManager.writeFile("Select * from personne;", "queryPerformer.sql", false); 

			

			
			myPreparedStatement 	= myConnect.prepareStatement("Insert into table values(?, ?"); 			
			
		/*	list = readHeavy();
			ArrayList<String> cham = new ArrayList<String>();
			cham.add("login");
			cham.add("Pass");
			cham.add("Mail");
			cham.add("Nom");
			cham.add("Prenom");
			cham.add("Adresse");
			cham.add("Pays");
			cham.add("Rang");
			
			ArrayList<Object> val = new ArrayList<Object>();
			val.add("hugo");
			val.add("test");
			val.add("hugo@klol.com");
			val.add("Laff");
			val.add("32 rue lol");
			val.add("France");
			
			Factory fact = new Factory(myConnect);
			//fact.update("users", cham, val, list.get(0));
			list = fact.readHeavy();
			
			Produit test = new Produit();
			//test.setId(1);
			test.setDispo(0);
			test.setNom("FUCKING JAVA");
			test.setDescription("LOLLLL");
			test.setPrix(1.1);
			test.setCat(1);
			//fact.update(test);
			fact.create(test);
			Users fuck = new Users();
			fuck.setLogin("syl");
			fuck.setMail("blabla@blabla.com");
			fuck.setNom("TISSIER");
			fuck.setPass("270489");
			fuck.setPays("FRANCE");
			fuck.setPrenom("Syvlain");
			fuck.setRang(1);
			fact.create(fuck);
			Categorie cat = new Categorie();
			cat.setNom("ecrans");
			fact.create(cat);
			
			ArrayList<Produit> t= fact.search("JAVA");
			
			for (int i = 0; i != t.size(); i++)
				System.out.println(t.get(i) + t.get(i).getNom());
			
			//myPreparedStatement.setInt(1, 3);
			//myPreparedStatement.setString(2, 'myStrValue');
			
			//myPreparedStatement.executeUpdate();
			//myPreparedStatement.executeQuery();	
			//fact.delete(list.get(7));
			System.out.println("YEAH MAN");*/
		}
		catch (ClassNotFoundException e) 	{System.out.println("dbConnect ClassNotFoundException: " + e.toString()); e.printStackTrace();}	
		catch (SQLException e) 				{System.out.println("dbConnect SQLException: " + e.toString()); e.printStackTrace();}	
		catch (Exception e) 				{System.out.println("dbConnect Exception: " + e.toString()); 	e.printStackTrace();}	
		finally
		{
			/*try {myState.close();}
			catch (java.sql.SQLException e)	{System.out.println("dbDisconnect: close statement: " + e.toString());}
			catch (Exception e)	{System.out.println("dbDisconnect: close statement: " + e.toString());}		
			
			try {myConnect.close();}
			catch (java.sql.SQLException e)	{System.out.println("dbDisconnect: close statement: " + e.toString());}
			catch (Exception e)	{System.out.println("dbDisconnect: close connection: " + e.toString());}		*/
		}
	}

	public void dbClose() {
		try {myState.close();}
		catch (java.sql.SQLException e)	{System.out.println("dbDisconnect: close statement: " + e.toString());}
		catch (Exception e)	{System.out.println("dbDisconnect: close statement: " + e.toString());}		
		
		try {myConnect.close();}
		catch (java.sql.SQLException e)	{System.out.println("dbDisconnect: close statement: " + e.toString());}
		catch (Exception e)	{System.out.println("dbDisconnect: close connection: " + e.toString());}
	}
	//////////////////
	//MISC
	/////////////////
	
	public ArrayList<Object> readHeavy()
	{
		Factory fact = new Factory(myConnect);
		
		ArrayList<Object> list = new ArrayList<Object>();
		list = fact.readHeavy();
		return list;
	}
	
	public Object readLight(String ob)
	{
		Factory fact = new Factory(myConnect);
		Object obj = new Object();
		obj = fact.readLight(ob);
		return obj;
	}
	
	/*public void add(String tableName, ArrayList<String> champs, ArrayList<String> values)
	{
		
	}
	
	private void doquery() {
		//5eme etape: invocation d'une requete (soit une selection stockee dans un ResultSet, soit un update/delete/insert renvoyant le nbr de ligne modifiee(s)).
		try {
			myResultSet				= myState.executeQuery("Select * from users;");
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//int nbrRow			= myState.executeUpdate("Delete from personne where id=2");
	}*/
	
	private void affmetabaseinfo() {
	
		try {
			//Option: Acces a un jeu de meta information sur la base avec laquelle on dialogue.
			myResultSetMetaData		= myResultSet.getMetaData();
			System.out.println("\r\nDbManager: dbConnect: show Query MetaData:");
			
			//la premiere colonne porte l'index 1, ET NON 0 !!!
			for (int index = 0; index != myResultSetMetaData.getColumnCount(); index++) 
			{
				System.out.println("DbManager: dbConnect: MetaInfo: columnName=" + myResultSetMetaData.getColumnName(index + 1) + ", columnType=" + myResultSetMetaData.getColumnTypeName(index + 1));
				//etc... de nombreuses autres info sont disponibles
			}

			System.out.println("\r\nDbManager: dbConnect: show Query Data:");
			
	/*		//6eme etape: parcours du resultSet et de ses donnees.
			while (myResultSet.next()) //incremente aussi l'index pour la lecture des donnees
			{
				//la premiere colonne porte l'index 1, ET NON 0 !!!
				System.out.println("DbManager: dbConnect: resultSet 1st column=" 	+ myResultSet.getString(1)); 
				System.out.println("DbManager: dbConnect: resultSet 2nd column=" 	+ myResultSet.getString(2) + "\r\n"); 
				
				//l'object ResultSet peut invoker bon nombre de getters: 
				//getShort, getDouble, getInt, getByte, getBoolean, getBigDecimal, getBinaryStream, getAsciiStream, 
				//getDate, getFloat, getBlob, getClob...						
			}*/
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static String escapeQuote(String strIn)
	{	
		if (strIn == null)
			return "";
		
		String strOut											= "";
		int strLength											= strIn.length();
				
		for (int i = 0; i != strLength; i++)
			strOut												+= (strIn.substring(i, i + 1).equalsIgnoreCase("'"))? "''" : strIn.substring(i, i + 1);
		
		return strOut;
	}	
	
	public static String upFirst(String value) {
		if (value == null) {
			return null;
		}
		if (value.length() == 0) {
			return value;
		}
		StringBuilder result = new StringBuilder(value);
		result.replace(0, 1, result.substring(0, 1).toUpperCase());
		return result.toString();
	}

}
