<%@page import="java.util.ArrayList"%><%@ page import="epi.tp2.*" %>
<% Factory fact = ((Factory) request.getAttribute("factory")); %>

<%
ArrayList<Produit> prod = fact.getProduits();
ArrayList<Categorie> cat = fact.getCategories();
out.print("<table align='center'>" +
		"<th>Produit</th><th>Categorie</th><th>Prix</th><th>Disponibilite</th>");
if (request.getParameter("catid") == null)
{
	for (int i = 0; i < prod.size(); i++)
	{
		out.print("<tr>");
		out.print("<td><a href=\"index.jsp?page=produit&proid=" + prod.get(i).getId() + "\">" + prod.get(i).getNom()+" </a></td>");
		for (int y = 0; y < cat.size(); y++)
		{
			if (cat.get(y).getId() == prod.get(i).getCat())
				out.print("<td>"+cat.get(y).getNom()+"</td>");
		}
		String str = new String();
		if (prod.get(i).getDispo() == 1)
			str = "<img src=\"images/accept.png\" />";
		else
			str = "<img src=\"images/cancel.png\" />";
		out.print("<td>" + prod.get(i).getPrix() + "</td>" + 
				"<td>" + str + "</td>" +
				"</tr>");
	}
}
else
{
	String reqId = request.getParameter("catid");

	for (int i = 0; i < prod.size(); i++)
	{
		if (prod.get(i).getCat().equals(Integer.parseInt(reqId)))
		{
			out.print("<tr>");
			out.print("<td><a href=\"index.jsp?page=produit&proid=" + prod.get(i).getId() + "\">" + prod.get(i).getNom()+" </a></td>");
			for (int y = 0; y < cat.size(); y++)
			{

				if (cat.get(y).getId() == prod.get(i).getCat())
					out.print("<td>"+cat.get(y).getNom()+"</td>");
			}
			String str = new String();
			if (prod.get(i).getDispo() == 1)
				str = "<img src=\"images/accept.png\" />";
			else
				str = "<img src=\"images/cancel.png\" />";
			out.print("<td>" + prod.get(i).getPrix() + "</td>" + 
					"<td>" + str + "</td>" +
					"</tr>");
		}
	}
}
	
	out.print("</table>");
%>

<%--
ArrayList<Categorie> cat = fact.getCategories();
for (int i = 0; i < cat.size(); i++)
	out.print("<li><a href=\"index.jsp?page=categorie&id=" + cat.get(i).getId() + "\">" + cat.get(i).getNom() + "</a></li>");
--%>
