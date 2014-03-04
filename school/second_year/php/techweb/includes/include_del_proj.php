<?php
	session_start();
	include("include_connection.php");
	include("../modules/fonctions.php");
	if (!isset($_SESSION))
		echo "Vous n'etes pas logges";
	else{
		if (verif_droit($_SESSION["id"], $_GET["id"], "admin")){
			$requete = "DELETE FROM tb_projet WHERE id_projet='".$_GET["id"]."'";
			$requete_usr = "DELETE FROM tb_users_projet WHERE id_projet='".$_GET["id"]."'";
			$requete_rgt = "DELETE FROM tb_droit_projet WHERE id_projet='".$_GET["id"]."'";
			
			$res = querybd($requete, "");
			$res_usr = querybd($requete_usr, "");
			$res_rgt = querybd($requete_rgt, "");
			
			if ($res && $res_usr && $res_rgt)
				echo "<div style=\"text-align: center; margin-top: 35px;\">
					La suppression a ete effectue avec succes !</div>";
			else
				echo "<div style=\"text-align: center; margin-top: 35px;\">
				Une erreur est survenue lors de la suppression, merci de contacter un administrateur !</div>";
		}
		else
			echo "<div style=\"text-align: center; margin-top: 35px;\">
			Vous n'avez pas les droits pour faire ceci !</div>";
	}
?>