<?php
    sleep(1);
	
	$co = mysql_connect("localhost", "vennys", "vennys") or die (mysql_error());
	mysql_select_db("vennys", $co) or die (mysql_error());

    $requete = "SELECT * FROM vennys_menu_site WHERE nom_menu_french LIKE '%".$_GET["get"]."%' OR nom_menu_english LIKE '%".$_GET["get"]."%';";
	
	$ret = mysql_query($requete, $co) or die (mysql_error());
	if (mysql_num_rows($ret) > 0){
            echo "<span class='title_s'>Menu</span><br />";
            while ($row = mysql_fetch_array($ret)){
                  echo "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href=\"index.php?page=".$row["pager_menu"]."\" class=\"menu_\">".substr($row["nom_menu_french"], 0, 18)."...<a><br />";
            }
      }

    $requete = "SELECT * FROM vennys_news WHERE titre_news LIKE '%".$_GET["get"]."%' OR text_news LIKE '%".$_GET["get"]."%';";
	
	$ret = mysql_query($requete, $co) or die (mysql_error());
	if (mysql_num_rows($ret) > 0){
            echo "<span class='title_s'>News</span><br />";
            while ($row = mysql_fetch_array($ret)){
                  echo "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href=\"index.php?p=accueil&rest=all\" class=\"menu_\">".substr($row["titre_news"], 0, 18)."...</a><br />";
            }
      }
		
            
    $requete = "SELECT * FROM vennys_faq WHERE text_question LIKE '%".$_GET["get"]."%' OR text_reponse LIKE '%".$_GET["get"]."%';";
	
	$ret = mysql_query($requete, $co) or die (mysql_error());
    if (mysql_num_rows($ret) > 0){
            echo "<span class='title_s'>F.A.Q</span><br />";
            while ($row = mysql_fetch_array($ret)){
                  echo "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href=\"index.php?page=faq\" class=\"menu_\">".substr($row["text_question"], 0, 18)."...</a><br />";
            }
      }

      $requete = "SELECT * FROM torrent_tracker WHERE torrent_name LIKE '%".$_GET["get"]."%' OR torrent_desc LIKE '%".$_GET["get"]."%';";
	
	$ret = mysql_query($requete, $co) or die (mysql_error());
	if (mysql_num_rows($ret) > 0){
            echo "<span class='title_s'>Torrent</span><br />";
            while ($row = mysql_fetch_array($ret)){
                  echo "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href=\"index.php?page=showtorrent&id=".$row["torrent_id"]."...\" class=\"menu_\">".substr($row["torrent_name"], 0, 18)."</a><br />";
            }
      }
      
	mysql_close($co);
?>