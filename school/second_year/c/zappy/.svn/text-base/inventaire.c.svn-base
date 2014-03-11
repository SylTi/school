/*
** inventaire.c for zappy inventaire in /u/epitech_2012/tissie_s/cu/rendu/c/zappy
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Tue Jun  9 15:36:01 2009 sylvain tissier
** Last update Sun Jun 21 16:03:01 2009 yoann jaspar
*/

#include "serveur.h"
#include "push.h"

int		boucle_inv(t_elem *tmp, t_env *env, struct timeval *temptime,
			   struct timeval *temptime2)
{
  int		nourriture;
  int		food;

  food = 0;
  if (!tmp)
    return (0);
  timersub(&tmp->time, temptime, temptime);
  nourriture = (env->delay * 10000 * 126);
  while (temptime->tv_usec > 0 && temptime->tv_sec > 0)
    {
      if (nourriture/1000000 == 0)
	temptime->tv_usec -= nourriture;
      else
	{
	  temptime2->tv_sec = nourriture / 1000000;
	  temptime2->tv_usec = (nourriture -  temptime2->tv_sec * 1000000 );
	  timersub(temptime, temptime2, temptime);
	}
      if (!(temptime->tv_usec > 0 && temptime->tv_sec > 0))
	break ;
      food++;
    }
  return (food);
}

void			print_inv(int fd, char *buf, t_env *env)
{
  sprintf(buf, "{nourriture %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d}\n",
	  env->fd[fd].inventaire.food,
	  env->fd[fd].inventaire.linemate,
	  env->fd[fd].inventaire.deraumere,
	  env->fd[fd].inventaire.sibur,
	  env->fd[fd].inventaire.mendiane,
	  env->fd[fd].inventaire.phiras,
	  env->fd[fd].inventaire.thystame);
}

void			inventaire(int fd, char *arg, t_env *env, t_list *list)
{
  char			*buf;
  t_elem		*tmp;
  struct timeval	temptime;
  struct timeval	temptime2;

  tmp = list->first;
  arg = arg;
  buf = xmalloc(300);
  while (tmp)
    {
      if ((tmp->fd == fd) &&
	  (strcmp(tmp->cmd, "mort") == 0))
	break;
      tmp = tmp->next;
    }
  if ((gettimeofday(&temptime, NULL) != -1))
    env->fd[fd].inventaire.food = 1 + boucle_inv(tmp, env, &temptime,
						 &temptime2);
  print_inv(fd, buf, env);
  write(fd, buf, strlen(buf));
  free(buf);
  return ;
}
