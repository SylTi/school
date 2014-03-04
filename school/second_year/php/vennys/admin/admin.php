<?php
	if ($_GET["menu"] == "3")
		include("includes/include_admin_deco.php");
	include ("includes/include_all.php");
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<link href="css/admin.css" type="text/css" rel="stylesheet" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<script src="js/admin.js" type="text/javascript" language="javascript"></script>
<title>Administration :: <?php echo strtoupper($client);?></title>
</head>

<body link="#EEEEEE" alink="#EEEEEE" vlink="#EEEEEE">
	<div id="admin_body">
    	<div class="coin_hg"></div><div class="coin_hc" style="width: 760px;"></div><div class="coin_hd"></div>
			<div class="centre_admin">
                <div class="logo_admin">
                	<a href="admin.php"><img src="images/logo_login.gif" alt="e-Go" name="e-Go" border="0" /></a>
                </div>
                
                <div id="menu_admin">
                <img src="images/titre_panneau.gif" border="" alt="Panneau d'administration" name="Panneau d'administration" />
                <?php
                $requete = "SELECT * FROM ".$client."_menu ORDER BY ordre_menu ASC";
				$query = mysql_query($requete) or die (mysql_error());
				while ($row = mysql_fetch_object($query)){ ?>
					<div class="cell_admin" onmouseover="this.style.color='#2DA6D0';" onmouseout="this.style.color='#777';" Onclick="display(<?php echo $row->id_menu; ?>)">
                    	<?php echo $row->nom_menu; ?>
                    </div>
                    <div id="<?php echo $row->id_menu; ?>" class="under_cell" <?php if ($_GET &&$_GET['menu'] && $_GET['menu'] == $row->id_menu){?> style="display: block" <?php }?>>
                    	<?php echo $row->desc_menu; ?><br /><a href="admin.php?menu=<?php echo $row->id_menu; ?>" style="color:#0066FF">Continuer</a>
                    </div>
				<?php } ?>
                </div>
                <div id="content">
                	<?php
						if ($_GET && $_GET['menu']){
							if ($_GET["menu"] == "1")
								include("includes/include_statistiques.php");
							if ($_GET["menu"] == "2" && $_SESSION['rang'] == '0')
								include("includes/include_admin_comptes.php");
							if ($_GET["menu"] == "6")
								include("includes/include_admin_news.php");
							if ($_GET["menu"] == "7")
								include("includes/include_menu_site.php");
							if ($_GET["menu"] == "8")
								include("includes/include_admin_faq.php");
							if ($_GET["menu"] == "9")
								include("includes/include_admin_users.php");
						}
						else
							include("includes/include_statistiques.php");
					?>
                </div>
	            <div style="clear: both; height: 20px;"></div>
            </div>
        <div class="coin_bg"></div><div class="coin_bc" style="width: 760px;"></div><div class="coin_bd"></div>
    </div>
</body>
</html>
