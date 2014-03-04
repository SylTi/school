<?php 
$db_name = "techweb";
$link = mysql_connect($db, "yo", "yo") or die("Connexion impossible.");
$table_name = 'phpbb_users, phpbb_posts';
$db = mysql_select_db($db_name, $link);
$query = "select * from " . $table_name." where phpbb_users.username = phpbb_posts.post_username";
$result = mysql_query($query, $link) or die("Impossible d'interroger la base de données");
$num = mysql_num_rows($result);
  if ($num != 0) {
  $file= fopen("../xml/results.xml", "w"); 
  $_xml="<init>\r\n"; 
  while ($row = mysql_fetch_array($result)) {
		$_xml .="\t<data>\r\n"; 
		$_xml .="\t\t<title>" . $row["post_username"] . "</title>\r\n";
		$_xml .="\t\t<link_to>" . $row["post_subject"] . "</link_to>\r\n";
		$_xml .="\t</data>\r\n"; }
	$_xml .="</init>";
	fwrite($file, $_xml); 
	fclose($file); 
	}
?>
 