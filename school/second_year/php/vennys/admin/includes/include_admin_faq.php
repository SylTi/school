<?php
	$requete = "SELECT * FROM ".$client."_news, ".$client."_faq";
	$query = mysql_query($requete);?>
    
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
    	<a href="javascript: void(0);" style="color:#0066FF; font-family: Arial; font-size: 10px; margin-right: 25px;" onclick="display('shadow_admin'); display('shadow_view');">Question / Reponse</a>
    </div>
    <table style="margin: auto; margin-top: 15px;" cellpadding="0" cellspacing="0">
    	<tr>
        	<td class="hg"></td><td class="hc"></td><td class="hd"></td>
        </tr>
    	<tr>
        	<td class="cg"></td><td class="cc">
            
	            <table cellpadding="0" cellspacing="2">
                	<tr>
                    	<td style="width: 20px;border: 1px solid #B4B4B4; text-align: center;">Id</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Question</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Reponse</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Options</td>
                    </tr>
<?php
	while ($row = mysql_fetch_object($query)){ ?>
					<tr>
						<td style="border: 1px solid #B4B4B4;">
							<?php echo $row->id_question; ?>
						</td>
                        <td style="border: 1px solid #B4B4B4;">
                            <?php echo substr($row->text_question, 0, 15)."..."; ?>
						</td>
                        <td style="border: 1px solid #B4B4B4;">
							<?php echo substr($row->text_reponse, 0, 15)."..."; ?>
                        </td>
                         <td style="border: 1px solid #B4B4B4; text-align: center;">
                         	<a href="javascript: void(0);" onclick="display('<?php echo $row->id_question."_m";?>')" style="color:#0066FF">d</a> - <a style="color:#0066FF" href="javascript: void(0);" Onclick="del_faq('<?php echo $row->id_question?>')">s</a>
                         </td>
                    </tr>
                    <tr>
                    	<td colspan="4" style="text-align:center; width: 100%;">
                        	<div id="<?php echo $row->id_question."_m";?>" style="display: none; border: 1px solid #B4B4B4; padding: 10px;">
								<div style="clear: both;"></div>
									<div style="text-align: left;">
                                    	<?php echo $row->text_question; ?>
                                        <br />
                                        <a href="javascript: void(0);" style="color:#0066FF; font-family: Arial; font-size: 10px;" onclick="window.open('fckeditor/_samples/php/sample03.php?id=<?php echo $row->id_question; ?>&row=question', 'Contenu de : <?php echo substr($row->text_reponse, 0, 5)."..." ?>', config='height=400, width=800, toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, directories=no, status=no')">Editer la question</a>
                                        <br />
                                        <?php echo $row->text_reponse; ?>
                                        <br />
                                        <a href="javascript: void(0);" style="color:#0066FF; font-family: Arial; font-size: 10px;" onclick="window.open('fckeditor/_samples/php/sample03.php?id=<?php echo $row->id_question; ?>&row=reponse', 'Contenu de : <?php echo substr($row->text_reponse, 0, 5)."..." ?>', config='height=400, width=800, toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, directories=no, status=no')">Editer la reponse</a>
                                    </div>
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