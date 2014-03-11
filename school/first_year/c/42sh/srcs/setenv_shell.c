/*
** setenv_shell.c for setenv_shell in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:55:04 2008 yoann jaspar
** Last update Sun Jun  1 00:37:22 2008 yoann jaspar
*/

#include "sh.h"

char	**set_temp2(char **temp2, char *temp)
{
  int	i;
  int	j;
  int	k;

  j = 0;
  k = 0;
  i = 0;
  while (temp[i] != '\0')
    {
      if (temp[i] == ' ')
	{
	  j++;
	  k = 0;
	  i++;
	}
      temp2[j][k++] = temp[i++];
    }
  temp2[++j] = NULL;
  return (temp2);
}

void	setenv_shell2(char **environ, char *str, t_sh *sh)
{
  int	ref_env;
  int	i;

  i = 0;
  sh->temp2 = xmalloc(sizeof(char *) * 3);
  while (i < 3)
    sh->temp2[i++] = xmalloc(sizeof(char) * 100);
  sh->temp2 = set_temp2(sh->temp2, str);
  if (verif_ref(sh->temp2) == 3)
    {
      if ((ref_env = check_var_to_env(sh->temp2[1], environ)) != -1)
	change_env(sh->temp2, environ, ref_env);
      else
	add_to_env(sh->temp2, environ);
    }
  else
    my_putstr("Syntaxe error\n\n");
}

void	setenv_shell(char **environ, t_sh *sh)
{
  int	ref_env;
  int	i;

  i = 0;
  sh->temp2 = xmalloc(sizeof(char *) * 3);
  while (i < 3)
    sh->temp2[i++] = xmalloc(sizeof(char) * 100);
  sh->temp2 = set_temp2(sh->temp2, sh->temp);
  if (verif_ref(sh->temp2) == 3)
    {
      if ((ref_env = check_var_to_env(sh->temp2[1], environ)) != -1)
	change_env(sh->temp2, environ, ref_env);
      else
	add_to_env(sh->temp2, environ);
    }
  else
    my_putstr("Syntaxe error\n\n");
  if (sh->flag == 1)
    my_read(sh);
}
