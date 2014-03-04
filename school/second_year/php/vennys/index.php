<?php
session_start();

if (!$_SESSION)
	header("location: index2.php");
$timestamp_expire = time() + 7*24*3600;

if ($_GET['page'] == 'logout')
  setcookie('remember', $_POST['remember'], $timestamp_expire);

include('./class/vennys.class.php');
include('./config.inc.php');
include('./lang.inc.php');

$memcache = new Memcache();
$memcache->connect('localhost', 11211) or die ("Connexion impossible");
if ($memcache == NULL)
  die("L'objet Memcache n'est pas diponible rien ne marchera.");
$db = new DB($host, $base, $login, $pass);
$curr = $_SESSION['user_lang'];
$lang = $tab_lang[$curr];

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
   "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html>
	<head>
    <link rel="stylesheet" type="text/css" href="css/<?php echo $_SESSION['user_style']; ?>" />
    <link rel="stylesheet" type="text/css" href="css/style.css" />
    <script type="text/javascript" src="js/functions.js"></script>
    <script type="text/javascript" src="js/jquery.js"></script>
    <title>Welcome on Vennys Project</title>
    </head>
    <body>
    	<div id="header">
      <div id="header_left"></div>
	 <div id="header_flag"></div>
	 <div id="header_logo" Onmouseover="hide_smenu()">
	 <img src="./images/logo.png" width="282px" height="142px" style="float:left;margin-top:15px;margin-left:5px;"></div>
	 <div id="header_r_centre">
	 <div id="header_centre">
	 <div id="up_menu" Onmouseover="hide_smenu()"></div>
	 <div id="dwn_menu">
	 <div class="jail_smenu"><a href="./index.php" class="menu_">Index</a></div>
	 <?php
	 $login_user = $_SESSION["user_login"];
	 $menus_req = "SELECT * FROM vennys_menu_site WHERE pere_menu = '-1'";
	 $menus_query = mysql_query($menus_req) or die (mysql_error());
	 while (($row = mysql_fetch_array($menus_query))){
	 	if ($row["pager_menu"] == $_GET["page"])
	 	$css = "menuvisited_";
	 	else
	 	$css = "menu_";
	 	echo "<div class=\"jail_smenu\"><a href=\"index.php?page=".$row["pager_menu"]."\" class=\"".$css."\" Onmouseover=\"display_smenu('".$row["id_menu"]."')\">".$row["nom_menu_".strtolower($_SESSION['user_lang'])]."</a></div>";
	}?>
<!--	<a href="index.php?page=uptorrent" class="menu_">UPTorrent</a>
	<a href="index.php?page=torrent" class="menu_">Torrent</a>
	<a href="" class="menu_">Index</a>
	<a href="" class="menu_">Index</a>
	<a href="index.php?page=send_mp" class="menu_">M.P.</a>
	<a href="index.php?page=logout" class="menu_">Logout</a> -->
	    </div>
       </div>
	    <div id="header_centre2">
        <div class="jail_smenu">
&nbsp;        </div>
        <?php
        $menus_req = "SELECT * FROM vennys_menu_site WHERE pere_menu = '-1'";
        $menus_query = mysql_query($menus_req) or die (mysql_error());
        while (($row = mysql_fetch_array($menus_query))){
		?>
			<div class="jail_smenu">
            &nbsp;
			        <?php
			        $smenus_req = "SELECT * FROM vennys_menu_site WHERE
									pere_menu = '".$row["id_menu"]."'";
			        $smenus_query = mysql_query($smenus_req) or die (mysql_error());
			        if (mysql_num_rows($smenus_query) > 0)
			        {
			        	echo "
							<div class=\"jailing\" id=\"smenu_".$row["id_menu"]."\">
						";
			        	while (($srow = mysql_fetch_array($smenus_query))){
			        		echo "&nbsp;&nbsp;&nbsp;<a href=\"index.php?page=".$srow["pager_menu"]."\" class=\"menu_\">".$srow["nom_menu_".strtolower($_SESSION['user_lang'])]."</a>
							<div class=\"separator\"></div>";
			        	}
			        	echo "
							</div>
						";
			        }
					?>
            </div>
        <?php }?>
        <div style="clear: both"></div>
        </div>
    </div>
	  <div id="header_location"><?php include("modules/recherche_rapide.php"); ?></div>

	    <div class="cont">
	    	<div id="content" Onmouseover="hide_smenu()"><?php include('./modules/load_page.php');?></div>
                <?php if ($_GET["page"] == "profil"){?>
	    	<div id="compte" Onmouseover="hide_smenu()" style="z-index: 0;">
		    	<div id="top_compte"  style="z-index: 0;"></div>
		    	<div id="center_compte"><?php include("./modules/load_profil.php")?></div>
		    	<div id="bot_compte"></div>
                <?php }?>
	    	</div>

	    	<div style="clear: both;"></div>

	    	<div id="footer">
	    		<div id="header_left_bas"></div>
	    		<div id="header_centre_bas"></div>
	    		<div id="header_right_bas"></div>
	    		<div style="clear: both;"></div>
    		</div>
   		</div>
</body>
</html>