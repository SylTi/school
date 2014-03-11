/*
** incantation.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jun 16 14:30:32 2009 emilien ampe
** Last update Mon Jun 22 17:49:51 2009 nikola cebovic
*/

#include "serveur.h"

int	incant_3(t_env *env, int fd, int nb)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].linemate != 2 &&
      env->map[env->fd[fd].x][env->fd[fd].y].sibur != 1 &&
      env->map[env->fd[fd].x][env->fd[fd].y].phiras != 1 && nb != 2)
    {
      xwrite(fd, "ko\n", 3);
      return (1);
    }
  else
    {
      eject_pierre(2, "linemate", env);
      env->map[env->fd[fd].x][env->fd[fd].y].linemate -= 2;
      eject_pierre(1, "sibur", env);
      env->map[env->fd[fd].x][env->fd[fd].y].sibur -= 1;
      eject_pierre(1, "phiras", env);
      env->map[env->fd[fd].x][env->fd[fd].y].phiras -= 1;
      leveling(env, fd, nb, 0);
      return (0);
    }
}

int	incant_2(t_env *env, int fd, int nb)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].linemate != 1 &&
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere != 1 &&
      env->map[env->fd[fd].x][env->fd[fd].y].sibur != 1 && nb != 2)
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
      eject_pierre(1, "sibur", env);
      env->map[env->fd[fd].x][env->fd[fd].y].sibur -= 1;
      leveling(env, fd, nb, 0);
      return (0);
    }
}

int	incant_1(t_env *env, int fd, int nb)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].linemate < 1 && nb != 1)
    {
      xwrite(fd, "ko\n", 3);
      return (1);
    }
  else
    {
      eject_pierre(1, "linemate", env);
      env->map[env->fd[fd].x][env->fd[fd].y].linemate -= 1;
      leveling(env, fd, nb, 0);
      return (0);
    }
}

int	my_incantation_fin(int fd, t_env *env, int nb)
{
  if (env->fd[fd].lvl == 5)
    {
      if (incant_5(env, fd, nb))
	return (1);
    }
  else if (env->fd[fd].lvl == 6)
    {
      if (incant_6(env, fd, nb))
	return (1);
    }
  else if (env->fd[fd].lvl == 7)
    {
      if (incant_7(env, fd, nb))
	return (1);
    }
  return (0);
}

int	my_incantation_suite(int fd, t_env *env, int nb)
{
  if (env->fd[fd].lvl == 1)
    {
      if (incant_1(env, fd, nb))
	return (1);
    }
  else if (env->fd[fd].lvl == 2)
    { 
      if (incant_2(env, fd, nb))
	return (1);
    }
  else if (env->fd[fd].lvl == 3)
    {
      if (incant_3(env, fd, nb))
	return (1);
    }
  else if (env->fd[fd].lvl == 4)
    {
      if (incant_4(env, fd, nb))
	return (1);
    }
  return (my_incantation_fin(fd, env, nb));
}

void	my_incantation(int fd, char *arg, t_env *env, t_list *list)
{
  int	nb;
  int	i;
  char	buf[256];

  list = list;
  arg = arg;
  i = -1;
  nb = 0;
  while (++i < MAX_FD)
    if (env->map[env->fd[i].x] == env->map[env->fd[fd].x] && 
	env->map[env->fd[i].y] == env->map[env->fd[fd].y] &&
	env->fd[i].lvl == env->fd[fd].lvl)
      nb++;
  
  if (my_incantation_suite(fd, env, nb))
    return;
  
  sprintf(buf, "niveau actuel : %i\n", env->fd[fd].lvl);
  xwrite(fd, buf, strlen(buf));
}
