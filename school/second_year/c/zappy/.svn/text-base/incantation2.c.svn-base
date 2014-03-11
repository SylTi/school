/*
** incantation2.c for zappy in /u/all/jaspar_y/rendu/c/zappy/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Sun Jun 21 16:10:01 2009 yoann jaspar
** Last update Mon Jun 22 17:50:05 2009 nikola cebovic
*/

#include "serveur.h"

void	eject_pierre2(char *ressource, t_env *env, int x, int y)
{
  if (!strcmp(ressource, "linemate"))
    env->map[x][y].linemate += 1;
  else if (!strcmp(ressource, "deraumere"))
    env->map[x][y].deraumere += 1;
  else if (!strcmp(ressource, "sibur"))
    env->map[x][y].sibur += 1;
  else if (!strcmp(ressource, "mendiane"))
    env->map[x][y].mendiane += 1;
  else if (!strcmp(ressource, "phiras"))
    env->map[x][y].phiras += 1;
  else if (!strcmp(ressource, "thystame"))
    env->map[x][y].thystame += 1;
}

void	eject_pierre(int nb, char *ressource, t_env *env)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  while (i < nb)
    {
      x = my_random(env->x_world);
      y = my_random(env->y_world);
      if (x < env->x_world && y < env->y_world)
	{
	  eject_pierre2(ressource, env, x, y);
	  i++;
	}
    }
}

void	incantation(int fd, char *arg, t_env *env, t_list *list)
{
  arg = arg;
  put_in_list(fd, "my_incantation", list, env);
  xwrite(fd, "elevation en cours\n", 19);
}

int	incant_6(t_env *env, int fd, int nb)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].linemate != 1 &&
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere != 2 &&
      env->map[env->fd[fd].x][env->fd[fd].y].sibur != 3 &&
      env->map[env->fd[fd].x][env->fd[fd].y].phiras != 1 && nb != 6)
    {
      xwrite(fd, "ko\n", 3);
      return (1);
    }
  else
    {
      eject_pierre(1, "linemate", env);
      env->map[env->fd[fd].x][env->fd[fd].y].linemate -= 1;
      eject_pierre(2, "deraumere", env);
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere -= 2;
      eject_pierre(3, "sibur", env);
      env->map[env->fd[fd].x][env->fd[fd].y].sibur -= 3;
      eject_pierre(1, "phiras", env);
      env->map[env->fd[fd].x][env->fd[fd].y].phiras -= 1;
      leveling(env, fd, nb, 0);
      return (0);
    }
}

int	incant_5(t_env *env, int fd, int nb)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].linemate != 1 &&
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere != 2 &&
      env->map[env->fd[fd].x][env->fd[fd].y].sibur != 1 &&
      env->map[env->fd[fd].x][env->fd[fd].y].mendiane != 3 && nb != 4)
    {
      xwrite(fd, "ko\n", 3);
      return (1);
    }
  else
    {
      eject_pierre(1, "linemate", env);
      env->map[env->fd[fd].x][env->fd[fd].y].linemate -= 1;
      eject_pierre(2, "deraumere", env);
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere -= 2;
      eject_pierre(1, "sibur", env);
      env->map[env->fd[fd].x][env->fd[fd].y].sibur -= 1;
      eject_pierre(3, "mendiane", env);
      env->map[env->fd[fd].x][env->fd[fd].y].mendiane -= 3;
      leveling(env, fd, nb, 0);
      return (0);
    }
}
