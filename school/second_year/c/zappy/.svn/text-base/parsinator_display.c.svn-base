/*
** parsinator_display.c for zappy in /u/all/jaspar_y/rendu/c/zappy/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Mon Jun 22 15:41:07 2009 yoann jaspar
** Last update Mon Jun 22 15:41:49 2009 yoann jaspar
*/

#include "serveur.h"

void	display_team(t_env *env)
{
  int	i;

  i = 0;
  printf("Nombre de teams : %d\n", env->nb_team);
  while (i < env->nb_team)
    {
      printf("Team -> %s\n", env->team_[i]);
      i++;
    }
}

void	display_syno()
{
  perror("Erreur dans la ligne de commande:\n./zappy [-p:port] [-n:team_1 team_2]\n");
  exit(EXIT_FAILURE);
}

void	error()
{
  display_syno();
}
