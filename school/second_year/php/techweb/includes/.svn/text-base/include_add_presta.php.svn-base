<?php
	session_start();
	include("include_connection.php");
	include("../modules/fonctions.php");
	if (!isset($_SESSION))
		echo "Vous n'etes pas logges";
	else{
		if (verif_droit($_SESSION["id"], $_GET["id_prj"], "decoupage")){
			$get = secure_tab($_GET);
			
			$requete1 = "INSERT INTO tb_users_projet (id_projet, id_user, user_confirm) VALUE ('".$get["id_prj"]."', '".$get["id_usr"]."', '0')";
			
			
			$requete2 = "INSERT INTO tb_droit_projet (id_projet, id_user, droit_decoupage, droit_evaluation, droit_visualisation) VALUE ('".$get["id_prj"]."', '".$get["id_usr"]."', '".$get["decoup"]."', '".$get["eval"]."', '".$get["visu"]."')";
			$res_2 = querybd($requete2, "");
			$res_1 = querybd($requete1, "");
			if ($res_1 && $res_2)
				echo "Une invitation a ete envoye a votre prestataire";
			else
				echo "Une erreur est survenu lors de l'invitation, merci de contacter un administrateur";
		}
		else
			echo "<div style=\"text-align: center; margin-top: 35px;\">
			Vous n'avez pas les droits pour faire ceci !</div>";
	}
?>