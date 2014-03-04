<?php
	sleep(1);
	
	$co = mysql_connect("localhost", "vennys", "vennys") or die (mysql_error());
	mysql_select_db("vennys", $co) or die (mysql_error());
	$requete = "SELECT user_id FROM users_tracker WHERE user_login='".$_GET["nick"]."';";
	
	$ret = mysql_query($requete, $co) or die (mysql_error());
	if (mysql_num_rows($ret) > 0)
		echo "false";
	else
		echo "true";
		
	mysql_close($co);
?>