/*
** check_term_cap.c for check_term_cap in /u/epitech_2012/jaspar_y/public/62sh/druidousback
** 
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
** 
** Started on  Wed Jun 11 17:32:34 2008 maxime dumez
** Last update Thu Jun 12 16:37:30 2008 maxime dumez
*/

#include "sh.h"

void	backspace_gest(t_sh *sh, int *len)
{
  int	i;
  
  i = 0;
  my_putchar('\r');
  my_prompt(environ, 0, sh->bult->prompt);
  while (i < *len + 1)
    {
      my_putchar(' ');
      i++;
    }
  my_putchar('\r');
  my_prompt(environ, 0, sh->bult->prompt);  
  if (*len > 0)
    {
      *len -= 1;
      sh->cmd[*len] = '\0';
      my_putstr(sh->cmd);
    }
}

int	check_backchar(t_sh *sh, char *buff, int *len)
{
  int	ret;
  char	*tmp;

  ret = 0;
  if (buff[0] == '\t')
    {
      my_putchar('\n');
      tmp = auto_complet(sh->cmd);
      if (tmp)
	sh->cmd = add_str_end(sh->cmd, tmp, len, 0);
      my_prompt(environ, 1, sh->bult->prompt);
      my_putstr(sh->cmd);
      ret++;
    }
  if (strcmp(buff, sh->cst->kbstr) == 0)
    {
      backspace_gest(sh, len);
      ret++;
    }  
  return (ret);
}

int	check_multichar(t_sh *sh, char *buff, int *len)
{
  int	ret;

  ret = 0;
  if (buff[0] == sh->cst->kustr[0] && buff[2] == sh->cst->kustr[2])
      ret++;
  else if (buff[0] == sh->cst->kdstr[0] && buff[2] == sh->cst->kdstr[2])
      ret++;
  else if (buff[0] == sh->cst->krstr[0] && buff[2] == sh->cst->krstr[2])
      ret++;
  else if (buff[0] == sh->cst->klstr[0] && buff[2] == sh->cst->klstr[2])
      ret++;
  return (ret);
}

int	check_term_cap(t_sh *sh, char *buff, int *len)
{
  int	ret;

  ret = 0;
  if (!buff)
    return (ret);
  if (strlen(buff) > 1)
    {
      ret += check_multichar(sh, buff, len);
      ret++;
    }
  else
    ret += check_backchar(sh, buff, len);
  return (ret);
}
