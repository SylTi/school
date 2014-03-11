<?php

function	check_cmd($env, $buf)
{
  if ($env['action'] == "voir\n" && $buf == "ok")
    return (FALSE);
  else if (strncmp($buf, "message", 6) == 0)
    return (manage_broadcast(&$env, substr($buf, 8)));
  else if ($buf != 'elevation en cours' && strncmp($buf, 'deplacement ', 12) != 0)
    {
      if ($buf == "BIENVENUE")
	cmd_bienvenue(&$env);
      else if (strncmp($buf, "{ ", 2) == 0 || strncmp($buf, "{,", 2) == 0)
	cmd_voir(&$env, $buf);
      else if (strncmp($buf, "{nourriture", 11) == 0)
	check_inventory(&$env, $buf);
      else if ($env['action'] == ($env['team'] . "\n") && is_numeric($buf))
	$env['slots'] = $buf;
      else if ($buf == 'ok' && strncmp($env['action'], "prend", 5) == 0)
	add_in_bag(&$env, substr($env['action'], 6, strlen($env['action']) - 7));
      else if (($buf == 'ok' || $buf == "ko") && strncmp($env['action'], "pose", 4) == 0)
	sub_in_bag(&$env, substr($env['action'], 5, strlen($env['action']) - 6));
      else if (strncmp($buf, "niveau actuel : ", 16) == 0)
	level_up(&$env, substr($buf, 16));
      else if (count($env['cmd']) == 0)
	cmd_move(&$env);
      return (TRUE);
    }
  return (FALSE);
}

function	init_send_cmd($env)
{
  static	$nb_cmd = array(INVENTORY_START, BDC_COUNT_START);

  if ($nb_cmd[1] <= 0 && $env['bag']['nourriture'] >= BDC_COUNT_FOOD_REQ)
    {
      init_count_teammates(&$env, NULL);
      $nb_cmd[1] = BDC_COUNT_RATE;
    }
  else if ($nb_cmd[0] <= 0)
    {
      array_push($env['cmd'], "inventaire\n");
      $nb_cmd[0] = INVENTORY_RATE;
    }
  $nb_cmd[0] -= 1;
  $nb_cmd[1] -= 1;
}

function	send_cmd($env)
{
  init_send_cmd(&$env);
  $cmd = array_shift($env['cmd']);
  $env['action'] = $cmd;
  if (!@socket_write($env['s'], $cmd))
    die ("write error\n");
  if ($cmd == "incantation")
      $env['cmd'] = array();
  else if ($cmd == ("broadcast " . BDC_COUNT_STOP . "\n"))
    {
      count_teammates_stop(&$env);
      $env['broadcast'] = FALSE;
    }
  if (($env['broadcast'] == TRUE && count($env['cmd']) == 0) ||
      (count($env['cmd']) == 1 && $env['cmd'][0] == ("broadcast " . BDC_RESPONSE . "\n")))
    $env['broadcast'] = FALSE;
}

function	ia_loop($env)
{
  while (1)
    {
      $fd_read = array($env['s']);
      $fd_write = array();
      $fd_except = array();
      socket_select(&$fd_read, &$fd_write, &$fd_except, TIMEOUT);
      if (count($fd_read) > 0)
	{
	  if (($buf = @socket_read($env['s'], BUF_SIZE, PHP_NORMAL_READ)))
	    {
	      $buf = substr($buf, 0, strlen($buf) - 1);
	      if (check_cmd(&$env, $buf) != FALSE)
		{
		  echo $buf. "\n";
		if (count($env['cmd']) != 0)
		  send_cmd(&$env);
		}
	    }
	  else
	    return ("Disconnected by host\n");
	}
      else
	{
	  if (!@socket_write($env['s'], "ping\n"))
	    die ();
	  if (count($env['cmd']) == 0)
	    cmd_move(&$env);
	}
    }
  return ('');
}

?>