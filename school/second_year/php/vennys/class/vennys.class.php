<?php
class DB {

	var $id = 0;
	/*	var $memcache;*/
	function DB($host, $base, $login, $pass){
		try {

			$this->id = @mysql_pconnect($host, $login, $pass);
			if ($this->id == FALSE)
			throw new Exception('Impossible de se connecter.');
			$select = @mysql_select_db($base);
			if ($select == FALSE)
			throw new Exception("La base $base, n'existe pas.");
		}
		catch (Exception $exc) {
			echo "$exc";
		}
	}
	function safetab($tab)
	{
		foreach($tab as $cle => $valeur)
		{
			$val = mysql_real_escape_string(htmlspecialchars(trim($valeur)), $this->id);
			$tab[$cle] = $val;
		}
		return($tab);
	}

	function query($query) {
		try {
			$res = mysql_query($query, $this->id) or die(mysql_error());
			if ($res == 0)
			throw new Exception("Aucun resultat");
			return ($res);
		}
		catch (Exception $exc) {
			echo "$exc";
		}

	}

	function query_f($query) {
		$i = 0;
		$fin = $this->query($query, $this->id);
		while ($res = mysql_fetch_array($fin))
		{
			foreach ($res as $name => $val)
			$tab[$i][$name] = $val;
			$i++;
		}
		if ($tab[1] == NULL)
		return ($tab[0]);
		return ($tab);
	}

	function query_num($query) {
		$res = $this->query($query);
		return (mysql_num_rows($res));
	}

	function db_close() {
		@mysql_close($this->id);
	}

	function AddUser($login, $pass, $mail, $verif = -1) {
		$pass = md5($pass);
		if ($verif == -1)
		{
			$code_activ = md5($login);
			$requete = "INSERT INTO users_tracker (user_login, user_pass, user_mail, user_group, user_codeactiv, user_lang) 
			VALUES ('$login', '$pass', '$mail', '$verif', '$code_activ', '0')";
			mail($mail, "Inscription Vennys", "Bienvenue sur Vennys...\n Cliquer sur le lien pour valider votre compte : \n http://vennys.ath.cx/tracker/index2.php?p=activate&valid=$code_activ");
		}
		else
		$requete = "INSERT INTO users_tracker (user_login, user_pass, user_mail, user_group, user_lang) VALUES ('$login', '$pass', '$mail', '$verif', '0')";
		$this->query($requete);
	}

	function DelUser($id) {
		if (is_numeric($id))
		{
			$requete = "DELETE FROM users_tracker WHERE user_id = '$id'";
			$this->query($requete);
		}
	}

	function GetUserId($login) {
		$requete = "SELECT user_id FROM users_tracker WHERE user_login = '$login'";
		$res = $this->query_f($requete);
		return ($res[0][0]);
	}

		function GetAdminId($login) {
		$requete = "SELECT id_user FROM vennys_users WHERE username = '$login'";
		$res = $this->query_f($requete);
		return ($res[0][0]);
	}
	
	function GetUserInfos($id) {
		$requete = "SELECT * FROM users_tracker WHERE user_id = '$id'";
		return ($this->query_f($requete));
	}

	function EditUser($id, $login = '', $pass = '', $mail = '', $client = '', $location = '', $user_style = '', $lang ='') {
		if (is_numeric($id) && ($login != '' || $pass != '' || $mail != '' || $client != '' || $location != '' || $lang != '' || $user_style != ''))
		{
			$requete = "UPDATE users_tracker SET ";
			if ($login != '')
			$requete .= "user_login='$login', ";
			if ($pass != '')
			$requete .= "user_pass='$pass', ";
			if ($mail != '')
			$requete .= "user_mail='$mail', ";
			if ($client != '')
			$requete .= "user_client='$client', ";
			if ($location != '')
			$requete .= "user_location='$location', ";
			if ($user_style != '')
			$requete .= "user_style='$user_style', ";
			if ($lang != '')
			$requete .= "user_lang='$lang' ";
			$requete .= "WHERE user_id='$id'";
			$this->query($requete);
		}
	}
	function add_torrent($name, $categorie, $user) {
		$requete = "INSERT INTO torrent_tracker (nom_torrent, categorie, posteur) VALUES ('$name', '$categorie', '$user')";
		$this->query($requete);
	}
	function EditTorrent($id, $nom_torrent = '', $categorie = '', $posteur = '') {
		if (is_numeric($id) && ($nom_torrent != '' || $categorie != '' || $posteur != ''))
		{
			$requete = "UPDATE users_tracker SET";
			if ($nom_torrent != '')
			$requete .= "nom_torrent='$nom_torrent'";
			if ($categorie != '')
			$requete .= ", categorie='$categorie'";
			if ($posteur != '')
			$requete .= ", posteur='$posteur'";
			$requete .= " WHERE torrent_id='$id'";
			$this->query($requete);
		}
	}

	function DelTorrent($id) {
		if (is_numeric($id))
		{
			$requete = "DELETE FROM torrent_tracker WHERE torrent_id = '$id'";
			$this->query($requete);
		}
	}

	function GetTorrentId($torrent) {
		$requete = "SELECT torrent_id FROM torrent_tracker WHERE nom_torrent = '$torrent'";
		$res = $this->query_f($requete);
		return ($res[0]);
	}

	function GetTorrentInfos($id) {
		$requete = "SELECT * FROM torrent_tracker WHERE torrent_id = '$id'";
		return ($this->query_f($requete));
	}
}