/*
** my_read.c for my_read in /u/epitech_2012/jaspar_y/cu/rendu/c/42sh/src
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Mon Apr 21 14:22:55 2008 yoann jaspar
** Last update Fri Jun 13 13:27:52 2008 yoann jaspar
*/

#include "sh.h"

void	my_read(t_sh *sh)
{
  char	buf[BUFF_MIN];
  int	i;
  int	lol;

  i = 0;
  my_putstr("\e[0m");
  if (sh->cmd)
    free(sh->cmd);
  my_prompt(environ, 1, sh->bult->prompt);
  sh->cmd = xmalloc(sizeof(char) * BUFF_DEF);
  sh->pipe = 0;
  while ((lol = xread(STDIN_FILENO, buf, BUFF_MIN)) > 0)
    {
      sh->pipe = 0;
      if (sh->cmd == NULL)
	sh->cmd = xmalloc(sizeof(char) * BUFF_DEF);
      buf[lol] = '\0';
      if (!check_term_cap(sh, buf, &i))
      {
	if (buf[0] == '\n')
	{
	  sh->cmd[i] = '\0';
	  my_putchar('\n');
	  if (strlen(sh->cmd) >= 1)
	  {
	    sh->cmd = trait_str(sh->cmd);
	    if (!check_synt(sh->cmd))
	      trait_cmd(sh);
	  }
	  free(sh->cmd);
	  sh->cmd = NULL;
	  i = 0;
	  buf[0] = '\0';
	  my_prompt(environ, 1, sh->bult->prompt);
	}
	else
	  sh->cmd = add_str_end(sh->cmd, buf, &i, 1);
      }
    }
}

char	*add_str_end(char *cmd, char *buff, int *len, int print)
{
  char	*new_ptr;
  int	i;
  int	j;

  j = 0;
  i = 0;
  if (buff)
    {
      if (print)
	my_putstr(buff);
      if (*len + strlen(buff) < BUFF_DEF)
	{
	  while (buff[i] != '\0')
	    {
	      cmd[*len] = buff[i++];
	      *len += 1;
	    }
	}
      else
	{
	  if (!(new_ptr = malloc((strlen(cmd) + strlen(buff) + 1) * sizeof(*new_ptr))))
	    aff_error("Couldn't malloc\n");
	  while (cmd[i])
	    new_ptr[i] = cmd[i++];
	  new_ptr[i] = '\0';
	  j = 0;
	  while (buff[j])
	    {
	      new_ptr[i++] = buff[j++];
	      *len += 1;
	    }
	  free(cmd);
	  cmd = new_ptr;
	}
    }
  return (cmd);
}
