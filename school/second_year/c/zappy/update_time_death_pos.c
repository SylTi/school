/*
** update_time_death_pos.c for zappy in /u/all/ampe_e/cu/rendu/c/zappy/zappy_svn/zappy
** 
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
** 
** Started on  Thu Jun 18 16:42:38 2009 emilien ampe
** Last update Mon Jun 22 16:22:38 2009 nikola cebovic
*/

#include "serveur.h"

void	update_time_death_pos2(t_elem *tmp, t_list *list)
{
  free(tmp->cmd);
  if (tmp == list->first && tmp == list->last)
    init_list(list);
  else if (tmp == list->first)
    {
      list->first = tmp->next;
      list->first->prev = NULL;
    }
  else if (tmp == list->last)
    {
      list->last = list->last->prev;
      list->last->next = NULL;
    }
  else
    {
      if (tmp->prev)
	if (tmp->prev->next)
	  tmp->prev->next = tmp->next;
      if (tmp->next)
	if (tmp->next->prev)
	  tmp->next->prev = tmp->prev;
    }
  free(tmp);
}

void			insert_death(t_list *list, struct timeval death,
				     int fd)
{
  t_elem		*new;
  
  new = xmalloc(sizeof(t_elem));
  if (!new)
    exit (1);
  new->fd = fd;
  new->prev = list->last;
  new->next = NULL;
  new->time = death;
  new->cmd = xmalloc(strlen("mort") + 1);
  new->cmd = strncpy(new->cmd, "mort", strlen("mort"));
  new->cmd[strlen("mort")] = '\0';
  if (list->last)
    insert_in_list2(list, new, new->time, NULL);
  else
    {
      list->first = new;
      list->last = new;
    }
}

void			update_time_death_pos(int fd, t_env *env, t_list *list)
{
  t_elem		*tmp;
  struct timeval	death;
  long			time_to_add;

  tmp = list->first;
  while (tmp)
    {
      if (tmp->fd == fd && (strcmp(tmp->cmd, "mort") == 0))
	break ;
      tmp = tmp->next;
    }
  time_to_add = 126 * env->delay * 10000;
  death.tv_usec = 0;
  death.tv_sec = 0;
  if (time_to_add/1000000 == 0)
    death.tv_usec = time_to_add;
  else
    {
      death.tv_sec = time_to_add / 1000000;
      death.tv_usec = (time_to_add - death.tv_sec*1000000);
    }
  timeradd(&death, &tmp->time, &death);
  update_time_death_pos2(tmp, list);
  insert_death(list, death, fd);
}

void			update_time_death_neg(int fd, t_env *env, t_list *list)
{
  t_elem		*tmp;
  struct timeval	death;
  long			time_to_sub;

  tmp = list->first;
  while (tmp)
    {
      if (tmp->fd == fd && (strcmp(tmp->cmd, "mort") == 0))
	break ;
      tmp = tmp->next;
    }
  time_to_sub = 126 * env->delay * 10000;
  death.tv_usec = 0;
  death.tv_sec = 0;
  if (time_to_sub/1000000 == 0)
    death.tv_usec = time_to_sub;
  else
    {
      death.tv_sec = time_to_sub / 1000000;
      death.tv_usec = (time_to_sub - death.tv_sec*1000000);
    }
  timersub(&death, &tmp->time, &death);
  update_time_death_pos2(tmp, list);
  insert_death(list, death, fd);
}
