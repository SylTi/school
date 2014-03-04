<%@page import="java.util.ArrayList"%><%@ page import="epi.tp2.*" %>
<% Factory fact = ((Factory) request.getAttribute("factory")); %>

<table>
	<th>Image</th>
	<th>Nom</th>
	<th>Prix</th>
<% 
if (request.getParameter("search") != null)
{
	System.out.println(request.getParameter("search").toString());
	String str = new String(request.getParameter("search"));
	
	//str = request.getParameter("Search").toString();
	ArrayList<Produit> resSearch = fact.search(str.toLowerCase());
	//System.out.println(request.getParameter("Search").toLowerCase());
	for (int i = 0; i < resSearch.size(); i++)
	{
		System.out.println("res = "+resSearch.get(i)+" name ="+resSearch.get(i).getNom());
		

%>

	<tr>
		<td><img src="images/produits/<%= resSearch.get(i).getId() %>.jpg" width="50px" /></td>
		<td><a href="index.jsp?page=produit&proid=<%= resSearch.get(i).getId() %>"><%= resSearch.get(i).getNom() %></a></td>
		<td><%= resSearch.get(i).getPrix() %></td>
	</tr>

<%
	}
}
%>
</table>