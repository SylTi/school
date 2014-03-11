/*
** voir_direct.c for zappy in /u/all/jaspar_y/rendu/c/zappy/zappy
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Sun Jun 21 17:39:55 2009 yoann jaspar
** Last update Mon Jun 22 14:51:57 2009 virgile bizet
*/

#include "serveur.h"

void	voir_up(int fd, t_env *env)
{
  int	x;
  int	y;
  int	flag;
  int	val_max;
  int	val_min;
  int	height_max;

  height_max = (env->fd[fd].lvl + 1);
  val_min = env->fd[fd].x;
  val_max = env->fd[fd].x;
  y = 0;
  flag = 0;
  xwrite(fd, "{", 1);
  while (y < height_max)
    {
      x = val_min;
      while (x <= val_max)
	voir_up_astek(flag++, env, fd, y, x++);
      val_min--;
      val_max++;
      y++;
    }
  xwrite(fd, "}\n", 2);
}

void	voir_down(int fd, t_env *env)
{
  int	x;
  int	y;
  int	flag;
  int	val_max;
  int	val_min;
  int	height_max;

  height_max = (- (env->fd[fd].lvl + 1));
  val_min = env->fd[fd].x;
  val_max = env->fd[fd].x;
  y = 0;
  flag = 0;
  xwrite(fd, "{", 1);
  while (y > height_max)
    {
      x = val_max;
      while (x >= val_min)
	voir_down_astek(flag++, env, fd, y, x--); 
      val_min--;
      val_max++;
      y--;
    }
  xwrite(fd, "}\n", 2);
}

void	voir_left(int fd, t_env *env)
{
  int	x;
  int	y;
  int	flag;
  int	val_max;
  int	val_min;
  int	height_max;

  height_max = (- (env->fd[fd].lvl + 1));
  val_min = env->fd[fd].y;
  val_max = env->fd[fd].y;
  x = 0;
  xwrite(fd, "{", 1);
  flag = 0;
  while (x > height_max)
    {
      y = val_min;
      while (y <= val_max)
	voir_left_astek(flag++, env, fd, y++, x);
      val_min--;
      val_max++;
      x--;
    }
  xwrite(fd, "}\n", 2);
}

void	voir_right(int fd, t_env *env)
{
  int	x;
  int	y;
    int	flag;
  int	val_max;
  int	val_min;
  int	height_max;

  height_max = (env->fd[fd].lvl + 1);
  val_min = env->fd[fd].y;
  val_max = env->fd[fd].y;
  x = 0;
  xwrite(fd, "{", 1);
  flag = 0;
  while (x < height_max)
    {
      y = val_max;
      while (y >= val_min)
	voir_right_astek(flag++, env, fd, y--, x);
      val_min--;
      val_max++;
      x++;
    }
  xwrite(fd, "}\n", 2);
}
