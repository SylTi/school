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
<div class="bdy_eval">
	<div class="eval_in">
	<strong><u>{$titre_projet}</u></strong>

		<div class="desc_evalbottom">
		<p class="eval_perc">Terminé à {$accomp}%.<br /><span>{$pourcentage}<br />
<br />
</span></p>
		<p class="eval_perc">Jours passé(s) : {$past_time}jours.</p>
		<p class="eval_perc">Jours restant(s) : {$rest_time}jours.</p>
		<p class="eval_perc">Durée de la tâche : {$duree_tmp}jours.</p>


		</div>

	</div>

	<div class="eval_in1">
	<p class="eval_p"><strong>Description :</strong></p><br />
	<p class="desc_eval">{$description_projet}</p>
	</div>

	<div class="desc_eval1">
	<p class="eval_p">Début de la tâche : </p>{$debut_projet}<br />
	<p class="eval_p">Fin de la tâche : </p>{$fin_projet}<br />
	<p class="eval_p">{$isended}</p>
</div>
</div>
	<p class="edit_eval">[ <a href="javascript: void(0);" Onclick="display_good_form('{$id_projet}', 'edit_eval')">Modifier l'avancement de cette tache</a> ]</p>
{$erreur}</div>
</div>
