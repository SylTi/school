<?php
//Envoie de mess. privés : Se.
function msg_read_update($chkbox, $_myid, $msg_read)
{
	$i = 0;
	while ($chkbox[$i]) {
		$ressql ="UPDATE priv_msg SET is_read = '$msg_read' where id_to = '$_myid' and id = '$chkbox[$i]'";
		mysql_query($ressql);
		echo $ressql;
		$i++;
	}
	header('Location:index.php');
}

function load_msg_list()
{
	$my_login= "NEED_SESSION";
	$_myid = "42";
	$id_action = $_POST[id_act];
	$action = $_POST[action];
	list_mp($_myid);

	$reqmyusers = "SELECT id, is_read, date, titre, txt, username,id_user FROM vennys_users, priv_msg where user_droit like '%' and vennys_users.id_user = priv_msg.id_to and priv_msg.id_to = '$_myid' and is_read != '-1'";
	$qrymuusers = mysql_query($reqmyusers);
	$i = '0';

	//Listage mails
	if(mysql_num_rows($qrymuusers) > '0')
	{
		$my_send_form ="
			<form action='#' method='post' class='msg_lform' name='lform'>
		<div class='list_msg_tin'>
		<div><strong>Liste de vos messages privés :</strong></div><br />
		<div class='list_msg_0t'>[]</div>
		<div class='list_msg_1t'>$lang['site']['list_msg_1t']</div>
		<div class='list_msg_2t'>$lang['site']['list_msg_2t']</div>
		<div class='list_msg_3t'>$lang['site']['list_msg_3t']</div>
		<div class='list_msg_4t'>$lang['site']['list_msg_4t']</div>
		";
		$rowc='0';
		while ($rmsg_users = mysql_fetch_array($qrymuusers)) {
			//else
			$rowc= $rowc=='19'?$rowc='2':$rowc='1';
			$my_send_form .= "
		<div class='list_msg_in'>
		<p class='list_msg_$rowc' style='width:27px;float:left;'><input type='checkbox' name='checkbox[]'  value='".$rmsg_users[id]."' style='float:left;'></p>
		<p class='list_msg_$rowc' style='width:38px;float:left;'><img style='float:left;width:15px;height:15px;' src='../images/pm_read".$rmsg_users[is_read].".png'></p>
		<p class='list_msg_$rowc' style='width:128px;float:left;'>$rmsg_users[username]</p>
		<p class='list_msg_$rowc' style='width:140px;float:left;'>".substr($rmsg_users[titre],0,75)."</p>
		<p class='list_msg_$rowc' style='width:190px;float:left;'>".substr($rmsg_users[txt],0,75)."</p>
		<p class='list_msg_$rowc' style='width:160px;float:left;'>le ".mysql_DateTime2($rmsg_users[date])."</p>
		</div>";
		}
		$my_send_form.='
		<div style="float:left;margin-top:5px;">
		<input type="submit" name="supp" value="Supprimer">
		<input type="submit" name="unread" value="marquer comme non lu">
		<input type="submit" name="read" value="marquer comme lu">
		<input type="hidden" value="'.$_myid.'" name="id_from">
		</div></form></div></div>';

		//Use my form to UP and DEL !
		if($_POST["supp"])
		$my_send_form= msg_read_update($_POST[checkbox],$_myid,'-1');
		else if($_POST["unread"])
		$my_send_form= msg_read_update($_POST[checkbox],$_myid,'0');
		else if($_POST["read"])
		$my_send_form= msg_read_update($_POST[checkbox],$_myid,'1');}
		else if (mysql_num_rows($qrymuusers) <= '0')
		$my_send_form="<div class='msg_err'><p>$lang['site']['MP_nonew']<br /><br /><a href='../index.php?page=accueil'>retour</a></p></div>";


		return $my_send_form;
}

function list_mp($id_user)
{
	if(mysql_query("SELECT * FROM priv_msg WHERE id_to = '$_myid' order by id_desc"))
	return (true);
	else
	return (false);
}

$msg_form = load_msg_list();
echo $msg_form;

?>
