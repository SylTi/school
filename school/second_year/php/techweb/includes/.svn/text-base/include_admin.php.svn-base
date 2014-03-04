<?php

if ($_GET["view"] == "admin" && isset($_SESSION["login"]))
{
	if ($_GET["page"] == "view_user") {
		if ($_GET["order"] == "all") 
			$requete = "SELECT user_id, username, user_email FROM phpbb_users ORDER by user_id";
		elseif ($_GET["order"] == "admin")
			$requete = "SELECT user_id, username, user_email FROM phpbb_users WHERE `group_id` != '6' ORDER by user_id";
		else
			$requete = "SELECT user_id, username, user_email FROM phpbb_users WHERE `group_id` = '2' ORDER by user_id";
		$tab = querybd($requete, "tab");
		$oSmarty->assign("all_users", $tab);
	}
	elseif ($_GET["page"] == "edit_user" && isset($_GET["user_id"]) && !isset($_POST["login"])) {
		if (is_numeric($_GET["user_id"]));
		{
			$user_id = $_GET["user_id"];
			$requete = "SELECT `username` , `user_email` , `user_birthday` , `user_icq` , `user_aim` , 
			`user_yim` , `user_msnm`, `user_jabber` , `user_website`, `user_rank` FROM `phpbb_users` WHERE user_id = '$user_id'";
			$result = querybd($requete, "str");
			$requete = "SELECT * FROM phpbb_users_info WHERE user_id = '$user_id'";
			$result2 = querybd($requete, "str");
			$oSmarty->assign("res_user", $result);
			$oSmarty->assign("res_user2", $result2);
		}
	}

	elseif ($_GET["page"] == "edit_user" && isset($_GET["user_id"]) && isset($_POST["login"])) {
		if (is_numeric($_GET["user_id"]));
		{
			$user_id = $_GET["user_id"];
			$tab = secure_tab($_POST);
			$login = $tab["login"];
			$password = $tab["password"];
			$mail = $tab["mail"];
			$nom = $tab["nom"];
			$prenom = $tab["prenom"];
			$location = $tab["location"];
			$birth = $tab["birth"];
			$societe = $tab["societe"];
			$icq = $tab["icq"];
			$aim = $tab["aim"];
			$yim = $tab["yim"];
			$msn = $tab["msn"];
			$jabber = $tab["jabber"];
			$site = $tab["site"];

			if ($tab["rank"] == "Administrateur")
				$rank = "1";
			else 
				$rank = "0";
				
			$requete = "UPDATE phpbb_users SET `username`='$login' , `user_email`='$mail' , `user_birthday`='$birth' ,
			 			`user_icq`='$icq', `user_aim`='$aim' , `user_yim`='$yim' ,`user_msnm`='$msn', 
			 			`user_jabber`='$jabber' , `user_website`='$site', `user_rank`='$rank'";
			if (isset($password))
			{
				$new_pass = md5($password);
				$requete = $requete . ", `user_password`='$new_pass'";
			}
			if ($rank = "1")
				$requete = $requete . ", `user_type`='3', `group_id`='5'";
			$requete = $requete . " WHERE user_id = '$user_id'";
			
			$requete2 = "UPDATE phpbb_users_info SET `user_societe`='$societe', `user_name`='$prenom', `user_lastname`='$nom', 
			`user_location`='$location' WHERE user_id = '$user_id'";
			querybd($requete, "");
			querybd($requete2, "");
		}
	}
	
	elseif ($_GET["page"] == "delete_user" && isset($_GET["user_id"])) {
		if (is_numeric($_GET["user_id"]))
		{
			$user_id = $_GET["user_id"];
			$requete = "DELETE FROM phpbb_users WHERE user_id = '$user_id'";
			$nb = querybd($requete, "");
			$requete = "DELETE FROM php_user_group WHERE user_id = '$user_id'";
			$nb2 = querybd($requete, "");
			$requete = "DELETE FROM php_users_info WHERE user_id = '$user_id'";
			$nb3 = querybd($requete, "");
			if (nb == 0 && nb2 == 0 && nb3 == 0)
				$oSmarty->assign("res_delete", "L'utilisateur $user_id a bien ete supprime");
			else
				$oSmarty->assign("error", "Probleme lors de la suppression.");
		}
		else
			$oSmarty->assign("error", "Il n'y a que des chiffres dans l'id connard !");
	}
	
	elseif ($_GET["page"] == "view_project" && !isset($_GET["id_project"])) {
		$requete = "SELECT `id_projet` , `type_projet` , `id_master_projet` , `description_projet` , `debut_projet`,
				 `fin_projet` , `titre_projet` , `id_pere_projet` FROM `tb_projet` WHERE `id_pere_projet` = '0' ORDER BY `id_projet`";
		$tab = querybd($requete, "tab");
		$oSmarty->assign("all_proj", $tab);
	}
	
	elseif ($_GET["page"] == "view_project" && isset($_GET["id_project"])) {
		if (is_numeric($_GET["id_project"]))
		{
			$id_project = $_GET["id_project"];
			$oSmarty->assign("select_proj_parent", get_proj_parent($id_project));
			$oSmarty->assign("select_proj", get_proj_childs($id_project));
			$oSmarty->assign("user_proj", user_proj($id_project));
		}
	}
	elseif ($_GET["page"] == "delete_project" && isset($_GET["id_project"])) {
		if (is_numeric($_GET["id_project"]))
		{
			$id_project = $_GET["id_project"];
			delete_proj($id_project);
		}
	}
	elseif ($_GET["page"] == "delete_child_project" && isset($_GET["id_project"])) {
		if (is_numeric($_GET["id_project"]))
		{
			$id_project = $_GET["id_project"];
			delete_child($id_project);
		}
	}
	elseif ($_GET["page"] == "delete_project_user" && isset($_GET["user_id"]) && isset($_GET["id_project"])){
		if (is_numeric($_GET["user_id"]) && is_numeric($_GET["id_project"]))
		{
			$user_id = $_GET["user_id"];
			$id_project = $_GET["id_project"];
			delete_proj_user($user_id, $id_project);
		}
	}
}
else 
	$oSmarty->assign("error", "Erreur");
?>