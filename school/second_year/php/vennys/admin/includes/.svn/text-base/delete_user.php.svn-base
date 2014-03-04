<?php
	include ("include_connection.php");
	$id = $_GET['id'];
	
	$requete = "DELETE FROM users_tracker WHERE user_id='".$id."'";
	mysql_query($requete) or die ("error on delete :".mysql_error());
	header("location: ../admin.php?menu=9");
?>