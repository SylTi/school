/*
** prend_ressource.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu Jun 18 16:36:05 2009 emilien ampe
** Last update Sun Jun 21 16:01:57 2009 yoann jaspar
*/

#include "serveur.h"

void	prend_linemate(int fd, t_env *env)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].linemate > 0)
    {
      env->fd[fd].inventaire.linemate += 1;
      env->map[env->fd[fd].x][env->fd[fd].y].linemate -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	prend_deraumere(int fd, t_env *env)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].deraumere > 0)
    {
      env->fd[fd].inventaire.deraumere += 1;
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	prend_sibur(int fd, t_env *env)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].sibur > 0)
    {
      env->fd[fd].inventaire.sibur += 1;
      env->map[env->fd[fd].x][env->fd[fd].y].sibur -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	prend_mendiane(int fd, t_env *env)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].mendiane > 0)
    {
      env->fd[fd].inventaire.mendiane += 1;
      env->map[env->fd[fd].x][env->fd[fd].y].mendiane -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	prend_phiras(int fd, t_env *env)
{
  if (env->map[env->fd[fd].x][env->fd[fd].y].phiras > 0)
    {
      env->fd[fd].inventaire.phiras += 1;
      env->map[env->fd[fd].x][env->fd[fd].y].phiras -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}
