<?php
session_start();
if ($_SESSION['id'])
{
	include("include_connection.php");
	include("../modules/fonctions.php");
	$tab = secure_tab($_GET);
	$duree_tmp = $tab["duree_tmp"];
	$accomp = $tab["accomp"];
	$id_task = $tab["id"];

	$request = "select * from tb_taskeval, tb_projet where id_projet='".$id_task."' and id_projet = id_task order by date_modif desc limit 1";

	$request_in = "INSERT INTO tb_taskeval (duree_tmp, accomp, cdp_valid, id_task,lastmodif_userid,date_modif) VALUES ('".$duree_tmp."', '".$accomp."', '0', '".$id_task."','".$_SESSION[id]."',NOW())";

	$query = mysql_query($request) or die("Error :".mysql_error());
	$row = mysql_fetch_array($query);
	$last_id = $row['id'];

	if ($row['id_projet'] == "$id_task")
	{
		$my_id = $_SESSION['id'];

		$request_up = "UPDATE tb_taskeval SET duree_tmp = $duree_tmp, accomp = $accomp, lastmodif_userid = $my_id
	WHERE id = $last_id";
		$query = mysql_query($request_up);
		header("Location: index.php?view=evalu&id=$id_proj");
	}
	else
	$query = mysql_query($request_in) or die("Error :".mysql_error());
	header("Location: index.php?view=evalu&id=$id_proj");
}
else
echo "Vous n'etes pas loggues...";
mysql_close();

?>