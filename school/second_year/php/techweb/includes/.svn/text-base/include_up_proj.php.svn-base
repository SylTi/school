<?php
session_start();
include("../modules/fonctions.php");
if (!$_SESSION)
	echo "Vous n'etes pas loggues";
else
{
	$tab = secure_tab($_GET);
	$tab["desc"] = ereg_replace(".ff.", "<br />", $tab["desc"]);
	if (verif_droit($_SESSION["id"], $tab["id"], "admin")){
		$request = "UPDATE tb_projet SET debut_projet='".sql_date($tab["debut"])."', titre_projet='".$tab["titre"]."', description_projet='".$tab["desc"]."' WHERE id_projet='".$tab["id"]."'";
		$res = querybd($request, "");
		if ($res)
			echo "Votre projet a bien ete mis a jour !";
	}
}
?>