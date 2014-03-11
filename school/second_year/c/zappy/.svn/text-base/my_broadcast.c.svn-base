/*
** my_broadcast.c for broadcast zappy in /u/all/tissie_s/cu/rendu/c/zappy
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Wed Jun  3 15:23:24 2009 sylvain tissier
** Last update Mon Jun 22 17:31:51 2009 nikola cebovic
*/

#include "serveur.h"

int		*my_angle(int dir);

typedef struct	s_broadcast
{
  int		haut;
  int		bas;
  int		gauche;
  int		droite;
  int		samex;
  int		samey;
}		t_broad;

int		my_broadcast2(t_broad broad, int fd, t_env *env)
{
  int		*champ;

  champ = my_angle(env->fd[fd].sens);
  if (broad.haut < broad.bas && broad.gauche < broad.droite
     && broad.samex != 1 && broad.samey != 1)
   return (champ[6]);
  else if (broad.haut < broad.bas && broad.droite < broad.gauche
	   && broad.samex == 1 && broad.samey != 1)
    return (champ[4]);
  else if (broad.bas < broad.haut && broad.gauche < broad.droite
	   && broad.samex != 1 && broad.samey != 1)
    return (champ[8]);
  else if (broad.bas < broad.haut && broad.droite < broad.gauche
	   && broad.samex != 1 && broad.samey != 1)
    return (champ[2]);
  else if (broad.bas < broad.haut && broad.samex == 1)
    return (champ[1]);
  else if (broad.haut < broad.bas && broad.samex == 1)
    return (champ[5]);
  else if (broad.gauche < broad.droite && broad.samey == 1)
    return (champ[7]);
  else if (broad.droite < broad.gauche && broad.samey == 1)
    return (champ[3]);
  else
    return (-1);
}

int		do_diff(int a, int b)
{
  int	val1;

  val1 = 0;
  while (a < b)
    {
      a++;
      val1++;
    }
  return (val1);
}

int		check_signe(int a)
{
  if (a < 0)
    a = a * (-1);
  return (a);
}

int		my_broadcast_suite(int fd, t_env *env, int listener)
{
  int		val1;
  int		val2;
  int		diff1;
  int		diff4;
  t_broad	broad;

  diff1 = env->fd[fd].x;
  diff4 = env->fd[listener].y;
  if (env->fd[fd].x == env->fd[listener].x)
    broad.samex = 1;
  if (env->fd[fd].y == env->fd[listener].y)
    broad.samey = 1;
  val1 = do_diff(diff1, env->x_world);
  val2 = do_diff(diff4, env->y_world);
  broad.gauche = env->fd[fd].x - env->fd[listener].x;
  broad.gauche = check_signe(broad.gauche);
  broad.droite = val1 + env->fd[listener].x;
  broad.bas = env->fd[fd].y - env->fd[listener].y;
  broad.bas = check_signe(broad.bas);
  broad.haut = env->fd[fd].y + val2;
  return (my_broadcast2(broad, fd, env));
}

int		my_broadcast(int fd, t_env *env, int listener)
{
  if ((env->fd[fd].x == env->fd[listener].x)
      && (env->fd[fd].y == env->fd[listener].y))
    return (0);
  else
    return (my_broadcast_suite(fd, env, listener));
}
