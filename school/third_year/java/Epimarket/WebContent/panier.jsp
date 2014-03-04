<%@page import="java.util.ArrayList"%><%@ page import="epi.tp2.*" %>
<% Factory fact = ((Factory) request.getAttribute("factory")); %>

<%
if (session != null && session.getAttribute("login") != null)
{
	int ok = 0;
	if (request.getParameter("add") != null)
	{
		Integer id = new Integer(request.getParameter("add").toString());
		
		Commande cm = new Commande();
		ArrayList<Object> obj = fact.readLight("Commande");
		if (obj.size() > 0)
		{
		for (int i = 0; i < obj.size(); i++)
		{
			cm = (Commande)obj.get(i);
			Integer s = new Integer(session.getAttribute("id").toString());
			if (cm.getUserId().equals(s))
			{
			ok = 1;
				break;
			}
		}
		if (ok == 1)
		{
			cm.addToPanier(id, new Integer(1));
			fact.update(cm);
		}
		}
		else
		{
			Integer userid = new Integer(session.getAttribute("id").toString());

			cm.setUserId(userid);
			cm.setProdIds(id.toString()+",");
			cm.setVals("1,");
			cm.setFinish(new Integer(0));
			fact.create(cm);
		}
	}
	else
	{
		%>
			<table>
				<th>Image</th>
				<th>Nom</th>
				<th>Quantitee</th>
				<th>Modifier</th>
				<th>Supprimer</th>
						
				
				
		<%
		Commande cm = new Commande();
		ArrayList<Object> obj = fact.readLight("Commande");
		System.out.println(obj);
		if (obj.size() > 0)
		{
			for (int i = 0; i < obj.size(); i++)
			{
				cm = (Commande)obj.get(i);
				Integer s = new Integer(session.getAttribute("id").toString());
				if (cm.getUserId().equals(s))
				{
					ArrayList<Integer> tid = cm.gTabProIds();
					ArrayList<Integer> tval = cm.gTabVals();
					ArrayList<Object> ob = fact.readLight("Produit");
					for (int index = 0; index < tid.size(); index++)
					{
						Integer id = tid.get(index);
						Integer val = tval.get(index);
						for (int y = 0; y < ob.size(); y++)
						{
							Produit prod = (Produit)ob.get(y);
							if (prod.getId().equals(id))
							{
								%>
								<tr>
									<td></td>
									<td><%= prod.getNom() %></td>
									<td><%= val %></td>
								</tr>					

									<%		
								break;
							}
						}
						

					}
					break;
				}
			}
		}
		%>
			</table>
		<%
	}
}
%>