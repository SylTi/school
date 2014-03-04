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

	<div id="titre_1">{if $login}<img src="img_titre/projets_index.png" border="0" align="left">
	{else}<img src="img_titre/projets_index.png" border="0" align="left">{/if}</div>
        <div id="text_1">
        {if !isset($smarty.session.login)}
        	<span class=\"rouge_12\">Vous devez etre authentifie pour utiliser ce module.</span>
		{else}
        <div id="proj_left">
        	<script type="text/javascript">load_projs();</script>
        </div>
        <div id="proj_right">
	        <div class="right_shiva" id="sprojets">Veuillez selectionner un projet sur votre gauche si toute fois vous etes inscrit dans un projet</div>
	        <div id="b" class="right_shiva2">
		        <div id="projet_new_over" Onclick="load_crea('projet')">Creer un projet</div>
		        <div id="sprojet_new" Onclick="load_crea('sprojet')">Creer un sous-projet</div>
		        <div id="add_presta" Onclick="load_crea('presta')">Ajouter un prestataire</div>
		        <br />
		        <br />
		        <div id="form_crea">
		        	<form id="crea_projet" name="crea_projet" action="javascript: void(0);" method="post" method="post" Onsubmit="verif_creat_proj(); return false">
		        	<div><p>Titre ::</p> <input type="text" class="input_" id="titre" /></div>
		        	<div><p>Date debut ::</p> <input type="text" class="input_" id="date_debut" /></div>
		        	<div><p>Type de projet ::</p> <select class="select_" id="type" />{foreach from=$type key=val1 item=val2}
			       	<option value="{$val1}">{$val2}</option>
		        	{/foreach}
		        	</select></div>
		        	Description ::<br /><textarea class="text_" id="description"></textarea><br />
		        	<input type="submit" value="Envoyer" class="submit_2" /></form>
		        	</div>
               </div>
           </div>
	  	{/if}
  </div>
</div>