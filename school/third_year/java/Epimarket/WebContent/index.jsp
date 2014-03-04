<?xml version="1.0" encoding="ISO-8859-1" ?>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<%@page import="java.util.ArrayList"%><html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr">
<head>
<title>JAVA - EpiMarket</title>
<meta name="Description" content="Description courte de votre activité" />
<meta name="Keywords" content="1 ou deux mots clés" />
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link rel="stylesheet" type="text/css" href="style.css" />
</head>

<body>
<%@ page import="epi.tp2.*"	%>
<jsp:useBean id="db" scope="page" class="epi.tp2.DBManager"></jsp:useBean>
<jsp:useBean id="fact" scope="page" class="epi.tp2.Factory"></jsp:useBean>
<% 
db.dbConnect();
fact.setConnect(db.myConnect); 
ArrayList<Object> list = new  ArrayList<Object>();
list = fact.readHeavy();
fact.setList(list);
request.setAttribute("factory", fact);
ArrayList<Categorie> cat = fact.getCategories();
%>

<div id="site">
<div id="header">

<h1><a href="#">EpiMarket</a></h1>

</div>
<div id="content">
<div id="centrage">
<div id="menu">
<ul>
<li><a href="index.jsp">Home</a></li>
<li><a href="index.jsp?page=profil">Profil</a></li>
<li><a href="index.jsp?page=panier">Panier</a></li>
<li><a href="index.jsp?page=contact">Contact</a></li>

<li><form method="post" id="form_search" action="index.jsp?page=search"><input type="text" value="rechercher" name="search" id="search" /> <input type="submit" value="Go !" /></form></li>
</ul>
</div>
<div id="side">

<h2>Connection</h2>

<%
	session = request.getSession();
	//String str = request.getParameter("login");
	if(session == null || (session.getAttribute("login")) == null)
	{
		out.print("<div id=\"lol\"><form method=\"post\" id=\"form_login\" action=\"index.jsp?page=login\">" +
				"<input type=\"text\" id=\"login\" name=\"login\" value=\"login\" /><br />"+
				"<input type=\"password\" id=\"pass\" name=\"pass\" value=\"pass\" /><br /><br />" +
				"<input type=\"submit\" value=\"Connection\" /><br /><br /><br />" +
			"</form><br />Ou <a href=\"index.jsp?page=register\">cliquez ici pour vous inscrire</a></div><p></p>");
	}
	else
	{
		out.print("Bienvenue " + request.getSession().getAttribute("login"));
		out.print("<br /><br /><a href=\"index.jsp?page=logout\">Deconnection</a>");
		//String name = request.getParameter( "login" );
   		//session.setAttribute( "login", name );
	}
%>


<!-- <h2>Articles récents</h2>
<ul>
<li><a href="http://www.e-news.name/">Home</a></li>
<li><a href="http://www.e-news.name/">About</a></li>
<li><a href="http://www.e-news.name/">Page Test</a></li>

</ul>-->


<h2><a href="index.jsp?page=categorie">Catégories</a></h2>
<ul>
<% 
	for (int i = 0; i < cat.size(); i++)
		out.print("<li><a href=\"index.jsp?page=categorie&catid=" + cat.get(i).getId() + "\">" + cat.get(i).getNom() + "</a></li>");
%>
</ul>

<%
if (session.getAttribute("admin") != null)
{
	String adm = session.getAttribute("admin").toString();
	Integer admin = Integer.parseInt(adm);
	if (admin == 1)
	{
%>
<h2>Admin</h2>

<ul>
<li><a href="#">Gestion Utilisateurs</a></li>
<li><a href="#">Gestion Produits</a></li>
<li><a href="#">Gestion Categories</a></li>
<li><a href="#">Statistiques</a></li>
</ul>
<% } } %>

</div>



<!-- <h1>Bienvenue sur notre site</h1>

<p id="titre">J'ai décidé d'être heureux parce que c'est bon pour la santé.</p>-->


<div id="contenu">
<% 
				String p = request.getParameter("page");
				
				if (p == null)
					p = "welcome.jsp";
				else if (p != null && !p.equals("")){
					p += ".jsp";
				}
				
				/* TODO : Tester si page existe */
			%>
			<jsp:include page="<%=p%>" />




</div>

<div id="side-left">

<%
	session = request.getSession();
	if(session != null && (session.getAttribute("login")) != null)
	{
		%>
<h2>Panier</h2>

<ul>
<li class="rest">Vous avez item dans votre panier</li>
<li class="rest">&nbsp</li>
<li class="rest">Total de la commande :  &euro</li>
<li class="pdf"><a href="#">Convertir en pdf</a></li>
</ul>

<%} %>
</div>
</div>
</div>

<div id="footer">

<p><a href="#">EpiMarket</a> | Design By Myself  </p>

</div>
</div>

<% db.dbClose(); %>
</body>
</html>