<?php
@session_start();
include("config.php");
include("../lang.inc.php");
$curr = $_SESSION[user_lang];
$lang =  $tab_lang[$curr];

function is_admin($login)
{
	$req =mysql_query("select * from vennys_users where username = '$login' limit 1")or die(mysql_error());
	if ($row = mysql_fetch_array($req))
	return ($row[username]);
}
if ($_SESSION[user_login])
{
	if ($_GET[id])
	$id_toedit = $_GET[id];

	$req = "SELECT * FROM torrent_tracker, vennys_users ,users_tracker WHERE users_tracker.user_login = vennys_users.username and torrent_id = ".$id_toedit." or torrent_id = ".$id_toedit." and torrent_posteur ='$_SESSION[user_login]' ORDER BY  torrent_date DESC , torrent_categorie LIMIT 1";
	$qry = mysql_query($req) or die(mysql_error());
	if($row = mysql_fetch_array($qry))
	{
		$title = $row['torrent_name'];
		$id = $row['torrent_id'];
		$cat = $row['torrent_categorie'];
		$id = $id_toedit;
		$from = $row['torrent_posteur'];
		$descr = $row['torrent_desc'];
	}
	$editform ="<div style='float:left;width:100%;'>
<form method='post' >
<span style='float:left;margin:0;padding:0;width:169px;'>Titre : </span><input type='text' disabled='disabled' value='$title' name='torrent_name'><br />
<span style='float:left;margin:0;padding:0;width:169px;'>Id : </span><input type='text' value='$id' name='torrent_id' disabled='disabled'><br />
<span style='float:left;margin:0;padding:0;width:169px;'>Catégorie : </span> <SELECT name='torrent_categorie'>

   <OPTION value =-1>Dissimuler / Rendre invisible</OPTION>
   <OPTION>----------------------------</OPTION>

   <OPTION value =1>".$lang[categories][Categorie1]."</OPTION>
   <OPTION value =2>".$lang[categories][Categorie2]."</OPTION>
   <OPTION value =3>".$lang[categories][Categorie3]."</OPTION>
   <OPTION value =4>".$lang[categories][Categorie4]."</OPTION>
   <OPTION value =5>".$lang[categories][Categorie5]."</OPTION>
   <OPTION value =6>".$lang[categories][Categorie6]."</OPTION>
   <OPTION value =7>".$lang[categories][Categorie7]."</OPTION>
   <OPTION value =8>".$lang[categories][Categorie8]."</OPTION>
  <OPTION value =0>".$lang[categories][Categorie0]."</OPTION>

   </SELECT><br />
<span style='float:left;margin:0;padding:0;width:169px;'>Description : </span><textarea cols='50' rows='7' name='torrent_desc'>$descr</textarea><br /><br />
<input type='submit' value='Enregistrer les modifications'>
<input type='hidden' value='$title' name='torrent_name'>
<input type='hidden' value='$id' name='torrent_id' >
</form></div>";

	if ($from !="$_SESSION[user_login]" && ($_SESSION[user_login] != is_admin($_SESSION[user_login])))
	$editform = "Vous ne pouvez pas éditer un fichier que vous n'avez pas soumis.";
}
if (!($_POST['torrent_desc']))
echo $editform;
else if (($_POST['torrent_desc']))
{
	$pname =$_POST['torrent_name'];
	$pcat = $_POST['torrent_categorie'];
	$pdescr =$_POST['torrent_desc'];
	$pid = $_GET['id'];

	$req_sql = "UPDATE torrent_tracker, vennys_users ,users_tracker SET torrent_name = '$pname', torrent_categorie = '$pcat', torrent_desc = '$pdescr' where torrent_id = '$pid' and torrent_posteur = '$_SESSION[user_login]' or  torrent_id = '$pid' and users_tracker.user_login= vennys_users.username";
	echo $editform;
	if(mysql_query($req_sql) or die((mysql_error())))
	$editform = "Modification apporté avec succès.<br />Vous pouvez fermer cette fenêtre...";
	else
	$editform = "Une erreure est survenue et vos modifications n'ont pas été enregistrées :(";
}
?>
