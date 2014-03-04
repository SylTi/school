<?php
	$requete = "SELECT * FROM ".$client."_users ORDER BY user_droit";
	$query = mysql_query($requete);?>
    <div class="shadow" id="shadow_admin" onclick="display('shadow_admin'); display('shadow_view');">
    </div>
    <div id="shadow_view" class="inner_shadow">
    	<img src="images/ajouter_un_utilisateur.gif" border="0" /><br /><br />
        <form action="includes/include_add_admin.php" method="post" name="form_a" id="form_a">
        <div class="titre_admin" id="login">Identifiant :</div><div class="case_admin"><input type="text" class="input_" id="login_a" name="login_a" value=""/></div>
        <div class="titre_admin" id="password">Mot de passe :</div><div class="case_admin"><input type="text" class="input_" id="password_a" name="password_a" value=""/></div>
<div class="titre_admin" id="rang">Rang :</div><div class="case_admin"><select name="rang_a" id="rang_a" class="select_"><option value="0">Administrateur</option><option value="1">Moderateur</option></select></div>
        <div class="titre_admin" id="ip">Ip :</div><div class="case_admin"><input type="text" class="input_" id="ip_a" name="ip_a" value=""/></div>
        <div class="titre_admin" id="ip"></div><div class="case_admin"><a href="javascript: void(0);" onclick="document.getElementById('ip_a').value='<?php echo $_SERVER['REMOTE_ADDR'];?>'" style="color:#0066FF; font-family: Arial; font-size: 10px;">[ Me donner mon ip ]</a></div>
        <div class="titre_admin" id="log1">&nbsp;</div><div class="case_admin"><a href="javascript: void(0);" onclick="add_admin(); return false;"><img src="images/bouton_submit.gif" style="margin-top: 5px;" /></a></div>
        </form>
    </div>
    <div style="height: 15px; background: #DFDFDF; margin: -5px; text-align: right;">
    	<a href="javascript: void(0);" style="color:#0066FF; font-family: Arial; font-size: 10px; margin-right: 25px;" onclick="display('shadow_admin'); display('shadow_view');">Ajouter un utilisateur</a>
    </div>
    <table style="margin: auto; margin-top: 15px;" cellpadding="0" cellspacing="0">
    	<tr>
        	<td class="hg"></td><td class="hc"></td><td class="hd"></td>
        </tr>
    	<tr>
        	<td class="cg"></td><td class="cc">
            
	            <table cellpadding="0" cellspacing="2">
                	<tr>
                    	<td style="width: 20px;border: 1px solid #B4B4B4; text-align: center;">Id</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Login</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Droit</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Options</td>
                    </tr>
<?php
	while ($row = mysql_fetch_object($query)){ ?>
					<tr>
						<td style="border: 1px solid #B4B4B4;">
							<?php echo $row->id_user; ?>
						</td>
                        <td style="border: 1px solid #B4B4B4;">
                            <?php echo $row->username; ?>
						</td>
                        <td style="border: 1px solid #B4B4B4;">
                            <?php if ($row->user_droit == 0) echo "Administrateur"; elseif ($row->user_droit == 1) echo "Moderateur" ?>
                        </td>
                         <td style="border: 1px solid #B4B4B4; text-align: center;">
                         	<a href="javascript: void(0);" onclick="display('<?php echo $row->id_user."_m";?>')" style="color:#0066FF">d</a> - <a href="javascript: void(0);" onclick="delete_admin('<?php echo $row->id_user;?>', '<?php echo $row->username?>', '<?php echo $row->user_droit;?>')" style="color:#0066FF">s</a>
                         </td>
                    </tr>
                    <tr>
                    	<td colspan="4" style="text-align:center; width: 100%;">
                        	<div id="<?php echo $row->id_user."_m";?>" style="display: none; border: 1px solid #B4B4B4; padding: 10px;">
								<div style="clear: both;"></div>
                                <form action="includes/include_modif_compte.php" method="post" id="form_<?php echo $row->id_user;?>m" name="form_<?php echo $row->id_user;?>m">
                                <input type="hidden" id="id_m" name="id_m" value="<?php echo $row->id_user; ?>" />
                            	<div class="titre_admin" id="log1">Identifiant :</div><div class="case_admin"><input type="text" class="input_" id="login_m" name="login_m" value="<?php echo $row->username; ?>"/></div>
                            	<div class="titre_admin" id="log2">Mot de passe :</div><div class="case_admin"><input type="text" class="input_" id="password_m" name="password_m" value=""/></div>
								<div class="titre_admin" id="log3">Ip :</div><div class="case_admin"><input type="text" class="input_" id="ip_m" name="ip_m" value=""/></div>
 <div class="titre_admin" id="ip"></div><div class="case_admin"><a href="javascript: void(0);" onclick="document.getElementById('ip_m').value='<?php echo $_SERVER['REMOTE_ADDR'];?>'" style="color:#0066FF; font-family: Arial; font-size: 10px;">[ Me donner mon ip ]</a></div>
                                <div class="titre_admin" id="log1">&nbsp;</div><div class="case_admin"><a href="javascript: void(0);" onclick="document.getElementById('form_<?php echo $row->id_user;?>m').submit();"><img src="images/bouton_submit.gif" style="margin-top: 5px;" /></a></div>
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