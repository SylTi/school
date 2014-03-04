<div class="border_logo">
</div>
    <table style="margin: auto; margin-top: 15px;" cellpadding="0" cellspacing="0">
    	<tr>
        	<td class="hg"></td><td class="hc"></td><td class="hd"></td>
        </tr>
    	<tr>
        	<td class="cg"></td><td class="cc">

    	<span style="font-size: 12px; text-decoration: underline;">Statistiques des Comptes</span>
			<table style="margin: auto; margin-top: 10px;" cellpadding="0" cellspacing="0">
            	<?php
                	$requete = "SELECT * FROM ".$client."_users WHERE user_droit='0'";
					$num = mysql_num_rows(mysql_query($requete));
				?>
            	<tr>
                	<td class="case_stats">Comptes administrateurs&nbsp;</td>
                	<td class="case_stats"><?php echo $num; ?></td>
                </tr>
            	<?php
                	$requete = "SELECT * FROM ".$client."_users WHERE user_droit='1'";
					$num = mysql_num_rows(mysql_query($requete));
				?>
            	<tr>
                	<td class="case_stats">Comptes moderateur&nbsp;</td>
                	<td class="case_stats"><?php echo $num; ?></td>
                </tr>
            </table>
            </td><td class="cd"></td>
        </tr>
    	<tr>
        	<td class="bg"></td><td class="bc"></td><td class="bd"></td>
        </tr>
    </table>
    
    
    <table style="margin: auto; margin-top: 15px;" cellpadding="0" cellspacing="0">
    	<tr>
        	<td class="hg"></td><td class="hc"></td><td class="hd"></td>
        </tr>
    	<tr>
        	<td class="cg"></td><td class="cc">

    	<span style="font-size: 12px; text-decoration: underline;">Statistiques des News</span>
			<table style="margin: auto; margin-top: 10px;" cellpadding="0" cellspacing="0">
            	<?php
                	$requete = "SELECT * FROM ".$client."_news";
					$num = mysql_num_rows(mysql_query($requete));
				?>
            	<tr>
                	<td class="case_stats">Nombre de news postees&nbsp;</td>
                	<td class="case_stats"><?php echo $num; ?></td>
                </tr>
            </table>
            </td><td class="cd"></td>
        </tr>
    	<tr>
        	<td class="bg"></td><td class="bc"></td><td class="bd"></td>
        </tr>
    </table>