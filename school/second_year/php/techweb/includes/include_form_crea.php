<?php
session_start();
include("include_connection.php");
include("../modules/fonctions.php");
$request = "SELECT * FROM tb_type_projet";
$query = mysql_query($request) or die ("Error: ".mysql_error());
if ($_GET["mod"] == "sprojet"){
$flag = 0;
	$request_dec = "SELECT * FROM tb_droit_projet, tb_projet, tb_users_projet WHERE tb_droit_projet.id_user='".$_SESSION["id"]."' AND tb_users_projet.id_user=tb_droit_projet.id_user AND tb_droit_projet.droit_decoupage='1' AND tb_droit_projet.id_projet=tb_projet.id_projet AND tb_users_projet.id_projet=tb_projet.id_projet AND tb_projet.id_pere_projet='0' AND tb_users_projet.user_confirm='1' ORDER BY tb_projet.id_god_projet ASC";
	$query_dec = mysql_query($request_dec) or die ("Error : ".mysql_error());

		$opt="";
		while ($row_dec = mysql_fetch_object($query_dec)){
				$opt .= "<option value=\"".$row_dec->id_projet."\" class=\"rouge\">".$row_dec->titre_projet."</option>";
				$requete_fils = "SELECT * FROM tb_droit_projet, tb_projet, tb_users_projet WHERE tb_droit_projet.id_user='".$_SESSION["id"]."' AND tb_users_projet.id_user=tb_droit_projet.id_user AND tb_droit_projet.droit_decoupage='1' AND tb_droit_projet.id_projet=tb_projet.id_projet AND tb_users_projet.id_projet=tb_projet.id_projet AND tb_users_projet.user_confirm='1' AND tb_projet.id_pere_projet='".$row_dec->id_projet."' ORDER BY tb_projet.id_god_projet ASC";
				$query_fils = mysql_query($requete_fils) or die ("Go die !");
				if (mysql_num_rows($query_dec) == 0)
				{
					if (mysql_num_rows($query_fils) == 0)
						$flag = 0;
					else
						$flag = 1;
				}
				else
					$flag = 1;


				while ($row_fils = mysql_fetch_object($query_fils)){
				$opt .= "<option value=\"".$row_fils->id_projet."\" class=\"gris\">&nbsp;&nbsp;&nbsp;".$row_fils->titre_projet."</option>";
				}
		}

		if ($flag == 0){
			$string = '<div id="projet_new" Onclick="load_crea(\'projet\')">Creer un projet</div>
				  <div id="sprojet_new_over" Onclick="load_crea(\'sprojet\')">Creer un sous-projet</div>
				  <div id="add_presta" Onclick="load_crea(\'presta\')">Ajouter un prestataire</div><br /><br />
				  <div id="form_crea">
				  <span class="vert_12">Vous n\'etes inscrit a aucun projet</span></div>
				  ';
		}else{
			$string = '<div id="projet_new" Onclick="load_crea(\'projet\')">Creer un projet</div>
			  <div id="sprojet_new_over" Onclick="load_crea(\'sprojet\')">Creer un sous-projet</div>
			  <div id="add_presta" Onclick="load_crea(\'presta\')">Ajouter un prestataire</div><br /><br />
			  <div id="form_crea">
					<form id="crea_projet" name="crea_projet" action="javascript: void(0);" method="post" method="post" Onsubmit="verif_creat_proj(\'sprojet\'); return false">
									<div><p>Projet pere ::</p> <select name="pere_projet" class="select_" id="id_pere">'.$opt.'</select></div>
									<div><p>Titre ::</p> <input type="text" class="input_" id="titre" /></div>
									<div><p>Date debut ::</p> <input type="text" class="input_" id="date_debut" /></div>
								   
									<div><p>Type de projet ::</p> <select class="select_" id="type" />';
				while ($row = mysql_fetch_object($query))
				{
					$string .= "<option value=\"".$row->id_type."\">".$row->nom_type."</option>";
				}
		$string .= '</select></div>
					Description ::<br /><textarea class="text_" id="description"></textarea>
					<br />
					<input type="submit" value="Envoyer" class="submit_2" />
				</form>
			</div>
			<div style="clear: both;"></div>';
		}

}
elseif ($_GET["mod"] == "presta"){

	$request_dec = "SELECT * FROM tb_droit_projet, tb_projet, tb_users_projet WHERE tb_droit_projet.id_user='".$_SESSION["id"]."' AND tb_users_projet.id_user=tb_droit_projet.id_user AND tb_droit_projet.droit_decoupage='1' AND tb_droit_projet.id_projet=tb_projet.id_projet AND tb_users_projet.id_projet=tb_projet.id_projet AND tb_projet.id_pere_projet='0' AND tb_users_projet.user_confirm='1' ORDER BY tb_projet.id_god_projet ASC";
	$query_dec = mysql_query($request_dec) or die ("Error : ".mysql_error());

		$flag = 0;
		$opt="<select class=\"select_\" onclick=\"javascript: check_users(this.value)\" id=\"projet_a\">";

		while ($row_dec = mysql_fetch_object($query_dec)){
				$opt .= "<option value=\"".$row_dec->id_projet."\" class=\"rouge\">".$row_dec->titre_projet."</option>";
				$requete_fils = "SELECT * FROM tb_droit_projet, tb_projet, tb_users_projet WHERE tb_droit_projet.id_user='".$_SESSION["id"]."' AND tb_users_projet.id_user=tb_droit_projet.id_user AND tb_droit_projet.droit_decoupage='1' AND tb_droit_projet.id_projet=tb_projet.id_projet AND tb_users_projet.id_projet=tb_projet.id_projet AND tb_users_projet.user_confirm='1' AND tb_projet.id_pere_projet='".$row_dec->id_projet."' ORDER BY tb_projet.id_god_projet ASC";
				$query_fils = mysql_query($requete_fils) or die ("Go die !");
			if (mysql_num_rows($query_dec) == 0)
			{
				if (mysql_num_rows($query_fils) == 0)
					$flag = 0;
				else
					$flag = 1;
			}
			else
				$flag = 1;
				while ($row_fils = mysql_fetch_object($query_fils)){
				$opt .= "<option value=\"".$row_fils->id_projet."\" class=\"gris\">&nbsp;&nbsp;&nbsp;".$row_fils->titre_projet."</option>";
				}
		}
		$opt .= "</select>";
		if ($flag == 0)
			$string = '<div id="projet_new" Onclick="load_crea(\'projet\')">Creer un projet</div>
			<div id="sprojet_new" Onclick="load_crea(\'sprojet\')">Creer un sous-projet</div>
			<div id="add_presta_over" Onclick="load_crea(\'presta\')">Ajouter un prestataire</div><br /><br />
			
			<div id="form_crea"><span class="vert_12">Vous n\'etes inscrit a aucun projet</span></div>';
		else	
			$string = '<div id="projet_new" Onclick="load_crea(\'projet\')">Creer un projet</div>
			<div id="sprojet_new" Onclick="load_crea(\'sprojet\')">Creer un sous-projet</div>
			<div id="add_presta_over" Onclick="load_crea(\'presta\')">Ajouter un prestataire</div><br /><br />
			
			<div id="form_crea">
			<form id="addingeuh" name="addingeuh" action="javascript: void(0);" method="post" Onsubmit="maislol();">
			<p><div style="width: 100px; float: left; text-align: left;" class="gris_10">Projet :: </div>'.$opt.'</select></p><br />
			<p><div style="width: 100px; float: left; text-align: left;" class="gris_10">Prestataires :: </div><span id="presta"></span></p><br />
			</form>
			</div>';
}
else
{
	$string = '<div id="projet_new_over" Onclick="load_crea(\'projet\')">Creer un projet</div>
          	<div id="sprojet_new" Onclick="load_crea(\'sprojet\')">Creer un sous-projet</div>
			<div id="add_presta" Onclick="load_crea(\'presta\')">Ajouter un prestataire</div><br /><br />
			<div id="form_crea">
				<form id="crea_projet" name="crea_projet" action="javascript: void(0);" method="post" method="post" Onsubmit="verif_creat_proj(\'projet\'); return false">
                            	<div><p>Titre ::</p> <input type="text" class="input_" id="titre" /></div>
                                <div><p>Date debut ::</p> <input type="text" class="input_" id="date_debut" /></div>
                                <div><p>Type de projet ::</p> <select class="select_" id="type" />';
			while ($row = mysql_fetch_object($query))
			{
				$string .= "<option value=\"".$row->id_type."\">".$row->nom_type."</option>";
			}
	$string .= '</select></div>
				Description ::<br /><textarea class="text_" id="description"></textarea>
				<br />
				<input type="submit" value="Envoyer" class="submit_2" />
			</form>
		</div>';
}
echo $string;
?>