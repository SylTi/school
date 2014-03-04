<?php
	session_start();
	include("include_connection.php");
	include("../modules/fonctions.php");
	if (!isset($_SESSION))
		echo "Vous n'etes pas logges";
	else{
		if (verif_droit($_SESSION["id"], $_GET["id_prj"], "decoupage")){
			$requete_add = "SELECT * FROM tb_users_projet WHERE id_projet='".$_GET["id_prj"]."'";
			$tab_add = querybd($requete_add, "tab");
			$requete_inc = "SELECT * FROM phpbb_users";
			$tab_inc = querybd($requete_inc, "tab");
			
			$tab = nice_tab($tab_inc, $tab_add);
			$i = 0;
			$string = "<select class='select_' id='presta_a'>";
			while ($i < sizeof($tab))
			{
				$string .= "<option value='".$tab[$i]["id"]."'>".$tab[$i]["name"]."</option>";
				$i++;
			}
			$string .= "</select><br />
			<p><div style='width: 100px; float: left; text-align: left;' class=\"gris_10\">droit decoupage :: </div><input type=\"checkbox\" value=\"1\" id=\"decoup_a\"></p><br />
			<p><div style='width: 100px; float: left; text-align: left;' class=\"gris_10\">droit visualisation :: </div><input type=\"checkbox\" value=\"1\" id=\"visu_a\"></p><br />
			<p><div style='width: 100px; float: left; text-align: left;' class=\"gris_10\">droit evaluation :: </div><input type=\"checkbox\" value=\"1\" id=\"eval_a\"></p><br />
			<input type='submit' class='submit_'>
			";
			
			echo $string;
		}
		else
			echo "<div style=\"text-align: center; margin-top: 35px;\">
			Vous n'avez pas les droits pour faire ceci !</div>";
	}
?>