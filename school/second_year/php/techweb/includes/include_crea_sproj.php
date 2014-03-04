<?php
	session_start();
	
	if ($_SESSION)
	{
		include("include_connection.php");
		include("../modules/fonctions.php");
		$tab = secure_tab($_GET);
		$titre = $tab["titre"];
		$debut = sql_date($tab["debut"]);
/*		$fin = sql_date($tab["fin"]);*/
		$type = $tab["type"];
		$desc = ereg_replace(".ff.", "<br />", $tab["desc"]);
		$id_pere = $tab["id_pere"];
		
		$request_pere = "SELECT * FROM tb_projet WHERE id_projet='".$id_pere."'";
		$query_pere = mysql_query($request_pere) or die ("Error : ".mysql_error());
		$row_pere = mysql_fetch_object($query_pere);
		if ($row_pere->id_god_projet == 0)
			$god = $row_pere->id_projet;
		else
			$god = $row_pere->id_god_projet;
		
		$request = "INSERT INTO tb_projet (type_projet, id_master_projet, description_projet, debut_projet, titre_projet, id_pere_projet, id_god_projet) VALUES ('".$type."', '".$row_pere->id_master_projet."', '".$desc."', '".$debut."', '".$titre."', '".$id_pere."', '".$god."')";
		
		$query = mysql_query($request) or die("Error :".mysql_error());
		
		$id_proj = mysql_insert_id();
		
		$request2 = "INSERT INTO tb_droit_projet (id_user, id_projet, droit_decoupage, droit_visualisation, droit_evaluation) VALUES ('".$_SESSION["id"]."', '".$id_proj."', '1', '1', '1')";
		
		$query2 = mysql_query($request2) or die("Error :".mysql_error());
		
		$request3 = "INSERT INTO tb_users_projet (id_user, id_projet, user_confirm) VALUES ('".$_SESSION["id"]."', '".$id_proj."', '1')";
		
		$query3 = mysql_query($request3) or die("Error :".mysql_error());
		if ($query && $query2 && $query3)
			echo "Votre sous-projet a ete cree avec succes !";
		else
			echo "Une erreur est survenu lors de la creation de votre sous-projet !";
		
		mysql_close();
	}else
		echo "Vous n'etes pas loggues...";
?>