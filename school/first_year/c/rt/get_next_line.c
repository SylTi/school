/*
** get_next_line.h for get next line in /u/epitech_2012/ampe_e/cu/rendu/c/get_next_line
**
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
**
** Started on  Mon Nov 19 11:30:01 2007 emilien ampe
** Last update Fri May 23 13:22:47 2008 emilien ampe
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*get_read(t_var *s, int fd)
{
  int		i;

  if (s->pos == 0 || s->pos == BUFF_READ)
    {
      i = 0;
      while (i < BUFF_READ)
	s->buffer[i++] = '\0';
      s->pos = 0;
      if(!(xread(fd, s->buffer, BUFF_READ, s)))
	{
	  s->line[s->j] = '\0';
	  s->ret = 1;
	  return (s->line);
	}
    }
  return (NULL);
}

void		*xmalloc(size_t size)
{
  int		*i;

  i = malloc(size);
  if (i == NULL)
    exit (1);
  return (i);
}

int		xread(int d, void *buf, size_t nbytes, t_var *s)
{
  int		ret;
  static int	ct = 0;

  ret = read(d, buf, nbytes);
  if (ret <= 0)
    {
      if (ct == 1)
	{
	  free(s->line);
	  return (0);
	}
      else
	{
	  ct++;
	  return (0);
	}
    }
  return (ret);
}

void		get_result(t_var *s)
{
  if (s->buffer[s->pos++] == '\n')
    {
      s->line[s->j] = '\0';
      s->ret2 = 1;
      return ;
    }
  else
    if (s->buffer[s->pos] == '\0' || s->j != BUFF_SIZE)
      {
	s->pos = 0;
	if(s->j == BUFF_SIZE)
	  {
	    s->line[s->j] = '\0';
	    s->ret2 = 1;
	    return ;
	  }
      }
}

char		*get_next_line(const int fd)
{
  static t_var		s;

  if (s.inte == 1)
    return (NULL);
  s.j = 0;
  s.line = xmalloc(sizeof(s.line) * (BUFF_SIZE + 1));
  while (s.j < BUFF_SIZE)
    {
      get_read(&s, fd);
      if (s.ret == 1)
	{
	  s.inte = 1;
	  return (s.line);
	}
      while (s.buffer[s.pos] != '\n' && s.buffer[s.pos] != '\0')
	s.line[s.j++] = s.buffer[s.pos++];
      get_result(&s);
      if (s.ret2 == 1)
	{
	  s.ret2 = 0;
	  return (s.line);
	}
    }
  return (NULL);
}
