<?php
	include("include_connection.php");
	$id=mysql_real_escape_string($_POST['id_menu']);
	$nom_menu_fr=mysql_real_escape_string($_POST['nom_menu_fr'.$id]);
	$nom_menu_en=mysql_real_escape_string($_POST['nom_menu_en'.$id]);
	$pager_menu=mysql_real_escape_string($_POST['pager_menu'.$id]);
	
	$requete = "UPDATE ".$client."_menu_site SET nom_menu_french='".$nom_menu_fr."', nom_menu_english='".$nom_menu_en."', pager_menu='".$pager_menu."' WHERE id_menu='".$id."'";

	mysql_query($requete) or die(mysql_error());
	header("Location: ../admin.php?menu=7");
?>