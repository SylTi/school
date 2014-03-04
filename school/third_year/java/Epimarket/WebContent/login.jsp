
<%@page import="java.util.ArrayList"%><%@ page import="epi.tp2.*" %>
<% Factory fact = ((Factory) request.getAttribute("factory")); %>
<%

if (session.getAttribute("login") == null)
{
	if (request.getParameter("login") != null && request.getParameter("pass") != null)
	{
		String login = request.getParameter("login");
		String pass = request.getParameter("pass");
		ArrayList<Object> lst = fact.readLight("Users");
		
		int ok = 0;
		for (int i = 0; i < lst.size(); i++)
		{
			Users use = new Users();
			use = ((Users)lst.get(i));
			if (use.getLogin().equalsIgnoreCase(login) && use.getPass().equals(pass))
			{
				out.print("Connection reussie !");
				request.getSession().setAttribute("login", login);
				request.getSession().setAttribute("id", use.getId());
				request.getSession().setAttribute("admin", use.getRang());
				ok = 1;
				break;
			}
		}
		if (ok != 1)
			out.print("L'utilisateur n'existe pas ou le mot depasse est incorrect");
	}
}
else
	out.print("Vous etes deja connecte !");
%>