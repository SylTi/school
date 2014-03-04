<?php
/* /!\ Statistics /!\ */
$query = "SELECT * FROM phpbb_topics";
$res = mysql_query($query) or die (mysql_error());
$topics = mysql_num_rows($res);

$query = "SELECT * FROM phpbb_users WHERE user_email!=''";
$res = mysql_query($query) or die (mysql_error());
$users = mysql_num_rows($res);

$query = "SELECT * FROM phpbb_posts";
$res = mysql_query($query) or die (mysql_error());
$posts = mysql_num_rows($res);
?>
