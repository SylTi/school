package epi.tp2;

public class Produit {

	private Integer		Id;
	private String		Nom;
	private String		Description;
	private Integer		Dispo;
	private Double		Prix;
	private Integer		cat;

	
	public Produit() {

	}

	public Integer getId() {
		return Id;
	}

	public void setId(Integer id) {
		Id = id;
	}

	public String getNom() {
		return Nom;
	}

	public void setNom(String name) {
		Nom = name;
	}

	public String getDescription() {
		return Description;
	}

	public void setDescription(String description) {
		Description = description;
	}

	public Integer getDispo() {
		return Dispo;
	}

	public void setDispo(Integer dispo) {
		Dispo = dispo;
	}

	public Double getPrix() {
		return Prix;
	}

	public void setPrix(Double prix) {
		Prix = prix;
	}
	
	public Integer getCat() {
		return cat;
	}

	public void setCat(Integer cat) {
		this.cat = cat;
	}

}
