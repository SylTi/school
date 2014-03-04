<?php
	$requete = "SELECT * FROM users_tracker";
	$query = mysql_query($requete) or die (mysql_error());?>
    
     <div class="shadow" id="shadow_admin" onclick="display('shadow_admin'); display('shadow_view');">
    </div>
    <div id="shadow_view" class="inner_shadow">
    	<img src="images/ajouter_un_utilisateur.gif" border="0" /><br /><br />
        <form action="includes/include_add_faq.php" method="post" name="form_a" id="form_a">
        <div class="titre_admin" id="t_question">Question :</div><div class="case_admin"><textarea name="question" value="" id="question" style="width: 149px; font-family: Arial; font-size: 10px;"/></textarea></div>
        <div class="titre_admin" id="t_reponse">Reponse :</div><div class="case_admin"><textarea name="reponse" id="reponse" value="" style="width: 149px; font-family: Arial; font-size: 10px;"/></textarea></div>
        <div class="titre_admin" id="log1">&nbsp;</div><div class="case_admin"><a href="javascript: void(0);" onclick="add_faq(); return false;"><img src="images/bouton_submit.gif" style="margin-top: 5px;" /></a></div>
        </form>
    </div>
    <div style="height: 15px; background: #DFDFDF; margin: -5px; text-align: right;">
    </div>
    <table style="margin: auto; margin-top: 15px;" cellpadding="0" cellspacing="0">
    	<tr>
        	<td class="hg"></td><td class="hc"></td><td class="hd"></td>
        </tr>
    	<tr>
        	<td class="cg"></td><td class="cc">
            
	            <table cellpadding="0" cellspacing="2">
                	<tr>
                    	<td style="width: 20px;border: 1px solid #B4B4B4; text-align: center;">Id</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Login</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Group</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Options</td>
                    </tr>
<?php
	while ($row = mysql_fetch_object($query)){ ?>
					<tr>
						<td style="border: 1px solid #B4B4B4;">
							<?php echo $row->user_id; ?>
						</td>
                        <td style="border: 1px solid #B4B4B4;">
                            <?php echo $row->user_login; ?>
						</td>
                        <td style="border: 1px solid #B4B4B4;">
							<?php echo $row->name_group; ?>
                        </td>
                         <td style="border: 1px solid #B4B4B4; text-align: center;">
                         	<a href="javascript: void(0);" onclick="display('<?php echo $row->user_id."_m";?>')" style="color:#0066FF">d</a> - <a style="color:#0066FF" href="includes/delete_user.php?id=<?php echo $row->user_id; ?>"  style="color:#0066FF">s</a>
                         </td>
                    </tr>
                    <tr>
                    	<td colspan="4" style="text-align:center; width: 100%;">
                        	<div id="<?php echo $row->user_id."_m";?>" style="display: none; border: 1px solid #B4B4B4; padding: 10px;">
								<div style="clear: both;"></div>
									<form action="includes/include_modif_user.php" method="post" id="form_<?php echo $row->user_id;?>m" name="form_<?php echo $row->user_id;?>m">
                                <input type="hidden" id="id_m" name="id_m" value="<?php echo $row->user_id; ?>" />
                            	<div class="titre_admin" id="log1">Identifiant :</div><div class="case_admin"><input type="text" class="input_" id="login_m" name="login_m" value="<?php echo $row->user_login; ?>"/></div>
                            	<div class="titre_admin" id="log2">Mot de passe :</div><div class="case_admin"><input type="text" class="input_" id="password_m" name="password_m" value=""/></div>
								<div class="titre_admin" id="log3">Mail :</div><div class="case_admin"><input type="text" class="input_" id="mail_m" name="mail_m" value="<?php echo $row->user_mail; ?>"/></div>
           						<div class="titre_admin" id="log3">Langue :</div><div class="case_admin"><select name="langue_m" id="langue_m" class="select_"><option <?php if ($row->user_lang == "French"){?>selected="selected"<?php }?> value="French">Francais</option><option value="English" <?php if ($row->user_lang == "French"){?>selected="selected"<?php }?>>Anglais</option></select></div>
                                 <div class="titre_admin" id="log1">&nbsp;</div><div class="case_admin"><a href="javascript: void(0);" onclick="document.getElementById('form_<?php echo $row->user_id;?>m').submit();"><img src="images/bouton_submit.gif" style="margin-top: 5px;" /></a></div>
                                 </form>
                                <div style="clear: both;"></div>
                            </div>
                        </td>
                    </tr>
<?php }?>
				</table>
            </td><td class="cd"></td>
        </tr>
    	<tr>
        	<td class="bg"></td><td class="bc"></td><td class="bd"></td>
        </tr>
    </table>