<?php
session_start();
/*
 * FCKeditor - The text editor for Internet - http://www.fckeditor.net
 * Copyright (C) 2003-2009 Frederico Caldeira Knabben
 *
 * == BEGIN LICENSE ==
 *
 * Licensed under the terms of any of the following licenses at your
 * choice:
 *
 *  - GNU General Public License Version 2 or later (the "GPL")
 *    http://www.gnu.org/licenses/gpl.html
 *
 *  - GNU Lesser General Public License Version 2.1 or later (the "LGPL")
 *    http://www.gnu.org/licenses/lgpl.html
 *
 *  - Mozilla Public License Version 1.1 or later (the "MPL")
 *    http://www.mozilla.org/MPL/MPL-1.1.html
 *
 * == END LICENSE ==
 *
 * Sample page.
 */

include("../../fckeditor.php") ;
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
	<head>
    	<script type="text/javascript" language="javascript">
        	window.opener.location.reload();
        </script>
		<title>Editer une news</title>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
		<meta name="robots" content="noindex, nofollow">
		<link href="../sample.css" rel="stylesheet" type="text/css" />
	</head>
	<body>
    	<?php if ($_GET){
			include ("../../../includes/include_connection.php");
			
			$requete = "SELECT * FROM ".$client."_faq WHERE id_question='".$_GET['id']."'";
			$query = mysql_query($requete) or die(mysql_error());
			$row = mysql_fetch_object($query);
			if ($_GET['row'] == 'question')
				$contenu = $row->text_question;
			elseif ($_GET['row'] == 'reponse')
				$contenu = $row->text_reponse;
			$id_faq = $_GET['id'];
		}
		else{
			$contenu = "";
			$id_faq = "";
		}
		?>
		<img src="../../../images/logo_login.gif" border="0" />
		<hr>
		<form action="sampleposteddata2.php" method="post" id="fck">
        <br />
        <input type="hidden" name="type" value="<?php echo $_GET['row']; ?>" />
        <input type="hidden" name="id_faq" value="<?php echo $id_faq; ?>" />
<?php
// Automatically calculates the editor base path based on the _samples directory.
// This is usefull only for these samples. A real application should use something like this:
// $oFCKeditor->BasePath = '/fckeditor/' ;	// '/fckeditor/' is the default value.

$sBasePath = $_SERVER['PHP_SELF'] ;
$sBasePath = substr( $sBasePath, 0, strpos( $sBasePath, "_samples" ) ) ;

$oFCKeditor = new FCKeditor('FCKeditor1');
$oFCKeditor->BasePath	= $sBasePath ;
$oFCKeditor->Value		=  $contenu;
$oFCKeditor->Create() ;
?>
			<br>
			<a href="javascript: void(0);" onClick="document.getElementById('fck').submit();"><img src="../../../images/bouton_submit.gif" border="0"></a>
		</form>
	</body>
</html>
