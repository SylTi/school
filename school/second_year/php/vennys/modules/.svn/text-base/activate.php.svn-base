<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
<head>
    <link rel="stylesheet" type="text/css" href="css/default.css" />
    <link rel="stylesheet" type="text/css" href="css/style.css" />
    <script type="text/javascript" src="js/functions.js"></script>
</head>
<?php
$valid = $_GET['valid'];
$req = "UPDATE users_tracker SET user_group = 0 WHERE user_codeactiv = '" . $valid . "';";
$req2 = 'SELECT * FROM users_tracker WHERE md5(user_login) = "' . $valid . '";';
$ret2 = mysql_query($req2);
$line = mysql_fetch_array($ret2);
if ($line)
{
	if ($line['user_codeactiv'] != 0)
	{
	$ret = mysql_query($req);
	if ($ret)
		echo 'Le compte '. $line['user_login']. ' a bien ete active';
	}
	else
		echo 'Le compte a deja ete active';
}
?>
</html>