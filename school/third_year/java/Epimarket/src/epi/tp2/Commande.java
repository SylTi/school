package epi.tp2;

import java.util.ArrayList;

public class Commande {

	private Integer					Id;
	private Integer					userId;
	private String 					prodIds;
	private String 					vals;
	private ArrayList<Integer>		tabProIds = new ArrayList<Integer>();
	private ArrayList<Integer> 		tabVals = new ArrayList<Integer>();
	private Integer					finish;
	
	
	public Commande() {
		
	}
	
	/*public Commande(Integer user, String prodId, String val) {
		this.userId = user;
		this.prodIds = prodId;
		this.vals = val;
	}*/
	
/*	public Commande(Integer user, String[] tabId, String[] tabVal) {
		this.userId = user;
		this.tabProIds = tabId;
		this.tabVals = tabVal;
	}*/

	public Integer getId() {
		return Id;
	}

	public void setId(Integer id) {
		Id = id;
	}

	public Integer getUserId() {
		return userId;
	}

	public void setUserId(Integer userId) {
		this.userId = userId;
	}

	public String getProdIds() {
		return prodIds;
	}

	public void setProdIds(String prodIds) {
		this.prodIds = prodIds;
		sTabProIds();
		/*if(prodIds.contains(","))
		{
			System.out.println(prodIds);
			String[] tab = prodIds.split(",");
			for (int i = 0; i < tab.length; i++)
			{
				if (i != (tab.length-1))
				{
					Integer l = new Integer(tab[i].trim());
					tabProIds.add(l);
				}
			}
		}*/
	}

	public String getVals() {
		return vals;
	}

	public void setVals(String vals) {
		this.vals = vals;
		sTabVals();
	}

	public ArrayList<Integer> gTabProIds() {
		return tabProIds;
	}

	public void sTabProIds() {
		if(prodIds.contains(","))
		{
			String[] tab = prodIds.split(",");
			for (int i = 0; i < tab.length; i++)
			{
				if (i != (tab.length-1))
				{
					Integer l = new Integer(tab[i].trim());
					tabProIds.add(l);
				}
			}
		}
	}

	public ArrayList<Integer> gTabVals() {
		return tabVals;
	}

	public void sTabVals() {
		if (vals.contains(","))
		{
			String[] tab = vals.split(",");
			for (int i = 0; i < tab.length; i++)
			{
				if (i != (tab.length-1))
				{
				Integer l = new Integer(tab[i].trim());
				tabVals.add(l);
				}
			}
		}
		
	}
	
	public Integer getFinish() {
		return finish;
	}

	public void setFinish(Integer finish) {
		this.finish = finish;
	}
	
	public void addToPanier(Integer itemId, Integer itemNb)
	{
		int ok = 0;
		for (int i = 0; i < tabProIds.size(); i++)
		{
			System.out.println("ItemId = "+itemId+ "tabProId = " + tabProIds.get(i));
			if (tabProIds.get(i).equals(itemId))
			{
				ok = 1;
				tabVals.set(i, tabVals.get(i)+1);
				break;
			}
			
		}
		if (ok == 0)
		{
			tabProIds.add(itemId);
			tabVals.add(itemNb);
		}
		String ids = new String(prodIds);
		for (int i = 0; i < tabProIds.size(); i++)
		{
			if (i < tabProIds.size())
				ids += tabProIds.get(i)+ ", ";
			/*else
				ids += tabProIds.get(i);*/
		}
		setProdIds(ids);
		
		String val = new String(vals);
		for (int i = 0; i < tabVals.size(); i++)
		{
			if (i < tabVals.size())
				val += tabVals.get(i)+ ", ";
			/*else
				val += tabVals.get(i);*/
		}
		setVals(val);
	}
	
	public void deleteFromPanier(Integer itemId)
	{
		tabProIds.remove(itemId);
		tabVals.remove(itemId);
		String ids = new String(/*prodIds*/);
		for (int i = 0; i < tabProIds.size(); i++)
		{
			if (i < tabProIds.size())
				ids += tabProIds.get(i)+ ", ";
			/*else
				ids += tabProIds.get(i);*/
		}
		//setProdIds(ids);
		String val = new String(vals);
		for (int i = 0; i < tabVals.size(); i++)
		{
			if (i < tabVals.size())
				val += tabVals.get(i)+ ", ";
			/*else
				val += tabVals.get(i);*/
		}
		//setVals(val);
	}
	
	public void updateItem(Integer itemId, Integer itemNb)
	{
		
	}
}
