<?php
session_start();

if (!$_SESSION)
echo "Merci de vous logguer";
else
{
	include("../modules/fonctions.php");
	switch ($_GET["type"]){
		case "edit":
			if (verif_droit($_SESSION["id"], $_GET["id"], "admin"))
			{
				$request = "SELECT * FROM tb_projet WHERE id_projet='".$_GET["id"]."'";
				$tab = querybd($request, "tab");
				if ($tab[0]["id_god_projet"] == 0)
				$god = "projet";
				else
				$god = "";
				$string = "
				<div style='height: 18px;'></div>
				<form name=\"update_sprojet\" action=\"javascript: void(0);\" Onsubmit=\"verif_update('".$god."'); return false;\">
				<input type=\"hidden\" id=\"id\" value=\"".$_GET["id"]."\">
				Titre::<br />
				<input type=\"text\" class=\"input_\" value=\"".$tab[0]["titre_projet"]."\" id=\"titre_u\"><br />
				Date de debut ::<br />
				<input type=\"text\" class=\"input_\" value=\"".human_date($tab[0]["debut_projet"])."\" id=\"date_debut_u\"><br />
				Description ::<br />
				<textarea class=\"text_\" id=\"description_u\">".ereg_replace("<br />", "\n", $tab[0]["description_projet"])."</textarea><br />
				<input type=\"submit\" value=\"Valider\" class=\"submit_\">
				</form>
				";
				echo $string;
			}
			else
			{
				echo "Vous n'avez pas les droits";
			}
			break;
		case "delete":
			if (verif_droit($_SESSION["id"], $_GET["id"], "admin"))
			{
				$request = "SELECT * FROM tb_projet WHERE id_pere_projet='".$_GET["id"]."'";
				$res = querybd($request, "");

				if (mysql_num_rows($res) == 0)
				{
					$request = "SELECT * FROM tb_projet WHERE id_projet='".$_GET["id"]."'";
					$tab = querybd($request, "tab");
					$string = "
					<div style=\"text-align: center; margin-top: 35px;\">
					Vous etes sur le point de supprimer&nbsp;&nbsp;<b>'".$tab[0]["titre_projet"]."'</b>.<br />
					Etes-vous certain de vouloir faire ceci ?<br />
					<br />
					<a href=\"javascript: void(0);\" Onclick=\"javascript: delete_sprojet(".$_GET["id"].");\">Supprimer&nbsp;&nbsp;'".$tab[0]["titre_projet"]."' !</a> - <a href=\"javascript: void(0);\" Onclick=\"javascript: document.getElementById('shadow').style.display='none';\">J'ai change d'avis !</a>
					</div>";
					echo $string;
				}
				else
				{
					echo "<div style=\"text-align: center; margin-top: 35px;\">
					Des dependances sont encore liees a cette activite, veuillez d'abord les supprimer avant de supprimer celle-ci !<br />
					<br />
					<a href=\"javascript: void(0);\" Onclick=\"javascript: document.getElementById('shadow').style.display='none'; select_sub_proj(".$_GET["id"].");\">Voir les dependances</a>
					</div>";
				}
			}else
			echo "Vous n'avez pas les droits";
			break;
		case "presta":
			$request = "SELECT * FROM tb_users_projet, phpbb_users, tb_projet WHERE tb_users_projet.id_projet='".$_GET["id"]."' AND tb_users_projet.id_user=phpbb_users.user_id AND tb_projet.id_projet='".$_GET["id"]."'";
			$tab = querybd($request, "tab");
			$i = 0;
			$string = "
				<div style=\"margin: 2px; float: left; width: 240px;\">
					Login ::
				</div>
				<div style=\"margin: 2px; float: left; width: 150px;\">
					Action ::
				</div>
				<div style=\"clear: both; height: 12px;\"></div>";
			while($i < sizeof($tab))
			{
				if ($tab[$i]["id_user"] == $tab[$i]["id_master_projet"]){
					$rank = "vert_10";
					$input = "None";

				}else{
					$rank = "";
					$input = "<a href=\"javascript: void(0);\" Onclick=\"presta('".$_GET["id"]."', '".$tab[0]["id_user"]."', 'del')\">Supprimer</a> - <a href=\"javascript: void(0);\" Onclick=\"javascript: display_good_form('".$_GET["id"]."', 'presta_ed', '".$tab[$i]["id_user"]."')\">Editer</a>";
				}
				$string .= "
				<div style=\"margin: 2px; float: left; width: 240px; border-bottom: 1px dotted #000;\">
					<span class=\"".$rank."\">".$tab[$i]["username"]."</span>
				</div>
				<div style=\"margin: 2px; float: left; width: 150px;\">
					".$input."
				</div>
				<div style=\"clear: both;\"></div>";
				$i++;
			}
			echo $string;
			break;
		case "presta_ed":
			$request = "SELECT * FROM tb_droit_projet, phpbb_users WHERE tb_droit_projet.id_user='".$_GET["id_usr"]."' AND tb_droit_projet.id_projet='".$_GET["id"]."' AND tb_droit_projet.id_user=phpbb_users.user_id";
			$tab = querybd($request, "tab");
			if ($tab[0]["droit_decoupage"] == 1)
			$droit_decoupage = "checked";
			else
			$droit_decoupage = "";
			if ($tab[0]["droit_visualisation"] == 1)
			$droit_visualisation = "checked";
			else
			$droit_visualisation = "";
			if ($tab[0]["droit_evaluation"] == 1)
			$droit_evaluation = "checked";
			else
			$droit_evaluation = "";

			$string = "
				<div style=\"margin: 5px; float: left; width: 240px; border-bottom: 1px dotted #000;\">
					Login ::
				</div>
				<div style=\"margin: 5px; float: left; width: 150px;\">
				".$tab[0]["username"]."
				</div>
				<div style=\"clear: both;\"></div>
				<div style=\"margin: 5px; float: left; width: 240px; border-bottom: 1px dotted #000;\">
					Droit de decoupage ::
				</div>
				<div style=\"margin: 5px; float: left; width: 150px;\">
				<input type=\"checkbox\" id=\"decoupage\" value=\"1\" checked=\"".$droit_decoupage."\">
				</div>
				<div style=\"clear: both;\"></div>
				<div style=\"margin: 5px; float: left; width: 240px; border-bottom: 1px dotted #000;\">
					Droit de visualisation ::
				</div>
				<div style=\"margin: 5px; float: left; width: 150px;\">
				<input type=\"checkbox\" id=\"visualisation\" value=\"1\" checked=\"".$droit_visualisation."\">
				</div>
				<div style=\"clear: both;\"></div>
				<div style=\"margin: 5px; float: left; width: 240px; border-bottom: 1px dotted #000;\">
					Droit d'evaluation ::
				</div>
				<div style=\"margin: 5px; float: left; width: 150px;\">
				<input type=\"checkbox\" id=\"evaluation\" value=\"1\" checked=\"".$droit_evaluation ."\">
				</div>
				<div style=\"clear: both;\"></div>
				<div style=\"margin: 5px; float: left; width: 240px;\">
					<a href=\"javascript: void(0)\" Onclick=\"presta('".$_GET["id"]."', '".$_GET["id_usr"]."', 'up');\">Valider</a>
				</div>
				<div style=\"margin: 5px; float: left; width: 150px;\">

				</div>";
			echo $string;
			break;



			/*

			case "edit_evalsub1":
			if (verif_droit($_SESSION["id"], $_GET["id"], "admin"))
			{
			$request = "SELECT * FROM tb_projet, phpbb_users, tb_taskeval WHERE tb_projet.id_projet='".$_GET["id"]."' AND  tb_projet.id_master_projet=phpbb_users.user_id";
			$tab = querybd($request, "tab");
			echo "debut : ";
			echo $duree_tmp;
			echo $accomp;

			echo "<div style='margin-top:5px;width:90%;'>
			<p>Evaluez l'état d'avancement de votre tache :</p>
			<p>".$tab[0]['titre_projet']."</p>
			<p><form style='float:left;width:100%;'  action=\"javascript: void(0);\" return false;\">Completez le nombre de jours nécéssaires pour finaliser cette tâche.<br />
			<a href=\"javascript: void(0);\" Onclick=\"javascript: edit_evalpoucentage(".$_GET["id"].",'','');\" return false;\">Valider l'état d'avancement de&nbsp;&nbsp;".$tab[0]["titre_projet"]." !</a>
			</form>
			</div>";}else
			{
			echo "Vous n'avez pas les droits";
			}
			break;
			*/



		case "edit_eval":
			$request = "SELECT * FROM tb_projet, tb_taskeval WHERE tb_projet.id_projet='".$_GET["id"]."' AND  `id_projet`=`id_task` order by date_modif desc limit 1";
			$tab = querybd($request, "tab");
			$nbjours = $tab[0]['duree_tmp'];
			$req_finproj = "select debut_projet, DATE_ADD(debut_projet,INTERVAL '$nbjours' DAY) as finpproj  FROM `tb_projet`, `tb_taskeval` WHERE `id_god_projet` ='$id_project' and `id_projet`=`id_task` or `id_projet`='$id_project'  and `id_projet`=`id_task` group by `type_projet` asc";
			$tab_finproj = querybd($req_finproj, "tab");

			$test = "<div style='margin-top:5px;width:100%;'>
			<p><strong>Evaluez l'état d'avancement de votre tâche</strong> (sur un taux horaire de 35h/semaine) :</p>
			<p style='margin:0;padding:0;'><strong><u>".ucfirst($tab[0]['titre_projet'])."</u></strong> :<br />
nombre de jour(s) strict : <strong>".$tab[0]['duree_tmp']."</strong><br />
Fin prévue le : <strong>".$tab_finproj[0]['finpproj']."</strong><br />
			<p style='float:left;width:100%;margin:0;padding:0;'><br />
			<form id=\"sel_accomp\" action=\"javascript: void(0);\" return false;\">
			<strong><u>Editer</u></strong> : <input type='text' class=\"input_\" maxlength='4' style='width:30px;text-align:right;' id=\"duree_tmp\"> jours de developpement necessaires.<br />
[/!\ : Cette modification réinitialise la date de début de la tâche à aujourd'hui.]<br />
<br />
<a href=''>Cette tâche nécéssite un jour de moins.</a><br />
<a href=''>Cette tache nécéssite un jour de plus.</a>
</p><br />
			<input type=\"hidden\" id=\"accomp\" value='0'>
			<input type=\"hidden\" id=\"fin_projet\" value='".$tab_finproj[0]['finpproj']."'>
			<input type=\"hidden\" id=\"id\" value=\"".$_GET["id"]."\"><br />
			<input type=\"submit\" value=\"Valider\" class=\"submit_2\" OnClick=\"javascript: edit_evalpoucentage(".$_GET["id"].");\"></form></p>
			</div>";
			echo utf8_encode($test);
			break;

			/*
			case "annuler_m" :
			$request = "SELECT * FROM tb_projet WHERE id_projet='".$_GET["id"]."'";
			$tab = querybd($request, "tab");
			$string = "
			<div style=\"text-align: center; margin-top: 35px;\">
			Vous etes sur le point de tronquer cette branche a partir de &nbsp;&nbsp;<b>'".$tab[0]["titre_projet"]."'</b>.<br />
			Etes-vous certain de vouloir faire ceci ?<br />
			<br />
			<a href=\"javascript: void(0);\" Onclick=\"javascript: abord_projet(".$_GET["id"].", 'abo');\">Tronquer a partir de &nbsp;&nbsp;'".$tab[0]["titre_projet"]."' !</a> - <a href=\"javascript: void(0);\" Onclick=\"javascript: document.getElementById('shadow').style.display='none';\">J'ai change d'avis !</a>
			</div>";
			echo $string;

			*/
























		case "annuler" :
			$request = "SELECT * FROM tb_projet WHERE id_pere_projet='".$_GET["id"]."'";
			$res = querybd($request, "");
			$request = "SELECT * FROM tb_projet WHERE id_projet='".$_GET["id"]."'";
			$tab = querybd($request, "tab");
			$string = "
			<div style=\"text-align: center; margin-top: 35px;\">
			Vous etes sur le point de tronquer cette branche a partir de &nbsp;&nbsp;<b>'".$tab[0]["titre_projet"]."'</b>.<br />
			Etes-vous certain de vouloir faire ceci ?<br />
			<br />
			<a href=\"javascript: void(0);\" Onclick=\"javascript: abord_sprojet(".$_GET["id"].", 'abo');\">Tronquer a partir de &nbsp;&nbsp;'".$tab[0]["titre_projet"]."' !</a> - <a href=\"javascript: void(0);\" Onclick=\"javascript: document.getElementById('shadow').style.display='none';\">J'ai change d'avis !</a>
			</div>";
			echo $string;
			break;
		case "annuler_m" :
			$request = "SELECT * FROM tb_projet WHERE id_projet='".$_GET["id"]."'";
			$tab = querybd($request, "tab");
			$string = "
			<div style=\"text-align: center; margin-top: 35px;\">
			Vous etes sur le point de tronquer cette branche a partir de &nbsp;&nbsp;<b>'".$tab[0]["titre_projet"]."'</b>.<br />
			Etes-vous certain de vouloir faire ceci ?<br />
			<br />
			<a href=\"javascript: void(0);\" Onclick=\"javascript: abord_projet(".$_GET["id"].", 'abo');\">Tronquer a partir de &nbsp;&nbsp;'".$tab[0]["titre_projet"]."' !</a> - <a href=\"javascript: void(0);\" Onclick=\"javascript: document.getElementById('shadow').style.display='none';\">J'ai change d'avis !</a>
			</div>";
			echo $string;
			break;

		case "restor" :
			$request = "SELECT * FROM tb_projet WHERE id_pere_projet='".$_GET["id"]."'";
			$res = querybd($request, "");
			$request = "SELECT * FROM tb_projet WHERE id_projet='".$_GET["id"]."'";
			$tab = querybd($request, "tab");
			$string = "
			<div style=\"text-align: center; margin-top: 35px;\">
			Vous etes sur le point de restaurer cette branche a partir de &nbsp;&nbsp;<b>'".$tab[0]["titre_projet"]."'</b>.<br />
			Etes-vous certain de vouloir faire ceci ?<br />
			<br />
			<a href=\"javascript: void(0);\" Onclick=\"javascript: abord_sprojet(".$_GET["id"].", 'rest');\">Restaurer a partir de &nbsp;&nbsp;'".$tab[0]["titre_projet"]."' !</a> - <a href=\"javascript: void(0);\" Onclick=\"javascript: document.getElementById('shadow').style.display='none';\">J'ai change d'avis !</a>
			</div>";
			echo $string;
			break;
		case "restor_m" :
			$request = "SELECT * FROM tb_projet WHERE id_projet='".$_GET["id"]."'";
			$tab = querybd($request, "tab");
			$string = "
			<div style=\"text-align: center; margin-top: 35px;\">
			Vous etes sur le point de restaurer cette branche a partir de &nbsp;&nbsp;<b>'".$tab[0]["titre_projet"]."'</b>.<br />
			Etes-vous certain de vouloir faire ceci ?<br />
			<br />
			<a href=\"javascript: void(0);\" Onclick=\"javascript: abord_projet(".$_GET["id"].", 'rest');\">Restaurer a partir de &nbsp;&nbsp;'".$tab[0]["titre_projet"]."' !</a> - <a href=\"javascript: void(0);\" Onclick=\"javascript: document.getElementById('shadow').style.display='none';\">J'ai change d'avis !</a>
			</div>";
			echo $string;
			break;

		case "delete_proj" :
			if (verif_droit($_SESSION["id"], $_GET["id"], "admin"))
			{
				$request = "SELECT * FROM tb_projet WHERE id_projet='".$_GET["id"]."'";
				$tab = querybd($request, "tab");
				$string = "
				<div style=\"text-align: center; margin-top: 35px;\">
				Vous etes sur le point de supprimer&nbsp;&nbsp;<b>'".$tab[0]["titre_projet"]."'</b>.<br />
				Etes-vous certain de vouloir faire ceci ?<br />
				<br />
				<a href=\"javascript: void(0);\" Onclick=\"javascript: delete_projet(".$_GET["id"].");\">Supprimer&nbsp;&nbsp;'".$tab[0]["titre_projet"]."' !</a> - <a href=\"javascript: void(0);\" Onclick=\"javascript: document.getElementById('shadow').style.display='none';\">J'ai change d'avis !</a>				<input type=\"submit\" value=\"Valider\" class=\"submit_\">

				</div>";
				echo $string;
			}else
			echo "Vous n'avez pas les droits";
			break;

	}
}
?>