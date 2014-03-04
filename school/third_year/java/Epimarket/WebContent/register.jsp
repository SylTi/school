<%@ page import="epi.tp2.*" %>
<% Factory fact = ((Factory) request.getAttribute("factory")); %>
<%
//session = request.getSession();
if (session.getAttribute("login") == null)
{
	//out.print(request.getParameter("login"));
	//out.print("login = "+ request.getParameter("login") + " pass = "+ request.getParameter("pass") +" conf = "+ request.getParameter("confpass"));
	if (request.getParameter("login") != null && request.getParameter("pass") != null && request.getParameter("confpass") != null && request.getParameter("mail") != null )
	{
		String login = request.getParameter("login");
		String pass = request.getParameter("pass");
		String confpass = request.getParameter("confpass");
		String mail = request.getParameter("mail");
		out.println("login = "+ login + " pass = "+pass+" conf = "+confpass);
		if (pass.equals(confpass))
		{
			out.print("Inscription reussi !");
			Users nouveau = new Users();
			
			nouveau.setLogin(login);
			nouveau.setPass(pass);
			nouveau.setMail(mail);
			nouveau.setNom("");
			nouveau.setPrenom("");
			nouveau.setAdresse("");
			nouveau.setPays("");
			nouveau.setRang(0);
			fact.create(nouveau);
			
			request.getSession().setAttribute("login", login);
			request.getSession().setAttribute("id", nouveau.getId());
			request.getSession().setAttribute("admin", nouveau.getRang());
		}
	
			
	}
	else
	{
		out.print("<form method=\"post\" name=\"forminscrip\" action=\"index.jsp?page=register\"><FIELDSET align=\"center\">"+
				"<LEGEND>Inscription</LEGEND>"+
				"<LABEL FOR=\"login\">Login </LABEL><br /><input type=\"text\" id=\"login\" name=\"login\" /><br /><br />" + 
				"<LABEL FOR=\"pass\">Pass </LABEL><br /><input type=\"password\" id=\"pass\" name=\"pass\" /><br /><br />" + 
				"<LABEL FOR=\"confpass\">Confirmation Password </LABEL><br /><input type=\"password\" id=\"confpass\" name=\"confpass\"/><br /><br />" +
				"<LABEL FOR=\"mail\">Email </LABEL><br /><input type=\"text\" id=\"mail\" name=\"mail\"/><br /><br />" +
				"<input type=\"submit\" id=\"send\" value=\"Inscription\" /><br />" +
				"</FIELDSET></form>");	
	}
}
else
	out.print("Vous etes deja logguer vous ne pouvez pas vous reinscrire.");

	
%>