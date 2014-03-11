/*
** get_next_line.c for  in /u/epitech_2012/bonsal_n/cu/rendu/my_getnextline
** 
** Made by nicolas bonsall
** Login   <bonsal_n@epitech.net>
** 
** Started on  Wed Feb  6 16:24:35 2008 nicolas bonsall
** Last update Thu Jun 12 19:28:11 2008 sylvain tissier
*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"

#define __GNL_BUFF_SIZE__ 1024

static char buff[__GNL_BUFF_SIZE__];
static int in_buf = 0;
static int start;

static int read_from_file(int fd)
{
  in_buf = read(fd, buff, __GNL_BUFF_SIZE__);
  start = 0;
  return (in_buf);
}

static char *add_to_line(char *line, int cur)
{
  char *new_elem;
  int old_len;

  if (!(new_elem = malloc((old_len = (line?strlen(line):0)) + cur + 1)))
    {
      my_putstr("func add_to_line : erreur de malloc\n");
      return (0);
    }
  strcpy(new_elem, line?line:"");
  memcpy(new_elem + old_len, buff + start, cur);
  new_elem[old_len + cur] = 0;
  if (line)
   free(line);
  start += cur + 1;
  return (new_elem);
}

char *get_next_line(int fd)
{
  int cur;
  char *line;

  for (line = 0, cur = 0; ;cur++)
    {
      if (start >= in_buf)
	{
	  if (!read_from_file(fd))
	    return (line);
	  cur = 0;
	}
      if (buff[start + cur] == '\n')
	{
	  line = add_to_line(line, cur);
	  return (line);
	}
      if (start + cur == in_buf - 1)
	line = add_to_line(line, cur + 1);
    }
}
