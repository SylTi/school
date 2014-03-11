<?

function	go_to_case($env, $case, $type)
{
  $env['cmd'] = array();
  if ($case == 0 && $type != NULL)
    {
      array_push($env['cmd'], "prend " . $type . "\n");
      array_push($env['cmd'], "voir\n");
    }
  else
    {
      $avance = 0;
      $lcase = 1;
      for ($totcase = 1; $totcase <= $case; $totcase += $lcase)
	{
	  $avance++;
	  $lcase += 2;
	}
      for ($j = 0; $j < $avance; $j++)
	array_push($env['cmd'], "avance\n");
      $middle = $totcase - (($lcase + 1) / 2);
      if ($case < $middle)
	array_push($env['cmd'], "gauche\n");
      else if ($case > $middle)
	array_push($env['cmd'], "droite\n");
      array_push($env['cmd'], "voir\n");
    }
}

function	check_res($env, $case, $res, $j)
{
  $level = $env['level'];
  for ($i = 0; $i < count($env['search'][$level]); $i++)
    {
      if ($res[$j] == 'nourriture' && $case == 0 &&
	  $env['bag']['nourriture'] <= MAX_FOOD)
	{
	  array_push($env['cmd'], "prend nourriture\n");
	  array_push($env['cmd'], "voir\n");
	  return (TRUE);
	}
      else if ($env['survival_mode'] == FALSE && $env['search'][$level] != NULL
	       && $res[$j] == $env['search'][$level][$i]['type'])
	{
	  if ($env['bag'][$res[$j]] < $env['search'][$level][$i]['nb'])
	    go_to_case(&$env, $case, $res[$j]);
	  return (TRUE);
	}
    }
  return (FALSE);
}

function	check_search($env, $res, $case)
{
  $level = $env['level'];
  if ($env['survival_mode'] == FALSE && $case == 0 &&
      can_incant_on_case(&$env, $res) == TRUE)
    return (incant(&$env, $res));
  $vide = TRUE;
  for ($j = 1; $j < count($res); $j++)
    {
      if ($res[$j] != '' && $res[$j] != 'joueur')
	$vide = FALSE;
      else if ($env['survival_mode'] == TRUE && $res[$j] == 'nourriture')
	{
	  go_to_case(&$env, $case, $res[$j]);
	  return (TRUE);
	}
      if ($env['search'][$level] != NULL)
	if (check_res(&$env, $case, $res, $j) == TRUE)
	  return (TRUE);
    }
  if ($vide == TRUE)
    return (begin_incant(&$env, $case));
  return (FALSE);
}
?>