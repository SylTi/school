<?php
session_start();

include("include_connection.php");
include("../modules/fonctions.php");

if (!$_SESSION)
	echo "Vous n'etes pas loggue";
else
{
	$tab = secure_tab($_GET);
	if (!verif_droit($_SESSION["id"], $tab["id_prj"], "decoupage"))
		echo "Vous n'avez pas les droits appropries";
	else
	{
		if ($tab["act"] == "del")
		{
			$requete_1 = "DELETE FROM tb_users_projet WHERE id_user='".$tab["id_usr"]."' AND id_projet='".$tab["id_prj"]."'";
			$res1 = querybd($requete_1, "");
			$requete_2 = "DELETE FROM tb_droit_projet WHERE id_user='".$tab["id_usr"]."' AND id_projet='".$tab["id_prj"]."'";
			$res2 = querybd($requete_2, "");
			if ($res1 && $res2)
				echo "ok";
		}
		elseif ($tab["act"] == "up")
		{
			if ($tab["decoup"] != "true")
				$tab["decoup"] = 0;
			else
				$tab["decoup"] = 1;
			if ($tab["visu"] != "true")
				$tab["visu"] = 0;
			else
				$tab["visu"] = 1;
			if ($tab["evaluation"] != "true")
				$tab["evaluation"] = 0;
			else
				$tab["evaluation"] = 1;
				
			$requete_1 = "UPDATE tb_droit_projet SET droit_decoupage='".$tab["decoup"]."', droit_visualisation='".$tab["visu"]."', droit_evaluation='".$tab["evaluation"]."' WHERE id_user='".$tab["id_usr"]."' AND id_projet='".$tab["id_prj"]."'";

			$res1 = querybd($requete_1, "");
			if ($res1)
				echo "ok";
		}
	}
}
?>