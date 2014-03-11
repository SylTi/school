/*
** check_synt.c for check synth in /u/epitech_2012/jaspar_y/public/62sh/srcs
** 
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
** 
** Started on  Mon Jun  9 15:58:22 2008 maxime dumez
** Last update Thu Jun 12 16:44:59 2008 maxime dumez
*/

#include "sh.h"

int	check_str_para(char *cmd)
{
  int	par;
  int	i;

  par = 0;
  i = 0;
  while (cmd[i])
    {
      if (cmd[i] == PRIO_S[PARA_LEFT])
	par++;
      if (cmd[i] == PRIO_S[PARA_RIGHT])
	par--;
      i++;
    }
  if (par < 0)
    my_putstr("Syntax error : Too much \"(\"");
  if (par > 0)
    my_putstr("Syntax error : Too much \")\"");
  return (par);
}

int	check_str_quote(char *cmd)
{
  int	s_quote;
  int	d_quote;
  int	i;

  s_quote = 0;
  d_quote = 0;
  i = 0;
  while (cmd[i])
    {
      if (cmd[i] == PRIO_S[QUOTE_DOUBLE])
	d_quote++;
      if (cmd[i] == PRIO_S[QUOTE_SIMPLE])
	s_quote++;
      i++;
    }
  if (d_quote % 2)
    my_putstr("Syntax error : Unmached \".");
  if (s_quote % 2)
    my_putstr("Syntax error : Unmached '.");
  return ((d_quote % 2) + (s_quote % 2));
}

int	is_prio_s(char c)
{
  int	i;

  i = 0;
  while (PRIO_S[i])
    {
      if (PRIO_S[i] == c)
	return (1);
      i++;
    }
  return (0);
}

int	check_str_pipe(char *cmd)
{
  int	ret_pipe;
  int	i;
  int	str_flag;
  int	nb_pipe;

  nb_pipe = 0;
  str_flag = 0;
  i = 0;
  ret_pipe = 0;
  while (cmd[i])
    {
      if (cmd[i] != ' ' && !is_prio_s(cmd[i]))
	str_flag = 1;
      else if (cmd[i] == SEP_S[T_PIPE] && !str_flag && !nb_pipe)
	ret_pipe++;
      else if (cmd[i] == SEP_S[T_PIPE] && str_flag)
	{
	  if (cmd[i + 1] == SEP_S[T_PIPE])
	    nb_pipe++;
	  str_flag = 0;
	}
      else if (nb_pipe)
	nb_pipe = 0;
      i++;
    }
  if (ret_pipe)
    my_putstr("Invalid null command");
  return (ret_pipe);
}

int	check_synt(char *cmd)
{
  int	ret;

  ret = 0;
  if (check_str_para(cmd) != 0)
    ret++;
  if (check_str_quote(cmd) != 0)
    ret++;
  if (check_str_pipe(cmd) != 0)
    ret++;
  return (ret);
}
