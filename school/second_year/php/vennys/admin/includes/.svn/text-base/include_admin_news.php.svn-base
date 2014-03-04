<?php
	$requete = "SELECT * FROM ".$client."_news, ".$client."_users WHERE ".$client."_news.id_user_news=".$client."_users.id_user ORDER BY date_news DESC";
	$query = mysql_query($requete);?>
    
    <div style="height: 15px; background: #DFDFDF; margin: -5px; text-align: right;">
    	<a href="javascript: void(0);" style="color:#0066FF; font-family: Arial; font-size: 10px; margin-right: 25px;" onclick="window.open('fckeditor/_samples/php/sample02.php', 'Creation de news', config='height=400, width=800, toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, directories=no, status=no')">Creer une news</a>
    </div>
    <table style="margin: auto; margin-top: 15px;" cellpadding="0" cellspacing="0">
    	<tr>
        	<td class="hg"></td><td class="hc"></td><td class="hd"></td>
        </tr>
    	<tr>
        	<td class="cg"></td><td class="cc">
            
	            <table cellpadding="0" cellspacing="2">
                	<tr>
                    	<td style="width: 20px;border: 1px solid #B4B4B4; text-align: center;">Id</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Titre</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Date</td><td style="width: 100px;border: 1px solid #B4B4B4; text-align: center;">Options</td>
                    </tr>
<?php
	while ($row = mysql_fetch_object($query)){ ?>
					<tr>
						<td style="border: 1px solid #B4B4B4;">
							<?php echo $row->id_news; ?>
						</td>
                        <td style="border: 1px solid #B4B4B4;">
                            <?php echo $row->titre_news; ?>
						</td>
                        <td style="border: 1px solid #B4B4B4;">
							<?php echo date_fr($row->date_news); ?>
                        </td>
                         <td style="border: 1px solid #B4B4B4; text-align: center;">
                         	<a href="javascript: void(0);" onclick="display('<?php echo $row->id_news."_m";?>')" style="color:#0066FF">d</a> - <a style="color:#0066FF" href="javascript: void(0);" Onclick="del_news('<?php echo $row->id_news?>')">s</a>
                         </td>
                    </tr>
                    <tr>
                    	<td colspan="4" style="text-align:center; width: 100%;">
                        	<div id="<?php echo $row->id_news."_m";?>" style="display: none; border: 1px solid #B4B4B4; padding: 10px;">
								<div style="clear: both;"></div>
									<div style="text-align: left;">
                                    	<?php echo $row->username; ?>
                                        <br />
                                        <?php echo date_fr($row->date_news); ?>
                                    </div>
                                    <div style="text-align: center;">
                                    	<?php echo $row->titre_news; ?>
                                    </div>
                                    <div style="text-align: left; margin-top: 10px;">
                                    	<?php echo $row->text_news; ?>
                                    </div>
                                    <div style="text-align: left; clear: both;">
                                        <a href="javascript: void(0);" style="color:#0066FF; font-family: Arial; font-size: 10px;" onclick="window.open('fckeditor/_samples/php/sample02.php?id=<?php echo $row->id_news; ?>', 'Contenu de : <?php echo $row->titre_news; ?>', config='height=400, width=800, toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, directories=no, status=no')">Editer le contenu</a>
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