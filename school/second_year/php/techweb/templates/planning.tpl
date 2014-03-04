<div id="contenu_page">
	<div id="titre_1">{if $login}<img src="img_titre/gantt_loggued.png">
	{else}<img src="img_titre/gantt_1.png">{/if}</div>
	<div id="text_1" style="float:left;width:80%;"><p style="float:left;width:90%;">
				
	<div style="background-color:red;width:70%;position:absolute;margin-top:55px;margin-left:207px;"><img src="../planning/draw_graph.php"></div>
	<table border="0">
			<th style="background-color:#C8C8C8;">proj ID</th>
			<th style="background-color:#C8C8C8;">Echéance</th>
			<th style="background-color:#C8C8C8;">Titre</th>
			<th style="text-align:center;width:420px;background-color:#F1F1F1;">Jan | Fev | Mar | Avr | Mai | Jui | Jul | Aou | Sep | Oct | Nov | Dev</th>
			
			{section name=gantt loop=$gantt}
			<tr>
				<td style="background-color:#F1F1F1;">{$gantt[gantt].id_projet}</td>
				<td style="background-color:#F1F1F1;">{$gantt[gantt].fin_projet}</td>
				<td style="background-color:#F1F1F1;">{$gantt[gantt].titre_projet}</td>
				
			
			</tr>
			{/section}
		</table>
</p></div>
</div>
