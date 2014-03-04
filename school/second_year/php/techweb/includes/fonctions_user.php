<?php

function get_proj_parent($id_proj)
{
	$requete1 = "SELECT `id_projet` , `type_projet` , `id_master_projet` , `description_projet` , `debut_projet`,
				 `fin_projet` , `titre_projet` , `id_pere_projet` FROM `tb_projet`
				 WHERE `id_projet` = '$id_proj' AND `id_pere_projet` = '0'";
	return (querybd($requete1, "str"));
}

function get_proj_childs($id_proj)
{
	$requete = "SELECT `id_projet` , `type_projet` , `id_master_projet` , `description_projet` , `debut_projet`,
				 `fin_projet` , `titre_projet` , `id_pere_projet` FROM `tb_projet`
				 WHERE `id_god_projet` = '$id_proj' ORDER BY `id_pere_projet`";

	return (querybd($requete, "tab"));
}

function delete_proj($id_proj)
{
	$requete = "DELETE FROM tb_projet WHERE id_god_projet = '$id_proj'";
	querybd($requete, "") or die("Impossible de supprimer le projet $id_proj");
	$requete2 = "DELETE FROM tb_projet WHERE id_projet = '$id_proj'";
	querybd($requete2, "") or die("Impossible de supprimer le projet $id_proj");
}

function delete_child($id_proj)
{
	$requete = "DELETE FROM tb_projet WHERE id_projet = '$id_proj'";
	querybd($requete, "");
}

function user_proj($id_proj)
{
	$requete = "SELECT * FROM tb_users_projet WHERE id_projet = '$id_proj' AND user_confirm = '1'";
	$tab = querybd($requete, "tab");
	$i = 0;
	while ($tab[$i])
	{
		$requete2 = "SELECT username, user_id FROM phpbb_users WHERE user_id = '".$tab[$i]['id_user']."'";
		$str_user = querybd($requete2, "str");
		$user[$i]["username"] = $str_user["username"];
		$user[$i]["user_id"] = $str_user["user_id"];
		//$user[$i]["id_project"] = $id_proj;
		$i++;
	}
	return ($user);
}

function delete_proj_user($user_id, $id_project)
{
	$requete = "DELETE FROM tb_users_projet WHERE id_user = '$user_id' AND id_projet = '$id_project'";
	querybd($requete, "") or die("Impossible de supprimer l'user dans user_projet.");
	$requete2 = "DELETE FROM tb_droit_projet WHERE id_user = '$user_id' AND id_projet = '$id_project'";
	querybd($requete2, "") or die("Impossible de supprimer les droit de l'user");
}

function get_eval_proj($id_proj)
{
	$requete1 = "SELECT `id_projet` , `type_projet` , `id_master_projet` , `description_projet` , `debut_projet`,
				 `fin_projet` , `titre_projet` , `id_pere_projet` FROM `tb_projet`
				 WHERE `id_projet` = '$id_proj'";
	$requete = "SELECT `id_projet` , `type_projet` , `id_master_projet` , `description_projet` , `debut_projet`,
				 `fin_projet` , `titre_projet` , `id_pere_projet` FROM `tb_projet`
				 WHERE `id_god_projet` = '$id_proj' ORDER BY `id_pere_projet`";
	$str = querybd($requete1, "str");
	$tab = querybd($requete, "tab");

	$j = 0;
	foreach($str as $cle => $valeur)
	$sauv[$j][$cle] = $valeur;
	$i = 0;
	$j = 1;
	while($tab[$i] != NULL)
	{
		foreach($tab[$i] as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i++;
		$j++;
	}
	return ($sauv);
}

?>