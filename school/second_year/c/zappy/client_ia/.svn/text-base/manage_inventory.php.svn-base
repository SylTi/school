<?php

function	check_inventory($env, $buf)
{
  $buf = substr($buf, 1, strlen($buf) - 2);
  $list = explode(',', $buf);
  for ($i = 0; $i < count($list); $i++)
    {
      $type = strtok($list[$i], " ");
      $nb = strtok(" ");
      $env['bag'][$type] = $nb;
      if ($type == 'nourriture' && $nb <= SURVIVAL_MODE_START)
	$env['survival_mode'] = TRUE;
      else if ($type == 'nourriture' && $nb >= SURVIVAL_MODE_STOP)
	$env['survival_mode'] = FALSE;
    }
  if (count($env['cmd']) == 0)
    cmd_move(&$env);
}

function	add_in_bag($env, $type)
{
  $env['bag'][$type] += 1;
  if (count($env['cmd']) == 0)
    cmd_move(&$env);
}

function	sub_in_bag($env, $type)
{
  $env['bag'][$type] -= 1;
  if (count($env['cmd']) == 0)
    array_push($env['cmd'], "voir\n");
}

?>