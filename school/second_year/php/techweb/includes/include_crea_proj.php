<?php
	session_start();
	
	if ($_SESSION)
	{
		include("include_connection.php");
		include("../modules/fonctions.php");
		$tab = secure_tab($_GET);
		$titre = $tab["titre"];
		$debut = sql_date($tab["debut"]);
		//$fin = sql_date($tab["fin"]);
		$type = $tab["type"];
		$desc = ereg_replace(".ff.", "<br />", $tab["desc"]);
		
		$request = "INSERT INTO tb_projet (type_projet, id_master_projet, description_projet, debut_projet, titre_projet, id_pere_projet, id_god_projet) VALUES ('".$type."', '".$_SESSION["id"]."', '".$desc."', '".$debut."', '".$titre."', '0', '0')";
		
		$query = mysql_query($request) or die("Error :".mysql_error());
		
		$id_proj = mysql_insert_id();
		
		$request2 = "INSERT INTO tb_droit_projet (id_user, id_projet, droit_decoupage, droit_visualisation, droit_evaluation) VALUES ('".$_SESSION["id"]."', '".$id_proj."', '1', '1', '1')";
		
		$query2 = mysql_query($request2) or die("Error :".mysql_error());
		
		$request3 = "INSERT INTO tb_users_projet (id_user, id_projet, user_confirm) VALUES ('".$_SESSION["id"]."', '".$id_proj."', '1')";
		
		$query3 = mysql_query($request3) or die("Error :".mysql_error());
		if ($query && $query2 && $query3)
			echo "Votre projet a ete cree avec succes !";
		else
			echo "Une erreur est survenu lors de la creation de votre projet !";
		
		mysql_close();
	}else
		echo "Vous n'etes pas loggues...";
?>