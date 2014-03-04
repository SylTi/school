<?php
	if (!isset($_GET['dad']))
		$dad = '-1';
	else
		$dad = $_GET['dad'];
	$requete = "SELECT * FROM ".$client."_menu_site WHERE pere_menu='".$dad."'";
	$query = mysql_query($requete) or die (mysql_error());?>

    <div class="shadow" id="shadow_admin" onclick="display('shadow_admin'); display('shadow_view');">
    </div>
    <div id="shadow_view" class="inner_shadow">
    	<img src="images/ajouter_un_utilisateur.gif" border="0" /><br /><br />
        <form action="includes/include_add_menu.php" method="post" name="form_a" id="form_a">
        <input type="hidden" name="id_pere" value="<?php echo $dad; ?>" />
        <div class="titre_admin" id="name">Nom du menu [fr] :</div><div class="case_admin"><input type="text" class="input_" id="nom_menu" name="nom_menu_fr" value=""/></div>
        <div class="titre_admin" id="name">Nom du menu [en] :</div><div class="case_admin"><input type="text" class="input_" id="nom_menu" name="nom_menu_en" value=""/></div>
        <div class="titre_admin" id="pager">Pager menu :</div><div class="case_admin"><input type="text" class="input_" id="pager_menu" name="pager_menu" value=""/></div>
        <div class="titre_admin" id="log1">&nbsp;</div><div class="case_admin"><a href="javascript: void(0);" onclick="verif_add_menu(); return false;"><img src="images/bouton_submit.gif" style="margin-top: 5px;" /></a></div>
        </form>
    </div>
	
    <?php
    	$request = "SELECT pere_menu FROM ".$client."_menu_site WHERE id_menu='".$dad."'";
		$query_dad = mysql_query($request) or die(mysql_error());
		$dada = mysql_fetch_object($query_dad);

		if (mysql_num_rows($query_dad) > 0)
			$id_p = $dada->pere_menu;
		else
			$id_p = $dad;
	?>

    <div style="height: 15px; background: #DFDFDF; margin: -5px; text-align: right;">
    	<a href="javascript: void(0);" style="color:#0066FF; font-family: Arial; font-size: 10px; margin-right: 25px;" onclick="document.location.replace('admin.php?menu=7&dad=<?php echo $id_p; ?>')">Remonter</a><a href="javascript: void(0);" style="color:#0066FF; font-family: Arial; font-size: 10px; margin-right: 25px;" onclick="display('shadow_admin'); display('shadow_view');">Ajouter un menu</a>
    </div>
    <table style="margin: auto; margin-top: 15px;" cellpadding="0" cellspacing="0">
    	<tr>
        	<td class="hg"></td><td class="hc"></td><td class="hd"></td>
        </tr>
    	<tr>
        	<td class="cg"></td><td class="cc">
            
	            <table cellpadding="0" cellspacing="2">
                	<tr>
                    	<td style="width: 20px;border: 1px solid #B4B4B4; text-align: center;">Id</td><td style="width: 200px;border: 1px solid #B4B4B4; text-align: center;">Nom du menu</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Options</td>
                    </tr>
<?php
	while ($row = mysql_fetch_object($query)){ ?>
					<tr>
						<td style="border: 1px solid #B4B4B4;">
							<?php echo $row->id_menu; ?>
						</td>
                        <td style="border: 1px solid #B4B4B4;">
                            <?php echo $row->nom_menu_french; ?>
						</td>
                         <td style="border: 1px solid #B4B4B4; text-align: center;">
                         	<a href="javascript: void(0);" onclick="display('<?php echo $row->id_menu."_m";?>')" style="color:#0066FF">d</a> - <a style="color:#0066FF" href="includes/include_del_menu.php?id=<?php echo $row->id_menu; ?>">s</a> - <a style="color:#0066FF" href="admin.php?menu=7&dad=<?php echo $row->id_menu; ?>">></a>
                         </td>
                    </tr>
                    <tr>
                    	<td colspan="4" style="text-align:center; width: 100%;">
                        	<div id="<?php echo $row->id_menu."_m";?>" style="display: none; border: 1px solid #B4B4B4; padding: 10px;">
								<div style="clear: both;"></div>
									<div style="text-align: left;">
                                    	<form name="edit_menu<?php echo $row->id_menu; ?>" id="edit_menu<?php echo $row->id_menu; ?>" action="includes/edit_menu.php" method="post" >
                                    	<input type="hidden" id="id_menu" name="id_menu" value="<?php echo $row->id_menu; ?>"/>
                                    	<div class="titre_admin" id="name<?php echo $row->id_menu; ?>">Nom du menu [fr] :</div><div class="case_admin"><input type="text" class="input_" id="nom_menu<?php echo $row->id_menu; ?>" name="nom_menu_fr<?php echo $row->id_menu; ?>" value="<?php echo $row->nom_menu_french; ?>"/></div>
                                        <div class="titre_admin" id="name<?php echo $row->id_menu; ?>">Nom du menu [en] :</div><div class="case_admin"><input type="text" class="input_" id="nom_menu<?php echo $row->id_menu; ?>" name="nom_menu_en<?php echo $row->id_menu; ?>" value="<?php echo $row->nom_menu_english; ?>"/></div>
                                    </div>
                                    <div style="text-align: center;">
                                    	<div class="titre_admin" id="pager<?php echo $row->id_menu; ?>">Pager menu :</div><div class="case_admin"><input type="text" class="input_" id="pager_menu<?php echo $row->id_menu; ?>" name="pager_menu<?php echo $row->id_menu; ?>" value="<?php echo $row->pager_menu; ?>"/>
                                    </div>
                                     <div class="titre_admin" id="log1">&nbsp;</div><div class="case_admin"><a href="javascript: void(0);" onclick="verif_edit_menu('<?php echo $row->id_menu; ?>'); return false;"><img src="images/bouton_submit.gif" style="margin-top: 5px;" /></a></div>
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