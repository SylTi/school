		    <div style="background-image:url('../images/bg_login.png'); background-repeat:no-repeat;height:91px;width:130px;float:left;margin-right:-5px;padding:3px;"><form name="inscription" action="ucp.php?mode=login" method="post" onsubmit="verif(); return false;">
			    	<input id="log" class="input_" type="text" tabindex="1" size="25" name="username" value="Login ..." Onfocus="freeable('Login ...', this.value, 'log', 'click');" Onblur="freeable('Login ...', this.value, 'log');"/><br />
			    	<input id="pwd" class="input_" type="password" name="password" tabindex="2" size="25" value="Password" Onfocus="freeable('Password', this.value, 'pwd', 'click');" Onblur="freeable('Password', this.value, 'pwd');"/><br />
				    <input class="submit_" type="image" name="login" src="../images/connection.gif" value="Envoyer" onfocus="this.src='../images/connection_over.gif'" onmouseup="this.src='../images/connection.gif'"><br />
					<input type="checkbox" name="autologin" id="save" class="check_" value="1"><span class="text1">Se souvenir de moi</span><br />
				</form>
                <input class="submit_" type="image" src="../images/inscription.gif" value="Envoyer" onfocus="this.src='../images/inscription_over.gif'" onmouseup="this.src='../images/inscription.gif'" onclick="document.location.replace('../index.php?view=subscribe');">
                </div>
