<?php
	include ("include_connection.php");
	
	$requete = "DELETE FROM ".$client."_menu_site WHERE id_menu='".$_GET['id']."'";
	
	mysql_query($requete) or die (mysql_error());
	header("location: ../admin.php?menu=7");
?>