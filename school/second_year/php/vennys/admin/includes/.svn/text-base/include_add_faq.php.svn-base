<?php
	include ("include_connection.php");
	
	$question = mysql_real_escape_string($_POST['question']);
	$reponse = mysql_real_escape_string($_POST['reponse']);
	
	$requete = "INSERT INTO ".$client."_faq (text_question, text_reponse) VALUE('".$question."', '".$reponse."')";
	mysql_query($requete) or die (mysql_error());
	header("location: ../admin.php?menu=8");
?>