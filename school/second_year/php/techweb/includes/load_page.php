<?php
include('sql/stats.php');

// On définit le tableau contenant les pages autorisées
// ----------------------------------------------------
$pageOK = array('doc' => './includes/include_doc.php',
'eval' => './includes/include_eval.php',
'evalu' => './includes/include_evalu.php',
'admin' => './includes/include_admin.php',
'profil' => './includes/include_profil.php',
'talk' => './includes/include_talk.php',
'subscribe' => './includes/include_subscribe.php',
'agenda' => './includes/include_agenda.php',
'planning' => './includes/include_planning.php',
'invitations' => './includes/include_invitations.php',
'projets' => './sql/projects.php');

// On teste que le paramètre d'url existe et qu'il est bien autorisé
// -----------------------------------------------------------------
if ( (isset($_GET['view'])) && (isset($pageOK[$_GET['view']])) ) {
include($pageOK[$_GET['view']]);   // Nous appelons le contenu central de la page

$oSmarty->assign('content', $_GET['view']);
} else {
   // Page par défaut quant elle n'existe pas dans le tableau
$oSmarty->assign('content', 'content');
}

if (isset($user->data['username']) && $user->data['username'] != "Anonymous"){

	$_SESSION["login"] = $user->data['username'];
	$_SESSION["id"] = $user->data['user_id'];
	$_SESSION["mail"] = $user->data['user_email'];

	$oSmarty->assign('login', $_SESSION["login"]);
	$oSmarty->assign('id', $_SESSION["id"]);
	$oSmarty->assign('mail', $_SESSION["mail"]);

	$cpt = 0;
	while ($row = mysql_fetch_object($res))
	{
		if ($row->post_username == $_SESSION["login"])
		$cpt++;
	}
	$oSmarty->assign('posts_user', $cpt);
}

?>