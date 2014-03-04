<?php

include("./include_connection.php");
include("../modules/fonctions.php");

$tab = secure_tab($_GET);
$login = $tab["login"];
$pass = md5($tab["password"]);
$mail = $tab["mail"];
$nom = $tab["nom"];
$prenom = $tab["prenom"];
$localisation = $tab["localisation"];
$birth = $tab["birth"];
$societe = $tab["societe"];
$icq = $tab["icq"];
$aim = $tab["aim"];
$yim = $tab["yim"];
$msn = $tab["msn"];
$jabber = $tab["jabber"];
$site = $tab["site"];

$login_clean = strtolower($login);
$reg = time();
$droits = secure_str("[BLOB - 0 o]");

$verif = mysql_query("SELECT username_clean FROM phpbb_users;");
$flag = 0;
while ($row =mysql_fetch_object($verif))
{
	if ($row->username_clean == $login_clean)
		$flag = 1;
}

if ($flag == 1)
	echo "login";
else
{
	$requete = "INSERT INTO phpbb_users";
	
	$requete .= " (user_type, group_id, user_permissions, user_regdate, username, username_clean, user_password, user_email, user_birthday, user_lang, user_style, user_sig, user_icq, user_aim, user_yim, user_msnm, user_jabber, user_website, user_occ, user_interests, user_form_salt)";
	
	$requete .= " VALUES ('0', '2', '$droits', '$reg','$login', '$login_clean',  '$pass', '$mail', '$birth', 'fr', '3','$droits', '$icq', '$aim', '$yim', '$msn', '$jabber', '$site', '$droits', '$droits', '')";
	//echo "$requete";
	$res = mysql_query($requete) or die("<p>Error 1 : " . mysql_error()."</p>");
			
	$requete = "SELECT user_id FROM phpbb_users WHERE username = '$login'";
	$res_id = mysql_fetch_array(mysql_query($requete));
	$user_id = $res_id["user_id"];
	
	$requete2 = "INSERT INTO phpbb_users_info";
	$requete2 .= " (user_id, user_name, user_lastname, user_location)";
	$requete2 .= " VALUES ('$user_id', '$nom', '$prenom', '$localisation')";
	$res = mysql_query($requete2) or die("<p>Error 1 : " . mysql_error()."</p>");

	
	
	$requete = "INSERT INTO phpbb_user_group (group_id, user_id, user_pending) VALUES ('2', '$user_id' , '0')";
	$res_group = mysql_query($requete) or die("<p>Error 2 : " . mysql_error()."</p>");;
	
	if ($res_group && $res) {
		echo "<span class=\"vert_12\">Votre inscription est effective, vous pouvez maintenant vous logguer.</span>";
	}
	else 
		echo "<span class=\"rouge_12\">Une erreur est survenu lors de votre inscription, merci de recommencer ou de contacter un administrateur.</span>";
}
?>