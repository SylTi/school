<?php

if ($_GET["view"] == "planning" && isset($_SESSION["login"])){	
	
			
	$requete = "SELECT * FROM phpbb_users, tb_projet WHERE username = '".$_SESSION["login"]."' and user_id = id_master_projet group by id_projet desc order by fin_projet asc";
	$tab = querybd($requete, "tab")or die("Error profile request :".mysql_error());
	$tab2 = querybd($requete, "tab")or die("Error profile request :".mysql_error());

	$oSmarty->assign("titre_projet", substr($tab[titre_projet],0,10));
	$oSmarty->assign("gantt", $tab);
	$oSmarty->assign("gantt2", $tab2);
	
}
?> 
