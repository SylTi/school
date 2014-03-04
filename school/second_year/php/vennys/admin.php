<?php
	session_start();
	include("../includes/include_connection.php");
	$_GET = $db->safetab($_GET);
	$login = $_GET['login'];
	$password = md5($_GET['pwd']);
	$ip = md5($_SERVER['REMOTE_ADDR']);
	$requete = "SELECT user_droit, id_user, username, user_pwd, user_ip FROM ".$client."_users WHERE username='".$login."' AND user_pwd='".$password."'";
	if ($query = $db->query_f($requete) != NULL)
	  {
	    $_SESSION["log"] = $query['username'];
	    $_SESSION["pwd"] = $query['user_pwd'];
	    $_SESSION["ip"] = $query['user_ip'];
	    $_SESSION["id"] = $query['id_user'];
	    $_SESSION["rang"] = $query['user_droit'];
	    header("location:../admin.php");
	  }
	else
	header("location:../index.php?login=error");
?>