/*
** winner.c for team winner in /u/all/tissie_s/cu/rendu/c/zappy
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Mon Jun 22 16:56:16 2009 sylvain tissier
** Last update Mon Jun 22 17:20:53 2009 sylvain tissier
*/

#include "serveur.h"

int	winner(t_env *env)
{
  int	i;

  i = 0;
  while (i < MAX_FD)
    {
      if (env->fd[i].team)
	if (env->fd[i].team->nbr_max_lvl >= 6)
	  return (1);
      i++;
    }
  return (0);
}
