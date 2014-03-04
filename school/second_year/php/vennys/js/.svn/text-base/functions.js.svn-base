var recherche = 0;

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

function	fast_search(str){
	if (str.length < 3){
		if (recherche == 1)
		{
			opacity("lol", 100, 0, 200);
			recherche = 0;
		}
		return false;
	}
	if (recherche == 0)
	{
		opacity("lol", 0, 100, 200);
		recherche = 1;
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
	httpRequest.open('GET', 'xml/init.xml', true);
	httpRequest.send(null);
}

function	use_fck_datas(httpRequest, str){
	if (httpRequest.readyState == 4)
	{
		document.getElementById("lol1").innerHTML = "";

		var i = 0;
		var xmldoc = httpRequest.responseXML;

		var init = xmldoc.getElementsByTagName('init');
		var data = xmldoc.getElementsByTagName('data');
		if (data.length <= 0)
		document.getElementById("lol1").innerHTML = "<div class=\"left_c\"></div><div class=\"center_c2\">Aucun resultat n'a ete trouve...</div><div class=\"right_c\"></div><div style=\"clear: both;\"></div>";
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
					document.getElementById("lol1").innerHTML += "<div class=\"left_c\"></div><div class=\"center_c\">"+titre+"</div><div class=\"right_c\"></div><div style=\"clear: both;\"></div>";
				}
				i++;
			}
			if (flag == 0){
				document.getElementById("lol1").innerHTML = "<div class=\"left_c\"></div><div class=\"center_c2\">Aucun resultat n'a ete trouve...</div><div class=\"right_c\"></div><div style=\"clear: both;\"></div>";
			}
		}
	}
}

function	nick_dispo(nick)
{
	var xhr;
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}catch(e){
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}catch(e2){
			try{
				xhr = new XMLHttpRequest();
			}catch(e3){
				xhr = false;
			}
		}
	}
	xhr.onreadystatechange  = function(){
		if (xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				$("#nick").slideUp("fast");
				if (xhr.responseText == "true"){
					document.getElementById("login2").style.borderColor="#3CB23F";
					return true;
				}
				else{
					document.getElementById("login2").style.borderColor="#660000";
					return false;
				}
			}
			else
			document.getElementById("nick").innerHTML="Erreur sur le serveur"+ xhr.status;
		}
		else
		{
			$("#nick").slideDown("fast");
			document.getElementById("nick").innerHTML="<img src='images/loader.gif' />&nbsp;Verification du login...";
		}
	};
	xhr.open( "GET", "script/check_nick.php?nick="+nick,  true);
	xhr.send(null);
}

function	hide_smenu()
{
    $(".jailing").slideUp("fast");
}

function	display_smenu(id)
{
    $(".jailing").slideUp("fast");
    $("#smenu_"+id).slideDown("fast");
}

function	clean_input(name, pattern)
{
    var obj = document.getElementById(name);
	obj.value="";
}

function	check_datas(matcher){
	var xhr;
	var doc = document.getElementById("s_f_r");
	try{
		xhr = new ActiveXObject('Msxml2.XMLHTTP');
	}catch(e){
		try{
			xhr = new ActiveXObject('Microsoft.XMLHTTP');
		}catch(e2){
			try{
				xhr = new XMLHttpRequest();
			}catch(e3){
				xhr = false;
			}
		}
	}
	xhr.onreadystatechange  = function(){
		if (xhr.readyState  == 4)
		{
			if(xhr.status  == 200)
			{
				if (xhr.responseText){
					doc.innerHTML=xhr.responseText;
				}
				else{
					doc.innerHTML="Aucun resultat."
				}
			}
			else
				return false;
		}
		else
                  doc.innerHTML="<img src='images/loader.gif' />&nbsp;Chargement... ";
	};
	xhr.open( "GET", "script/check_datas.php?get="+matcher,  true);
	xhr.send(null);	
}

function	make_my_search()
{
    var obj = document.getElementById("f_r");
    
    if (obj.value.length >= 3){
		$("#s_f_r").slideDown("fast");
		check_datas(obj.value);
    }else{
		$("#s_f_r").slideUp("fast");
		return;
    }
}

function	verif_registering(name)
{
	var login = document.getElementById("login2");
	var mail = document.getElementById("mail");
	var pwd = document.getElementById("pwd2");
	var pwd_check = document.getElementById("pwd_check");

	var flag = 0;

	if (!(login.value) || login.value == "")
	{
		login.style.borderColor="#660000";
		flag = 1;
	}
	else
	{
		if (nick_dispo(login.value) == false)
		flag = 1;
		else
		login.style.borderColor="#fff";
	}

	if (!(pwd.value) || pwd.value == "")
	{
		pwd.style.borderColor="#660000";
		flag = 1;
	}
	else
	pwd.style.borderColor="#fff";

	if (!(pwd_check.value) || pwd_check.value == "")
	{
		pwd_check.style.borderColor="#660000";
		flag = 1;
	}
	else
	pwd_check.style.borderColor="#fff";

	if (!(mail.value) || mail.value == "")
	{
		mail.style.borderColor="#660000";
		flag = 1;
	}
	else
	mail.style.borderColor="#fff";


	if (flag == 1)
	return false;
	else
	document.getElementById(name).submit();
}





/* ---------------------------- */
/* XMLHTTPRequest Enable 		*/
/* ---------------------------- */
function createObject() {
	var request_type;
	var browser = navigator.appName;
	if(browser == "Microsoft Internet Explorer"){
		request_type = new ActiveXObject("Microsoft.XMLHTTP");
	}else{
		request_type = new XMLHttpRequest();
	}
	return request_type;
}

var http = createObject();

/* -------------------------- */
/* SEARCH					 */
/* -------------------------- */
function autosuggest(divid,location) {
	q = document.getElementById(""+divid+"").value;
	// Set te random number to add to URL request
	nocache = Math.random();
	http.open('get', 'modules/search.php?type='+location+'&'+location+'='+q+'&nocache = '+nocache);

	if(location == "clb_e")
	{http.onreadystatechange = autosuggestReply_clb_e;
	http.send(null);}
}
function fill(i,s_loc,s_sugg) {
	document.getElementById(""+s_loc+"").value=i;
	document.getElementById(""+s_sugg+"").style.display="none";
}

function autosuggestReply_clb_e() {
	if(http.readyState == 4){
		var response = http.responseText;
		e = document.getElementById('res_clb_e');
		if(response!=""){
			e.innerHTML=response;
			e.style.display="block";
		} else {
			e.style.display="none";
		}
	}
}