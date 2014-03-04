<%@ page import="epi.tp2.*" import="java.util.*" %>
<% Factory fact = ((Factory) request.getAttribute("factory")); %>
<% 
if (session.getAttribute("login") != null)
{
	ArrayList<Object> lst = fact.readLight("Users");
	Users use = new Users();
	for (int i = 0; i < lst.size(); i++)
	{
		use = ((Users)lst.get(i));
		if (use.getId() == session.getAttribute("id"))
		{
			break;
		}
	}
	if (request.getParameter("mail") == null)
	{
%>
<form method=post name="forminscrip" action="index.jsp?page=profil">
	<FIELDSET align="center">
		<LEGEND>Profil</LEGEND>
		<LABEL FOR="login">Login </LABEL><br />
		<input type="text" id="login" name="login" value="<%= use.getLogin() %>" /><br /><br /> 
		<LABEL FOR="pass">Pass </LABEL><br />
		<input type="password" id="pass" name="pass" value="<%= use.getPass() %>" /><br /><br /> 
		<LABEL FOR="confpass">Confirmation Password </LABEL><br />
		<input type="password" id="confpass" name="confpass" value="<%= use.getPass() %>" /><br /><br />
		<LABEL FOR="mail">Email </LABEL><br />
		<input type="text" id="mail" name="mail" value="<%= use.getMail() %>" /><br /><br />
		<LABEL FOR="nom">Nom </LABEL><br />
		<input type="text" id="nom" name="nom" value="<%= use.getNom() %>" /><br /><br />
		<LABEL FOR="prenom">Prenom </LABEL><br />
		<input type="text" id="prenom" name="prenom" value="<%= use.getPrenom() %>" /><br /><br />
		<LABEL FOR="adresse">Adresse </LABEL><br />
		<input type="text" id="adresse" name="adresse" value="<%= use.getAdresse() %>" /><br /><br />
		<LABEL FOR="pays">Pays </LABEL><br />
		<input type="text" id="pays" name="pays" value="<%= use.getPays() %>" /><br /><br />
		<input type="submit" id="send" value="Inscription" /><br />
	</FIELDSET>
</form>

<%
	}
	
	else
	{
		if (request.getParameter("pass").equals(request.getParameter("confpass")))
		{
			use.setPass(request.getParameter("pass"));
			use.setMail(request.getParameter("mail"));
			use.setNom(request.getParameter("nom"));
			use.setPrenom(request.getParameter("prenom"));
			use.setAdresse(request.getParameter("adresse"));
			use.setPays(request.getParameter("pays"));
			fact.update(use);
		}
		
%>
Vos information on bien ete modifiees ! <br /><a href="index.jsp?page=profil">Retourner a votre profil</a>
<%
	} 
}
else
	out.print("Vous devez vous connecter pour afficher votre profil !");
%>