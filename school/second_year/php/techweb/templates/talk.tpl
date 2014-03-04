<div id="contenu_page">
<div id="titre_1"><img src="img_titre/talk_index.png" border="0" align="left" /></div>
        <div id="text_1">
        	{if !isset($smarty.session.login)}
            	<span class=\"rouge_12\">Vous devez etre authentifie pour utiliser ce module.</span>
			{else}
        	Envie de partager ce site avec vos amis / contacts ?<br />
			Envoyez un e-mail a vos contacts en utilisant le formulaire ci-dessous.<br />
			Celui ci se conduit comme un client d'adresse mail ce qui veut dire que la ou se trouve des ' <span class="rouge">*</span> ' vous pouvez y renseigner plusieurs adresses e-mail separe par une ' , ' (virgule).<br />
            <br />
            <span class="signature">Cordialement, l'equipe de SPYNES &copy;</span>
            <br />
            <br />
            <form id="mail_to" name="mail_top" action="javascript: void(0);" method="post" onsubmit="javascript: mail_to(); return false;">                
            	<div><p style="width:180px;float:left;margin:0;padding:0;">Adresse e-mail :: </p><input id="mail" type="text" name="mail" value="{$mail}" class="input_"/></div>
                <br />
                <div><p style="width:180px;float:left;margin:0;padding:0;">A <span class="rouge">*</span> :: </p><input id="a" type="text" name="login" value="" class="input_"/></div>
                <div><p style="width:180px;float:left;margin:0;padding:0;">Cc <span class="rouge">*</span> :: </p><input id="cc" type="text" name="login" value="" class="input_"/></div>
                <div><p style="width:180px;float:left;margin:0;padding:0;">Cci <span class="rouge">*</span> :: </p><input id="cci" type="text" name="login" value="" class="input_"/></div>
                <br />
                <div><p style="width:180px;float:left;margin:0;padding:0;">Corps <span class="rouge">*</span> :: </p><textarea id="corps" class="input_" style="width: 350px; height: 100px;" name="corps"></textarea></div>
                <input type="submit" class="submit_2" value="Envoyer">
            </form>
            <div id="response"></div>
			{/if}
        </div>
        
</div>
