<?php

include("./include_connection.php");
include("../modules/fonctions.php");

$tab = secure_tab($_GET);
$id = $tab["id"];
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

if ($flag == 1)
	echo "<span class=\"rouge_12\">Ce pseudonyme est deja pris, merci d'en changer.</span>";
else
{
	$requete = "UPDATE phpbb_users SET";
	$requete .= " user_email='".$mail."',";
	$requete .= " user_birthday='".$birth."',";
	$requete .= " user_icq='".$icq."',";
	$requete .= " user_aim='".$aim."',";
	$requete .= " user_jabber='".$jabber."',";
	$requete .= " user_yim='".$yim."',";
	$requete .= " user_website='".$site."',";
	$requete .= " user_msnm='".$msn."'";
	if ($_GET["password"] != "")
		$requete .= ", user_password='".$pass."'";
	$requete .= " WHERE user_id='".$id."'";
	//echo $requete;
	$res = mysql_query($requete) or die("<p>Error 1 : " . mysql_error()."</p>");
	//echo "<br />";
	$requete2 = "UPDATE phpbb_users_info SET";
	$requete2 .= " user_name='".$nom."'";
	$requete2 .= ", user_societe='".$societe."'";
	$requete2 .= ", user_lastname='".$prenom."'";
	$requete2 .= ", user_location='".$localisation."'";
	$requete2 .= " WHERE user_id='".$id."'";
	
	//echo $requete2;
	$res = mysql_query($requete2) or die("<p>Error 2 : " . mysql_error()."</p>");

		
	if ($res) {
		echo "<span class=\"vert_12\">Vos modifications sont maintenant effectives.</span>";
	}
	else 
		echo "<span class=\"rouge_12\">Une erreur est survenu lors des modifications de vos informations, merci de contacter un administrateur.</span>";
}
?>