/*
** prend.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jun 16 14:23:53 2009 emilien ampe
** Last update Mon Jun 22 14:45:36 2009 virgile bizet
*/

#include "serveur.h"

void	add_food(int nb, t_env *env)
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
	  env->map[x][y].food += 1;
	  i++;
	}
    }
}

void	prend_thystame(int fd, t_env *env)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].thystame > 0)
    {
      env->fd[fd].inventaire.thystame += 1;
      env->map[env->fd[fd].x][env->fd[fd].y].thystame -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	prend_nourriture(int fd, t_env *env, t_list *list)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].food > 0)
    {
      env->map[env->fd[fd].x][env->fd[fd].y].food -= 1;
      update_time_death_pos(fd, env, list);
      add_food(1, env);
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	 prend(int fd, char *arg, t_env *env, t_list *list)
{
  list = list;
  if (!strncmp(" linemate", &arg[5], strlen(" linemate")))
    prend_linemate(fd, env);
  else if (!strncmp(" deraumere", &arg[5], strlen(" deraumere")))
    prend_deraumere(fd, env);
  else if (!strncmp(" sibur", &arg[5], strlen(" sibur")))
    prend_sibur(fd, env);
  else if (!strncmp(" mendiane", &arg[5], strlen(" mendiane")))
    prend_mendiane(fd, env);
  else if (!strncmp(" phiras", &arg[5], strlen(" phiras")))
    prend_phiras(fd, env);
  else if (!strncmp(" thystame", &arg[5], strlen(" thystame")))
    prend_thystame(fd, env);
  else if (!strncmp(" nourriture", &arg[5], strlen(" nourriture")))
    prend_nourriture(fd, env, list);
  else
    xwrite(fd, "ko\n", 3);
}
