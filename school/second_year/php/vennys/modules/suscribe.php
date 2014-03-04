<?php
  /*include_once('./../class/captcha.class.php');*/
  include_once 'securimage/securimage.php';
$securimage = new Securimage();

    define("CAPTCHA_INVERSE", 1);    // black background
    define("CAPTCHA_NEW_URLS", 1);   // no auto-disabling/hiding for the demo
function verif_mail($mail)
{
  $req = 'SELECT * FROM users_tracker WHERE user_mail = "' . $mail . '";';
  $ret = mysql_query($req);
  if ($line = mysql_fetch_array($ret))
    {
      echo 'Email deja utilise';
      return (false);
    }
  return (true);
}
if (!isset($_POST['mail']))
  {
  ?>
  <script language=Javascript>
function bouton()
{
window.location.replace("index2.php" );
}
</script>
    <div id="login">

	  <table cellpadding="0" cellspacing="0">
	<tr>
    	<td class="hg"></td><td class="hc"></td><td class="hd"></td>
    </tr>
	<tr>
    	<td class="cg"></td><td class="cc">
    <form id="registering" name="registering"  Onsubmit="verif_registering('registering'); return false;"x-enctype="multipart/form-data" accept-encoding="UTF-8" method="POST">
     <input type="hidden" name="" value="">
     <label>Nom d\'utilisateur : </label>
     <input type="text" name="login2" id="login2" class="input_" /><br />
     <label>Email : </label>
     <input type="text" name="mail" id="mail" class="input_" /><br />
     <label>Mot de passe : </label>
     <input type="password" name="pwd2" id="pwd2" class="input_"/><br />
     <label style="width: 154px;">Repeter votre mot de passe :</label>
     <input type="password" name="pwd_check" id="pwd_check" class="input_"/><br /><br />
     <label>Recopier le mot</label>
 <?php/*
    echo captcha::form("&rarr;&nbsp;");
   php_egg_logo_guid()
   */?>

 <img id="captcha" src="./securimage/securimage_show.php" alt="CAPTCHA Image" />
<input type="text" class="input_" name="captcha_code" size="10" maxlength="6" />
    <div id="nick" style="height: 50px; display: none;"><img src="images/loader.gif"/> Verification du login ...</div>
     <input type="submit" value="Register" class="button_"/>
     <button type="button" onclick="document.location.replace('index2.php')" class="button_" style="margin-left: 30px;">Retour</button>
    <br/>
     </form>
	 </td><td class="cd"></td>
    </tr>
	<tr>
    	<td class="bg"></td><td class="bc"></td><td class="bd"></td>
    </tr>

</table>
     </div>
     <?php
      }
 else
   {
/*include_once 'securimage/securimage.php';
$securimage = new Securimage();*/

if ($securimage->check($_POST['captcha_code']) == false) {
  // the code was incorrect
  // handle the error accordingly with your other error checking

  // or you can do something really basic like this
  $err_mess = ('The code you entered was incorrect.  Go back and try again.');
}

     $args_post = $_POST;
     $flag = true;
     $pattern = "^([A-Za-z0-9\.|_|-]{1,60})([@])";
     $pattern .="([A-Za-z0-9\.|_|\-]{1,60})(\.)([A-Za-z\.]{2,7})$";

     if (count($args_post))
       foreach ($args_post as $key => $value)
		$args_post[$key] = mysql_real_escape_string($value);
     if (!(isset($args_post['login2'][0] )) || !(isset($args_post['mail'][0])) || !(isset($args_post['pwd2'][0])))
       {
		 echo 'CHAMP OBLIGATOIRE NON REMPLI OU Captcha incorrect';
		 return (false);
       }
     $req = 'SELECT * FROM users_tracker WHERE login = "' . $args_post['login2'] . '";';
     $ret = mysql_query($req);
     if ($line = $db->GetUserId($args_post['login2']))
       $err_mess = 'Login deja existant';
     else if (!ereg($pattern, $args_post['mail']))
       $err_mess ='Format mail invalide';
     else if ($args_post['pwd2'] != $args_post['pwd_check'])
       $err_mess ='La verification du mot de pass a echoue';
     else
       $flag = false;
     if (!verif_mail(mysql_real_escape_string($args_post['mail'])))
       return (false);
     /*Insertion suivant le resultatn de la recherche derreurs*/
     if ($flag)
	 {
		echo $err_mess;
       return (false);
	  }
	 echo "L'enregistrement c'est bien effectue veuillez cliquer sur le lien d'activation
	 que vous allez revevoir par mail a l'adresse ". $args_post['mail'];
     $db->AddUser($args_post['login2'], $args_post['pwd2'], $args_post['mail']);
	 return (false);
   }
?>