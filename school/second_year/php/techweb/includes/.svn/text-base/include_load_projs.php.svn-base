<?php
session_start();
include("../modules/fonctions.php");
include("include_connection.php");

if ($_SESSION){
	$request = "SELECT * FROM tb_projet, phpbb_users, tb_users_projet, tb_type_projet WHERE tb_users_projet.id_user='".$_SESSION["id"]."' AND tb_users_projet.id_projet=tb_projet.id_projet AND phpbb_users.user_id=tb_projet.id_master_projet AND tb_projet.id_pere_projet='0' AND tb_type_projet.id_type=tb_projet.type_projet AND tb_users_projet.user_confirm='1'";
	$query = mysql_query($request) or die ("Error request :".mysql_error());
	$i = 0;
	if (mysql_num_rows($query) == 0)
	$tab[0] = "Vous n'est actuellement assigne a aucun projet";
	while ($row = mysql_fetch_array($query))
	{
		if ($row["id_master_projet"] == $_SESSION["id"])
		$classe = "fond_proj_main";
		else
		$classe = "fond_proj";

		$requestx = "SELECT * FROM tb_users_projet, phpbb_users WHERE tb_users_projet.id_projet='".$row["id_projet"]."' AND phpbb_users.user_id=tb_users_projet.id_user AND tb_users_projet.user_confirm='1'";
		$queryx = mysql_query($requestx) or die("Error:".mysql_error());
		$string = "";
		while ($row_usr = mysql_fetch_object($queryx))
		{
			if (strlen($row_usr->username) > 7) {
			$string .= substr($row_usr->username, 0, 10)."...";
			}
else		$string .= $row_usr->username;
		}

		/*Declaration des menu droits*/



		$opt = "";
		if ($_SESSION["id"] == $row["id_master_projet"]){
			$opt .= "<p class='edit_proj'><a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row["id_projet"]."', 'edit')\">Editer</a> | <a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row["id_projet"]."', 'delete_proj')\">Supprimer</a> | <a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row["id_projet"]."', 'annuler_m')\">Annuler</a> | ";
			$opt_a = "<a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row["id_projet"]."', 'restor_m')\">Restaurer</a> | ";

			$opt .= "<a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row[0]."', 'presta')\">Gestion des prestataires</a> | ";

			$opt .= "<a href=\"javascript: void(0);\" Onclick=\"document.location.replace('index.php?view=eval&id=".$row["id_projet"]."')\")\">Vue Eval</a></p>";
		}

	if ($row["etat_projet"] == 0)
		{
			$opt2 = "
				<div class='sprojet1'>".$opt."</div>";
		}else{
			$opt2 = "<div class='sprojet1'>".$opt_a."</div>";
		}

		/*Fin declaration*/
		echo "".$opt2."
						<div class=\"".$classe."\" Onclick=\"select_sub_proj(".$row["id_projet"].")\">
							<div class=\"left_projet\">
								<div class=\"titre_projet\">
									<b><u>".utf8_encode($row["titre_projet"])." :: ".utf8_encode($row["nom_type"])."</u></b>
								</div>
								<div class=\"description_projet\">
									".utf8_encode($row["description_projet"])."
								</div>
								<div class=\"login_master\">
									Chef de projet :: <b><a href=\"mailto:".$row["user_email"]."\">".$row["username"]."</a></b>
								</div>
							</div>
							<div class=\"right_projet\">Prestataire(s) dispo : ".$string.".</div>
							<div style=\"clear: both\"></div>
						</div>
				";
		$i++;
	}
}else
echo "Vous n'etes pas loggues...";

?>