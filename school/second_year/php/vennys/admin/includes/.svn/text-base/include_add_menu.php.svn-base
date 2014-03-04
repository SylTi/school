<?php
	include ("include_connection.php");
	
	$titre_fr = mysql_real_escape_string($_POST['nom_menu_fr']);
	$titre_en = mysql_real_escape_string($_POST['nom_menu_en']);
	
	$requete = "INSERT INTO ".$client."_menu_site (nom_menu_french, nom_menu_english, pere_menu, pager_menu) VALUE('".$titre_fr."', '".$titre_en."','".$_POST['id_pere']."', '".$_POST['pager_menu']."')";
	mysql_query($requete) or die (mysql_error());
	header("location: ../admin.php?menu=7&dad=".$_POST['id_pere']);
?>