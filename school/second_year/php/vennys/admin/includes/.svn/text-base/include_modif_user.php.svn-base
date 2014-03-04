<?php
	include ("include_connection.php");
	
	$id = mysql_real_escape_string($_POST['id_m']);
	$login = mysql_real_escape_string($_POST['login_m']);
	if ($_POST['password_m'])
		$password = mysql_real_escape_string($_POST['password_m']);
	$mail = mysql_real_escape_string($_POST['mail_m']);
	
	if (!$mail)
		header("Location: ../admin.php?menu=9&error=mail:none:");
	if (!$login)
		header("Location: ../admin.php?menu=9&error=login:none");

	$request = "UPDATE users_tracker SET user_mail='".$mail."', user_login='".$login."'";
	if ($password)
		$request .= ", user_pass='".md5($password)."'";
	$request .= " WHERE user_id='".$id."'";
		
	mysql_query($request) or die (mysql_error());
	header("Location: ../admin.php?menu=9");
?>