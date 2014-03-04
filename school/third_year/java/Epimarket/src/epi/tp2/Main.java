package epi.tp2;

import java.util.ArrayList;

@SuppressWarnings("unused")
public class Main {

	DBManager db;
	public Main() {
		loadManager();

	}
	
	public static void main(String[] args) {
		Main app = new Main();
	}
	
	public void loadManager(){
		db = new DBManager();
		db.dbConnect();		
	}
}
