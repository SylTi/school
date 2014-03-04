<?php

if ($_GET["view"] == "profil" && isset($_SESSION["login"])){	
	$request = "SELECT * FROM phpbb_users WHERE user_id = '".$_SESSION["id"]."'";
	$row = querybd($request, "str") or die("Error profile request :".mysql_error());
	$oSmarty->assign('login_usr', $row["username"]);
	$oSmarty->assign('mail_usr', $row["user_email"]);
	$oSmarty->assign('id_usr', $_SESSION["id"]);
	$oSmarty->assign('birth_usr', $row["user_birthday"]);
	$oSmarty->assign('icq_usr', $row["user_icq"]);
	$oSmarty->assign('msn_usr', $row["user_msnm"]);
	$oSmarty->assign('jabber_usr', $row["user_jabber"]);
	$oSmarty->assign('yim_usr', $row["user_yim"]);
	$oSmarty->assign('aim_usr', $row["user_aim"]);
	$oSmarty->assign('site_usr', $row["user_website"]);

	$request = "SELECT * FROM phpbb_users_info WHERE user_id = '".$_SESSION["id"]."'";
	$row2 = querybd($request, "str") or die("Error profile request :".mysql_error());
	$oSmarty->assign('name_usr', $row2["user_name"]);
	$oSmarty->assign('lastname_usr', $row2["user_lastname"]);
	$oSmarty->assign('location_usr', $row2["user_location"]);
	$oSmarty->assign('societe_usr', $row2["user_societe"]);
}
else 
	header("location: index.php");
?>