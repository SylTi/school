<?php
session_start();
include('modules/fonctions.php');
include('includes/fonctions_user.php');
include('includes/include_connection.php');
include('includes/include_session.php');
include("includes/load_page.php");


$oSmarty->assign('topics', $topics);
$oSmarty->assign('users', $users);
$oSmarty->assign('posts', $posts);
$invitations = check_my_invits();


$oSmarty->assign('invitations', $invitations);

$oSmarty->assign('projets_fini', "Non communique");
$oSmarty->assign('projets_cours', "Non communique");
$oSmarty->display('index.tpl');
?>
