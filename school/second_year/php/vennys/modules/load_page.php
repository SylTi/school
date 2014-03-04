<?php
include_once("fonctions.php");

// On definit le tableau contenant les pages autorisees
$pageOK = array('accueil' => './modules/accueil.php',
				'send_mp' => './modules/send_mp.php',
				'list_mp' => './modules/list_mp.php',
				'register' => './modules/suscribe.php',
				'logout' => './modules/logout.php',
				'uptorrent' => './modules/torrent.php',
				'torrent' => './modules/listtorrent.php',
				'showtorrent' => './modules/showtorrent.php',
				'profil' => './modules/profile.php',
				'faq' => './modules/faq.php',
				'login' => './modules/login.php');
				


// Si url OK


if ((isset($_GET['page'])) && (isset($pageOK[$_GET['page']]))) {
	// Nous appelons le contenu central de la page
	include($pageOK[$_GET['page']]);

} else {
	// Page par defaut quant elle n'existe pas dans le tableau
	include('accueil.php');

}

?>