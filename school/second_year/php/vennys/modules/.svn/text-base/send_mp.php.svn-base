<?php
//Envoie de mess. privés : Se.

$nav_pmbarre ="<div class='msg_cont'><p><a href='./index.php?page=send_mp&act=new'>".$lang['site']['New_mess']."</a> | ".$lang['site']['Order_mess']." <a href='./index.php?page=send_mp&ord=read'>".$lang['site']['list_msg_1t']."</a> | <a href='./index.php?page=send_mp&ord=date'>".$lang['site']['list_msg_4t']."</a> | <a href='./index.php?page=send_mp&ord=from'>".$lang['site']['list_msg_2t']."</a></p></div>";


function list_mp($act)
{
	if($_GET['ord'])
	switch ($_GET['ord'])
	{
		case "read":
			$_SESSION[ord_read] = $_SESSION[ord_read]=="order by is_read desc"?"order by is_read asc":"order by is_read desc";
			$sql_oon_read=$_SESSION[ord_read];

			break;
		case "date":
			$_SESSION[ord_date] = $_SESSION[ord_date]=="order by date desc"?"order by date asc":"order by date desc";
			$sql_oon_date=$_SESSION[ord_date];

			break;
		case "from":
			$_SESSION[ord_from] = $_SESSION[ord_from]=="order by user_login desc"?"order by user_login asc":"order by user_login desc";			$sql_oon_from=$_SESSION[ord_from];

			break;

	}
	if (is_numeric($act))
	$and_req = "and id = '$act'";
	else $and_req ="";

	$rekmy = "SELECT user_id,user_login, id, id_from, id_to, is_read, date, txt, titre
	FROM priv_msg, users_tracker
	WHERE id_to = user_id and id_from = user_id and id_to = '".$_SESSION['user_id']."' $and_req
	GROUP by id desc $sql_oon_read $sql_oon_date $sql_oon_from";

	$qrypm = mysql_query($rekmy)or die(mysql_error());

	if($act=="all"){
		$my_send_form= "<form action='#' method='post' class='msg_form'><div class='span_apm'><span class='span_bpm'>".$lang['site']['list_msg_1t']."</span><span class='span_cpm'>".$lang['site']['list_msg_2t']."</span><span class='span_dpm'>".$lang['site']['list_msg_3t']."</span><span class='span_epm'>".$lang['site']['msg_preview']."</span><span span='span_fpm'></span>";
		$nbrow = mysql_numrows($qrypm);
		if($nbrow)
		while($pmrow = mysql_fetch_array($qrypm))
		{
			$row = $row=="1"?$row="2":$row="1";
			$rowcolor = $row=="1"?"#474747":"#090909";
			$img_mail = $pmrow['is_read']=="0"?"<img class='span_img' src='./images/ic_mail_non_lu.gif'>":"<img style='border:0;padding:1px;margin-top:1px;'  src='./images/ic_mail_lu.gif'>";
			$img_repmail ="<img src='./images/ic_mail_reply.gif' class='span_img2'>";
			$img_delmail ="<img src='./images/ic_mail_accu.gif' class='span_img2'>";
			$my_send_form.= "
		<div style='background-color:$rowcolor;' class='span_spe'><span class='span_bapm'>$img_mail</span><span class='span_capm'><a href='./index.php?page=user&id=$pmrow[user_id]'>$pmrow[user_login]</a></span><span class='span_dapm'>$pmrow[titre]</a></span><span class='span_eapm'><a href='./index.php?page=send_mp&id=$pmrow[id]'>".substr($pmrow[txt],0,25)."...</a></span><span class='span_fapm'><a href='./index.php?page=send_mp&act=del&id=$pmrow[id]' title='supprimer le message'>$img_delmail</a> - <a href='./index.php?page=send_mp&act=reply&id=$pmrow[id]' title='répondre au message'>$img_repmail</a></span></div>";
		}
		else
		$my_send_form.= "
	<p class='span_err'><strong>".$lang['site']['MP_nonew']."</strong></p>";
		$my_send_form.= "</div></form>";
	}
	else
	$my_send_form= "
	<div class='span_err2'>";
	$nbrow = mysql_numrows($qrypm);
	if($nbrow)
	while($pmrow = mysql_fetch_array($qrypm))
	{
		$idtoup = $pmrow['id'];
		$img_mail = $pmrow['is_read']=="0"?"<img src='./images/ic_mail_non_lu.gif'>":"<img src='./images/ic_mail_lu.gif'>";
		$row = $row=="1"?$row="2":$row="1";
		$rowcolor = $row=="1"?"#B7B7B7":"#C7C7C7";
		$my_send_form.= "<span class='span_act'>Action : <a href='./index.php?page=send_mp&act=del&id=$pmrow[id]' title='supprimer le message'><img src='./images/ic_mail_accu.gif' border='0'></a>  <a href='./index.php?page=send_mp&act=reply&id=$pmrow[id]' title='répondre au message'><img src='./images/ic_mail_reply.gif' class='span_img2'></a></span>
		<span class='span_pad'>".$lang['site']['msg_send']." $pmrow[user_login] le ".mysql_DateTime2($pmrow[date])."</span><br /><br /><span class='span_pad'>".$lang['site']['msg_titre']." <strong><u>$pmrow[titre]</u></strong></span><hr /><span class='span_rep'>".nl2br($pmrow[txt])."<br /></span>";
		if (($and_req)) {
			update_mp($idtoup,"1");
		}
	}
	$my_send_form.="</div>";
	return ($my_send_form);
}

function update_mp($id_mp,$whatupdate)
{
	$rekmy = "UPDATE priv_msg SET is_read = '$whatupdate' WHERE id = '$id_mp' and id_to = '$_SESSION[user_id]'";
	mysql_query($rekmy) or die(mysql_error());
}

function delete_mp($id_mp)
{
	$rekmy = "DELETE from priv_msg where id='$id_mp' and id_to = '$_SESSION[user_id]'";
	if (mysql_query($rekmy))
	$msg_form="<div class='msg_err'><p>".$lang['site']['msg_corec_sup']."</p></div>";
	else
	$msg_form="<div class='msg_err'><p>".$lang['site']['msg_no_sup']."</p></div>";
	return ($msg_form);
}


function load_msg_form($replyto_id)
{
	$my_login= "$_SESSION[user_login]";
	$_myid = $_SESSION[user_id];

	if(!$_POST['id_from']){
		$reqmyusers = "SELECT * FROM users_tracker where user_group != '-1' $sql_oon_read $sql_oon_date $sql_oon_from";
		$qrymuusers = mysql_query($reqmyusers) or die(mysql_error());

		if (empty($replyto_id) && empty($replyto_userid) && empty($replyto_uselogin)){
			if ($rmsg_users = mysql_fetch_array($qrymuusers))
			{
				$msg_listusers = '<input autocomplete="off" name="clb_e" id="clb_e" type="text" value="'.$lang["site"]["msg_fdest"].'" onFocus="javascript:if(this.value==\'Trouver un destinataire...\') this.value=\'\';" onkeyup="javascript:autosuggest(\'clb_e\',\'clb_e\')" style="margin:1px;width:220px;"/>
<div id="res_clb_e"></div>';
			}
			$my_send_form = "
	<form action='#' method='post' name='submit_pm' class='msg_form'>
	<div class='msg_in'>
	<div><strong>".$lang['site']['msg_enterit']."</strong></div><br />
	<div class='msg_txt'>".$lang['site']['msg_dest']."</div><div>$msg_listusers</div>
	<div class='msg_txt'>".$lang['site']['msg_from']."</div><div><input type='text' value='$my_login' name='user' disabled='disabled'></div>
	<div class='msg_txt'>".$lang['site']['msg_titre']."</div><div><input type='text' name='titre'></div>
	<div class='msg_txt'>".$lang['site']['msg_contenu']."</div><div><textarea cols='45' rows='5' name='txt'></textarea></div>
	<input type='submit' value='Envoyer le MP' style='float:right;margin-top:10px;'>
	<input type='hidden' value='$_myid' name='id_from'>
	</div>
	</form>";
		}
		else
		{
			$reqmyusers2 = "SELECT * FROM priv_msg, users_tracker where id_to = user_id and id_from = user_id and user_group != '-1' and id = '$replyto_id' limit 1";
			$qrymuusers2 = mysql_query($reqmyusers2) or die(mysql_error());
			$msg_listusers ="<option value='$replyto_userid'>$replyto_uselogin</option>";

			$findreq = "SELECT user_login, user_id FROM priv_msg, users_tracker where id_from = user_id and user_group != '-1' and id = '$replyto_id' limit 1";
			$qryreq = mysql_query($findreq) or die(mysql_error());
			if ($rmsg_users2 = mysql_fetch_array($qrymuusers2)){
				if ($rmsg_req = mysql_fetch_array($qryreq))
				$msg_listusers = "<option value='$rmsg_req[user_id]'>$rmsg_req[user_login]</option>";
				$thetitre = stripslashes(mysql_real_escape_string(htmlspecialchars($rmsg_users2[titre])));
				$thetxt = (stripslashes((($rmsg_users2[txt]))));
				$my_send_form = "
	<form action='#' method='post' name='submit_pm' class='msg_form'>
	<div class='msg_in'>
	<div><strong>".$lang['site']['msg_enterit']."</strong></div><br />
	<div class='msg_txt'>".$lang['site']['msg_dest']."</div><div><select name='id_to'>$msg_listusers</select></div>
	<div class='msg_txt'>".$lang['site']['msg_from']."</div><div><input type='text' value='$my_login' name='user' disabled='disabled'></div>
	<div class='msg_txt'>".$lang['site']['msg_titre']."</div><div><input type='text' name='titre' value='Re: ";
				$my_send_form.="$thetitre'></div>";
				$my_send_form.="
	<div class='msg_txt'>".$lang['site']['msg_contenu']."</div><div><textarea cols='45' rows='16' name='txt'>


_____________________________________________
".$lang['site']['msg_previous']." :
$thetxt</textarea></div>
	<input type='submit' value='Envoyer le MP' style='float:right;margin-top:10px;'>
	<input type='hidden' value='$_myid' name='id_from'>
	</div>
	</form>";
			}
		}		}
if (!empty($_POST[id_from]))
		if (!empty($_POST['id_to']) && !empty($_POST['id_from']) && !empty($_POST['txt']) && !empty($_POST['titre']))
		{
			if(send_mp($_POST['id_to'],$_POST['txt'],$_POST['titre']))
			$my_send_form="<div class='msg_err'><p>Votre message à correctement été envoyé,<br />Merci pour votre envoie !<br /><br /><a href='./index.php'>< retour ></a></p></div>";
			else
			$my_send_form="<div class='msg_err'><p>une erreur est survenue, désolé pour vous.<br /><br /><br />
		- <strong><a href='../index.php?page=send_mp&act=new' title='Retenter ma chance pour un nouvel envoi !'>Retenter ma chance maintenant !!</a></strong><br />- <strong><a href='../index.php?page=send_mp' title='Accueil vennys'>Je désespère : retour accueil</a></strong></p></div>";
		}
		else{
		$my_send_form="<div class='msg_err'><p>une erreur est survenue, désolé pour vous.<br /><br /><br />
		- <strong><a href='../index.php?page=send_mp&act=new' title='Retenter ma chance pour un nouvel envoi !'>Retenter ma chance maintenant !!</a></strong><br />- <strong><a href='../index.php?page=send_mp' title='Accueil vennys'>Je désespère : retour accueil</a></strong></p></div>";
		}return $my_send_form;
}

function send_mp($id_to, $messtosend,$titremp)
{
	$rekmy = "INSERT INTO priv_msg(id_from, id_to, txt, titre, date)
 VALUES('".$_SESSION[user_id]."','".$id_to."', '".$messtosend."','".$titremp."',NOW())";
	if (mysql_query($rekmy))
	return (true);
	else
	return (false);
}

if($_GET['act'])
switch ($_GET['act'])
{
	case "del":
		$msg_form = delete_mp($_GET['id']);
		break;
	case "reply":
		$msg_form = load_msg_form($_GET['id']);
		break;
	case "new":
		$msg_form = load_msg_form("");
		break;
}

else if($_GET[id])
$msg_form.=list_mp($_GET[id]);
else
$msg_form.=list_mp("all");
echo "<div class='msg_cont'>$nav_pmbarre<br />$msg_form</div>";
?>
