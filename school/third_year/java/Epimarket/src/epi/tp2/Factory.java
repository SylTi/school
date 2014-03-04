package epi.tp2;

import java.lang.reflect.Method;
import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class Factory {

	private Connection				myConnect;	
	private Statement				myState;
	private ResultSet				myResultSet;
	private DatabaseMetaData		myDbMetaData;
	private ResultSetMetaData		myResultSetMetaData;	
	private ArrayList<Object> 		list	= new ArrayList<Object>();
	private String 					STR_PACKAGE_PREFIX	= "epi.tp2"; 
	
	public Factory() {

	}
	
	public Factory(Connection conn) {
		myConnect = conn;
	}
	
	public void setConnect(Connection co) {
		myConnect = co;
	}
	
	public void setList(ArrayList<Object> lst) {
		list = lst;
	}
	
	public ArrayList<Object> readHeavy() {
		try {
			myDbMetaData 			= myConnect.getMetaData();

			
			//4eme etape: creation d'une instruction/formule, socle pour executer des requetes
			myState					= myConnect.createStatement();

		/*	System.out.println("DbManager: dbConnect: show DataBase MetaData:");
			System.out.println("DbManager: dbConnect: productName=" 	+ myDbMetaData.getDatabaseProductName());
			System.out.println("DbManager: dbConnect: productVersion=" 	+ myDbMetaData.getDatabaseProductVersion());*/
		    String[] types = {"TABLE"};
	        ResultSet rs = myDbMetaData.getTables(null,null,"%",types);
	        //System.out.println("Table name:");
	        while (rs.next()){
	          String table = rs.getString("TABLE_NAME");
	          //System.out.println(table);
	          reflectElement(table);
	        }
	      /*  for (int i = 0; i != list.size(); i++)
	        {
	        	System.out.println(list.get(i).toString());
	        }*/
			//etc... de nombreuses autres info sont disponibles
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        return (list);
	}
	
	private void reflectElement(String className)
	{
		//System.out.println("reflectElement: " + className);
		
		try
		{
			Class<?> associatedClass								= Class.forName(STR_PACKAGE_PREFIX + "." + className.substring(0, 1).toUpperCase() + className.substring(1));
			//Class<?> tabParameterTypes[]							= {String.class};
			
			//permet de recuperer un constructeur specifique
			//Constructors tabAssociatedConstructors			= associatedClass.getDeclaredConstructors(tabParameterTypes);
			//Class tabParameterTypes[] = {Class.forName(myResultSetMetaData.getColumnClassName(count))};


			
			myResultSet				= myState.executeQuery("Select * from "+ className + ";");
			myResultSetMetaData		= myResultSet.getMetaData();
			
			//la premiere colonne porte l'index 1, ET NON 0 !!!
			while (myResultSet.next()) 
			{
				Object newInstance									= associatedClass.newInstance();
				for (int index = 0; index != myResultSetMetaData.getColumnCount(); index++) 
				{
					
					Class<?> tabParameterTypes[] = {Class.forName(myResultSetMetaData.getColumnClassName(index+1))};
					String currentAttributeName						= myResultSetMetaData.getColumnName(index+ 1);
					Object currentAttributeValue					= myResultSet.getObject(index + 1);
					String currentMethodName						= "set" + currentAttributeName.substring(0, 1).toUpperCase() + currentAttributeName.substring(1);
					
					Object tabParameterValues[]						= {currentAttributeValue};
			/*	java.lang.reflect.Method[] m = associatedClass.getMethods();
				for (int i = 0; i < m.length; i++)
			          System.out.println(m[i]);*/
					Method associatedSetMethod						= associatedClass.getMethod(currentMethodName, tabParameterTypes);

			
					associatedSetMethod.invoke(newInstance, tabParameterValues);	

					
				}
				list.add(newInstance);
				//System.out.println("NewInstance: " + ((Users) newInstance).getId());
			}
		}
		catch (NoSuchMethodException ex)
        {
            System.out.println("Method either doesn't exist " +
                "or is not public: " + ex.toString());
            
            ex.printStackTrace();
        }

		catch (SQLException e) 				{System.out.println("dbConnect SQLException: " + e.toString()); e.printStackTrace();}	
		catch (Exception e) {System.out.println("reflectElement: " + e.toString()); e.printStackTrace();}
	}
	
	public ArrayList<Object> readLight(String str)
	{
		ArrayList<Object> obj = new ArrayList<Object>();
		
		for (int i = 0; i < list.size(); i++)
		{
			String str1 = list.get(i).getClass().getName().substring(8);
			if ((str1.compareTo(str)) == 0)
				obj.add(list.get(i));
		}
		return (obj);
	}
	
	public void create(Object obj)
	{
		try {
			int d = obj.getClass().getName().lastIndexOf(".");
			String objectType = obj.getClass().getName().substring(d+1);
			ResultSet myResultSet = myState.executeQuery("SELECT MAX(LAST_INSERT_ID(`Id`)) as lastId FROM `" + objectType.toLowerCase() + "`;");
            myResultSet.first();
            String objectId = myResultSet.getString("lastId");
            //System.out.println(objectId);
            Integer objId;
            if (objectId == null)
            	 objId = new Integer(1);
            else
            	objId = new Integer(objectId);
            objId++;
           
            Class<?> associatedClasse = obj.getClass();;
            Class<?> tabParameterTypes1[] = {Integer.class};
            String setterName = "setId";
            Object tabParameterValues1[] = {objId};
            Method associatedSetMethod1 = associatedClasse.getMethod(setterName, tabParameterTypes1);
            associatedSetMethod1.invoke(obj, tabParameterValues1);
            
            
            
			//Integer 	myid = null;
			Class<?> associatedClass								= obj.getClass();
			java.lang.reflect.Method[] m = obj.getClass().getMethods();

			int y = 0;
			String sqlReq = new String ("INSERT INTO ");
			
			sqlReq += objectType + " (" ;//+ champs.get(0) + "=" + "'" + values.get(0) + "'";
			int a = 0;
			for (int b = 0; b < m.length; b++)
				if ((y = m[b].toString().indexOf("get")) > 0 && (m[b].toString().indexOf("getClass")) < 0)
					a++;
			int index = 0;
			while (index < 2)
			{
				int l = 0;
				for (int i = 0; i < m.length; i++)
				{
					if ((y = m[i].toString().indexOf("get")) > 0 && (m[i].toString().indexOf("getClass")) < 0)
					{
			
						String str = new String();
						str = m[i].toString().substring(y);
						int z = 0;
						String str2 = new String();
						while (str.charAt(z) != '(')
						{
							str2 += str.charAt(z); 
							z++;				 
						}
						y = str2.indexOf("get");
						String champ = str2.substring(y+3);
				
						Class<?> tabParameterTypes[] = {};
					
						String currentMethodName						= str2;
						Object tabParameterValues[]						= {};
			
						Method associatedSetMethod						= associatedClass.getMethod(currentMethodName, tabParameterTypes);

						Object value = new Object();
						value = associatedSetMethod.invoke(obj, tabParameterValues);	
						if (l < (a-1) && index == 0)
							sqlReq += champ + ",";
						else if (index == 0)
							sqlReq += champ + ") VALUES(";
						else if (l < (a-1) && index == 1)
							sqlReq += "'" + value + "',";
						else
							sqlReq += "'" + value + "')";
				
						l++;
					}
				}	
				index++;
			}
			System.out.println(sqlReq);
	
			myState.executeUpdate(sqlReq);
			list.add(obj);
		} 
		catch (IndexOutOfBoundsException e) {System.out.println("Array Index problem " + e.toString()); e.printStackTrace();}
		
		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (Exception e) {e.printStackTrace();}
	}
	
	//public void update(String tableName, ArrayList<String> champs, ArrayList<String> values, Object obj)
	public void update(Object obj)
	{
		try {
			Integer 	myid = null;
			Class<?> associatedClass								= obj.getClass();
			java.lang.reflect.Method[] m = obj.getClass().getMethods();

			int y = 0;
			String sqlReq = new String ("UPDATE ");
			int c = obj.getClass().getName().lastIndexOf(".");
			String obj_name = obj.getClass().getName().substring(c+1);
			sqlReq += obj_name + " SET " ;//+ champs.get(0) + "=" + "'" + values.get(0) + "'";
			int a = 0;
			for (int b = 0; b < m.length; b++)
				if ((y = m[b].toString().indexOf("get")) > 0 && (m[b].toString().indexOf("getClass")) < 0)
					a++;
			int l = 0;
			for (int i = 0; i < m.length; i++)
			{
				if ((y = m[i].toString().indexOf("get")) > 0 && (m[i].toString().indexOf("getClass")) < 0)
				{
			
					String str = new String();
					str = m[i].toString().substring(y);
					int z = 0;
					String str2 = new String();
					while (str.charAt(z) != '(')
					{
						str2 += str.charAt(z); 
						z++;				 
					}
					y = str2.indexOf("get");
					String champ = str2.substring(y+3);
				
					Class<?> tabParameterTypes[] = {};
					
					String currentMethodName						= str2;
					Object tabParameterValues[]						= {};
			
					Method associatedSetMethod						= associatedClass.getMethod(currentMethodName, tabParameterTypes);

					Object value = new Object();
					value = associatedSetMethod.invoke(obj, tabParameterValues);	
					if (l < (a-1))
						sqlReq += champ + "='" + value + "', ";
					else
						sqlReq += champ + "='" + value + "' ";
				
					
					if (currentMethodName.equals("getId"))
						 myid = (Integer)value;
				
					l++;
				}
				
			}
			sqlReq += "WHERE Id=" + myid;
			System.out.println(sqlReq);
	
			myState.executeUpdate(sqlReq);
		} 
		catch (IndexOutOfBoundsException e) {System.out.println("Array Index problem " + e.toString()); e.printStackTrace();}
		
		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (Exception e) {e.printStackTrace();}
	}
	
	public void delete(Object obj)
	{
		try {
		Class<?> associatedClass								= obj.getClass();
		int c = obj.getClass().getName().lastIndexOf(".");
		String obj_name = obj.getClass().getName().substring(c+1);
		
		String sqlReq = new String("DELETE FROM ");
		sqlReq += obj_name + " WHERE Id=";
		
		String currentMethodName						= "getId";
		Object tabParameterValues[]						= {};
		Class<?> tabParameterTypes[] = {};

		Method associatedSetMethod						= associatedClass.getMethod(currentMethodName, tabParameterTypes);

		Object value = new Object();
		value = associatedSetMethod.invoke(obj, tabParameterValues);
		
		sqlReq += value;
		System.out.println(sqlReq);
		myState.executeUpdate(sqlReq);
		list.remove(obj);
		}
		catch (IndexOutOfBoundsException e) {System.out.println("Array Index problem " + e.toString()); e.printStackTrace();}
		
		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (Exception e) {e.printStackTrace();}
	}
	
	public ArrayList<Produit> search(String str) {
		ArrayList<Produit> obj_lst = new ArrayList<Produit>();
		Object curr = new Object();
		for (int i = 0; i != list.size(); i++)
		{
			curr = list.get(i);
			if (curr instanceof Produit && ((Produit) curr).getNom().contains(str))
				obj_lst.add((Produit)curr);
			//else if (curr instanceof User)
		}
		
		return obj_lst;
	}
	
	public ArrayList<Produit> search(Integer id) {
		ArrayList<Produit> obj_lst = new ArrayList<Produit>();
		Object curr = new Object();
		for (int i = 0; i != list.size(); i++)
		{
			curr = list.get(i);
			if (curr instanceof Produit && (((Produit) curr).getId() == id))
				obj_lst.add((Produit)curr);
			//else if (curr instanceof User)
		}
		
		return obj_lst;
	}
	
	public ArrayList<Categorie> getCategories() {
		ArrayList<Categorie> obj_lst = new ArrayList<Categorie>();
		Object curr = new Object();
		for (int i = 0; i < list.size(); i++)
		{
			curr = list.get(i);
			if (curr instanceof Categorie)
				obj_lst.add((Categorie)curr);
			//else if (curr instanceof User)
		}
		return (obj_lst);
	}
	
	public ArrayList<Produit> getProduits() {
		ArrayList<Produit> obj_lst = new ArrayList<Produit>();
		Object curr = new Object();
		for (int i = 0; i < list.size(); i++)
		{
			curr = list.get(i);
			if (curr instanceof Produit)
				obj_lst.add((Produit)curr);
			//else if (curr instanceof User)
		}
		return (obj_lst);
	}
}
