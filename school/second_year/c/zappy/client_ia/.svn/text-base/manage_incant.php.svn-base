<?php

function	can_incant_on_case($env, $res)
{
  $level = $env['level'];
  if ($env['search'][$level] == NULL)
    return (FALSE);
  $case_res = array('nourriture' => 0, 'linemate' => 0, 'deraumere' => 0,
		    'sibur' => 0, 'mendiane' => 0, 'phiras' => 0, 'thystame' => 0);
  for ($j = 1; $j < count($res); $j++)
    if ($res[$j] != 'joueur')
      $case_res[$res[$j]] += 1;
  $search_res = array('nourriture' => 0, 'linemate' => 0, 'deraumere' => 0,
		      'sibur' => 0, 'mendiane' => 0, 'phiras' => 0, 'thystame' => 0);
  for ($j = 0; $j < count($env['search'][$level]); $j++)    
    $search_res[$env['search'][$level][$j]['type']] = $env['search'][$level][$j]['nb'];
  $diff = array_diff_assoc($case_res, $search_res);
  if (count($diff) == 0)
    return (TRUE);
  return (FALSE);
}

function	can_incant($env)
{
  $level = $env['level'];
  for ($i = 0; $i < count($env['search'][$level]); $i++)
    {
      $type = $env['search'][$level][$i]['type'];
      if ($env['bag'][$type] < $env['search'][$level][$i]['nb'])
	return (FALSE);
    }
  return (TRUE);
}

function	begin_incant($env, $case)
{
  if (can_incant(&$env) == TRUE)
    {
      if ($case != 0)
	go_to_case(&$env, $case, NULL);
      $level = $env['level'];
      for ($i = 0; $i < count($env['search'][$level]); $i++)
	{
	  $type = $env['search'][$level][$i]['type'];
	  for ($j = 0; $j < $env['search'][$level][$i]['nb']; $j++)
	    array_push($env['cmd'], "pose " . $type . "\n");
	}
      array_push($env['cmd'], "voir\n");
      return (TRUE);
    }
  return (FALSE);
}

function	incant($env, $res)
{
  $nb_player = 0;
  for ($j = 1; $j < count($res); $j++)
    if ($res[$j] == "joueur")
      $nb_player += 1;
  $nb_player_req = ($env['level'] == 1 || $env['level'] % 2 == 0 ?
		    $env['level'] : $env['level'] - 1);
  if ($nb_player == $nb_player_req)
    {
      $env['cmd'] = array();
      array_push($env['cmd'], "incantation\n");
    }
  else if ($nb_player > $nb_player_req)
    array_push($env['cmd'], "expulse\n");
  else
    {
      array_push($env['cmd'], "broadcast " . BDC_INCANT . $env['level'] . "\n");
      array_push($env['cmd'], "voir\n");
    }
  return (TRUE);
}

?>
