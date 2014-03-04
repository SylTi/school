<div style="margin-top: 15px; margin-left: 50px;">
<FORM method="POST" action="./index.php?page=torrent" ENCTYPE="multipart/form-data">
   <INPUT type="text" name="nom_torrent" />
   <SELECT name="categorie">

   <OPTION value =-1><?php echo $lang["categories"]["Categorie-1"] ?></OPTION>
   <OPTION value =1><?php echo $lang["categories"]["Categorie1"]; ?></OPTION>
   <OPTION value =2><?php echo $lang["categories"]["Categorie2"]; ?></OPTION>
   <OPTION value =3><?php echo $lang["categories"]["Categorie3"]; ?></OPTION>
   <OPTION value =4><?php echo $lang["categories"]["Categorie4"]; ?></OPTION>
   <OPTION value =5><?php echo $lang["categories"]["Categorie5"]; ?></OPTION>
   <OPTION value =6><?php echo $lang["categories"]["Categorie6"]; ?></OPTION>
   <OPTION value =7><?php echo $lang["categories"]["Categorie7"]; ?></OPTION>
   <OPTION value =8><?php echo $lang["categories"]["Categorie8"]; ?></OPTION>
   <OPTION value =0><?php echo $lang["categories"]["Categorie0"]; ?></OPTION>
   </SELECT>
   <INPUT type="submit" name="rechercher_torrent" value="Search">
   </FORM>

   </div>
      <?php
      if (isset($_POST['rechercher_torrent']))
      {
      	if (strlen($_POST['nom_torrent']) < 3)
      	{
      		echo "<div style='margim: auto; margin-top: 20px; text-align: center; color: #EE0000;'>Veuillez saisir au minimum 3 caract&egrave;res pour votre recherche.</div>";
      		return ;
      	}
      	$req = "SELECT * FROM torrent_tracker WHERE torrent_name LIKE '%".$_POST['nom_torrent']."%'";
      	if ($_POST['categorie'] != -1)
      	$req .= " AND torrent_categorie = ". $_POST['categorie'];
      	$req .= " ORDER BY torrent_categorie, torrent_date;";
      	$ret = mysql_query($req);
      	if($ret)
      	{
      		aff_torrent($ret, $lang);
      	}
      }
      else if ($_GET['cat'] == '')
      {
      	$n = 1;

      	while ($n != 0)
      	{
      		if ($n == 9)
      		$n =  0;
      		$req = "SELECT * FROM torrent_tracker WHERE torrent_categorie = ".$n;
      		$req.= " ORDER BY  torrent_date DESC , torrent_categorie LIMIT 0,5;";
      		$ret = mysql_query($req);
      		if($ret)
      		{
      			if(mysql_num_rows($ret)!=0)
      			aff_torrent($ret, $lang);
      		}
      		if ($n != 0)
      		$n++;
      	}
      }
      else
      {
      	$req = "SELECT * FROM torrent_tracker";
      	$req .= " WHERE torrent_categorie = ". $_GET['cat'];
      	$req .= " ORDER BY torrent_categorie, torrent_date;";
      	$ret = mysql_query($req);
      	if($ret)
      	{
      		aff_torrent($ret, $lang);
      	}
      }

      function aff_torrent($ret, $lang)
      {
      	if(mysql_num_rows($ret)==0)
      	echo "<center><b>Pas de Résultat</b></center>";
      	else
      	{
      		if($line['torrent_posteur'] == $_SESSION[user_login])
      		$can_modif = "<a href='modules/mod_torrent.php?id=$line[torrent_id]' target='_blank'><img src='./images/edit.png' style='width:10px;height:10px;'></a> ";
      		echo "<table cellpadding='0' cellspacing='0' style='margin: auto; margin-top: 10px;'>
				   <tr>
					   <td class=\"titre_torrent\">".$lang['categories']['Ncat1']."</td>
					   <td class=\"titre_torrent\">".$lang['categories']['Ncat2']."</td>
					   <td class=\"titre_torrent\">".$lang['categories']['Ncat3']."</td>
					   <td class=\"titre_torrent\">".$lang['categories']['Ncat4']."</td>
					   <td class=\"titre_torrent\">".$lang['categories']['Ncat5']."</td>
				   </tr>";
      		$cat = -2;
      		$i = 0;
      		while($line = mysql_fetch_array($ret))
      		{
      			if ($cat != $line['torrent_categorie'])
      			{
      				if ($i == 0){
      					echo '
					<tr><td colspan="5" class="titre_classe">'.$lang["categories"]["Categorie".$line['torrent_categorie']].'</td></tr>';
      				}else{
      					echo '
					<tr><td colspan="5"><br /><br /></td></tr><tr><td colspan="5" class="titre_classe">'.$lang["categories"]["Categorie".$line['torrent_categorie']].'</td></tr>';
      				}
      				$i++;
      			}
      			echo
      			"
				<tr>
					<td class=\"line_torrent\">$can_modif <a href='index.php?page=showtorrent&id=".$line['torrent_id']."'>".$line['torrent_name']."</a></td>
					<td class=\"line_torrent\">".$lang["categories"]["Categorie".$line['torrent_categorie']]."</td>
					<td class=\"line_torrent\">".$line['torrent_posteur']."</td>
					<td class=\"line_torrent\">".$line['torrent_taille']."</td>
					<td class=\"line_torrent\">".$line['torrent_date']."</td>
				</tr>";
      			$cat = $line['torrent_categorie'];
      		}
      		echo "
				<tr>
					<td class=\"end_torrent\"></td>
					<td class=\"end_torrent\"></td>
					<td class=\"end_torrent\"></td>
					<td class=\"end_torrent\"></td>
					<td class=\"end_torrent\"></td>
				</tr>
		   </table>";
      	}
      }
?>

