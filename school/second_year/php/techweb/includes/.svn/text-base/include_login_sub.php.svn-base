<?php
	session_start();
	
	include ("../include_connection.php");
	
	$login = $_GET["log"];
	$password = $_GET["pass"];
	
	$request = "SELECT * FROM phpbb_users WHERE username='".$login."'";
	$query = mysql_query($request) or die (header("location: ../../index.php?err=".mysql_error()));
	while ($row = mysql_fetch_object($query))
	{
		echo $row->username."<br />";
		echo $row->user_password."<br />";
		echo md5($password);
			//header ("location: ../index.php?log=success");
	}
	//header ("location: ../index.php?log=failure");
?>