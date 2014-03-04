<?php

if ($_GET["page"] == "faq")
  {
    $tab = $db->query_f("SELECT * FROM vennys_faq");
    $i = 0;
    while ($tab[$i])
      {
?>
    <div id='titre_faq'><?php echo "Q. "." ".$tab[$i]['text_question']; ?></div>
    <div id='reponse_faq'><?php echo "R. ".$tab[$i]['text_reponse']; ?></div>
    <br />

<?php
     $i++;
    }
  }
 else 
   echo "Acces Denied\n";

?>