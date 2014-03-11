;;/*
** trait_cmd.c for trait_cmd in /u/epitech_2012/jaspar_y/cu/rendu/c/42sh/src
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Mon Apr 21 14:30:08 2008 yoann jaspar
** Last update Wed Jun 11 19:22:32 2008 sylvain tissier
*/

#include "sh.h"

void		last_exec(t_sh *sh)
{
  sh->flag = 1;
  sh->temp = trait_str(sh->temp);
  check_exec(sh);
  my_read(sh);
}

void		my_check_pipe(t_sh *sh, int i)
{
  if (sh->cmd[i] != '|' || (sh->cmd[i] != '|' && sh->cmd[i + 1] == '|'))
    {
      if (sh->cmd[i] == '|' && sh->cmd[i + 1] == '|' && sh->cmd[i + 2] == '|')
        {
          my_putstr("Invalid null command\n");
          last_exec(sh);
        }
      else if (sh->cmd[i] == '|' && sh->cmd[i + 1] == '|')
        {
          my_putstr("double pipe\n");
          last_exec(sh);
        }
    }
}

void		trait_cmd(t_sh *sh)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  sh->temp = xmalloc(sizeof(char*) * 200);
  sh->temp = xmalloc(sizeof(char*) * 200);
  while (sh->cmd[i] != '\0')
    {
      my_check_pipe(sh, i);
      if (sh->cmd[i] == ';' || (sh->cmd[i] == '&' && sh->cmd[++i] == '&'))
	{
	  sh->flag = 0;
	  sh->temp = trait_str(sh->temp);
	  check_exec(sh);
	  j = 0;
	  i++;
	}
      sh->temp[j++] = sh->cmd[i++];
      sh->temp[j] = '\0';
    }
  if (sh->cmd[0] != '|')
  last_exec(sh);
  my_putstr("Come Back in 2042 for Useless Cmd\n");
}
