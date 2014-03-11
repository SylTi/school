/*
** incantation3.c for zappy in /u/all/jaspar_y/rendu/c/zappy/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Sun Jun 21 17:04:20 2009 yoann jaspar
** Last update Mon Jun 22 17:49:35 2009 nikola cebovic
*/

#include "serveur.h"

int	incant_4(t_env *env, int fd, int nb)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].linemate != 1 &&
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere != 1 &&
      env->map[env->fd[fd].x][env->fd[fd].y].sibur != 2 &&
      env->map[env->fd[fd].x][env->fd[fd].y].phiras != 1 && nb != 4)
    {
      xwrite(fd, "ko\n", 3);
      return (1);
    }
  else
    {
      eject_pierre(1, "linemate", env);
      env->map[env->fd[fd].x][env->fd[fd].y].linemate -= 1;
      eject_pierre(1, "deraumere", env);
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere -= 1;
      eject_pierre(2, "sibur", env);
      env->map[env->fd[fd].x][env->fd[fd].y].sibur -= 2;
      eject_pierre(1, "phiras", env);
      env->map[env->fd[fd].x][env->fd[fd].y].phiras -= 1;
      leveling(env, fd, nb, 0);
      return (0);
    }
}

int	incant_7(t_env *env, int fd, int nb)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].linemate != 2 && 
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere != 2 &&
      env->map[env->fd[fd].x][env->fd[fd].y].sibur != 2 &&
      env->map[env->fd[fd].x][env->fd[fd].y].mendiane != 2 &&
      env->map[env->fd[fd].x][env->fd[fd].y].phiras != 2 &&
      env->map[env->fd[fd].x][env->fd[fd].y].thystame != 1 && nb != 6)
    {
      xwrite(fd, "ko\n", 3);
      return (1);
    }
  else
    {
      eject_pierre(2, "linemate", env);
      env->map[env->fd[fd].x][env->fd[fd].y].linemate -= 2;
      eject_pierre(2, "deraumere", env);
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere -= 2;
      eject_pierre(2, "sibur", env);
      env->map[env->fd[fd].x][env->fd[fd].y].sibur -= 2;
      eject_pierre(2, "phiras", env);
      env->map[env->fd[fd].x][env->fd[fd].y].phiras -= 2;
      eject_pierre(1, "thystame", env);
      env->map[env->fd[fd].x][env->fd[fd].y].thystame -= 1;
      leveling(env, fd, nb, 1);
      return (0);
    }
}

void	leveling(t_env *env, int fd, int nb, int maxlvl)
{
  int	i;
  int	flag;

  i = 0;
  flag = 0;
  while (i < MAX_FD)
    {
      if (env->map[env->fd[i].x] == env->map[env->fd[fd].x] &&
          env->map[env->fd[i].y] == env->map[env->fd[fd].y])
	{
	  env->fd[i].lvl++;
	  flag++;
	}
      if (flag > nb)
	break ;
      i++;
    }
  if (maxlvl == 1)
    env->fd[fd].team->nbr_max_lvl++;
}
