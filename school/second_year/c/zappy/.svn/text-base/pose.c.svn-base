/*
** pose.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Tue Jun 16 14:25:55 2009 emilien ampe
** Last update Mon Jun 22 14:52:27 2009 virgile bizet
*/

#include "serveur.h"

void	pose_thystame(int fd, t_env *env)
{
  if (env->fd[fd].inventaire.thystame > 0)
    {
      env->map[env->fd[fd].x][env->fd[fd].y].thystame += 1;
      env->fd[fd].inventaire.thystame -= 1;
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	pose_nourriture(int fd, t_env *env, t_list *list)
{
  if (env->fd[fd].inventaire.food > 0)
    {
      env->map[env->fd[fd].x][env->fd[fd].y].food += 1;
      env->fd[fd].inventaire.food -= 1;
      update_time_death_neg(fd, env, list);
      xwrite(fd, "ok\n", 3);
    }
  else
    xwrite(fd, "ko\n", 3);
}

void	pose(int fd, char *arg, t_env *env, t_list *list)
{
  list = list;
  if (!strncmp(" linemate", &arg[4], strlen(" linemate")))
    pose_linemate(fd, env);
  else if (!strncmp(" deraumere", &arg[4], strlen(" deraumere")))
    pose_deraumere(fd, env);
  else if (!strncmp(" sibur", &arg[4], strlen(" sibur")))
    pose_sibur(fd, env);
  else if (!strncmp(" mendiane", &arg[4], strlen(" mendiane")))
    pose_mendiane(fd, env);
  else if (!strncmp(" phiras", &arg[4], strlen(" phiras")))
    pose_phiras(fd, env);
  else if (!strncmp(" thystame", &arg[4], strlen(" thystame")))
    pose_thystame(fd, env);
  else if (!strncmp(" nourriture", &arg[4], strlen(" nourriture")))
    pose_nourriture(fd, env, list);
  else
    xwrite(fd, "ko\n", 3);
}
