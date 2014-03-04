	function	submit()
	{
		var login = document.getElementById("login").value;
		var password = document.getElementById("password").value;
		if (login == "")
		{
			document.getElementById("log1").style.color='#DA3838';
			return false;
		}
		else
			document.getElementById("log1").style.color='#777';
		if (password == "")
		{
			document.getElementById("log2").style.color='#DA3838';
			return false;
		}
		else
			document.getElementById("log1").style.color='#777';
		if (login != "" && password != "")
			document.location.replace("fonctions/admin.php?login="+login+"&pwd="+password);
	}

	function	edit_user(name)
	{
		alert(name);
		document.getElementById(name).submit();
	}
	
	function	display(id)
	{
		if (document.getElementById(id).style.display=="none" || document.getElementById(id).style.display=="")
			document.getElementById(id).style.display="block";
		else
			document.getElementById(id).style.display="none";
		return (0);
	}
	
	function	set_reset(ids)
	{
		tab = ids.split(';');
		
		var i = 0;
		while (i < tab.length)
		{
			document.getElementById(tab[i]).value="";
			i++;
		}
	}

	function	add_admin()
	{
		var flag = 0;
		if (document.getElementById('login_a').value=="")
		{
			document.getElementById('login').style.color="#DA3838";
			flag = 1;
		}
		else
			document.getElementById('login').style.color="#777";	
			
		if (document.getElementById('password_a').value=="")
		{
			document.getElementById('password').style.color="#DA3838";
			flag = 1;
		}
		else
			document.getElementById('password').style.color="#777";
			
		if (document.getElementById('ip_a').value=="")
		{
			document.getElementById('ip').style.color="#DA3838";
			flag = 1;
		}
		else
			document.getElementById('ip').style.color="#777";
			
		if (flag == 1)
			return false;
		else
			document.getElementById("form_a").submit();		
	}
	
	function	delete_admin(id, name, right)
	{
		if (right == '0')
			right = 'Administrateur';
		else
			right = 'Moderateur';
			
		if (window.confirm('Etes vous sur de vouloir supprimer le compte '+right+': '+name+' ?'))
			document.location.replace("includes/include_del_admin.php?id="+id);
		else
			return (false);
	}
	
	function	del_news(id)
	{
		if (window.confirm('Etes vous sur de vouloir supprimer cette news ?'))
			document.location.replace("includes/include_del_news.php?id="+id);
		else
			return (false);
	}
	
	function	verif_add_menu()
	{
		if (document.getElementById('nom_menu').value==""){
			document.getElementById('name').style.color='#DA3838';
			return false;
		}if (document.getElementById('pager_menu').value==""){
			document.getElementById('pager').style.color='#DA3838';
			return false;
		}else{
			document.getElementById('name').style.color='#777';
			document.getElementById('pager').style.color='#777';
			document.getElementById('form_a').submit();
		}
	}
	
	function	verif_edit_menu(id)
	{
		if (document.getElementById('nom_menu'+id).value==""){
			document.getElementById('name'+id).style.color='#DA3838';
			return false;
		}if (document.getElementById('pager_menu'+id).value==""){
			document.getElementById('pager'+id).style.color='#DA3838';
			return false;
		}else{
			document.getElementById('name'+id).style.color='#777';
			document.getElementById('pager'+id).style.color='#777';
			document.getElementById('edit_menu'+id).submit();
		}
	}

	
	function	add_faq()
	{
			if (!document.getElementById('question').value && !document.getElementById('reponse').value)
			{
				document.getElementById('t_question').style.color="#DA3838";
				document.getElementById('t_reponse').style.color="#DA3838";
			}
			else
			{
				document.getElementById('t_question').style.color="#777";
				document.getElementById('t_reponse').style.color="#777";
				document.getElementById("form_a").submit()
			}
	}