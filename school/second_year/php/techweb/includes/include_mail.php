<?php
	$mail = $_GET["mail"];
	$a = $_GET["a"];
	$cc = $_GET["cc"];
	$cci = $_GET["cci"];
	$corps = ereg_replace(".ff.", "<br />", htmlentities($_GET["corps"]));
	// echo "<span class=\"vert_12\">Vos mails on parfaitement ete envoyes...</span>";
	// echo "<span class=\"rouge_12\">Une erreur est survenu lors de l'evoi du mail ###</span>";
$string="
<html>
<head>
<title>Reclamation de ".$mail." a votre attention !</title>
</head>
<body style='text-align: center;'>
<table>
	<tr>
    	<td width='550'><img src='http://dotslashe.dyndns.org/dev/techweb/images/ban.gif' border='0' width='550'/></td>
    </tr>
    <tr>
    	<td style='text-align: center; font-family: Arial; font-size: 12px; font-weight: bold; color: #363A3D; padding-top: 15px; padding-bottom: 15px;'>
        	".$mail." reclame votre attention ...
        </td>
    </tr>
    <tr>
    	<td style='text-align: left; font-family: Arial; font-size: 12px; color: #363A3D; border: 1px solid #363A3D;'>
        	En effet,<br /><br />Votre ami vous a envoye ce mail depuis <b><a href='http://dotslashe.dyndns.org/dev/techweb/' style='color: #96CE36'>PSYNES&copy;</a></b> dans le but de vous le faire decouvrire.<br /><b><a href='http://dotslashe.dyndns.org/dev/techweb/' style='color: #96CE36'>PSYNES&copy;</a></b> est un site de gestionnaire de projets recensant tout un tas de prestataires et de projets.<br /><br />De plus il est gratuit et dans le cadre d'un projet pour une ecole.
            <br />
           Enfin, votre ami souhaitait vous faire parvenir ce message :
            <div style='border: 1px dotted #363A3D; background: #96CE36; width: 350px; margin-left: 50px; padding: 7px; margin-top: 17px; margin-bottom: 17px;'>
            ".$corps."
            </div>
        </td>
    </tr>
    <tr>
    	<td style='text-align: center;'>
        	A tres bientot sur <b><a href='http://dotslashe.dyndns.org/dev/techweb/' style='color: #96CE36'>PSYNES&copy;</a></b><br />
            <span style='font-size: 10px; color: #96CE36'>L'equipe de PSYNES&copy;</span>
        </td>
    </tr>
    <tr>
    	<td style='background: #363A3D; height: 10px;'>
        </td>
    </tr>
</table>
</body>
</html>";
$headers  = 'MIME-Version: 1.0' . "\r\n";
$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";

// En-têtes additionnels
$headers .= 'To:'.$a.''. "\r\n";
$headers .= 'From: noreply@psynes.com' . "\r\n";
if ($cc != "")
	$headers .= 'Cc: '.$cc.'' . "\r\n";
if ($cci != "")
	$headers .= 'Bcc: '.$cci.'' . "\r\n";

if (mail($a, "PSYNES ::".$mail." reclame votre attention.", $string, $headers))
	echo "<span class='vert_12'>Envoi effectue avec succe !</span>";
else
	echo "<span class='rouge_12'>Une erreur est survenu lors de l'envoi, verifiez vos adresses de destinatires...</span>";
//echo $string;