<?php
	include ("include_connection.php");
	$login = mysql_real_escape_string($_POST['login_m']);
	$password = mysql_real_escape_string($_POST['password_m']);
	$ip = mysql_real_escape_string($_POST['ip_m']);
	$id = mysql_real_escape_string($_POST['id_m']);
	$request = "UPDATE ".$client."_users SET id_user='".$id."' ";
	if ($ip)
	{
		if (!@gethostbyaddr($ip))
			header("Location: ../admin.php?menu=2&error=ip:".$ip);
		else
			$request .= ", user_ip='".md5($ip)."' ";
	}		
	if ($login)
		$request .= ", username='".$login."' ";
		
	if ($password)
		$request .= ", user_pwd='".md5($password)."' ";
		
	$request .= "WHERE id_user='".$id."'";
		
	mysql_query($request) or die (mysql_error());
	header("Location: ../admin.php?menu=2");
?>