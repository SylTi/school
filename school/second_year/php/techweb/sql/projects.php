<?php
//Projets : trouve les projets associé a l'id du mem logué.
$request = "SELECT * FROM tb_projet, phpbb_users, tb_users_projet WHERE tb_users_projet.id_user='".$_SESSION["id"]."' AND tb_users_projet.id_projet=tb_projet.id_projet AND phpbb_users.user_id=tb_projet.id_master_projet AND tb_projet.id_pere_projet='0'";
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
	$request2 = "SELECT * FROM tb_users_projet, phpbb_users WHERE tb_users_projet.id_projet='".$row["id_projet"]."' AND phpbb_users.user_id=tb_users_projet.id_user";
	$query2 = mysql_query($request2) or die("Error:".mysql_error());
	$string = "";
	while ($row_usr = mysql_fetch_object($query2))
	{
		$string .= substr($row_usr->username, 0, 10)."...<br />";
	}
	$tab[$i] = "
					<div class=\"".$classe."\" Onclick=\"select_sub_proj(".$row["id_projet"].")\">
						<div class=\"left_projet\">
							<div class=\"titre_projet\">
								<b><u>".$row["titre_projet"]." :: ".$row["type_projet"]."</u></b>
							</div>
							<div class=\"description_projet\">
								".$row["description_projet"]."
							</div>
							<div class=\"login_master\">
								Chef de projet :: <b><a href=\"mailto:".$row["user_email"]."\">".$row["username"]."</a></b>
							</div>
						</div>
						<div class=\"right_projet\">
							".$string."<br />
						</div>
						<div style=\"clear: both\"></div>
					</div>
			";
	$i++;
}
$request3 = "SELECT * FROM tb_type_projet";
$query3 = mysql_query($request3) or die("Error:".mysql_error());
while ($row = mysql_fetch_object($query3))
{
	$type[$row->id_type] = $row->nom_type;
}
$oSmarty->assign('nb_projet', sizeof($tab));
$oSmarty->assign('type', $type);
$oSmarty->assign('projet', $tab);
?>