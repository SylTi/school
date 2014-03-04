<?php
   if(!isset($_GET['rest']))
     {
       echo '<div id="ficve_last">Les 5 dernieres news du site : <br /><br /><br />';
       $tab = $db->query_f("SELECT * FROM vennys_news LIMIT 5");
     }
      else
       $tab = $db->query_f("SELECT * FROM vennys_news");
     $i = 0;
     while($tab[$i])
       {
?>
<div name="titre_news" id="titre_news"><?php echo $tab[$i]['titre_news']; ?></div>
<div name="contenu_news" id="contenu_news"><?php echo $tab[$i]['text_news']; ?></div><br /><br />
										   <?php $i++; } if (!isset($_GET['rest'])) {?>
<br /><div name="aff_rest" id="aff_rest"><a href="index.php?p=accueil&rest=all">Afficher toutes les autres news</a><br /><?php } ?>