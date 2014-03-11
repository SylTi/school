/*
** get_next_line.h for get next line in /u/epitech_2012/ampe_e/cu/rendu/c/get_next_line
**
** Made by emilien ampe
** Login   <ampe_e@epitech.net>
**
** Started on  Mon Nov 19 11:30:01 2007 emilien ampe
** Last update Fri May 23 13:24:16 2008 emilien ampe
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define BUFF_READ 2048
# define BUFF_SIZE 4096

typedef struct s_var
{
  char		*line;
  int		j;
  int		ct2;
  int		ret;
  int		ret2;
  int		pos;
  char		buffer[BUFF_READ];
  int		inte;
}		t_var;

int		xread(int d, void *buf, size_t nbytes, t_var *s);
char		*get_next_line(const int fd);
void		my_clear(char *buff);
void		get_result(t_var *s);

#endif
