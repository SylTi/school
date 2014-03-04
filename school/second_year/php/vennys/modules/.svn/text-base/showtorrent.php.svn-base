<?php
@session_start();
include("config.php");
include("lang.inc.php");
$curr = $_SESSION[user_lang];
$lang =  $tab_lang[$curr];

function is_admin($login)
{
	$req =mysql_query("select * from vennys_users where username = '$login' limit 1")or die(mysql_error());
	if ($row = mysql_fetch_array($req))
	return ($row[username]);
}

	$str = $db->GetTorrentInfos($_GET['id']);
	 if(!$str)
	     echo "<center><b>Torrent Inexistant</b></center>";
	else
		{
			if (($str['torrent_posteur'] == $_SESSION[user_login]) || $_SESSION[user_login]==is_admin($_SESSION[user_login]))
			$can_modif = "<a href='modules/mod_torrent.php?id=$_GET[id]' target='_blank'><img src='./images/edit.png' style='border:0;'></a> ";

		echo "<H1>".$str['torrent_name']."</H1>";
		echo "$can_modif<br/><br/>";
		echo '<a href="./upload_dir/'.$str['torrent_name'].'">DOWNLOAD</a>';
		echo "<br/>";
		echo "Categorie:".$lang["categories"]["Categorie".$str['torrent_categorie']];
		echo "<br/>";
		echo "taille: ".$str['torrent_taille'];
		echo "<br/>";
		echo "Ajouté le:" .$str['torrent_date'];
		echo "<br/>";
		echo "<div id=Descriptif><br/><H2>Descriptif</H2>";
		echo $str['torrent_desc'];
		echo "</div>";
		}
?>