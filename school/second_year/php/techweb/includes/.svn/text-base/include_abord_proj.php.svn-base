<?php
	session_start();
	include("include_connection.php");
	include("../modules/fonctions.php");
	if (!isset($_SESSION))
		echo "Vous n'etes pas logges";
	else{
		if (verif_droit($_SESSION["id"], $_GET["id"], "admin")){
			if ($_GET["act"] == "abo")
				$requete = "UPDATE tb_projet SET etat_projet='1' WHERE id_projet='".$_GET["id"]."'";
			else
				$requete = "UPDATE tb_projet SET etat_projet='0' WHERE id_projet='".$_GET["id"]."'";
			
			$res = querybd($requete, "");
			if ($res)
				if ($_GET["act"] == "abo")
					echo "<div style=\"text-align: center; margin-top: 35px;\">
					La troncature a ete effectue avec succes !</div>";
				else
					echo "<div style=\"text-align: center; margin-top: 35px;\">
					La restauration a ete effectue avec succes !</div>";
			else
				if ($_GET["act"] == "abo")
					echo "<div style=\"text-align: center; margin-top: 35px;\">
					Une erreur est survenue lors de la troncature, merci de contacter un administrateur !</div>";
				else
					echo "<div style=\"text-align: center; margin-top: 35px;\">
					Une erreur est survenue lors de la restauration, merci de contacter un administrateur !</div>";
		}
		else
			echo "<div style=\"text-align: center; margin-top: 35px;\">
			Vous n'avez pas les droits pour faire ceci !</div>";
	}
?>