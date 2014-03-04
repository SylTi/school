<?php
	include ("include_connection.php");
	$login = mysql_real_escape_string($_POST['login_a']);
	$password = mysql_real_escape_string($_POST['password_a']);
	$ip = mysql_real_escape_string($_POST['ip_a']);
	$rang = mysql_real_escape_string($_POST['rang_a']);
	
	if ($ip)
	{
		if (!($ipay = gethostbynamel($ip)))
		{
			header("Location: ../admin.php?menu=2&error=ip:".$ip);
		}
		$ipay = $ipay[0];
	}
	else
		header("Location: ../admin.php?menu=2&error=ip:none:");
		
	if (!$login)
		header("Location: ../admin.php?menu=2&error=login:none");
	if (!$password)
		header("Location: ../admin.php?menu=2&error=password:none");

	$request = "INSERT INTO ".$client."_users (username, user_pwd, user_ip, user_droit) VALUE ('".$login."', '".md5($password)."', '".md5($ipay)."', '".$rang."')";
			
	mysql_query($request) or die (mysql_error());
	header("Location: ../admin.php?menu=2");
?>