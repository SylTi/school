<?php
if($_GET["page"] == "profil"){
	$id = $db->GetUserId($_SESSION["user_login"]);
	$info = $db->GetUserInfos($id);
	if(!isset($_GET['result']))
	{
  ?>
      <form name="modif_profil" action="index.php?page=profil&result=ok" method="POST">
       <span><br /><?php echo $lang["site"]["pro_log"]; ?> <?php echo $info['user_login']; ?><br /></span>
       <span><br /><?php echo $lang["site"]["pro_pass"]; ?>  :<br /></span>
       <input class="form_profil" type="password" name="profil_pwd" value="" /><br />
       <span><br /><?php echo $lang["site"]["pro_pass2"]; ?>  :<br /></span>
       <input class="form_profil" type="password" name="profil_pwd2" value="" /><br />
       <span><br /><?php echo $lang["site"]["pro_mail"]; ?>  :<br /></span>
       <input class="form_profil" type="text" name="mail" name="mail" value="<?php echo $info['user_mail']; ?>" /><br />
       <span><br /><?php echo $lang["site"]["pro_client"]; ?>  :<br /></span>
       <input class="form_profil" type="text" name="client" name="client" value="<?php echo $info['user_client']; ?>" /><br />
       <span><br /><?php echo $lang["site"]["pro_location"]; ?>  :<br /></span>
       <input class="form_profil" type="text" name="locat" name="locat" value="<?php echo $info['user_location']; ?>" /><br />
       <span><br /><?php echo $lang["site"]["pro_style"]; ?>  :<br /></span>
       <select name="user_style">
       <?php
       foreach ($disp_style AS $style => $value)
       {
       	?>
		<option value='<?php echo $value; if ($value == $_SESSION["user_style"]) echo "' selected='selected'"; else echo "'"; ?>>
		<?php echo $style; ?>
		</option>
		<?php } ?>
    	</select>
        <span><br /><?php echo $lang["site"]["pro_lang"]; ?>  :<br /></span>
        <select name="Language">
		<?php 
		$i = 0;
		foreach ($tab_lang AS $cle => $valeur)
		{
			if ($info['user_lang'] == $i)
			{
       	?>
		<option selected value="<?php echo $i; ?>"><?php echo $cle; $i++; ?></option>
		<?php
			}
			else
		{?>
	  		<option value="<?php echo $i; ?>"><?php echo $cle; $i++;?></option>
			<?php }
		}?>
    </select>
     <br /><br />
    <input type="submit" value="Envoyer" style="margin-left: 20px"/><br /><br />
     </form>   
<?php } 
else
{
	if (isset($_POST))
	{
		$fr = "French";
		$en = "English";
		$tab = $_POST;
		if (($_POST['profil_pwd'] != '') && ($_POST['profil_pwd2'] == $_POST['profil_pwd']))
		{
			if (isset($tab['Language'])){
				if ( $tab['Language'] == '0')
				$_SESSION['user_lang'] = $fr;
				else if ($tab['Language'] == '1')
				$_SESSION['user_lang'] = $en;
				$curr = $_SESSION['user_lang'];
				$lang = $tab_lang[$curr];}
				$pass = md5($tab['profil_pwd']);
				if ($_SESSION['user_style'] != $tab['user_style'] && $tab['user_style'] != '')
				$_SESSION['user_style'] = $tab['user_style'];
				else
				$tab['user_style'] = '';

				$db->EditUser($id,'', $pass, $tab['mail'], $tab['client'], $tab['locat'], $tab['user_style'], $tab['Language']);
		}
		else if ($tab['profil_pwd'] == '')
		{
			if (isset($tab['Language']))
			{
				if ( $tab['Language'] == '0')
				$_SESSION['user_lang'] = $fr;
				else if ($tab['Language'] == '1')
				$_SESSION['user_lang'] = $en;
				$curr = $_SESSION['user_lang'];
				$lang = $tab_lang[$curr];
			}
			if ($_SESSION['user_style'] != $tab['user_style'] && $tab['user_style'] != '')
			$_SESSION['user_style'] = $tab['user_style'];
			else
			$tab['user_style'] = '';

			$db->EditUser($id,'', '', $tab['mail'], $tab['client'], $tab['locat'], $tab['user_style'], $tab['Language']);
			echo "<a href='index.php?page=profil'>Retourner sur votre profil</a>";
		}
		else
		echo "Fuck You<br />";
	}
	else
	echo "Non-Non-Non<br /><br />";
}
}
?>