<?php
session_start();
include_once('./modules/captcha.php');
if ($_POST['remember'] == 'on')
{
	$timestamp_expire = time() + 7*24*3600;
	setcookie('login', $_POST['login'], $timestamp_expire);
	setcookie('pass', $_POST['pwd'], $timestamp_expire);
	setcookie('remember', $_POST['remember'], $timestamp_expire);
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
<head>
    <link rel="stylesheet" type="text/css" href="css/default.css" />
    <link rel="stylesheet" type="text/css" href="css/style.css" />
    <script type="text/javascript" src="js/jquery.js"></script>
    <script type="text/javascript" src="js/functions.js"></script>
</head>
<?php
include('./class/vennys.class.php');
include('./config.inc.php');

$memcache = new Memcache();
$memcache->connect('localhost', 11211) or die ("Connexion impossible");


$db = new DB($host, $base, $login, $pass);
if (isset($_GET) && $_GET['p'] == "activate")
{
	include('./modules/activate.php');
	return;
}
if (isset($_POST) && $_POST['login'])
login_form_treat($_POST);

function login_form_treat($args_post)
{
	$login = mysql_real_escape_string($args_post['login']);
	$pass = mysql_real_escape_string($args_post['pwd']);
	$req = ('SELECT * FROM users_tracker WHERE user_login = \'' . $login.'\';');
	$ret = mysql_query($req);
	if ($ret && $line = mysql_fetch_array($ret))
	{
		if	($line['user_group'] >= 0)
		{
			if ($line['user_pass'] == md5($pass))
			{
				log_in($line, $pass, $args_post['remember']);
			}
			else
			echo "Utilisateur inconnue ou mot de passe invalide";
		}
		else
		echo "Vous n'avez pas encore active votre compte";
	}

	else
	echo "Utilisateur inconnue ou mot de passe invalide";
}

if (isset($_COOKIE) && $_COOKIE['remember'] == 'on')
{
	$args_post['login'] = $_COOKIE['login'];
	$args_post['pwd'] = $_COOKIE['pass'];
	login_form_treat($args_post);
}

function log_in($sql_line, $pass, $remember)
{
	$fr = "French";
	$en = "English";
	$_SESSION['user_id'] = $sql_line['user_id'];
	$_SESSION['user_login'] = $sql_line['user_login'];
	$_SESSION['user_style'] = $sql_line['user_style'];
	if ( $sql_line['user_lang'] == 0)
		$_SESSION['user_lang'] = $fr;
	else if ($sql_line['user_lang'] == 1)
		$_SESSION['user_lang'] = $en;
	else
		$_SESSION['user_lang'] = "FUCK_YPU";
	if (isset($_SESSION))
	{
?>
<script type="text/javascript">
window.location = "http://vennys.ath.cx/tracker/index.php"
</script>
<?php 
	}
} ?>
<body>
   <?php if (!$_GET['page'] == 'login_form'){ ?>
  <div id="login">
  <table cellpadding="0" cellspacing="0">
	<tr>
    	<td class="hg"></td><td class="hc"></td><td class="hd"></td>
    </tr>
	<tr>
    	<td class="cg"></td><td class="cc">
<form method="post" action="./index2.php">
      <br />
      <br />
      <input type="hidden" name="login" value="./index2.php?page=login_form" />
      <label>Login :</label><input type="text" name="login" class="input_" /><br />
      <label>Mot de passe :</label><input type="password" name="pwd" class="input_" />
      <br />
      <p style="width: 143px;">
          <label style="width: 120px;">Remember :</label><input type="checkbox" name="remember" class="checkbox_"><br />
          <p style="text-align: center;">
          <input type="submit" value="OK" class="button_"/>
     <button type="button" onclick="document.location.replace('index2.php?page=register')" class="button_" style="margin-left: 30px">Register</button>
         </p>
     </p>
</form>
</td><td class="cd"></td>
    </tr>
	<tr>
    	<td class="bg"></td><td class="bc"></td><td class="bd"></td>
    </tr>

</table>
</div>
   <?php }else{
   	include ("modules/suscribe.php");
    }?>
</body>
</html>