/*
** cpy_to_tcsh.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:24:43 2008 jean-philippe rey
** Last update Fri May 16 21:40:47 2008 jean-philippe rey
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "colle.h"

int		len_list(t_list *pr)
{
  int		len;

  len = 0;
  pr->list = pr->first;
  while (pr->list)
    {
      len++;
      pr->list = pr->list->next;
    }
  return (len);
}

char	*list_to_str(t_list *list)
{
  int	i;
  char	*str;

  i = 0;
  str = xmalloc(sizeof(*str) * (len_list(list) + 1));
  list->list = list->first;
  while (list->list)
    {
      str[i] = list->list->c;
      list->list = list->list->next;
      i++;
    }
  str[i] = '\0';
  return (str);
}

char	*put_in(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    str[i++] = 0;
  return (str);
}

void	write_in(char *pr, char *rpr, int fd)
{
  char	c;

  c = '"';
  xwrite(fd, "\n", 1);
  xwrite(fd, "set prompt=", 11);
  xwrite(fd, &c, 1);
  xwrite(fd, pr, strlen(pr));
  xwrite(fd, &c, 1);
  xwrite(fd, "\n", 1);
  xwrite(fd, "set rprompt=", 12);
  xwrite(fd, &c, 1);
  xwrite(fd, rpr, strlen(rpr));
  xwrite(fd, &c, 1);
  xwrite(fd, "\n", 1);
}

void	cpy_to_tcsh(t_allpr *lpr)
{
  char	*pr;
  char	*rpr;
  char	*str;

  pr = list_to_str(lpr->pr);
  rpr = list_to_str(lpr->rpr);
  while ((str = get_next_line(lpr->pr->fd)))
    {
      if (matchn("set prompt", str) == 1)
	write(lpr->pr->fd, "/r", 1);
      else if (matchn("set rprompt", str) == 1)
	str = put_in(str);
      free(str);
    }
  write_in(pr, rpr, lpr->pr->fd);
  close(lpr->pr->fd);
  free(pr);
  free(rpr);
}
