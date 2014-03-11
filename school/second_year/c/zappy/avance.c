/*
** avance.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jun 16 14:22:14 2009 emilien ampe
** Last update Sun Jun 21 16:06:11 2009 yoann jaspar
*/

#include "serveur.h"

void	avance_up(t_env *env, int fd)
{
  if (env->fd[fd].y == (env->y_world - 1))
    env->fd[fd].y = 0;
  else
    env->fd[fd].y += 1;
}

void	avance_down(t_env *env, int fd)
{
  if (env->fd[fd].y == 0)
    env->fd[fd].y = (env->y_world - 1);
  else
    env->fd[fd].y -= 1;
}

void	avance_right(t_env *env, int fd)
{
  if (env->fd[fd].x == (env->x_world - 1))
    env->fd[fd].x = 0;
  else
    env->fd[fd].x += 1;
}

void	avance_left(t_env *env, int fd)
{
  if (env->fd[fd].x == 0)
    env->fd[fd].x = (env->x_world - 1);
  else
    env->fd[fd].x -= 1;
}

void	avance(int fd, char *arg, t_env *env, t_list *list)
{
  list = list;
  arg = arg;
  if (env->fd[fd].sens == UP)
    avance_up(env, fd);
  else if (env->fd[fd].sens == DOWN)
    avance_down(env, fd);
  else if (env->fd[fd].sens == LEFT)
    avance_left(env, fd);
  else if (env->fd[fd].sens == RIGHT)
    avance_right(env, fd);
  xwrite(fd, "ok\n", 3);
}
