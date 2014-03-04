<?php
	session_start();
	include ("../../../includes/include_connection.php");
	
	if ($_POST['id'] && $_POST['id_news']){
		$request = "UPDATE ".$client."_news SET titre_news='".$_POST['titre']."', text_news='".$_POST['FCKeditor1']."', id_user_news='".$_POST['id']."', date_news=CURRENT_TIMESTAMP WHERE id_news='".$_POST['id_news']."'";
		
//		echo $request;
		mysql_query($request) or die (mysql_error());
		header("location: sample02.php?id=".$_POST['id_news']);
	}
	else{
		$request = "INSERT INTO ".$client."_news (titre_news, text_news, id_user_news, date_news) VALUE ('".$_POST['titre']."', '".$_POST['FCKeditor1']."', '".$_POST['id']."', CURRENT_TIMESTAMP)";
		
//		echo $request;
		mysql_query($request) or die (mysql_error());
		header("location: sample02.php?id=".mysql_insert_id());
	}
?>