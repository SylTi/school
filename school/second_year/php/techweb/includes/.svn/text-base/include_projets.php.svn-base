<?php
	session_start();
	include("../modules/fonctions.php");
	include("include_connection.php");

	$request = "SELECT id_projet, titre_projet, username, description_projet, DAY(debut_projet), MONTH(debut_projet), YEAR(debut_projet), DAY(fin_projet), MONTH(fin_projet), YEAR(fin_projet), etat_projet, id_god_projet FROM tb_projet, phpbb_users WHERE id_pere_projet=".$_GET["id"]." AND phpbb_users.user_id=tb_projet.id_master_projet";

	$query = mysql_query($request) or die (mysql_error());
	if (mysql_num_rows($query) == 0)
		echo "Aucune sous categorie n'a encore ete cree...";
	while ($row = mysql_fetch_array($query)){
			$opt = "";
			if (verif_droit($_SESSION["id"], $row[0], "admin")){
				$opt .= "<a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row[0]."', 'edit')\">Editer</a> | <a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row[0]."', 'delete')\">Supprimer</a> | <a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row[0]."', 'annuler')\">Annuler</a> | ";
				$opt_a = "<a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row[0]."', 'restor')\">Restaurer</a> | ";
			}
			if (verif_droit($_SESSION["id"], $row[0], "decoupage"))
				$opt .= "<a href=\"javascript: void(0);\" Onclick=\"display_good_form('".$row[0]."', 'presta')\">Gestion des prestataires</a> | ";
			if (verif_droit($_SESSION["id"], $row[0], "evaluation"))
				$opt .= "<a href=\"javascript: void(0);\" Onclick=\"document.location.replace('index.php?view=evalu&id=".$row[0]."')\">Evaluer cette tache</a> ";

			if ($row[10] == 0)
			{
				echo "<a href='javascript: void(0);' Onclick='select_sub_proj(".$row[0].")'>".$row[1]."</a><br />
				<div class='sprojet' style='width:100%;margin-left:-4px; margin-bottom: -6px;'>
					".$opt."
				</div>
				<div class='sprojet' style='width:100%;margin-left:-4px;'>
					<p><div style='width: 100px; float: left'>Chef de projet :: </div>".$row[2]."</p><br />
					<p><div style='width: 100px; float: left'>Date de debut :: </div>".$row[4]."/".$row[5]."/".$row[6]."</p><br />
<br />
					<p><div style='width: 100px; float: left'>Description :: </div>".$row[3]."</p><br />
				</div>";
			}
			else
			{
				if (verif_droit($_SESSION["id"], $row[11], "admin")){
					echo "<span class=\"vert_10\">".$row[1]."</span><br />
					<div class='sprojet_a' style='width:100%;margin-left:-4px; margin-bottom: -6px;'>
						".$opt_a."
					</div>
					<div class='sprojet' style='width:100%;margin-left:-4px;'>
						<p>Chef de projet</p> :: ".$row[2]."<br />
						<p>Description</p> :: ".$row[3]."<br />
						<p>Date de debut</p> :: ".$row[4]."/".$row[5]."/".$row[6]."<br />
						<p>Date de fin</p> :: ".$row[7]."/".$row[8]."/".$row[9]."<br />
					</div>";
				}
			}
	}
?>