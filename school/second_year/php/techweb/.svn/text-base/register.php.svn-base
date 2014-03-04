<?php
include("./includes/include_connection.php");
include("./modules/phpbb_hash.php");

$tab = secure_tab($_POST);

$login = $tab["login"];
$password = phpbb_hash($tab["password"]);
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

$requete = "SELECT user_id FROM phpbb_users";
$res = mysql_query($requete);
$nb_users = mysql_num_rows($res);
$login_clean = strtolower($login);
$reg = time();

$requete = "INSERT INTO `phpbb_users` (`user_type`, `group_id`, `user_permissions`, `user_regdate`, `username`, `username_clean`, 
										`user_password`, `user_email`, `user_birthday`, `user_lang`, `user_style`, `user_sig`, 
										`user_icq`, `user_aim`, `user_yim`, `user_msnm`, `user_jabber`, `user_website`,
										 `user_occ`, `user_interests`, `user_form_salt`)
						VALUES ('0', '2', '[BLOB - 0 o]', '$reg','$login', '$login_clean',  '$password', '$mail', '$birth', 'fr', 
								'3','[BLOB - 0 o]', '$icq', '$aim', '$yim', '$msn', '$jabber', '$site', '[BLOB - 0 o], 
								'[BLOB - 0 o]', '')";
$res = mysql_query($requete);

$requete = "SELECT `user_id` FROM `phpbb_users` WHERE username = '$login'";
$user_id = mysql_query($requete);

$requete = "INSERT INTO `phpbb_users_group` (`group_id`, `user_id`, `user_pending`) VALUES ('2', '$user_id' , '0')";
$res_group = mysql_query($requete);

if ($res_group && $res) {
	$smarty->assign("res_enre", "OK");
}
else 
	$smarty->assign("res_enre", "ERREUR");
?>