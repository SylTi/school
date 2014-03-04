<?php
	include("include_connection.php");
	$id=mysql_real_escape_string($_POST['id']);
	$id_usr=mysql_real_escape_string($_POST['id_usr']);
	$titre=mysql_real_escape_string($_POST['titre']);
	
	$requete = "UPDATE ".$client."_news SET titre_news='".$titre."', id_user_news='".$id_usr."', date_news=CURRENT_TIMESTAMP WHERE id_news='".$id."'";
	
	mysql_query($requete) or die(mysql_error());
	header("Location: ../admin.php?menu=6");
?>