<%@page import="java.util.ArrayList"%><%@ page import="epi.tp2.*" %>
<% 
if (request.getParameter("proid") != null);
{
	
	Factory fact = ((Factory) request.getAttribute("factory")); 
	ArrayList<Produit> prods = fact.getProduits();

	Produit prod = new Produit();
	for (int i = 0; i < prods.size(); i++)
	{
		if (prods.get(i).getId() == Integer.parseInt(request.getParameter("proid")))
		{
			prod = prods.get(i);
			break;	
		}
	}

%>

<div id="prodimg"><img src="images/produits/<%= prod.getId() %>.jpg" /></div>
<div id="prodname"><%= prod.getNom() %></div>
<div id="prodesc"><%= prod.getDescription() %></div>
<div id="prodprix">Prix TTC <%= prod.getPrix() %> &euro;</div>
<% 
if(session.getAttribute("login") != null)
{
%>
<div id="prodadd"><a href="index.jsp?page=panier&add=<%= prod.getId() %>"><img src="images/add.png" border="0" /> Ajouter au panier</a></div>
<% }%>
<!--<table>
	<tr>
		<td><img src="images/produits/<%= prod.getId() %>.jpg" /></td>
		<td><b><%= prod.getNom() %></b></td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td><%= prod.getDescription() %></td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td><%= prod.getPrix() %></td>
	</tr>
</table>
-->

<%
}
%>