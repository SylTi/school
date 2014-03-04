<?php
	include ("include_connection.php");
	
	$requete = "DELETE FROM ".$client."_news WHERE id_news='".$_GET['id']."'";
	
	mysql_query($requete) or die (mysql_error());
	header("location: ../admin.php?menu=6");
?>