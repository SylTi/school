<?php
	session_start();
	include("../includes/include_connection.php");
	$login = mysql_escape_string($_GET['login']);
	$password = md5($_GET['pwd']);
	$ip = md5($_SERVER['REMOTE_ADDR']);
	
	$requete = "SELECT user_droit, id_user, username, user_pwd, user_ip FROM ".$client."_users WHERE username='".$login."' AND user_pwd='".$password."'";
	$query = mysql_query($requete) or die (gener_error(4)."login");
	if (mysql_num_rows($query) == 1)
	{
		$row = mysql_fetch_object($query);
		$_SESSION["log"] = $row->username;
		$_SESSION["pwd"] = $row->user_pwd;
		$_SESSION["ip"] = $row->user_ip;
		$_SESSION["id"] = $row->id_user;
		$_SESSION["rang"] = $row->user_droit;
		header("location:../admin.php");
	}
	else
		header("location:../index.php?login=error");
?>