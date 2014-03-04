var cheat="";
var cheat2="";

function opacity(id, opacStart, opacEnd, millisec) {
	//speed for each frame
	var speed = Math.round(millisec / 100);
	var timer = 0;
	if(opacStart > opacEnd) {
		for(i = opacStart; i >= opacEnd; i--) {
			setTimeout("changeOpac(" + i + ",'" + id + "')",(timer * speed));
			timer++;
		}
	} else if(opacStart < opacEnd) {
		for(i = opacStart; i <= opacEnd; i++) {
			setTimeout("changeOpac(" + i + ",'" + id + "')",(timer * speed));
			timer++;
		}
	}
}


function changeOpac(opacity, id) {
	var object = document.getElementById(id).style;
	object.opacity = (opacity / 100);
	object.MozOpacity = (opacity / 100);
	object.KhtmlOpacity = (opacity / 100);
	object.filter = "alpha(opacity=" + opacity + ")";
}

function	verif()
{
	var flag = 0;
	if (document.getElementById("log").value == "" || document.getElementById("log").value == "Login ...")
	{
		flag = 1;
		document.getElementById("log").style.borderColor="#941515";
	}
	else
	document.getElementById("log").style.borderColor="#000000";

	if (document.getElementById("pwd").value == "" || document.getElementById("pwd").value == "Password")
	{
		flag = 1;
		document.getElementById("pwd").style.borderColor="#941515";
	}
	else
	document.getElementById("pwd").style.borderColor="#000000";
	if (flag == 1)
	return false;
	else
	document.getElementById("login").submit();
}

function	freeable(string, valeur, id, ev)
{
	if (ev == "click")
	{
		if (valeur == string)
		document.getElementById(id).value="";
	}
	else
	{
		if (valeur == "")
		document.getElementById(id).value=string;
	}
}

function	favoris()
{
	if (navigator.appName != 'Microsoft Internet Explorer')
	window.sidebar.addPanel("PSYNES :: Techweb","http://dotslashe.dyndns.org/dev/techweb/","");
	else
	window.external.AddFavorite("http://dotslashe.dyndns.org/dev/techweb/","SPYNES :: Techweb");
}

function	printw()
{
	window.print();
}

function	enreg(){
	var flag = 0;

	if (document.getElementById("login").value=="")
	{
		flag = 1
		document.getElementById("login").style.borderBottomColor="#900";
	}
	else
	document.getElementById("login").style.borderBottomColor="#000";

	if (document.getElementById("password_2").value!=document.getElementById("password").value)
	{
		flag = 1;
		document.getElementById("password").style.borderBottomColor="#939";
		document.getElementById("password_2").style.borderBottomColor="#939";
	}

	else
	{
		document.getElementById("password").style.borderBottomColor="#000";
		document.getElementById("password_2").style.borderBottomColor="#000";
	}

	if (document.getElementById("password").value=="")
	{
		flag = 1;
		document.getElementById("password").style.borderBottomColor="#900";
	}
	else
	{
		document.getElementById("password").style.borderBottomColor="#000";
	}

	if (document.getElementById("password_2").value=="")
	{
		flag = 1;
		document.getElementById("password_2").style.borderBottomColor="#900";
	}
	else
	document.getElementById("password_2").style.borderBottomColor="#000";

	if ((document.getElementById("password_2").value!= "" && document.getElementById("password").value !="") && document.getElementById("password_2").value == document.getElementById("password").value)
	{
		document.getElementById("password").style.borderBottomColor="#000";
		document.getElementById("password_2").style.borderBottomColor="#000";
	}
	else
	{
		if (document.getElementById("password_2").value== "" && document.getElementById("password").value =="")
		{
			flag = 1;
			document.getElementById("password").style.borderBottomColor="#900";
			document.getElementById("password_2").style.borderBottomColor="#900";
		}
		else
		{
			flag = 1;
			document.getElementById("password").style.borderBottomColor="#939";
			document.getElementById("password_2").style.borderBottomColor="#939";
		}
	}

	if (document.getElementById("mail").value=="")
	{
		flag = 1;
		document.getElementById("mail").style.borderBottomColor="#900";
	}
	else
	document.getElementById("mail").style.borderBottomColor="#000";

	if (document.getElementById("mail_2").value=="")
	{
		flag = 1;
		document.getElementById("mail_2").style.borderBottomColor="#900";
	}
	else
	document.getElementById("mail_2").style.borderBottomColor="#000";

	if ((document.getElementById("mail_2").value!= "" && document.getElementById("mail").value !="") && document.getElementById("mail_2").value == document.getElementById("mail").value)
	{
		document.getElementById("mail").style.borderBottomColor="#000";
		document.getElementById("mail_2").style.borderBottomColor="#000";
	}
	else
	{
		if (document.getElementById("mail_2").value== "" && document.getElementById("mail").value =="")
		{
			flag = 1;
			document.getElementById("mail").style.borderBottomColor="#900";
			document.getElementById("mail_2").style.borderBottomColor="#900";
		}
		else
		{
			flag = 1;
			document.getElementById("mail").style.borderBottomColor="#939";
			document.getElementById("mail_2").style.borderBottomColor="#939";
		}
	}

	if (document.getElementById("nom").value=="")
	{
		flag = 1;
		document.getElementById("nom").style.borderBottomColor="#900";
	}
	else
	document.getElementById("nom").style.borderBottomColor="#000";

	if (document.getElementById("prenom").value=="")
	{
		flag = 1;
		document.getElementById("prenom").style.borderBottomColor="#900";
	}
	else
	document.getElementById("prenom").style.borderBottomColor="#000";

	if (document.getElementById("location").value=="")
	{
		flag = 1;
		document.getElementById("location").style.borderBottomColor="#900";
	}
	else
	document.getElementById("location").style.borderBottomColor="#000";

	if (document.getElementById("birth").value=="")
	{
		flag = 1;
		document.getElementById("birth").style.borderBottomColor="#900";
	}
	else
	{
		var reg = new RegExp('^[0-9]{2}/[0-9]{2}/[0-9]{4}$', 'i');

		if(reg.test(document.getElementById("birth").value))
		document.getElementById("birth").style.borderBottomColor="#000";
		else
		{
			flag = 1;
			document.getElementById("birth").style.borderBottomColor="#939";
		}
	}

	if (flag == 1)
	return false;
	else
	enreg_ajax();
}


function	modif(){
	var flag = 0;
	if (document.getElementById("password").value != "" && document.getElementById("password_2").value != ""){
		if (document.getElementById("password_2").value!=document.getElementById("password").value)
		{
			flag = 1;
			document.getElementById("password").style.borderBottomColor="#939";
			document.getElementById("password_2").style.borderBottomColor="#939";
		}

		else
		{
			document.getElementById("password").style.borderBottomColor="#000";
			document.getElementById("password_2").style.borderBottomColor="#000";
		}
		if (document.getElementById("password").value=="")
		{
			flag = 1;
			document.getElementById("password").style.borderBottomColor="#900";
		}
		else
		{
			document.getElementById("password").style.borderBottomColor="#000";
		}

		if (document.getElementById("password_2").value=="")
		{
			flag = 1;
			document.getElementById("password_2").style.borderBottomColor="#900";
		}
		else
		document.getElementById("password_2").style.borderBottomColor="#000";

		if ((document.getElementById("password_2").value!= "" && document.getElementById("password").value !="") && document.getElementById("password_2").value == document.getElementById("password").value)
		{
			document.getElementById("password").style.borderBottomColor="#000";
			document.getElementById("password_2").style.borderBottomColor="#000";
		}
		else
		{
			if (document.getElementById("password_2").value== "" && document.getElementById("password").value =="")
			{
				flag = 1;
				document.getElementById("password").style.borderBottomColor="#900";
				document.getElementById("password_2").style.borderBottomColor="#900";
			}
			else
			{
				flag = 1;
				document.getElementById("password").style.borderBottomColor="#939";
				document.getElementById("password_2").style.borderBottomColor="#939";
			}
		}
	}
	if (document.getElementById("mail").value=="")
	{
		flag = 1;
		document.getElementById("mail").style.borderBottomColor="#900";
	}
	else
	document.getElementById("mail").style.borderBottomColor="#000";

	if (document.getElementById("mail_2").value=="")
	{
		flag = 1;
		document.getElementById("mail_2").style.borderBottomColor="#900";
	}
	else
	document.getElementById("mail_2").style.borderBottomColor="#000";

	if ((document.getElementById("mail_2").value!= "" && document.getElementById("mail").value !="") && document.getElementById("mail_2").value == document.getElementById("mail").value)
	{
		document.getElementById("mail").style.borderBottomColor="#000";
		document.getElementById("mail_2").style.borderBottomColor="#000";
	}
	else
	{
		if (document.getElementById("mail_2").value== "" && document.getElementById("mail").value =="")
		{
			flag = 1;
			document.getElementById("mail").style.borderBottomColor="#900";
			document.getElementById("mail_2").style.borderBottomColor="#900";
		}
		else
		{
			flag = 1;
			document.getElementById("mail").style.borderBottomColor="#939";
			document.getElementById("mail_2").style.borderBottomColor="#939";
		}
	}

	if (document.getElementById("nom").value=="")
	{
		flag = 1;
		document.getElementById("nom").style.borderBottomColor="#900";
	}
	else
	document.getElementById("nom").style.borderBottomColor="#000";

	if (document.getElementById("prenom").value=="")
	{
		flag = 1;
		document.getElementById("prenom").style.borderBottomColor="#900";
	}
	else
	document.getElementById("prenom").style.borderBottomColor="#000";

	if (document.getElementById("location").value=="")
	{
		flag = 1;
		document.getElementById("location").style.borderBottomColor="#900";
	}
	else
	document.getElementById("location").style.borderBottomColor="#000";

	if (document.getElementById("birth").value=="")
	{
		flag = 1;
		document.getElementById("birth").style.borderBottomColor="#900";
	}
	else
	{
		var reg = new RegExp('^[0-9]{2}/[0-9]{2}/[0-9]{4}$', 'i');

		if(reg.test(document.getElementById("birth").value))
		document.getElementById("birth").style.borderBottomColor="#000";
		else
		{
			flag = 1;
			document.getElementById("birth").style.borderBottomColor="#939";
		}
	}

	if (flag == 1)
	return false;
	else
	modif_ajax();
}


function	mail_ajax(){
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				opacity("response", 100, 0, 500);
				document.getElementById("response").innerHTML=xhr.responseText;
				opacity("response", 0, 100, 500);
			}
			else
			document.getElementById("text_1").innerHTML="&nbsp;<br />Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;
		}
		else
		document.getElementById("response").innerHTML="<img src=\"images/loading.gif\" border=\"0\"><span class=\"load_enreg\">Envoi de mail en cours, merci de patienter...</span>";
	};

	var mail = document.getElementById("mail").value;
	var a = document.getElementById("a").value;
	var cc = document.getElementById("cc").value;
	var cci = document.getElementById("cci").value;
	var corps = document.getElementById("corps").value;
	corps = corps.replace(/\n/g, ".ff.");

	xhr.open( "GET", "includes/include_mail.php?mail="+mail+"&a="+a+"&cc="+cc+"&cci="+cci+"&corps="+corps+"",  true);
	xhr.send(null);
}



function	enreg_ajax(){
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				if (xhr.responseText == "login")
				document.getElementById("error_login").innerHTML="<span class='rouge_10'>Ce pseudonyme existe deja</span>";
				else{
					document.getElementById("text_1").innerHTML="<div style=\"clear: both;\"></div><div id=\"subscribe\"></div>";
					opacity("subscribe", 100, 0, 500);
					document.getElementById("subscribe").innerHTML=xhr.responseText;
					opacity("subscribe", 0, 100, 500);
				}
			}
			else
			{
				document.getElementById("text_1").innerHTML="<div style=\"clear: both;\"></div><div id=\"subscribe\"></div>";
				document.getElementById("subscribe").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;
			}
		}
	};

	var login = document.getElementById("login").value;
	var password = document.getElementById("password").value;
	var mail = document.getElementById("mail").value;
	var nom = document.getElementById("nom").value;
	var prenom = document.getElementById("prenom").value;
	var localisation = document.getElementById("location").value;
	var birth = document.getElementById("birth").value;
	var societe = document.getElementById("societe").value;
	var icq = document.getElementById("icq").value;
	var aim = document.getElementById("aim").value;
	var yim = document.getElementById("yim").value;
	var msn = document.getElementById("msn").value;
	var jabber = document.getElementById("jabber").value;
	var site = document.getElementById("site").value;

	xhr.open( "GET", "includes/include_enreg.php?login="+login+"&password="+password+"&mail="+mail+"&nom="+nom+"&prenom="+prenom+"&localisation="+localisation+"&birth="+birth+"&societe="+societe+"&icq="+icq+"&aim="+aim+"&yim="+yim+"&msn="+msn+"&jabber="+jabber+"&site="+site+"",  true);
	xhr.send(null);
}


function	modif_ajax(){
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("text_1").innerHTML="<div style=\"clear: both;\"></div><div id=\"subscribe\"></div>";
				opacity("subscribe", 100, 0, 500);
				document.getElementById("subscribe").innerHTML=xhr.responseText;
				opacity("subscribe", 0, 100, 500);
			}
			else
			{
				document.getElementById("text_1").innerHTML="<div style=\"clear: both;\"></div><div id=\"subscribe\"></div>";
				document.getElementById("subscribe").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;
			}
		}
		else
		{
			document.getElementById("text_1").innerHTML="<div style=\"clear: both;\"></div><div id=\"subscribe\"></div>";
			document.getElementById("subscribe").innerHTML="<img src=\"images/loading.gif\" border=\"0\"><span class=\"load_enreg\">Inscription en cours, merci de patienter "+prenom+"...</span>";
		}
	};

	var password = document.getElementById("password").value;
	var id = document.getElementById("id").value;
	var mail = document.getElementById("mail").value;
	var nom = document.getElementById("nom").value;
	var prenom = document.getElementById("prenom").value;
	var localisation = document.getElementById("location").value;
	var birth = document.getElementById("birth").value;
	var societe = document.getElementById("societe").value;
	var icq = document.getElementById("icq").value;
	var aim = document.getElementById("aim").value;
	var yim = document.getElementById("yim").value;
	var msn = document.getElementById("msn").value;
	var jabber = document.getElementById("jabber").value;
	var site = document.getElementById("site").value;

	xhr.open( "GET", "includes/include_modif.php?id="+id+"&password="+password+"&mail="+mail+"&nom="+nom+"&prenom="+prenom+"&localisation="+localisation+"&birth="+birth+"&societe="+societe+"&icq="+icq+"&aim="+aim+"&yim="+yim+"&msn="+msn+"&jabber="+jabber+"&site="+site+"",  true);
	xhr.send(null);
}



function	mail_to(){
	var flag = 0;

	if (document.getElementById("mail").value == "")
	{
		flag = 1;
		document.getElementById("mail").style.borderBottomColor = "#900";
	}
	else
	{
		var reg = new RegExp('^[a-z0-9]+([_|\.|-]{1}[a-z0-9]+)*@[a-z0-9]+([_|\.|-]­{1}[a-z0-9]+)*[\.]{1}[a-z]{2,6}$', 'i');

		if(reg.test(document.getElementById("mail").value))
		document.getElementById("mail").style.borderBottomColor = "#000";
		else
		{
			flag = 1;
			document.getElementById("mail").style.borderBottomColor = "#939";
		}
	}

	if (document.getElementById("a").value == "")
	{
		flag = 1;
		document.getElementById("a").style.borderBottomColor = "#900";
	}
	else
	document.getElementById("a").style.borderBottomColor = "#000";

	if (document.getElementById("corps").value == "")
	{
		flag = 1;
		document.getElementById("corps").style.borderBottomColor = "#900";
	}
	else
	document.getElementById("corps").style.borderBottomColor = "#000";

	if (flag == 1)
	return false;
	else
	mail_ajax();
}

function	my_recherche(str){
	if (str.length < 3){
		document.getElementById("selection").style.display="none";
		return false;
	}
	if (window.XMLHttpRequest)
	{
		httpRequest = new XMLHttpRequest();
		if (httpRequest.overrideMimeType)
		httpRequest.overrideMimeType('text/xml');
	}
	else if (window.ActiveXObject) { // IE
		try{
			httpRequest = new ActiveXObject("Msxml2.XMLHTTP");
		}
		catch (e) {
			try{
				httpRequest = new ActiveXObject("Microsoft.XMLHTTP");
			}
			catch (e) {}
		}
	}

	if (!httpRequest) {
		alert('Abandon :( Impossible de créer une instance XMLHTTP');
		return false;
	}
	httpRequest.onreadystatechange = function() { use_fck_datas(httpRequest, str); };
	httpRequest.open('GET', 'results.xml', true);
	httpRequest.send(null);
}

function	use_fck_datas(httpRequest, str){
	if (httpRequest.readyState == 4)
	{
		document.getElementById("selection").innerHTML = "";

		var i = 0;
		var xmldoc = httpRequest.responseXML;

		var init = xmldoc.getElementsByTagName('init');
		var data = xmldoc.getElementsByTagName('data');
		if (data.length <= 0)
		document.getElementById("selection").innerHTML = "<span class='texte7'>Aucun resultat n'a ete trouve ...</span>";
		else if (data.length > 0){
			var flag = 0;
			while (i < data.length){
				title = data[i].getElementsByTagName("title");
				titre = title[0].firstChild.nodeValue;
				link_to = data[i].getElementsByTagName("link_to");
				lien = link_to[0].firstChild.nodeValue;
				var reg = new RegExp(str);
				if (reg.test(titre))
				{
					flag = 1;
					document.getElementById("selection").innerHTML += "<span class='texte7' id='"+i+"'>"+titre+" - "+lien+"</span><br />";
				}
				i++;
			}
			if (flag == 0)
			document.getElementById("selection").innerHTML = "<span class='texte7'>Aucun resultat n'a ete trouve ...</span>";
		}
	}else if(httpRequest.readyState != 4){
		document.getElementById("selection").innerHTML = "<img src='images/loading.gif' border='0' height='15'><span class='texte7'>Chargement ...</span>";
	}
}

function	select_sub_proj(id, id_parent){
	cheat = id;
	cheat2 = id_parent;
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				opacity("sprojets", 100, 0, 500);
				document.getElementById("sprojets").innerHTML=xhr.responseText;
				opacity("sprojets", 0, 100, 500);
			}
			else
			document.getElementById("sprojets").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;

		}
		else
		document.getElementById("sprojets").innerHTML="<span class='load_enreg' style='color: #F6F7FB; text-align: center;q'><img src='images/loading2.gif' border='0'><br />Chargement des sous-categories du projet...</span>";
	};

	xhr.open( "GET", "includes/include_projets.php?id="+id,  true);
	xhr.send(null);
}

function	load_crea(string)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("b").innerHTML=xhr.responseText;
			}
			else
			document.getElementById("b").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;

		}
	};

	xhr.open( "GET", "includes/include_form_crea.php?mod="+string,  true);
	xhr.send(null);
}

function	verif_creat_proj(where){
	var flag = 0;
	var reg = new RegExp('^[0-9]{2}/[0-9]{2}/[0-9]{4}$', 'i');

	if (document.getElementById("titre").value == "")
	{
		document.getElementById("titre").style.borderColor="#900";
		flag = 1;
	}
	else
	document.getElementById("titre").style.borderColor="#000";

	if (document.getElementById("date_debut").value == "")
	{
		document.getElementById("date_debut").style.borderColor="#900";
		flag = 1;
	}
	else
	{
		if (reg.test(document.getElementById("date_debut").value))
		document.getElementById("date_debut").style.borderColor="#000";
		else{
			flag = 1
			document.getElementById("date_debut").style.borderColor="#900";
		}
	}

	/*	if (document.getElementById("date_fin").value == "")
	{
	document.getElementById("date_fin").style.borderColor="#900";
	flag = 1;
	}
	else
	{
	if (reg.test(document.getElementById("date_fin").value))
	document.getElementById("date_fin").style.borderColor="#000";
	else{
	flag = 1
	document.getElementById("date_fin").style.borderColor="#900";
	}
	}

	if (flag == 0)
	{
	if (verif_date(document.getElementById("date_debut").value, document.getElementById("date_fin").value))
	{
	flag = 1;
	document.getElementById("date_debut").style.borderColor="#939";
	document.getElementById("date_fin").style.borderColor="#939";
	}
	}
	*/

	if (document.getElementById("description").value == "")
	{
		document.getElementById("description").style.borderColor="#900";
		flag = 1;
	}
	else
	document.getElementById("description").style.borderColor="#000";

	if (flag == 1)
	return false;
	else
	valide_proj(where);
}




function	edit_evalpoucentage(id)
{
	var xhr;
	try{xhr = new ActiveXObject('Msxml2.XMLHTTP');}
	catch (e){
		try{xhr = new ActiveXObject('Microsoft.XMLHTTP');}
		catch (e2){
			try{xhr = new XMLHttpRequest();}
			catch (e3){xhr = true;}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4){
			if(xhr.status  == 200){
				document.getElementById("right_edit").innerHTML=xhr.responseText;
				document.getElementById("shadow").style.display="none";
			}
			else{document.getElementById("right_edit").innerHTML=xhr.responseText;
				document.getElementById("shadow").style.display="none";}}
			else
			document.getElementById("right_edit").innerHTML="<span class='load_enreg' style='color: #F6F7FB; text-align: center;'><img src='images/loading2.gif' border='0'><br />Edition de l'évaluation en cours ...</span>";};
			if (document.getElementById("duree_tmp").value == "" || document.getElementById("duree_tmp").value == "0")
			{
				document.getElementById("duree_tmp").style.borderColor="#900";
				document.getElementById("duree_tmp").style.borderWidth="2px";
				flag = 1;
			}
			else if (document.getElementById("duree_tmp").value != "")
			{
				document.getElementById("duree_tmp").style.borderWidth="0";
				flag = 0;
			}
			var duree=document.getElementById("duree_tmp").value;
			var accomp_tmp=document.getElementById("accomp").value;

			xhr.open( "GET", "includes/include_eval_form.php?id="+id+"&duree_tmp="+duree+"&accomp="+accomp_tmp,  true);
			xhr.send(null);window.location.reload();
}






function	valide_proj(where)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("form_crea").innerHTML=xhr.responseText;
				load_projs();
			}
			else
			document.getElementById("form_crea").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;

		}
		else
		document.getElementById("form_crea").innerHTML="<span class='load_enreg' style='color: #F6F7FB; text-align: center;'><img src='images/loading2.gif' border='0'><br />Creation du rojet en cours...</span>";
	};

	var titre = document.getElementById("titre").value;
	var debut = document.getElementById("date_debut").value;
	var type = document.getElementById("type").value;
	var desc = document.getElementById("description").value;
	desc = desc.replace(/\n/g, ".ff.");
	if (where == "sprojet")
	{
		var id_pere = document.getElementById("id_pere").value;
		xhr.open( "GET", "includes/include_crea_sproj.php?titre="+titre+"&debut="+debut+"&type="+type+"&desc="+desc+"&id_pere="+id_pere,  true);
	}else
	xhr.open( "GET", "includes/include_crea_proj.php?titre="+titre+"&debut="+debut+"&type="+type+"&desc="+desc,  true);
	xhr.send(null);
}

function	load_projs()
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("proj_left").innerHTML=xhr.responseText;
			}
			else
			document.getElementById("proj_left").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;

		}
		else
		document.getElementById("proj_left").innerHTML="<span class='load_enreg' style='text-align: center;'><img src='images/loadingX.gif' border='0'><br />Raffraichissement de vos projets...</span>";
	};

	xhr.open( "GET", "includes/include_load_projs.php",  true);
	xhr.send(null);
}

function	display_good_form(id, type, id_usr){
	var xhr;

	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		document.getElementById("shadow").style.display="block";
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("right_edit").innerHTML=xhr.responseText;
			}
			else
			document.getElementById("right_edit").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a un administrateur : " + xhr.status;

		}
		else
		document.getElementById("right_edit").innerHTML="<span class='load_enreg' style='text-align: center;'><img src='images/loading2.gif' border='0'><br />Raffraichissement de vos projets...</span>";
	};

	xhr.open( "GET", "includes/include_load_form_edit.php?id="+id+"&type="+type+"&id_usr="+id_usr,  true);
	xhr.send(null);
}

function	verif_update(from){
	var flag = 0;
	var reg = new RegExp('^[0-9]{2}/[0-9]{2}/[0-9]{4}$', 'i');

	if (document.getElementById("titre_u").value == "")
	{
		document.getElementById("titre_u").style.borderColor="#900";
		flag = 1;
	}
	else
	document.getElementById("titre_u").style.borderColor="#000";

	if (document.getElementById("date_debut_u").value == "")
	{
		document.getElementById("date_debut_u").style.borderColor="#900";
		flag = 1;
	}
	else
	{
		if (reg.test(document.getElementById("date_debut_u").value))
		document.getElementById("date_debut_u").style.borderColor="#000";
		else{
			flag = 1
			document.getElementById("date_debut_u").style.borderColor="#900";
		}
	}
	/*
	if (document.getElementById("date_fin_u").value == "")
	{
	document.getElementById("date_fin_u").style.borderColor="#900";
	flag = 1;
	}
	else
	{
	if (reg.test(document.getElementById("date_fin_u").value))
	document.getElementById("date_fin_u").style.borderColor="#000";
	else{
	flag = 1
	document.getElementById("date_fin_u").style.borderColor="#900";
	}
	}

	if (flag == 0)
	{
	if (verif_date(document.getElementById("date_debut_u").value, document.getElementById("date_fin_u").value))
	{
	flag = 1;
	document.getElementById("date_debut_u").style.borderColor="#939";
	document.getElementById("date_fin_u").style.borderColor="#939";
	}
	}
	*/
	if (document.getElementById("description_u").value == "")
	{
		document.getElementById("description_u").style.borderColor="#900";
		flag = 1;
	}
	else
	document.getElementById("description_u").style.borderColor="#000";

	if (flag == 1)
	return false;
	else
	valide_update(from);

}

function	verif_date(date_debut, date_fin){
	var j = date_debut.split("/" )[0];
	var m = date_debut.split("/" )[1];
	var a = date_debut.split("/" )[2];
	date_debut= parseInt(""+a+m+j, 10);

	var jq = date_fin.split("/" )[0];
	var mq = date_fin.split("/" )[1];
	var aq = date_fin.split("/" )[2];
	date_fin= parseInt(""+aq+mq+jq, 10);

	if (date_fin > date_debut)
	return (0);
	else
	return (1);
}

function	valide_update(from)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("right_edit").innerHTML=xhr.responseText;
				document.getElementById("shadow").style.display="none";
				if (!from)
				select_sub_proj(cheat, cheat2);
				else
				load_projs();
			}
			else
			document.getElementById("right_edit").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;

		}
		else
		document.getElementById("right_edit").innerHTML="<span class='load_enreg' style='color: #F6F7FB; text-align: center;'><img src='images/loading2.gif' border='0'><br />Modification du projet en cours...</span>";
	};

	var titre = document.getElementById("titre_u").value;
	var debut = document.getElementById("date_debut_u").value;
	/*	var fin = document.getElementById("date_fin_u").value;*/
	var id = document.getElementById("id").value;
	var desc = document.getElementById("description_u").value;
	desc = desc.replace(/\n/g, ".ff.");
	xhr.open( "GET", "includes/include_up_proj.php?id="+id+"&titre="+titre+"&debut="+debut+"&desc="+desc+"&type="+from,  true);
	xhr.send(null);
}

function	delete_sprojet(id)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("right_edit").innerHTML=xhr.responseText;
				document.getElementById("shadow").style.display="none";
				select_sub_proj(cheat, cheat2);
			}
			else
			document.getElementById("right_edit").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;

		}
		else
		document.getElementById("right_edit").innerHTML="<span class='load_enreg' style='color: #F6F7FB; text-align: center;'><img src='images/loading2.gif' border='0'><br />Suppression de l'activite en cours ...</span>";
	};

	xhr.open( "GET", "includes/include_del_proj.php?id="+id,  true);
	xhr.send(null);
}

function	delete_projet(id)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("right_edit").innerHTML=xhr.responseText;
				document.getElementById("shadow").style.display="none";
				load_projs();
				select_sub_proj(id);
			}
			else
			document.getElementById("right_edit").innerHTML="Une erreur est survenu lors de la suppression du projet, merci de la communiquer a une administrateur : " + xhr.status;

		}
		else
		document.getElementById("right_edit").innerHTML="<span class='load_enreg' style='color: #F6F7FB; text-align: center;'><img src='images/loading2.gif' border='0'><br />Suppression du projet en cours ...</span>";
	};

	xhr.open( "GET", "includes/include_del_proj2.php?id="+id,  true);
	xhr.send(null);
}

function	abord_sprojet(id, type)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("right_edit").innerHTML=xhr.responseText;
				document.getElementById("shadow").style.display="none";
				select_sub_proj(cheat, cheat2);
			}
			else
			document.getElementById("right_edit").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;

		}
		else
		document.getElementById("right_edit").innerHTML="<span class='load_enreg' style='color: #F6F7FB; text-align: center;'><img src='images/loading2.gif' border='0'><br />Troncature de l'activite en cours ...</span>";
	};

	xhr.open( "GET", "includes/include_abord_proj.php?id="+id+"&act="+type,  true);
	xhr.send(null);
}

function	abord_projet(id, type)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				document.getElementById("right_edit").innerHTML=xhr.responseText;
				document.getElementById("shadow").style.display="none";
				//select_sub_proj(cheat, cheat2);
				load_projs();
			}
			else
			document.getElementById("right_edit").innerHTML="Une erreur est survenu lors de l'inscription, merci de la communiquer a une administrateur : " + xhr.status;

		}
		else
		document.getElementById("right_edit").innerHTML="<span class='load_enreg' style='color: #F6F7FB; text-align: center;'><img src='images/loading2.gif' border='0'><br />Troncature de l'activite en cours ...</span>";
	};

	xhr.open( "GET", "includes/include_abord_proj.php?id="+id+"&act="+type,  true);
	xhr.send(null);
}


function	presta(id_prj, id_usr, string)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				if (xhr.responseText == 'ok')
				display_good_form(id_prj, 'presta');
				else
				document.getElementById("right_edit").innerHTML=xhr.responseText;
			}
			else
			document.getElementById("right_edit").innerHTML="Une erreur est survenu lors de la gestion des prestataires, merci de la communiquer a une administrateur : " + xhr.status;

		}
		else
		document.getElementById("right_edit").innerHTML="<span class='load_enreg' style='color: #F6F7FB; text-align: center;'><img src='images/loading2.gif' border='0'><br />Chargement en cours ...</span>";
	};
	if (string == "del")
	xhr.open( "GET", "includes/include_presta.php?id_usr="+id_usr+"&id_prj="+id_prj+"&act="+string,  true);
	else
	{
		decoup = document.getElementById("decoupage").checked;
		visu = document.getElementById("visualisation").checked;
		evaluation = document.getElementById("evaluation").checked;
		xhr.open( "GET", "includes/include_presta.php?id_usr="+id_usr+"&id_prj="+id_prj+"&visu="+visu+"&decoup="+decoup+"&evaluation="+evaluation+"&act="+string,  true);
	}
	xhr.send(null);
}

function	check_users(id_prj)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			document.getElementById("presta").innerHTML=xhr.responseText;
			else
			alert("Une erreur est survenu lors de la gestion des prestataires, merci de la communiquer a une administrateur : " + xhr.status);

		}
		else
		document.getElementById("presta").innerHTML="Chargement...";
	};

	xhr.open( "GET", "includes/include_load_users.php?id_prj="+id_prj,  true);
	xhr.send(null);
}

function	maislol()
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}
	catch (e)
	{
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}
		catch (e2)
		{
			try{
				xhr = new XMLHttpRequest();
			}
			catch (e3){
				xhr = false;
			}
		}
	}

	xhr.onreadystatechange  = function()
	{
		if(xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			document.getElementById("form_crea").innerHTML=xhr.responseText;
			else
			alert("Une erreur est survenu lors de la gestion des prestataires, merci de la communiquer a une administrateur : " + xhr.status);

		}
	};

	id_prj= document.getElementById("projet_a").value;
	id_usr= document.getElementById("presta_a").value;
	if (document.forms.addingeuh.decoup_a.checked == true)
	decoup_a= document.getElementById("decoup_a").value;
	else
	decoup_a = "0";
	if (document.forms.addingeuh.visu_a.checked == true)
	visu_a= document.getElementById("visu_a").value;
	else
	visu_a = "0";
	if (document.forms.addingeuh.eval_a.checked == true)
	eval_a= document.getElementById("eval_a").value;
	else
	eval_a="0";

	xhr.open( "GET", "includes/include_add_presta.php?id_prj="+id_prj+"&id_usr="+id_usr+"&decoup="+decoup_a+"&visu="+visu_a+"&eval="+eval_a,  true);
	xhr.send(null);
}

function	check_display(id){

	if (document.getElementById(id).style.display == "block")
	document.getElementById(id).style.display = "none";
	else
	document.getElementById(id).style.display = "block";
}