<?php
$login = "psynes";
$password = "psynes";
// CETTE LIGNE A DECO si vous codez depuis votre local
$host= "psynes.ath.cx";
// CETTE LIGNE A CO si vous codez depuis le serv. http
//$host= "localhost";
$db = "psynes";

mysql_connect($host, $login, $password) or die ("Owned bolos:".mysql_error());
mysql_select_db($db);
?>