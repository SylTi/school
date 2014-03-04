<?php
if (!isset($_SESSION['user_id']))
  {
    ?>
    <form method="post">
      <br />
      <br />
      <input type="hidden" name="login" value="./index.php?page=login_form" />
      <label>Login :</label><input type="text" name="login" /><br />
      <label>Password :</label><input type="password" name="pwd" />
      <br />
      <label>Remember :</label><input type="checkbox" name="remember"><br />
      <input type="submit" value="OK"/><br />
</form>

<?php
      }
 else
   login_form_treat($_POST);

function log_in($sql_line)
{
  $fr = "French";
  $en = "English";
  $_SESSION['user_id'] = $sql_line['user_id'];
  $_SESSION['user_login'] = $sql_line['user_login'];
  if ( $sql_line['user_lang'] == 0)
    $_SESSION['user_lang'] = $fr;
  else if ($sql_line['user_lang'] == 1)
    $_SESSION['user_lang'] = $en;
  else
    $_SESSION['user_lang'] = "FUCK_YPU";
  header('Location: ./');
}

function login_form_treat($args_post)
{
  $login = mysql_real_escape_string($args_post['login']);
  $pass = mysql_real_escape_string($args_post['pwd']);
  $req = ("SELECT * FROM users_tracker WHERE user_login = '$login'");
  $ret = mysql_query($req);
  if ($ret && $line = mysql_fetch_array($ret))
    {
      if ($line['pwd'] == md5($pass))
        log_in($line);
      else
        echo "Mot de passe invalide";
    }
  else
    echo "Utilisateur inconnu";
}
?>