<?php
@session_start();
require_once('smarty/libs/Smarty.class.php');
if (isset($_COOKIE[md5("psynes")]) && !$_SESSION["login"])
header("location: includes/include_login_sub.php?from=cookie");
if (!isset($oSmarty))
$oSmarty = new Smarty();

if (isset($user->data['username']) && $user->data['username'] != "Anonymous"){
	
	$_SESSION["login"] = $user->data['username'];
	$_SESSION["id"] = $user->data['user_id'];
	$_SESSION["mail"] = $user->data['user_email'];
}

$oSmarty->template_dir = 'templates';
$oSmarty->compile_dir = 'templates_c';
if (isset($_SESSION["login"])){
	$oSmarty->assign('login', $_SESSION["login"]);
	$oSmarty->assign('id', $_SESSION["id"]);
	$oSmarty->assign('mail', $_SESSION["mail"]);
	$query = "SELECT * FROM phpbb_posts";
	$res = mysql_query($query) or die (mysql_error());
	$posts = mysql_num_rows($res);
	$cpt = 0;
	while ($row = mysql_fetch_object($res))
	{
		if ($row->post_username == $_SESSION["login"])
		$cpt++;
	}
	$oSmarty->assign('posts_user', $cpt);
	$id = $_SESSION["id"];
	$requete = "SELECT `user_rank` FROM `phpbb_users` WHERE user_id ='$id'";
	$res = mysql_query($requete);
	$str = mysql_fetch_array($res);
	$oSmarty->assign("rank", $str["user_rank"]);
}
?>