/*
** all_cd.c for all_cd in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Thu Feb 28 15:51:31 2008 yoann jaspar
** Last update Sun Jun  1 00:14:20 2008 maxime dumez
*/

#include "sh.h"
#define	BUFF_MAX	512

void		all_cd2(char *str, t_sh *sh)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  sh->temp2 = xmalloc(sizeof(char *));
  while (i < 2)
    sh->temp2[i++] = xmalloc(sizeof(char) * BUFF_MAX);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	{
	  k = 0;
	  i++;
	  j++;
	}
      sh->temp2[j][k++] = str[i++];
    }
  j++;
  sh->temp2[j] = NULL;
  cd_fct(sh);
}

void		all_cd(t_sh *sh)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  sh->temp2 = xmalloc(sizeof(char *));
  while (i < 2)
    sh->temp2[i++] = xmalloc(sizeof(char) * BUFF_MAX);
  i = 0;
  while (sh->temp[i] != '\0')
    {
      if (sh->temp[i] == ' ')
	{
	  k = 0;
	  i++;
	  j++;
	}
      sh->temp2[j][k++] = sh->temp[i++];
    }
  j++;
  sh->temp2[j] = NULL;
  cd_fct(sh);
}

void	cd_fct(t_sh *sh)
{
  if (sh->temp2[1] == NULL)
    cd_shell(sh->home, sh->flag, sh);
  else if (sh->temp2[1][0] == '~')
    cd_shell_tilde(sh->temp2[1], sh->home, sh->flag, sh);
  else
    cd_shell(sh->temp2[1], sh->flag, sh);
}
