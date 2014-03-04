<?php
	session_start();
	
	if (!$_SESSION)
		header("location:index.php?login=error");
	elseif(!$_SESSION['log'] || !$_SESSION['pwd'] || !$_SESSION['ip'] || !$_SESSION['id'])
		header("location:index.php?login=error");
	else
		{
			include("fonctions/functions.php");
			include("include_connection.php");
		}
	
?>