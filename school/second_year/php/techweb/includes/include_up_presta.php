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
		$requete_1 = "UPDATE tb_droit_projet SET droit_decoupage='".$tab["decoup"]."', droit_visualisation='".$tab["visu"]."', droit_evaluation='".$tab["evaluation"]."' WHERE id_user='".$tab["id_usr"]."' AND id_projet='".$tab["id_prj"]."'";
		$res1 = querybd($requete_1, "");
		if ($res1)
			echo "ok";
	}
}
?>