/*
** expulse_direc.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Fri Jun 19 15:16:40 2009 emilien ampe
** Last update Fri Jun 19 15:18:52 2009 emilien ampe
*/

#include "serveur.h"

void	expulse_up(t_env *env, int fd_p)
{
  if (env->fd[fd_p].y == (env->y_world - 1))
    env->fd[fd_p].x = 0;
  else
    env->fd[fd_p].x += 1;
}

void	expulse_down(t_env *env, int fd_p)
{
  if (env->fd[fd_p].y == 0)
    env->fd[fd_p].x = (env->y_world - 1);
  else
    env->fd[fd_p].x -= 1;
}

void	expulse_right(t_env *env, int fd_p)
{
  if (env->fd[fd_p].x == (env->x_world - 1))
    env->fd[fd_p].x = 0;
  else
    env->fd[fd_p].x += 1;
}

void	expulse_left(t_env *env, int fd_p)
{
  if (env->fd[fd_p].x == 0)
    env->fd[fd_p].x = (env->x_world - 1);
  else
    env->fd[fd_p].x -= 1;
}
