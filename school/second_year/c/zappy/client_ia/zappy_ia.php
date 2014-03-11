#!/usr/local/bin/php
<?php

dl('sockets.so');
require_once('define.php');
require_once('ia_loop.php');
require_once('search.php');
require_once('basic_cmd.php');
require_once('manage_incant.php');
require_once('manage_broadcast.php');
require_once('manage_inventory.php');

function	connect($host, $port)
{
  if (($s = socket_create(AF_INET, SOCK_STREAM, getprotobyname("tcp"))))
    {
      if (@socket_connect($s, $host, $port))
	return ($s);
      else if (@socket_connect($s, gethostbyname($host), $port))
	return ($s);
    }
  return (FALSE);
}

function	parse_arg($ac, $av, $host, $port)
{
  $port = -1;
  $host = NULL;
  $team = NULL;
  for ($i = 1; $i < $ac; $i++)
    {
      if ($av[$i + 1] != NULL && $av[$i] == '-p')
	$port = $av[++$i];
      else if ($av[$i + 1] != NULL && $av[$i] == '-h')
	$host = $av[++$i];
      else if ($av[$i + 1] != NULL && $av[$i] == '-n')
	$team = $av[++$i];
      else
	return (FALSE);
    }
  if ($team == NULL)
    return (FALSE);
  if ($port == -1)
    $port = DEFAULT_PORT;
  if ($host == NULL)
    $host = DEFAULT_HOST;
  return ($team);
}

function	init_env($s, $team)
{
  $env['s'] = $s;
  $env['team'] = $team;
  $env['level'] = 1;
  $env['cmd'] = array();
  $env['action'] = NULL;
  $env['slot'] = NULL;
  $env['broadcast'] = FALSE;
  $env['bag'] = array('nourriture' => 0, 'linemate' => 0, 'deraumere' => 0,
		      'sibur' => 0, 'mendiane' => 0, 'phiras' => 0, 'thystame' => 0);
  $env['survival_mode'] = FALSE;
  $env['nb_teammates'] = 0;
  $env['search'][1] = array(array('type' => 'linemate', 'nb' => 1));
  $env['search'][2] = array(array('type' => 'linemate', 'nb' => 1),
			    array('type' => 'deraumere', 'nb' => 1),
			    array('type' => 'sibur', 'nb' => 1));
  $env['search'][3] = array(array('type' => 'linemate', 'nb' => 2),
			    array('type' => 'sibur', 'nb' => 1),
			    array('type' => 'phiras', 'nb' => 2));
  $env['search'][4] = array(array('type' => 'linemate', 'nb' => 1),
			    array('type' => 'deraumere', 'nb' => 1),
			    array('type' => 'sibur', 'nb' => 2),
			    array('type' => 'phiras', 'nb' => 1));
  $env['search'][5] = array(array('type' => 'linemate', 'nb' => 1),
			    array('type' => 'deraumere', 'nb' => 2),
			    array('type' => 'sibur', 'nb' => 1),
			    array('type' => 'mendiane', 'nb' => 3));
  $env['search'][6] = array(array('type' => 'linemate', 'nb' => 1),
			    array('type' => 'deraumere', 'nb' => 2),
			    array('type' => 'sibur', 'nb' => 3),
			    array('type' => 'phiras', 'nb' => 1));
  $env['search'][7] = array(array('type' => 'linemate', 'nb' => 2),
			    array('type' => 'deraumere', 'nb' => 2),
			    array('type' => 'sibur', 'nb' => 2),
			    array('type' => 'mendiane', 'nb' => 2),
			    array('type' => 'phiras', 'nb' => 2),
			    array('type' => 'thystame', 'nb' => 1));
  $env['search'][8] = NULL;
  return ($env);
}

if (($team = parse_arg($argc, $argv, &$host, &$port)))
  {
    if (($s = connect($host, $port)))
      {
	echo "\nConnected on " . $host . "\n\n";
	$env = init_env($s, $team);
	if (($msg = ia_loop(&$env)) != '')
	  echo $msg;
      }
    else
      echo "\nerror: could not connect to server (connect() returns `$s`)\n";
  }
else
  echo 'usage: ./zappy_ia.php -n team [-h host] [-p port]' . "\n";

?>
