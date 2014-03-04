<?php
	if ($_GET && $_GET['id'])
	{
		include('include_connection.php');
		$id=mysql_real_escape_string($_GET['id']);
		$request="DELETE FROM ".$client."_users WHERE id_user='".$id."'";
		mysql_query($request) or die (mysql_error());
		header("Location: ../admin.php?menu=2");
	}
	else
		header("Location: ../admin.php?error=id:none");
?>