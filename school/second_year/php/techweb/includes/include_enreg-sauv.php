<?php
	include("include_connection.php");
	
	$login = $_GET["login"];
	$password = $_GET["password"];
	$nom = $_GET["nom"];
	$prenom = $_GET["prenom"];
	$mail = $_GET["mail"];
	$birth = $_GET["birth"];
	$localisation = $_GET["localisation"];
	$icq = $_GET["icq"];
	$yim = $_GET["yim"];
	$jabber = $_GET["jabber"];
	$msn = $_GET["msn"];
	$site = $_GET["site"];
	
	echo var_dump($_GET);
	
?>