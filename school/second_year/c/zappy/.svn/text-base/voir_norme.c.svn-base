/*
** voir_norme.c for zappy in /u/all/jaspar_y/rendu/c/zappy/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Sun Jun 21 16:56:09 2009 yoann jaspar
** Last update Sun Jun 21 17:01:45 2009 yoann jaspar
*/

#include "serveur.h"

void	voir_up_astek(int flag, t_env *env, int fd, int y, int x)
{
  int	temp_x;
  int	temp_y;

  if (flag > 0)
    xwrite(fd, ",", 1);
  if (x >= env->x_world)
    temp_x = (x - env->x_world);
  else if (x <= -1)
    temp_x = (x + env->x_world);
  else
    temp_x = x;
  if (y + env->fd[fd].y >= env->y_world)
    temp_y = ((y + env->fd[fd].y) - env->y_world);
  else
    temp_y = (y + env->fd[fd].y);
  display_voir(temp_x, temp_y, fd, env);
}

void	voir_down_astek(int flag, t_env *env, int fd, int y, int x)
{
  int	temp_x;
  int	temp_y;

  if (flag > 0)
    xwrite(fd, ",", 1);
  if (x >= env->x_world)
    temp_x = (x - env->x_world);
  else if (x <= -1)
    temp_x = (x + env->x_world);
  else
    temp_x = x;
  if (y + env->fd[fd].y <= -1)
    temp_y = ((y + env->fd[fd].y) + (env->y_world - 1));
  else
    temp_y = (y + env->fd[fd].y);
  display_voir(temp_x, temp_y, fd, env);
}

void	voir_left_astek(int flag, t_env *env, int fd, int y, int x)
{
  int	temp_x;
  int	temp_y;

  if (flag > 0)
    xwrite(fd, ",", 1);
  if (y >= env->y_world)
    temp_y = (y - env->y_world);
  else if (y <= -1)
    temp_y = (y + env->x_world);
  else
    temp_y = y;
  if (x + env->fd[fd].x <= -1)
    temp_x = ((x + env->fd[fd].x) + (env->x_world - 1));
  else
    temp_x = (x + env->fd[fd].x);
  display_voir(temp_x, temp_y, fd, env);
}

void	voir_right_astek(int flag, t_env *env, int fd, int y, int x)
{
  int	temp_x;
  int	temp_y;

  if (flag > 0)
    xwrite(fd, ",", 1);
  if (y >= env->x_world)
    temp_y = (y - env->y_world);
  else if (y <= -1)
    temp_y = (y + env->y_world);
  else
    temp_y = y;
  if (x + env->fd[fd].x >= env->y_world)
    temp_x = ((x + env->fd[fd].x) - env->x_world);
  else
    temp_x = (x + env->fd[fd].x);
  display_voir(temp_x, temp_y, fd, env);
}
