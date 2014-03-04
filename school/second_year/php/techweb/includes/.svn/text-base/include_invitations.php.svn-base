<?php
if (!$_SESSION)
	$oSmarty->assign('message', "Vous n'etes pas loggue !");
else
{
	$requete = "SELECT * FROM tb_type_projet, tb_users_projet, tb_projet, tb_droit_projet, phpbb_users WHERE tb_users_projet.id_user='".$_SESSION["id"]."' AND tb_users_projet.user_confirm='0' AND tb_projet.id_projet=tb_users_projet.id_projet AND tb_droit_projet.id_projet=tb_projet.id_projet AND tb_droit_projet.id_user=tb_users_projet.id_user AND phpbb_users.user_id=tb_projet.id_master_projet AND tb_type_projet.id_type=tb_projet.type_projet";
	$tab = querybd($requete, "tab");
	$nb = sizeof($tab);
	if ($nb > 1)
		$s="s";
	else
		$s="";
	if ($nb > 0)
		$oSmarty->assign('nb', "Vous avez actuellement ".$nb." invitation".$s);
	else
		$oSmarty->assign('nb', "Vous n'avez actuellement aucune invitation");
		
	$oSmarty->assign('tab', $tab);
}
?>