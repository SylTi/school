<?php

function	init_count_teammates($env, $msg)
{
  if ($msg == NULL)
    {
      $env['cmd'] = array();
      array_push($env['cmd'], "connect_nbr\n");
      array_push($env['cmd'], "broadcast " . BDC_COUNT_TEAMMATES . $env['team'] . "\n");
      for ($i = BDC_COUNT_TIMER; $i >= 0; $i--)
	array_push($env['cmd'], "broadcast " . $i . "\n");
      array_push($env['cmd'], "broadcast " . BDC_COUNT_STOP . "\n");
      $env['broadcast'] = TRUE;
      $env['nb_teammates'] = 0;
      echo "Je fais l'appel\n";
    }
  else
    $env['nb_teammates'] += 1;
}

function	count_teammates_stop($env)
{
  echo $env['nb_teammates'] . ($env['nb_teammates'] == 1 ? " a" :" ont")
    . " repondu present\n";
  if ($env['nb_teammates'] < (NB_TEAMMATES - BDC_COUNT_MARGIN))
    {
      $env['cmd'] = array();
      array_push($env['cmd'], "fork\n");
    }
}

function	broadcast_count_teammates($env)
{
  $env['cmd'] = array();
  array_push($env['cmd'], "broadcast " . BDC_COUNT_RESPONSE . "\n");
  return (FALSE);
}

function	broadcast_elevation($env, $dir)
{
  $env['cmd'] = array();
  if ($dir == BDC_DIR_U/* || $dir == BDC_DIR_UR || $dir == BDC_DIR_UL*/)
    array_push($env['cmd'], "avance\n");
  else if ($dir == BDC_DIR_D || $dir == BDC_DIR_DR || $dir == BDC_DIR_DL)
    {
      array_push($env['cmd'], "droite\n");
      array_push($env['cmd'], "droite\n");
      array_push($env['cmd'], "avance\n");
    }
  if ($dir == BDC_DIR_L || $dir == BDC_DIR_UL || $dir == BDC_DIR_DR)
    {
      array_push($env['cmd'], "gauche\n");
      array_push($env['cmd'], "avance\n");
    }
  else if ($dir == BDC_DIR_R || $dir == BDC_DIR_UR || $dir == BDC_DIR_DL)
    {
      array_push($env['cmd'], "droite\n");
      array_push($env['cmd'], "avance\n");
    }
  array_push($env['cmd'], "broadcast " . BDC_RESPONSE . "\n");
  array_push($env['cmd'], "voir\n");
  if ($dir == BDC_CASE)
    {
      $env['cmd'] = array();
      array_push($env['cmd'], "broadcast " . BDC_SAME_POS . "\n");
    }
  $env['broadcast'] = TRUE;
  return (FALSE);
}

function	manage_broadcast($env, $msg)
{
  $dir = strtok($msg, ",");
  $msg = substr($msg, strlen($dir) + 1);
  if ($env['broadcast'] == FALSE && strncmp($msg, BDC_INCANT, strlen(BDC_INCANT)) == 0
      && substr($msg, strlen(BDC_INCANT)) == $env['level'])
    return (broadcast_elevation(&$env, $dir));
  else if (strncmp($msg, BDC_COUNT_TEAMMATES, strlen(BDC_COUNT_TEAMMATES)) == 0 &&
	   substr($msg, strlen(BDC_COUNT_TEAMMATES)) == $env['team'])
    return (broadcast_count_teammates(&$env));
  else if ($msg == BDC_COUNT_RESPONSE)
    init_count_teammates(&$env, $msg);
  return (FALSE);
}

?>