/*
** gauche_droite.c for gauche_droite in /u/all/bizet_v/cu/rendu/c/zappy
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Tue Jun  9 15:24:37 2009 virgile bizet
** Last update Fri Jun 19 13:18:57 2009 yoann jaspar
*/

#include "serveur.h"

void    droite(int fd, char *arg, t_env *env)
{
  arg = arg;
  if (env->fd[fd].sens != UP)
    env->fd[fd].sens -= 1;
  else
    env->fd[fd].sens = 4;
  xwrite(fd, "ok\n", 3);
}

void    gauche(int fd, char *arg, t_env *env)
{
  arg = arg;
  if (env->fd[fd].sens != RIGHT)
    env->fd[fd].sens += 1;
  else
    env->fd[fd].sens = 1;
  xwrite(fd, "ok\n", 3);
}
