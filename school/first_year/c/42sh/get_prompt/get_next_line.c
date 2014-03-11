/*
** get_next_line.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:25:53 2008 jean-philippe rey
** Last update Fri May 16 21:40:31 2008 jean-philippe rey
*/

#include <string.h>
#include <stdlib.h>
#include "colle.h"
#define BUFF_SIZE 1

static char     buff[BUFF_SIZE];
static int      in_buf = 0;
static int      start;

static int      read_from_file(int fd)
{
  in_buf = xread(fd, buff, BUFF_SIZE);
  start = 0;
  return (in_buf);
}

static char     *add_to_line(char *line, int cur)
{
  char	*new;
  int	old_len;

  new = xmalloc((old_len=(line ? strlen(line) : 0)) + cur + 1);
  if (line)
    {
      memcpy(new, line, old_len);
      free(line);
    }
  memcpy(new + old_len, buff + start, cur);
  new[old_len + cur] = 0;
  start += cur + 1;
  return (new);
}

void	get_next_line_init(void)
{
  memset(buff, 0, strlen(buff));
  in_buf = 0;
  start = 0;
}

char		*get_next_line(int fd)
{
  int		cur;
  char		*line;

  for (line = 0, cur = 0; ; cur++)
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
      if (start + cur == in_buf-1)
        line = add_to_line(line, cur + 1);
    }
}

void	get_next_line_reset(void)
{
  in_buf = 0;
}
