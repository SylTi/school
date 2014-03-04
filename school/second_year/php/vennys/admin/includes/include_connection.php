<?php
	function	gener_error($num)
	{
		if ($num == 1) //Connection serveur
			echo "1";
		elseif ($num == 2) //Connection database
			echo "2";
	elseif ($num == 3) //Connection database
			echo "3";
	}


	$usr = "vennys";
	$pwd = "vennys";
	$host = "localhost";
	$client = "vennys";
	
	$co = @mysql_connect($host, $usr, $pwd) or die (gener_error(1));
	$bd = @mysql_select_db($client, $co) or die (gener_error(2));
?>