<?php

function mysql_DateTime($d)
{
	$date = substr($d,8,2)." / ";        // jour
	$date = $date.substr($d,5,2)." / ";  // mois
	$date = $date.substr($d,0,4). ""; // année
	return $date;
}


function get_evalu_percent($id_proj)
{
	$prerequete = "select * from tb_taskeval, tb_projet where id_task = id_projet order by date_modif desc ";

	$requete_in = "INSERT INTO tb_taskeval (duree_tmp,accomp,cdp_valid,id_task,lastmodif_userid,date_modif)
	VALUE ('0','0','-1','$id_proj','$_SESSION[id]', NOW())";

	$preres = querybd($prerequete,"tab");
	while($preres[$i] != NULL)
	{
		foreach($preres[$i] as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i++;
		$j++;
	}

	$requete1 = "SELECT  id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif
FROM `tb_projet`, `tb_taskeval`
WHERE `id_projet`='$id_proj' and `id_task`=`id_projet`
order by duree_tmp asc";

	$requete = "SELECT  id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif
FROM `tb_projet`, `tb_taskeval`
WHERE `id_projet`='$id_proj' and `id_task`=`id_projet`
order by duree_tmp asc
";

	$str = querybd($requete1, "str");
	$tab = querybd($requete, "tab");

	if (!empty($str))
	{
		$j = 0;
		foreach($str as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i = 0;
		$j = 0;
		while($tab[$i] != NULL)
		{
			foreach($tab[$i] as $cle => $valeur)
			$sauv[$j][$cle] = $valeur;
			$i++;
			$j++;
		}
		return ($sauv);
	}
	else
	{
		@querybd($requete_in, "str");
		header('Location: index.php?view=evalu&id='.$id_proj.'');
	}
}

function pourcentage($values,$order, $showValue, $maxLength, $barHeight, $spacing, $gap, $tableWidth , $colors) {
	$a=$values;
	rsort($a);
	$maxValue=$a[0]; // gets maximum value of the array which will correspond to $maxLength

	($order==0 ? "" : ($order==1 ? asort($values) : arsort($values)));

	$captions=array_keys($values);
	$values=array_values($values);

	$ratio=$values;
	for ($i=0;$i<count($ratio);$i++) {
		$ratio[$i]/=$maxValue;
	}
	$numberValues=count($values);
	$defaultColors=array('purple','green','gold','gray','blue');

	if (empty($colors)) {
	($colors=$defaultColors);
	}

	while (count($colors)<$numberValues) {
		$colors = array_merge($colors,$colors);
	}

	$percent="<div width=$tableWidth style='margin:0;padding:0;height:10%;'>";

	for ($i=0;$i<$numberValues;$i++){
		$percent.="<div width=".($tableWidth/5-$gap)." style='float:left;'>".$captions[$i]."</div>";
		$percent.="<div width=".(4*$tableWidth/5)." style='float:left;margin-top:1px;'>";

		for ($j=0; $j<($maxLength*$ratio[$i]); $j++) {
			$percent.="<IMG src='./images/".$colors[$i].".png' height=$barHeight width=1>";
		}
		$percent.=($showValue ? "<i style='float:left;height:10px;margin:0;padding:0;'>".$values[$i]."%</i>" : "");
		$percent.="</div>";
	}

	$percent.="</div>";

	return ($percent);
}

if ((isset($_GET['view'])) && isset($_GET["id"])) {
	if (isset($_SESSION[login]) && $_SESSION[login] != "Anonymous"){
		$id_project = $_GET["id"];
		$tab = get_evalu_percent($id_project);
		$oSmarty->assign("select_eval", $tab);
	}
	$oSmarty->assign("erreur", "");
}
else {
	$oSmarty->assign("erreur", "Merci bien de ne pas vouloir couiller !<br /><br />");
}

function fin_pproj($id_project){
	$req_findate = "SELECT ROUND( AVG( (accomp) ) , 2 ) AS 'calc_accomp', SUM( duree_tmp ) AS 'duree_totale', id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif, tb_taskeval.id
FROM `tb_projet` , `tb_taskeval`
WHERE `id_projet` = `id_task`
AND `id_task` = '$id_project'
GROUP BY `id_task` , `duree_tmp` ASC";
	$i=0;
	$j=0;
	$res_findate = querybd($req_findate,"tab");
	while($res_findate[$i] != NULL){
		foreach($res_findate[$i] as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i++;
		$j++;
	}
	$fin_pproj = $res_findate[0][duree_totale];
	return ($fin_pproj);
}

function get_endsubproj($id_project,$fin_pproj)
{

	$req_endproj = "select debut_projet, DATE_ADD(debut_projet,INTERVAL '$fin_pproj' DAY) as finpproj from tb_taskeval, tb_projet where id_task = id_projet and id_projet = $id_project";
	$i=0;
	$j=0;
	$res_endproj = querybd($req_endproj,"tab");
	while($res_endproj[$i] != NULL){
		foreach($res_endproj[$i] as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i++;
		$j++;
	}
	$fin_projdate = $res_endproj[0][finpproj];
	return ($fin_projdate);
}

function istask_ended($id_project,$fin_projdate,$task_percent)
{
	$today = date ("Y-m-d-s", mktime(date("m"),date("d")-0,date("Y")));
	if ($today >= $fin_projdate && $task_percent != -1)
	$text = "<img src='images/tache_ok.png' width='193px' height='50px'>";
	else if ($today <= $fin_projdate && $task_percent != -1)
	$text = "<img src='images/tache_ko.png' width='193px' height='50px'>";
	else
	$text = "<img src='images/tache_edit.png' width='193px' height='50px'>";
	return ($text);
}


function get_pastime($id_project,$datefin_sproj){
	$req_taskpourcent = "select debut_projet, DATEDIFF(NOW(),debut_projet) as rst_jours_pproj from tb_taskeval, tb_projet where id_task = id_projet and id_projet = $id_project";
	$i=0;
	$j=0;
	$res_taskpourcent = querybd($req_taskpourcent,"tab");
	while($res_taskpourcent[$i] != NULL){
		foreach($res_taskpourcent[$i] as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i++;
		$j++;
	}
	if($res_taskpourcent[0][rst_jours_pproj])
	$past_time = $res_taskpourcent[0][rst_jours_pproj];

	return ($past_time);
}

function get_taskaccomp($id_project,$rest_time,$duree_tmp){
	if (!isset($rest_time)){
$req_taskpourcent = "select 1 as percentproj  from tb_taskeval, tb_projet where id_task = id_projet and id_projet = $id_project";
		$requete_insub = "UPDATE tb_projet SET debut_projet = NOW() where id_projet = $id_project";
		@querybd($requete_insub, "str");
	}
	else
	$req_taskpourcent = "select ROUND(SUM($rest_time*100/$duree_tmp),2) as percentproj  from tb_taskeval, tb_projet where id_task = id_projet and id_projet = $id_project";
	$i=0;
	$j=0;
	$res_taskpourcent = querybd($req_taskpourcent,"tab");
	while($res_taskpourcent[$i] != NULL){
		foreach($res_taskpourcent[$i] as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i++;
		$j++;
	}
	if($res_taskpourcent[0][percentproj] >'100')
	$task_percent = '100';
	else if($res_taskpourcent[0][percentproj] <='100' && $res_taskpourcent[0][percentproj] >'0')
	$task_percent = $res_taskpourcent[0][percentproj];
	else if($res_taskpourcent[0][percentproj] <='100' && $res_taskpourcent[0][percentproj] =='0')
	$task_percent = "1";
	else if($res_taskpourcent[0][percentproj] <='100' && $res_taskpourcent[0][percentproj] <'0')
	$task_percent = -1;
	return ($task_percent);
}

function jourtask($id_project){
	$req_task = "select id_task,id as _idpere from tb_taskeval, tb_projet where id_task=id_projet and id_projet = $id_project group by id_pere_projet";
	$i=0;
	$j=0;
	$res_task = querybd($req_task,"tab");
	while($res_task[$i] != NULL){
		foreach($res_task[$i] as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i++;
		$j++;
	}
	$_idpere = $res_task[0]['_idpere'];
	$req_taskpourcent = "select SUM(duree_tmp) as nb_jours from tb_taskeval, tb_projet where id = '$_idpere' and id_projet = id_task group by id_pere_projet";
	$i=0;
	$j=0;
	$res_taskpourcent = querybd($req_taskpourcent,"tab");
	while($res_taskpourcent[$i] != NULL){
		foreach($res_taskpourcent[$i] as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i++;
		$j++;
	}
	$nb_jours = $res_taskpourcent[0]['nb_jours'];
	return ($nb_jours);
}

function get_restime($duree_totale,$jours_passes){
	$rest_time = $duree_totale-$jours_passes;
	return ($rest_time);
}

$jours_task = jourtask($id_project);
$fin_pproj = fin_pproj($id_project);
$datefin_sproj=get_endsubproj($id_project,$fin_pproj);
$past_time = get_pastime($id_project,$datefin_sproj);
$rest_time = get_restime($jours_task,$past_time);

$task_percent = get_taskaccomp($id_project,$past_time,$jours_task);
$isended = istask_ended($id_project,$datefin_sproj,$task_percent);

$accompt_rest = 100-$task_percent;
//$values=array('Vingt' => 20, 'Cinquante' => 50, 'Trente'=>30);
$values=array($task_percent => $task_percent,'&nbsp;'.$accompt_rest.'' => $accompt_rest);
$colors=array('blue','gray');
$percent = pourcentage($values,0,false,60,10,10,6,600,$colors);
$oSmarty->assign("rest_time", $rest_time);
$oSmarty->assign("past_time", $past_time);
$oSmarty->assign("titre_projet", $tab[0][titre_projet]);
$oSmarty->assign("accomp", $task_percent);
$oSmarty->assign("duree_tmp", $tab[0][duree_tmp]);
$oSmarty->assign("description_projet", $tab[0][description_projet]);
$oSmarty->assign("fin_projet", mysql_DateTime($datefin_sproj));
$oSmarty->assign("debut_projet", mysql_DateTime($tab[0][debut_projet]));
$oSmarty->assign("id_projet", $tab[0][id_projet]);
$oSmarty->assign("pourcentage", $percent);
$oSmarty->assign("isended", $isended);
?>
