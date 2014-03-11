/*
** pose_ressource.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Wed Jun 17 16:54:11 2009 emilien ampe
** Last update Sun Jun 21 16:01:41 2009 yoann jaspar
*/

#include "serveur.h"

void	pose_linemate(int fd, t_env *env)
{
  if (env->fd[fd].inventaire.linemate > 0)
    {
      env->map[env->fd[fd].x][env->fd[fd].y].linemate += 1;
      env->fd[fd].inventaire.linemate -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	pose_deraumere(int fd, t_env *env)
{
  if (env->fd[fd].inventaire.deraumere > 0)
    {
      env->map[env->fd[fd].x][env->fd[fd].y].deraumere += 1;
      env->fd[fd].inventaire.deraumere -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	pose_sibur(int fd, t_env *env)
{
  if (env->fd[fd].inventaire.sibur > 0)
    {
      env->map[env->fd[fd].x][env->fd[fd].y].sibur += 1;
      env->fd[fd].inventaire.sibur -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	pose_mendiane(int fd, t_env *env)
{
  if (env->fd[fd].inventaire.mendiane > 0)
    {
      env->map[env->fd[fd].x][env->fd[fd].y].mendiane += 1;
      env->fd[fd].inventaire.mendiane -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	pose_phiras(int fd, t_env *env)
{
  if (env->fd[fd].inventaire.phiras > 0)
    {
      env->map[env->fd[fd].x][env->fd[fd].y].phiras += 1;
      env->fd[fd].inventaire.phiras -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}
