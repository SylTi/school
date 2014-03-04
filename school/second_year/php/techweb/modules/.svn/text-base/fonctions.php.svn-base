<?php

function bdconnect()
{
$login = "psynes";
$password = "psynes";
// CETTE LIGNE A DECO si vous codez depuis votre local
$host= "psynes.ath.cx";
// CETTE LIGNE A CO si vous codez depuis le serv. http
//$host= "localhost";
$db = "psynes";

mysql_connect($host, $login, $password) or die ("Owned bolos:".mysql_error());
mysql_select_db($db);
}

function secure_tab($tab)
{
	bdconnect();
	foreach($tab as $cle => $valeur)
	{
		$val = mysql_real_escape_string(htmlspecialchars(trim($valeur)));
		$tab[$cle] = $val;
	}
	return($tab);
}

function secure_str($str)
{
		bdconnect();
	return(mysql_real_escape_string(htmlspecialchars(trim($str))));
}

function querybd($requete, $str)
{

	bdconnect();
	$res = mysql_query($requete) or die("Error : " . mysql_error());
	if ($str == "str")
	{
		$fin = mysql_fetch_array($res);
		mysql_close();
		return ($fin);
	}
	elseif ($str == "tab")
	{
		while ($fin = mysql_fetch_array($res))
			$tab[] = $fin;
		mysql_close();
		return ($tab);
	}
	else
	{
		$res = mysql_query($requete) or die("Error : " . mysql_error());
		mysql_close();
		return ($res);
	}
}

function	verif_droit($id_user, $id_projet, $rang)
{
	bdconnect();
	if ($rang == "admin"){
		$request = "SELECT * FROM tb_droit_projet WHERE id_projet='".$id_projet."' AND id_user='".$id_user."'";
		$tab = querybd($request, "tab");
		$request = "SELECT * FROM tb_projet WHERE id_projet='".$id_projet."'";
		$tab2 = querybd($request, "tab");
		$request = "SELECT * FROM tb_users_projet WHERE id_projet='".$id_projet."' AND id_user='".$id_user."'";
		$tab3 = querybd($request, "tab");
		if ($tab3[0]["user_confirm"] == 1){
			if (sizeof($tab) > 0)
			{
				if ($tab[0]["droit_decoupage"] == 1 && $tab[0]["droit_visualisation"] == 1 && $tab[0]["droit_evaluation"] == 1 && $tab2[0]["id_master_projet"] == $id_user)
					return (1);
				else
					return (0);
			}
		}
		return (0);
	}
	if ($rang == "decoupage")
	{
		$request = "SELECT * FROM tb_droit_projet WHERE id_projet='".$id_projet."' AND id_user='".$id_user."'";
		$tab = querybd($request, "tab");
		$request = "SELECT * FROM tb_users_projet WHERE id_projet='".$id_projet."' AND id_user='".$id_user."'";
		$tab3 = querybd($request, "tab");
		if ($tab3[0]["user_confirm"] == 1){
			if (sizeof($tab) > 0)
			{
				if ($tab[0]["droit_decoupage"] == 1 && $tab[0]["droit_visualisation"] == 1)
					return (1);
				else
					return (0);
			}
		}
		return (0);
	}
	if ($rang == "evaluation")
	{
		$request = "SELECT * FROM tb_droit_projet WHERE id_projet='".$id_projet."' AND id_user='".$id_user."'";
		$tab = querybd($request, "tab");
		$request = "SELECT * FROM tb_users_projet WHERE id_projet='".$id_projet."' AND id_user='".$id_user."'";
		$tab3 = querybd($request, "tab");
		if ($tab3[0]["user_confirm"] == 1){
			if (sizeof($tab) > 0)
			{
				if ($tab[0]["droit_evaluation"] == 1 && $tab[0]["droit_visualisation"] == 1)
					return (1);
				else
					return (0);
			}
		}
		return (0);
	}

}

function	sql_date($date){
$tab = explode("/", $date);
return ($tab[2]."-".$tab[1]."-".$tab[0]);
}

function	human_date($date){
$cut = explode(" ", $date);
$tab = explode("-", $cut[0]);
return ($tab[2]."/".$tab[1]."/".$tab[0]);
}

function	nice_tab($tab1, $tab2){
	$i = 0;
	$tab = "";
	$k = 0;
	while ($i < sizeof($tab1))
	{
		$j = 0;
		$flag = 0;
		while ($j < sizeof($tab2))
		{
			if ($tab2[$j]["id_user"] == $tab1[$i]["user_id"])
				$flag = 1;
			$j++;
		}
		if ($flag == 0){
			$tab[$k]["id"] = $tab1[$i]["user_id"];
			$tab[$k]["name"] = $tab1[$i]["username"];
			$k++;
		}
		$i++;
	}
	return ($tab);
}

function	check_my_invits(){
	bdconnect();
	$request = "SELECT * FROM tb_users_projet WHERE id_user='".$_SESSION["id"]."' AND user_confirm='0'";
	$query = mysql_query($request) or die ("Error : ".mysql_error());
	return (mysql_num_rows($query));
}