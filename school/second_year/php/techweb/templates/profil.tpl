<div id="contenu_page">
	<div id="titre_1">
	{if isset($smarty.session.login)}
    <script src="js/spynes1.js" type="text/javascript"></script>
	<img src="img_titre/membre_profil.png" border="0" align="left"></div>
	    <div id="text_1"> 
            <div id="subscribe" style="float:left;width:50%;">
            <form name="inscription" action="javascript: void(0);" method="post" onsubmit="javascript: modif(); return false;">
            	<input type="hidden" name="id" id="id" value="{$id_usr}">
            	<div><p>Login <span class="rouge">*</span> ::</p> {if isset($login_usr)}{$login_usr}{else}Anonyme{/if}</div>
            	<div><p>Mot de passe <span class="rouge">*</span> :: </p><input id="password" type="password" name="login" value="" class="input_"/></div>
            	<div><p>Verification du mot de passe <span class="rouge">*</span> :: </p><input id="password_2" type="password" name="login" value="" class="input_"/></div>
            	<div><p>E-mail <span class="rouge">*</span> :: </p><input id="mail" type="mail" name="login" value="{$mail_usr}" class="input_"/></div>
            	<div><p>Verification de l'e-mail <span class="rouge">*</span> :: </p><input id="mail_2" type="text" name="login" value="{$mail_usr}" class="input_"/></div>
                <br />
                <div><p>Nom <span class="rouge">*</span> :: </p><input id="nom" type="text" name="login" value="{$lastname_usr}" class="input_"/></div>
                <div><p>Prenom <span class="rouge">*</span> :: </p><input id="prenom" type="text" name="login" value="{$name_usr}" class="input_"/></div>
                <div><p>location <span class="rouge">*</span> :: </p><input id="location" type="text" name="login" value="{$location_usr}" class="input_"/></div>
                <div id="explain"></div>
                <div><p>Date de naissance [<span class="rouge" onmouseover="javascript: explain('enter');" onmousemove="javascript: explain('move');" onmouseout="javascript: explain('quit');">jj/mm/aaaa</span>] <span class="rouge">*</span> :: </p><input id="birth" type="text" name="login" value="{$birth_usr}" class="input_"/></div>
                <div><p>Societe :: </p><input type="text" name="login" value="{$societe_usr}" class="input_" id="societe"/></div>
                <br />
                <div><p>Adresse icq :: </p><input type="text" name="login" value="{$icq_usr}" class="input_" id="icq" /></div>
                <div><p>Adresse aim :: </p><input type="text" name="login" value="{$aim_usr}" class="input_" id="aim"/></div>
                <div><p>Adresse yim :: </p><input type="text" name="login" value="{$yim_usr}" class="input_" id="yim"/></div>
                <div><p>Adresse msn :: </p><input type="text" name="login" value="{$msn_usr}" class="input_"id="msn"/></div>
                <div><p>Adresse jabber :: </p><input type="text" name="login" value="{$jabber_usr}" class="input_" id="jabber"/></div>
                <div><p>Adresse site perso :: </p><input type="text" name="login" value="{$site_usr}" class="input_" id="site"/></div>
                <br />
                <input type="submit" class="submit_2" value="Envoyer">
            </form><br />
            </div> 
            <div style="float:left;width:40%;"><p>Modifiez vos informations perso. !</p><img src="img_deco/profil.jpg"><br />Bisous ;)</div>
        </div>
	{else}
	<img src="img_titre/membre_profil.png" border="0" align="left"></div>
        <div id="text_1">
        <p style="width:45%;float:left;margin-right:50px;">Pas encore utilisateur ?<br /><br />
        Remédiez à cela en vous inscrivant a notre projet.<br /><br />
        Pour se faire, rien de plus simple, remplissez le formulaire ci-dessous en prennant soin de remplir les champs obligatoires possedant une <strong>etoile rouge</strong>.<br /><br />
        Par le suite, une e-mail vous sera envoyer pour confirmer votre inscrption qui ne sera effective qu'apres validation.<br /><br /><br />
        <span class="signature">Cordialement, l'equipe de SPYNES &copy;</span></p>{/if}
        
</div>