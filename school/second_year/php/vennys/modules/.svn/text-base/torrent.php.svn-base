<?php

function right_upload($login, $db)
{
$id = $db->GetAdminId($_SESSION["user_login"]);
if ($id != NULL)
	return (TRUE);
return (FALSE);
}
function send_file($torrent_category, $torrent_taille, $desc)
{
	$categorie = array ("autre","Anime","Livre","Jeu","Film","Musique","Image","Programme","TV");
	$torrent_name = $_FILES['fichier']['name'];
	$torrent_posteur = $_SESSION['user_login'];
	$torrent_date = time();
	$torrent_date = date("Y-m-d H:i:s");
	$torrent_date2= date("D M j G:i:s T Y");
	echo "Le fichier : $torrent_name<br />a ete ajoute le : $torrent_date2<br />
dans la categorie : $categorie[$torrent_category]<br />";

	$q1 = "INSERT INTO `torrent_tracker` (`torrent_name`, `torrent_categorie`,
`torrent_posteur`, `torrent_taille`, `torrent_date`, `torrent_desc`) 
VALUES('$torrent_name', '$torrent_category', '$torrent_posteur', '$torrent_taille', 
'$torrent_date', '$desc');";
	/* dans lordre : id, name, catego, posteur, taille, date, refxbtt */
	
	mysql_query($q1);
	
	$q2 = "INSERT INTO ";
}

function check_torrent($torrent, $filename)
{
	if (strripos($torrent, "http://vennys.ath.cx:2710/announce") === FALSE)
	{
		echo "Le fichier n'est pas un torrent ou url d'announce n'est pas valide.<br />";
		unlink($filename);
		return (-1);

	}
	else
		echo "Le fichier a un header de torrent <br />";
	/* calc_hash*/
}

function check_file($_FILES)
{
	$extension_file = strrchr($_FILES['fichier']['name'], '.');
	$type_file = $_FILES['fichier']['type'];
	$tmp_file = $_FILES['fichier']['tmp_name'];
	$content_dir = 'upload_dir/';
	$name_file = $_FILES['fichier']['name'];

	if (!is_dir($content_dir))
	{
		echo "Creation du dossier d'upload<br />";
		mkdir($content_dir, 700);
	}
	if (preg_match('#[\x00-\x1F\x7F-\x9F/\\\\]#', $name_file))
	{
		echo "Nom de fichier non valide";
		return (-1);
	}
	if (!is_uploaded_file($tmp_file))
	{
		echo "Fichier temporaire d'upload introuvable <br />";
		return (-1);
	}
	if(!(move_uploaded_file($tmp_file, $content_dir . $name_file)))
	{
		echo "Impossible de copier le fichier dans $content_dir";
		return (-1);
	}
	return ($content_dir . $name_file);
}


if (isset($_POST['Envoyer_torrent']))
{
	$filename = check_file($_FILES);
	if ($filename == -1)
	exit (0);
	$torrent_size = filesize($filename);
	$file_torrent = fopen($filename, "r+") or die("File check error");
	$torrent = fread($file_torrent, $torrent_size);
	if (check_torrent($torrent, $filename) == -1)
	exit (0);
	send_file($_POST['categorie'], $torrent_size, $_POST['torrent_desc']);
}
if (right_upload($_SESSION['user_login'], $db) === TRUE)
{?>
<html>
<body>
<div>
<FORM method="POST" action="./index.php?page=uptorrent" ENCTYPE="multipart/form-data">
  <label for="fichier">Torrent (Merci d'utliser l'url du tracker : http://vennys.ath.cx:2710/announce)</label>
  <INPUT type="file" name="fichier" size="30"><br />
  <label for="categorie">Categorie</label>
  <SELECT name="categorie">
   <OPTION value =1><?php echo $lang["categories"]["Categorie1"]; ?></OPTION>
   <OPTION value =2><?php echo $lang["categories"]["Categorie2"]; ?></OPTION>
   <OPTION value =3><?php echo $lang["categories"]["Categorie3"]; ?></OPTION>
   <OPTION value =4><?php echo $lang["categories"]["Categorie4"]; ?></OPTION>
   <OPTION value =5><?php echo $lang["categories"]["Categorie5"]; ?></OPTION>
   <OPTION value =6><?php echo $lang["categories"]["Categorie6"]; ?></OPTION>
   <OPTION value =7><?php echo $lang["categories"]["Categorie7"]; ?></OPTION>
   <OPTION value =8><?php echo $lang["categories"]["Categorie8"]; ?></OPTION>
   <OPTION value =0><?php echo $lang["categories"]["Categorie0"]; ?></OPTION>
   </SELECT><br />
   <label for="torrent_desc">Description</label>
  <textarea name="torrent_desc"></textarea><br />
  <INPUT type="submit" name="Envoyer_torrent" value="Envoie">
  </FORM>
  
  </div>
  </body>
  </html>
  <?php }
  else
  {?>
  Vous n'avez pas les droits d'accés d'upload
  <?php }?>