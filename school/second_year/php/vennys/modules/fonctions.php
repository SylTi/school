<?php
function	sql_date($date){
	$tab = explode("/", $date);
	return ($tab[2]."-".$tab[1]."-".$tab[0]);
}
function	sql_datefr($date){
	$tab = explode("/", $date);
	return ($tab[2]."-".$tab[1]."-".$tab[0]);
}

function	human_date($date){
	$cut = explode(" ", $date);
	$tab = explode("-", $cut[0]);
	return ($tab[2]."/".$tab[1]."/".$tab[0]);
}

function mysql_DateTime2($d)
{
	//20080126231922 - 01/26/2008 23h19'22
	$date = substr($d,8,2)."/";        // jour
	$date = $date.substr($d,5,2)."/";  // mois
	$date = $date.substr($d,0,4)." à "; // année
	$date = $date.substr($d,11,2). "h";
	$date = $date.substr($d,14,2);     // heures et minutes
	return $date;
}

function mysql_DateTime($d)
{

	$date = substr($d,8,2)."/";        // jour
	$date = $date.substr($d,5,2)."/";  // mois
	$date = $date.substr($d,0,4);
	return $date;
}

function make_niceurl($select_motsclef,$nb_mots,$min_lenmots)
{
	$renamed="";
	$niced_url1="";
	$niced_url="";
	$speciaux = array("[","]","?","!","@","%","&","*","(",")","=","+",";",":","'",".","--","-","/",",","\"","\'"," ","  ","&nbsp;","&nbsp;&nbsp;","%20");
	$niced_url1 = strtr( $select_motsclef,"ÀÁÂÃÄÅàáâãäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÇçÌÍÎÏìíîïÙÚÛÜùúûüÿÑñ","AAAAAAaaaaaaOOOOOOooooooEEEEeeeeCcIIIIiiiiUUUUuuuuyNn");
	$niced_url = str_replace($speciaux, " ", $select_motsclef);
	$tab = explode(" ",$niced_url);
	$i = 0;
	$erf = 0;
	while($tab[$i]){
		if ((strlen($tab[$i]) >= $min_lenmots) && ($erf <= $nb_mots) && ($tab[$i] != $speciaux))
		{
			$erf++;
			//strtr( $select_motsclef,"ÀÁÂÃÄÅàáâãäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÇçÌÍÎÏìíîïÙÚÛÜùúûüÿÑñ","AAAAAAaaaaaaOOOOOOooooooEEEEeeeeCcIIIIiiiiUUUUuuuuyNn");
			$renamed.= strtr( $tab[$i]."-","ÀÁÂÃÄÅàáâãäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÇçÌÍÎÏìíîïÙÚÛÜùúûüÿÑñ","AAAAAAaaaaaaOOOOOOooooooEEEEeeeeCcIIIIiiiiUUUUuuuuyNn");
			$i++;
		}
		else
		$i++;
	}
	$niced_url = substr($renamed,0,strlen($renamed)-1);
	$niced_url = strtolower($niced_url);
	//
	return ($niced_url);
}

?>