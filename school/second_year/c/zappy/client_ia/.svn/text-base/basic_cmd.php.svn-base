<?php

function	cmd_bienvenue($env)
{
  array_push($env['cmd'], $env['team'] . "\n");
}

function	cmd_move($env)
{
  static $last;

  $val = rand() % 3;
  if ($val == 0 && $last != 1)
    array_push($env['cmd'], "droite\n");
  else if ($val == 1 && $last != 0)
    array_push($env['cmd'], "gauche\n");
  else
    array_push($env['cmd'], "avance\n");
  array_push($env['cmd'], "voir\n");
  $last = $val;
}

function	cmd_voir($env, $buf)
{
  $buf = substr($buf, 1, strlen($buf) - 2);
  $voir = explode(',', $buf);
  for ($case = 0; $case < count($voir); $case++)
    {
      $res = explode(' ', $voir[$case]);
      if (check_search(&$env, $res, $case) == TRUE)
	break ;
    }
  if (count($env['cmd']) == 0)
    cmd_move(&$env);
}

function	level_up($env, $level)
{
  $env['level'] = $level;
  echo "Je passe au niveau $level !\n";
  if (count($env['cmd']) == 0)
    cmd_move(&$env);
}

?>