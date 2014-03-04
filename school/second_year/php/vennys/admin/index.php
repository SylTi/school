<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<link href="css/admin.css" type="text/css" rel="stylesheet" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<script src="js/admin.js" type="text/javascript" language="javascript"></script>
<title>Administration :: Societe</title>
</head>

<body link="#EEEEEE" alink="#EEEEEE" vlink="#EEEEEE">
<div id="body_login">
	<div class="coin_hg"></div><div class="coin_hc"></div><div class="coin_hd"></div>
    <div class="body_admin">
    	<div class="logo_admin">
        	<img src="images/logo_login.gif" alt="e-Go" name="e-Go" border="0" />
        </div>
        <form action="?login=error">
        <div class="identifiant_admin">
        	<div class="titre_admin" id="log1">Identifiant :</div><div class="case_admin"><input type="text" class="input_" id="login"/></div>
            <div style="clear: both;"></div>
        </div>
        <div class="identifiant_admin">
        	<div class="titre_admin" id="log2">Mot de passe :</div><div class="case_admin"><input type="password" class="input_" id="password"/></div>
            <div style="clear: both;"></div>
        </div>
         </form>
        <div id="bouton_login">
			<a href="javascript: void(0);" Onclick="submit(); return false;"><img src="images/bouton_submit.gif" class="submit" border="0"/></a><a href="javascript: void(0);" Onclick="set_reset('login;password');"><img src="images/bouton_reset.gif" class="reset" border="0"/></a>
        </div>
        <div id="explain_error">
        <?php if ($_GET && $_GET["login"] == "error"){ ?>
        	<p style="background: #000;">
        	<?php echo "Connecte depuis : ".$_SERVER['REMOTE_ADDR']."<br />Port de connection : ".$_SERVER['REMOTE_PORT'];?></p>
            <p>
            <u>Pour recuperer vos identifiants merci de renseigner votre adresse e-mail :</u><br /></p>
            <input type="text" class="input_" /><br /><br />
            <a href="javascript: void(0);"><img src="images/bouton_submit.gif" class="reset" border="0"/></a><br />&nbsp;
        <?php }else{ 
			echo "Bienvenu(e) sur le panneau d'administration de votre site internet.<br />
			Renseignez les champs ci-dessus pour vous identifier.";
		}
		?>
        </div>
    </div>
	<div class="coin_bg"></div><div class="coin_bc"><a href="javascript: void(0);" onclick="javascript: display('explain_error');"><img src="images/fleche_bc.gif" border="0"/></a></div><div class="coin_bd"></div>
    </div>
<?php if ($_GET && $_GET["login"] == "error"){ ?>
    <script type="text/javascript">
	  	document.getElementById("explain_error").style.display="block";
	</script>
<?php } ?>
</body>
</html>
