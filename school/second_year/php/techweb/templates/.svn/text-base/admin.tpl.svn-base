<div id="contenu_page">
	<div id="titre_1"></div>
	{if !isset($error) && $rank == "1"}
	{if $smarty.get.page == "view_user"}
	<p><a href="index.php?view=admin">Index</a> &gt; <a href="index.php?view=admin&page=view_user">View User</a></p>
	 	<p align="center">Afficher : <a href="index.php?view=admin&page=view_user&order=all">Tous les utilisateurs</a>,
	 	<a href="index.php?view=admin&page=view_user&order=admin">avec les admins</a></p>
	    	<div id="text_1" style="margin-left:170px;">
		<table border="0">
			<th>User ID</th>
			<th>Username</th>
			<th>Mail</th>
			<th>Modifier</th>
			<th>Supprimer</th>
			{section name=user loop=$all_users}
			<tr>
				<td>{$all_users[user].user_id}</td>
				<td>{$all_users[user].username}</td>
				<td>{$all_users[user].user_email}</td>
				<td><a href="index.php?view=admin&page=edit_user&user_id={$all_users[user].user_id}">Modifier</a></td>
				<td><a href="index.php?view=admin&page=delete_user&user_id={$all_users[user].user_id}">Supprimer</a></td>
			</tr>
			{/section}
		</table>
		</div>

	{elseif $smarty.get.page == "edit_user" && isset($smarty.get.user_id) && !isset($smarty.post.login)}
	<p><a href="index.php?view=admin">Index</a> &gt; <a href="index.php?view=admin&page=view_user">View User</a> &gt; <a href="index.php?view=admin&page=edit_user&user_id={$smarty.get.user_id}">Edit User</a></p>
		<div id="text_1">
			<form name="inscription" method="post" action="index.php?view=admin&page=edit_user&user_id={$smarty.get.user_id}" target="_parent">
			<fieldset>
       		<legend>Infos obligatoires</legend> 
			<div><p class="lvl">Level <span class="rouge">*</span> ::</p>
			{if $res_user.user_rank == "1"}
			<select name="rank">
				<option selected="selected">Administrateur</option>
				<option>Membre</option>
			</select>
			{else}
			<select name="rank">
				<option>Administrateur</option>
				<option selected="selected">Membre</option>
			</select>
			{/if}
			</div>
            	<div><p>Login <span class="rouge">*</span> ::</p> <input id="login" type="text" name="login" value="{$res_user.username}" class="input_"/></div>
            	<div><p>Mot de passe <span class="rouge"></span> :: </p><input id="password" type="password" name="password" value="" class="input_"/></div>
             	<div><p>E-mail <span class="rouge">*</span> :: </p><input id="mail" type="mail" name="mail" value="{$res_user.user_email}" class="input_"/></div>
                <br />
                <div><p>Nom <span class="rouge">*</span> :: </p><input id="nom" type="text" name="nom" value="{$res_user2.user_lastname}" class="input_"/></div>
                <div><p>Prenom <span class="rouge">*</span> :: </p><input id="prenom" type="text" name="prenom" value="{$res_user2.user_name}" class="input_"/></div>
                <div><p>location <span class="rouge">*</span> :: </p><input id="location" type="text" name="location" value="{$res_user2.user_location}" class="input_"/></div>
                <div id="explain"></div>
                <div><p>Date de naissance [<span class="rouge">jj/mm/aaaa</span>] <span class="rouge">*</span> :: </p><input id="birth" type="text" name="birth" value="{$res_user.user_birthday}" class="input_"/></div>
				</fieldset>
			<fieldset>
       		<legend>Infos complementaire</legend>
            	<div><p>Societe :: </p><input type="text" name="societe" value="{$res_user2.societe}" class="input_" id="societe"/></div>
                <div><p>Adresse icq :: </p><input type="text" name="icq" value="{$res_user.user_icq}" class="input_" id="icq" /></div>
                <div><p>Adresse aim :: </p><input type="text" name="aim" value="{$res_user.user_aim}" class="input_" id="aim"/></div>
                <div><p>Adresse yim :: </p><input type="text" name="yim" value="{$res_user.user_yim}" class="input_" id="yim"/></div>
                <div><p>Adresse msn :: </p><input type="text" name="msn" value="{$res_user.user_msnm}" class="input_"id="msn"/></div>
                <div><p>Adresse jabber :: </p><input type="text" name="jabber" value="{$res_user.user_jabber}" class="input_" id="jabber"/></div>
                <div><p>Adresse site perso :: </p><input type="text" name="site" value="{$res_user.user_website}" class="input_" id="site"/></div>
            </fieldset>
                <br />
                <input type="submit" class="submit_2" value="Envoyer" />
            </form>
	    </div>
	    
	{elseif $smarty.get.page == "edit_user" && isset($smarty.get.user_id) && isset($smarty.post.login)}
	<p><a href="index.php?view=admin">Index</a> &gt; <a href="index.php?view=admin&page=view_user">View User</a> &gt; <a href="index.php?view=admin&page=edit_user&user_id={$smarty.get.user_id}">Edit User</a></p>
	<div id="text_1" style="margin-left:170px;">
        	{$edit_user_res}OK !<br />
        	<a href="index.php?view=admin&page=edit_user">Revenir a l'edition des utilisateurs</a>
        	<a href="index.php?view=admin">Retourner a l'index du panneau d'admin</a>
	</div>
	
	{elseif $smarty.get.page == "delete_user"}
	<p><a href="index.php?view=admin">Index</a> &gt; Delete User</p>
	<div id="text_1" style="margin-left:170px;">
		{$res_delete}
	</div>
	
	{elseif $smarty.get.page == "view_project" && !isset($smarty.get.id_project)}
	<p><a href="index.php?view=admin">Index</a> &gt; <a href="index.php?view=admin&page=view_project">View Project</a></p>
	<div id="text_1">
		<table border="0">
			<th>ID</th>
			<th>Titre du Projet</th>
			<th>Type</th>
			<th>Date de debut<br />Date de fin</th>
			<th>Description</th>
			<th>Administrateur</th>
			<th>Voir Proj</th>
			<th>Supprimer</th>

			{section name=proj loop=$all_proj}
			<tr>
				<td>{$all_proj[proj].id_projet}</td>
				<td>{$all_proj[proj].titre_projet}</td>
				<td>{$all_proj[proj].type_projet}</td>
				<td>{$all_proj[proj].debut_projet}<br />{$all_proj[proj].fin_projet}</td>
				<td>{$all_proj[proj].description_projet}</td>
				<td>{$all_proj[proj].id_master_projet}</td>
				<td><a href="index.php?view=admin&page=view_project&id_project={$all_proj[proj].id_projet}">Details</a></td>
				<td><a href="index.php?view=admin&page=delete_project&id_project={$all_proj[proj].id_projet}">Supprimer</a></td>
			</tr>
			{/section}
		</table>
		</div>
		
	{elseif $smarty.get.page == "view_project" && isset($smarty.get.id_project)}
	<p><a href="index.php?view=admin">Index</a> &gt; <a href="index.php?view=admin&page=view_project">View Project</a> &gt; <a href="index.php?view=admin&page=view_project&id_project={$smarty.get.id_project}">View Project</a></p>
	<div id="text_1">
			<table border="0">
			<th>ID</th>
			<th>Titre du Projet</th>
			<th>Type</th>
			<th>Date de debut<br />Date de fin</th>
			<th>Description</th>
			<th>Administrateur</th>
			<th>Modifier</th>
			<th>Supprimer</th>
			<tr>
				<td>{$select_proj_parent.id_projet}</td>
				<td>{$select_proj_parent.titre_projet}</td>
				<td>{$select_proj_parent.type_projet}</td>
				<td>{$select_proj_parent.debut_projet}<br />{$select_proj_parent.fin_projet}</td>
				<td>{$select_proj_parent.description_projet}</td>
				<td>{$select_proj_parent.id_master_projet}</td>
			</tr><tr>&nbsp;</tr>
			{section name=proj loop=$select_proj}
			<tr>
				<td>{$select_proj[proj].id_projet}</td>
				<td>{$select_proj[proj].titre_projet}</td>
				<td>{$select_proj[proj].type_projet}</td>
				<td>{$select_proj[proj].debut_projet}<br />{$select_proj[proj].fin_projet}</td>
				<td>{$select_proj[proj].description_projet}</td>
				<td>{$select_proj[proj].id_master_projet}</td>
				<td><a href="index.php?view=admin&page=edit_project&id_project={$select_proj[proj].id_projet}">Modifier</a></td>
				<td><a href="index.php?view=admin&page=delete_child_project&id_project={$select_proj[proj].id_projet}">Supprimer</a></td>
			</tr>
			{/section}
		</table>
		<table>
		<th>Membre</th>
		<th>Supprimer</th>
		{section name=proj2 loop=$user_proj}
		<tr>
			<td>{$user_proj[proj2].username}</td>
			<td><a href="index.php?view=admin&page=delete_project_user&id_project={$smarty.get.id_project}&user_id={$user_proj[proj2].user_id}">Supprimer</a></td>	
		</tr>
		{/section}
		</table>
	</div>
	
	{elseif $smarty.get.page == "edit_project"}
	<p><a href="index.php?view=admin">Index</a> &gt; <a href="index.php?view=admin&page=view_project">View Project</a> &gt; <a href="index.php?view=admin&page=view_project&id_project={$smarty.get.id_project}">Project</a> &gt; <a href="index.php?view=admin&page=edit_project&id_project={$smarty.get.id_project}">Edit Project</a></p>
	<div id="text_1" style="margin-left:170px;">
	</div>
	
	{elseif $smarty.get.page == "delete_project"}
	<p><a href="index.php?view=admin">Index</a> &gt; <a href="index.php?view=admin&page=view_project">View Project</a> &gt; <a href="index.php?view=admin&page=view_project&id_project={$smarty.get.id_project}">Project</a> &gt; Delete Project</p>
	<div id="text_1" style="margin-left:170px;">
	Projet et sous projet(s) correctement supprimé(s).
	</div>
	
	{elseif $smarty.get.page == "delete_child_project"}
	<p><a href="index.php?view=admin">Index</a> &gt; <a href="index.php?view=admin&page=view_project">View Project</a> &gt; <a href="index.php?view=admin&page=view_project&id_project={$smarty.get.id_project}">Project</a> &gt; Delete Project Child</p>
	<div id="text_1" style="margin-left:170px;">
	Sous projet(s) correctement supprimé(s).
	</div>
	
	{elseif $smarty.get.page == "delete_project_user"}
	<p><a href="index.php?view=admin">Index</a> &gt; <a href="index.php?view=admin&page=view_project">View Project</a> &gt; <a href="index.php?view=admin&page=view_project&id_project={$smarty.get.id_project}">Project</a> &gt; Delete Project User</p>
	<div id="text_1" style="margin-left:170px;">
	Utilisateur correctement supprimé du projet.
	</div>
	
	{else}
	<p><a href="index.php?view=admin">Index</a> &gt; </p>
	<div id="text_1" style="margin-left:170px;">
		<h1>Que voulez vous faire ? </h1><br />
		<a href="index.php?view=admin&page=view_user">Voir les utilisateurs</a>
		<br /><br />
		<a href="index.php?view=admin&page=view_project">Voir les projects</a><br />
	</div>
	{/if}
{else}
	{$error}
{/if}
</div> <div style="clear:both;"></div>