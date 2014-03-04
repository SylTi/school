<?php
include("../modules/fonctions.php");
include("./include_connection.php");

//yo t'es moche

function get_subprojects_ids($id_projpapa){
	$requete = "SELECT id_projet
FROM phpbb_users, tb_projet
WHERE user_id = id_master_projet
AND tb_projet.id_pere_projet = $id_projpapa
GROUP BY id_projet DESC
ORDER BY fin_projet ASC
LIMIT 0 , 30";

	$tab = querybd($requete,"tab");
	//$res = mysql_query($requete);
	//while($row = mysql_fetch_array($res))
	//$tab.= array($row[id_projet]);

	return ($tab);
}



$tab = get_subprojects_ids(34);
echo $tab[0][0];
echo $tab[1][0].'<br /><br />';
// ou bien

$i=0;
while ($tab[$i][0]) {
	echo $tab[$i][0];
	$i++;
}
?> 

