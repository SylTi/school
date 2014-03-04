<div id="contenu_page">

<div id="shadow" style="display: none;">
	<div class="dark" onclick="document.getElementById('shadow').style.display='none'">
    </div>
    	<div id="edit_center">
        	<div id="left_edit"></div>
            <div id="right_edit">
            </div>
        </div>
	</div>

	<div id="titre_1">{if $login}<img src="img_titre/eval1_index.png">
	{else}<img src="img_titre/eval0_index.png">{/if}</div>
	<div id="texteval"><p>Evaluation de votre projet :</p><br />

	{section name=eval loop=$select_peval}
		{section name=eval loop=$select_eval}
				{section name=eval loop=$select_seval}
			{if $select_eval[eval].id_projet == $smarty.get.id}
				<div class="select_eval">
			{/if}
			<div class="bdy_eval">
			<div class="eval_in"><p class="ein">n° {$select_eval[eval].id_projet} : </p>
			<strong><u><a href="index.php?view=eval&id={$select_eval[eval].id_projet}">{$select_eval[eval].titre_projet}</a></u></strong>
		</div>

		<div class="eval_in1">
		{if $select_eval[eval].id_projet == $smarty.get.id}
			<p style="float:left;"><strong>Evaluation du projet :</strong></p>
			<p class="ppeval_perc"><span>{$pourcentage}&nbsp;</span></p><br /><br />
		{else}

		{/if}
	<p class="eval_p"><strong>Description :</strong></p><br />
		<p class="desc_eval">{$select_eval[eval].description_projet}</p>
		</div>

		<div class="desc_eval1">
			{if $select_eval[eval].id_projet ==  $smarty.get.id}
			<p class="peval_perc">Durée Totale du projet :
			<strong>{$select_peval[eval].duree_totale}jours</strong><br />
			Jours restants : {$rest_time}</p>
			{else}
			<p class="peval_perc">Durée estimée de la tâche :
			<strong>{$select_eval[eval].duree_totale} jours</strong><br /></p><br />
			<p class="eval_p">Début de la tache : </p>{$select_eval[eval].debut_projet}<br />

			{/if}

		{if $select_eval[eval].id_projet ==  $smarty.get.id}
		<p class="eval_p">Création du projet : </p>{$select_eval[eval].date_modif}<br />
			<p class="eval_p">Fin prévue le :</p><strong>{$fin_projet}</strong><br />
{/if}
	</div>
	</div>{if $select_eval[eval].id_projet == $smarty.get.id && $select_eval[eval].id_master_projet == $smarty.session.id}
		<p class="edit_eval_m">[ <a href="javascript: void(0);" Onclick="display_good_form('{$select_eval[eval].id_projet}', 'edit_eval')">Modifier l'avancement général du projet père</a> ]</p></div>
		{else}
		<p class="edit_eval">[ <a href="javascript: void(0);" Onclick="display_good_form('{$select_eval[eval].id_projet}', 'edit_eval')">Modifier l'avancement de cette tache</a> ]</p>
		{/if}
		{/section}
	{/section}
{/section}

{$erreur}</div>
</div>
