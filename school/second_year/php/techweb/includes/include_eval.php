<?php

function mysql_DateTime($d)
{

	$date = substr($d,8,2)."/";        // jour
	$date = $date.substr($d,5,2)."/";  // mois
	$date = $date.substr($d,0,4). " à "; // année
	$date = $date.substr($d,11,5);     // heures et minutes
	return $date;
}

function get_eval_percent($id_proj)
{
	$prerequete = "select * from tb_taskeval, tb_projet where id_task = id_projet and id_projet = '.$id_proj.' order by date_modif desc limit 1";

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
	$requete1 = "SELECT SUM(duree_tmp) as 'duree_totale', id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif, tb_taskeval.id FROM `tb_projet`, `tb_taskeval` WHERE `id_god_projet` ='$id_proj' and `id_projet`=`id_task` or `id_projet`='$id_proj' and `id_projet`=`id_task`  group by `id_projet` asc";

	$requete = "SELECT SUM(duree_tmp) as 'duree_totale', id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif, tb_taskeval.id FROM `tb_projet`, `tb_taskeval` WHERE `id_god_projet` ='$id_proj' and `id_projet`=`id_task` or `id_projet`='$id_proj'  and `id_projet`=`id_task` group by `id_projet` asc";

	$str = querybd($requete1, "str");
	$tab = querybd($requete, "tab");
	if (!empty($str)){
		$j = 0;
		foreach($str as $cle => $valeur)
		$sauv[$j][$cle] = $valeur;
		$i = 0;
		$j = 0;
		while($tab[$i] != NULL){
			foreach($tab[$i] as $cle => $valeur)
			$sauv[$j][$cle] = $valeur;
			$i++;
			$j++;
		}
		return ($sauv);
	}else{
		@querybd($requete_in, "str");
		header('Location: index.php?view=eval&id='.$id_proj.'');}
}

function get_seval_percent($id_proj)
{
	$requete1 = "SELECT * FROM `tb_projet`, `tb_taskeval` WHERE `id_god_projet` ='$id_proj' and `id_projet`=`id_task` or `id_projet`='$id_proj' and `id_projet`=`id_task`  group by `id_projet` asc";
	$str = querybd($requete1, "str");
	$reqstat = "SELECT ROUND(AVG((accomp)), 2) AS 'calc_accomp', SUM( duree_tmp ) AS 'duree_totale',
		id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif, tb_taskeval.id
FROM `tb_projet` , `tb_taskeval`
WHERE `id_god_projet` ='$id_proj' and `id_projet`=`id_task` or `id_projet`='$id_proj'  and `id_projet`=`id_task` group by `id_projet` asc";

	$stat_tab = querybd($reqstat, "tab");
	$reqXstat ="select debut_projet, DATEDIFF(NOW(),debut_projet) as rst_jours_pproj,id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif, tb_taskeval.id from tb_taskeval, tb_projet WHERE `id_god_projet` ='$id_proj' and `id_projet`=`id_task` or `id_projet`='$id_proj'  and `id_projet`=`id_task` and id_god_projet = '0' group by `id_projet` asc";

	$stat_xtab = querybd($reqXstat, "tab");


	while($stat_xtab[$i] != NULL){
		foreach($stat_xtab[$i] as $cle => $valeur)
		$stat_xtab[$j][$cle] = $valeur;
		$i++;
		$j++;
	}
	return ($stat_xtab);
}

function get_peval_percent($id_proj)
{
	$prerequete = "select * from tb_taskeval, tb_projet where id_pere_projet = '$id_proj' and id_task = id_projet or id_task = id_projet and id_projet = $id_proj";
	$preres = querybd($prerequete,"tab");

	if(!empty($preres[0][0]) && !empty($preres[1][0])){
		while($preres[$i] != NULL){
			foreach($preres[$i] as $cle => $valeur)
			$sauv[$j][$cle] = $valeur;
			$i++;$j++;
		}
		$requete1 = "SELECT ROUND(AVG((accomp)), 2) AS 'calc_accomp', SUM( duree_tmp ) AS 'duree_totale',
		id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif, tb_taskeval.id
FROM `tb_projet` , `tb_taskeval`
WHERE `id_projet` = `id_task`
AND `id_pere_projet` = '$id_proj'
GROUP BY `type_projet` , `id_pere_projet` ASC";
		$requete = "SELECT ROUND( AVG( (accomp) ) , 2 ) AS 'calc_accomp', SUM( duree_tmp ) AS 'duree_totale', id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif, tb_taskeval.id
FROM `tb_projet` , `tb_taskeval`
WHERE `id_projet` = `id_task`
AND `id_pere_projet` = '$id_proj'
GROUP BY `type_projet` , `id_pere_projet` ASC";
	}
	else if(empty($preres[1][0])){header("Location:index.php?view=evalu&id=$id_proj");}
	if($str = querybd($requete1, "str") && ($ptab = querybd($requete, "tab"))){
		if (!empty($str)){
			$j = 0;
			$i = 0;
			$j = 0;
			while($ptab[$i] != NULL){
				foreach($ptab[$i] as $cle => $valeur)
				$sauv[$j][$cle] = $valeur;
				$i++;
				$j++;
			}
			return ($sauv);
		}
		else{
			@querybd($requete_in, "str");
			header('Location: index.php?view=eval&id='.$id_proj.'');
		}}
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
		$tab = get_eval_percent($id_project);
		$stat_tab = get_seval_percent($id_project);
		$ptab = get_peval_percent($id_project);
		$oSmarty->assign("select_eval", $tab);
		$oSmarty->assign("select_seval", $stat_tab);
		$oSmarty->assign("select_peval", $ptab);
	}
	$oSmarty->assign("erreur", "");}
	else {$oSmarty->assign("erreur", "Merci de bien vouloir ne pas couiller !<br /><br />");
	}

	function fin_pproj($id_project){
		$req_findate = "SELECT SUM( duree_tmp ) AS 'duree_totale'
FROM `tb_projet` , `tb_taskeval`
WHERE `id_projet` = `id_task`
AND `id_pere_projet` ='$id_project'
GROUP BY `id_pere_projet` ASC";
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
	function get_endproj($id_project,$fin_pproj)
	{
		$req_endproj = "select debut_projet, DATE_ADD(debut_projet,INTERVAL '$fin_pproj' DAY) as finpproj  FROM `tb_projet`, `tb_taskeval` WHERE `id_god_projet` ='$id_project' and `id_projet`=`id_task` or `id_projet`='$id_project'  and `id_projet`=`id_task` group by `type_projet` asc";
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

	function get_restime($id_project){
		$req_findjours = "SELECT SUM( duree_tmp ) AS 'duree_totale',
		id_projet, type_projet, id_master_projet, description_projet, debut_projet, fin_projet, titre_projet, id_pere_projet, id_god_projet, etat_projet, duree_tmp, accomp, cdp_valid, id_task, lastmodif_userid, date_modif, tb_taskeval.id
FROM `tb_projet` , `tb_taskeval`
WHERE `id_projet` = `id_task`
AND `id_pere_projet` = '$id_project'
GROUP BY `type_projet` , `id_pere_projet` ASC";
		$res_findjours = querybd($req_findjours,"tab");
		while($res_findjours[$i] != NULL){
			foreach($res_findjours[$i] as $cle => $valeur)
			$sauv[$j][$cle] = $valeur;
			$i++;
			$j++;
		}
		$nb_jours =$res_findjours[0][duree_totale];


		$req_jourspasses = "SELECT debut_projet, DATEDIFF(DATE_ADD(debut_projet,INTERVAL '$nb_jours'
DAY ),NOW( )) AS rst_jours_pproj, titre_projet, id_task, id_pere_projet
FROM tb_taskeval, tb_projet
WHERE id_task =$id_project
AND id_task = id_projet
GROUP BY id_projet
";
		$res_jourspasses = querybd($req_jourspasses,"tab");
		while($res_jourspasses[$i] != NULL){
			foreach($res_jourspasses[$i] as $cle => $valeur)
			$sauv[$j][$cle] = $valeur;
			$i++;
			$j++;
		}
		$rest_time =$res_jourspasses[0][rst_jours_pproj];

		return ($rest_time);
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
		$_idpere = $res_task[0]['id_task'];
		$req_taskpourcent = "select SUM(duree_tmp) as nb_jours from tb_taskeval, tb_projet where id_pere_projet = '$_idpere' and id_projet = id_task group by id_pere_projet";
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

	function get_taskaccomp($id_project,$rest_time,$duree_tmp){
		if (!isset($rest_time)){
$req_taskpourcent = "select (SUM(1) as percentproj  from tb_taskeval, tb_projet where id_task = id_projet and id_projet = $id_project";
		$requete_insub = "UPDATE tb_projet SET debut_projet = NOW() where id_projet = $id_project";
		@querybd($requete_insub, "str");
	}
	else
	$req_taskpourcent = "select ROUND(SUM($rest_time*100/$duree_tmp)) as percentproj, count(id_task) as nbtask  from tb_taskeval, tb_projet where id_pere_projet = $id_project group by id_pere_projet";
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
	$jours_task = jourtask($id_project);

	$fin_pproj = fin_pproj($id_project);
	$datefin_sproj=get_endproj($id_project,$fin_pproj);
	$past_time = get_pastime($id_project,$datefin_sproj);
	$rest_time = get_restime($id_project);

	$task_percent = get_taskaccomp($id_project,$past_time,$jours_task);
	$isended = istask_ended($id_project,$datefin_sproj,$task_percent);
	$accompt_rest = 100-$task_percent;
	//$values=array('Vingt' => 20, 'Cinquante' => 50, 'Trente'=>30);
	$values=array($task_percent => $task_percent,'&nbsp;'.$accompt_rest.'' => $accompt_rest);
	$colors=array('blue','gray');
	$percent = pourcentage($values,0,false,60,10,10,6,600,$colors);
	$oSmarty->assign("rest_time", $rest_time);
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
