<?php
	session_start();
	include ("../../../includes/include_connection.php");
	
	if ($_POST['id_faq'] && $_POST['type']=='question'){
		$request = "UPDATE ".$client."_faq SET text_question='".$_POST['FCKeditor1']."' WHERE id_question='".$_POST['id_faq']."'";
		
//		echo $request;
		mysql_query($request) or die (mysql_error());
		header("location: sample03.php?id=".$_POST['id_faq']."&row=question");
	}
	else{
		$request = "UPDATE ".$client."_faq SET text_reponse='".$_POST['FCKeditor1']."' WHERE id_question='".$_POST['id_faq']."'";
		
//		echo $request;
		mysql_query($request) or die (mysql_error());
		header("location: sample03.php?id=".$_POST['id_faq']."&row=reponse");
	}
?>