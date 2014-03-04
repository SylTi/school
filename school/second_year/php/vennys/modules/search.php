<?php
$dblogin = "vennys";
$password = "vennys";
$host= "localhost";
$db = "vennys";

mysql_connect($host, $dblogin, $password) or die ("Owned bolos:".mysql_error());
mysql_select_db($db);
include("../modules/fonctions.php");

$_treq = isset($_GET['type'])?$_GET['type']:"none";
switch ($_treq){
 case "clb_e":
   $_sreq = strip_tags($_GET['clb_e']);
   $_sloc ="clb_e";
   $s_sugg = "res_clb_e";
   $SQL_FROM = 'users_tracker';
   $SQL_WHAT = 'user_login';
   $SQL_WHERE = 'user_group != \'-1\' and '.$SQL_WHAT.' like "'.$_sreq.'%" ';
   
   $s_sql = "select * from $SQL_FROM where $SQL_WHERE group by user_login asc limit 20";
   $flagreq_ = '1';
   break;
   
 }
if($flagreq_ !="1"){
  $tree1 = $memcache->get(md5($s_sql));
  if ($tree1 === FALSE)    {
    /*$tree1 = array();
     $s_qry = mysql_query($s_sql);*/
    $tree1 = mysql_query($s_sql);
    if(strlen($_sreq) > 0){
      echo '<ul>';
      $flag=1;
      while ($row = mysql_fetch_array($tree1)) {
	if (!empty($row[$SQL_WHAT])){
	  $r_titre =$row[$SQL_WHAT];
	  $r_adress=$row[user_login];
	  $r_idx=$row[user_id];
	  $r_contact=$row[user_mail];
	  echo $flag==1?utf8_encode("Données déjà existantes :"):"";
	  echo"<li><a href=\"#\" onclick=\"fill('".make_nice_stitle($r_titre,10,2)."', '$_sloc','$s_sugg');\">".make_nice_stitle($r_titre,10,2)."</a></li>";
	  /*$tree1[] = $row;*/
	}
	else
	  echo utf8_encode("<li>Aucun résultat trouvé...</li>");
	$flag++;
      }
    }
  }
  $memcache->set(md5($s_sql), $tree1);
 }
 else if($flagreq_ =="1"){
   $tree2 = $memcache->get(md5($s_sql));
   if ($tree2 === FALSE) {
     /*$tree2 = array();
      $s_qry = mysql_query($s_sql) or die(mysql_error());*/
     $tree2 = mysql_query($s_sql) or die(mysql_error());
     if(strlen($_sreq) > 0){
       echo '<ul>';
       $flag=1;
       while ($row = mysql_fetch_array($tree2)) {
	 if (!empty($row[$SQL_WHAT])){
	   $r_titre =$row[$SQL_WHAT];
	   $r_adress=$row[adresse];
	   $r_idx=$row[idx];
	   echo $flag==1?utf8_encode("Données déjà existantes :"):"";
	   echo"<li><a href='#' onclick=\"fill('".strtolower($r_titre)."', '$_sloc','$s_sugg');\">".ucfirst(strtolower($r_titre))."</a></li>";
	   /*$tree2[] = $row;*/
	 }
	 else
	   echo utf8_encode("<li>Aucun résultat trouvé...</li>");
	 $flag++;
       }
     }
     $memcache->set(md5($s_sql), $tree2);
   }
 }
echo '</ul>';
?>