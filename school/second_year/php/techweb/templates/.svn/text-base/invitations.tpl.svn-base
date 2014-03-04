<div id="contenu_page">
	<div id="titre_1"><img src="img_titre/projets_index.png" border="0" align="left"></div>
    {if $message}
    	{$message}
	{else}
		<span id="text_1">{$nb}</span>
	{/if}
    <div class="scale">
    	<div class="case" style="width: 60px;">ID projet</div><div class="case" style="width: 350px;">Titre du projet</div><div class="case" style="width: 150px;">Nom du chef de projet</div>
        <div class="case" style="width: 150px;">Options</div>
        <div style="clear: both"></div>
    </div>
	{section name=customer loop=$tab}
    <div id="{$tab[customer].id_projet}" class="scale" onmouseover="document.getElementById({$tab[customer].id_projet}).style.backgroundColor='#EAF0FB'" onmouseout="document.getElementById({$tab[customer].id_projet}).style.backgroundColor='#F6F7FB'">
    	<div class="case" style="width: 60px;">{$tab[customer].id_projet}</div><div class="case" style="width: 350px;">{$tab[customer].titre_projet}</div><div class="case" style="width: 150px;">{$tab[customer].username}</div><div class="case" style="width: 150px; text-align:center;"><a href="javascript: void(0);">Accepter</a> // <a href="javascript: void(0);">Refuser</a> // <a href="javascript: void(0);" onclick="check_display('{$tab[customer].id_projet}_v');">Display</a></div>
        <div style="clear: both"></div>
    </div>
    <div id="{$tab[customer].id_projet}_v" class="description">
    	<div class="left_desc">Titre du projet ::</div><div class="right_desc">{$tab[customer].titre_projet} - {if $tab[customer].id_pere_projet == 0}[Projet]{else}[Activite]{/if}</div><br /><br />
        <div class="left_desc">Type d'activite ::</div><div class="right_desc">{$tab[customer].nom_type}</div><br /><br />
    	<div class="left_desc">Date de debut ::</div><div class="right_desc">{$tab[customer].debut_projet}</div><br /><br />
        <div class="left_desc">Chef de projets ::</div><div class="right_desc">{$tab[customer].username}</div><br /><br />
        <div class="left_desc">Description ::</div><div class="right_desc">{$tab[customer].description_projet}</div><br /><br />
        <div class="left_desc">Droit decoupage ::</div><div class="right_desc">{$tab[customer].droit_decoupage}</div><br /><br />
        <div class="left_desc">Droit visualisation ::</div><div class="right_desc">{$tab[customer].droit_visualisation}</div><br /><br />
        <div class="left_desc">Droit evaluation ::</div><div class="right_desc">{$tab[customer].droit_evaluation}</div><br /><br />
    </div>
    {/section}
    <br />
</div>