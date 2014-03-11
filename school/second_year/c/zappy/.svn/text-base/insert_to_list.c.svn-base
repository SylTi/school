/*
** insert_to_list.c for insert_to_list.c in /u/epitech_2012/bizet_v/rendu/c/push_swap
** 
** Made by virgile bizet
** Login   <bizet_v@epitech.net>
** 
** Started on  Thu Apr 24 13:43:54 2008 virgile bizet
** Last update Mon Jun 22 16:23:18 2009 nikola cebovic
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "push.h"
#include "serveur.h"

struct	timeval	last_time(t_list *s, int fd, struct timeval time)
{
  t_elem	*new;
  struct timeval time_tmp;

  new = s->first;
  time_tmp.tv_sec = 0;
  time_tmp.tv_usec = 0;
  while (new != NULL)
    {
      if (new->fd == fd
	  && strcmp(new->cmd, "mort")
	  && strcmp(new->cmd, "my_fork")
	&& strcmp(new->cmd, "my_fork"))
	time_tmp = new->time;
      new = new->next;
    }
  if (time_tmp.tv_sec == 0 && time_tmp.tv_usec == 0)
    gettimeofday(&time_tmp, NULL);
  timeradd(&time, &time_tmp, &time);
  return (time);
}

void	insert_to_list2_suite(t_elem *new, t_list *s)
{
  if (timercmp(&new->time, &s->first->time, >))
    {
      s->last->next = new;
      s->last = new;
    }
  else
    {
      s->first->prev = new;
      new->prev = NULL;
      new->next = s->first;
      s->first = new;
    }
}

void	insert_in_list2(t_list *s, t_elem *new, struct timeval time, 
			t_elem *tmp)
{
  if (s->last == s->first)
    {
      insert_to_list2_suite(new, s);
      return ;
    }
  tmp = insert_by_order(s, new->time);
  if (timercmp(&s->last->time, &time, <))
    {
      s->last->next = new;
      s->last = new;
    }
  else if (timercmp(&s->first->time, &time, >))
    {
      s->first->prev = new;
      new->prev = NULL;
      new->next = s->first;
      s->first = new;
    }
  else
    {
      new->next = tmp;
      new->prev = tmp->prev;
      tmp->prev->next = new;
      tmp->prev = new;
    }
}

t_elem	*insert_in_list_is_new(t_list *s, int fd, struct timeval tempcmd, 
			       char *cmd)
{
  t_elem *new;
  t_elem *tmp;

  tmp = NULL;
  new = xmalloc(sizeof(t_elem));
  if (!new)
    return (NULL);
  new->fd = fd;
  new->prev = s->last;
  new->next = NULL;
  new->time = last_time(s, fd, tempcmd);
  new->cmd = xmalloc(strlen(cmd) + 1);
  new->cmd = strncpy(new->cmd, cmd, strlen(cmd));
  new->cmd[strlen(cmd)] = '\0';
  if (s->last)
    insert_in_list2(s, new, new->time, tmp);
  else
    {
      s->first = new;
      s->last = new;
    }
  return (new);
}

void			insert_in_list(t_list *s, int fd, char *cmd, 
				       t_env *env)
{
  t_elem		*new;
  struct timeval	tempcmd;
  int			temp;
  long			time_to_add;

  temp = check_time(s, cmd);
  if (temp == -1)
    return ;
  time_to_add = (temp * 10000 * env->delay);
  tempcmd.tv_sec = 0;
  tempcmd.tv_usec = 0;
  if (time_to_add/1000000 == 0)
    tempcmd.tv_usec = time_to_add;
  else
    {
      tempcmd.tv_sec = time_to_add / 1000000;
      tempcmd.tv_usec = (time_to_add - tempcmd.tv_sec*1000000);
    }
  new = insert_in_list_is_new(s, fd, tempcmd, cmd);
  if (new == NULL)
    return ;
}
