package epi.tp2;

public class Users {

	private Integer		Id;
	private String 		Login;
	private String 		Pass;
	private String 		Mail;
	private String		Nom;
	private String 		Prenom;
	private String		Adresse;
	private String		Pays;
	private Integer		Rang;
	
	public Users(){
		
	}

	public Integer getId() {
		return Id;
	}

	public void setId(Integer id) {
		Id = id;
	}

	public String getLogin() {
		return Login;
	}

	public void setLogin(String login) {
		Login = login;
	}

	public String getPass() {
		return Pass;
	}

	public void setPass(String pass) {
		Pass = pass;
	}

	public String getMail() {
		return Mail;
	}

	public void setMail(String mail) {
		Mail = mail;
	}

	public String getNom() {
		return Nom;
	}

	public void setNom(String nom) {
		Nom = nom;
	}

	public String getPrenom() {
		return Prenom;
	}

	public void setPrenom(String prenom) {
		Prenom = prenom;
	}

	public String getAdresse() {
		return Adresse;
	}

	public void setAdresse(String adresse) {
		Adresse = adresse;
	}

	public String getPays() {
		return Pays;
	}

	public void setPays(String pays) {
		Pays = pays;
	}

	public Integer getRang() {
		return Rang;
	}

	public void setRang(Integer rang) {
		Rang = rang;
	}
}
