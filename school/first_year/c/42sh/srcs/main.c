/*
** main.c for main in /u/epitech_2012/jaspar_y/cu/rendu/c/42sh/src
**
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
**
** Started on  Mon Apr 21 14:21:05 2008 yoann jaspar
** Last update Fri Jun 13 14:28:32 2008 nicolas bonsall
*/

#include "sh.h"

int	main(void)
{
  t_sh	*sh;

  if (!isatty(STDIN_FILENO))
    {
      my_putstr("Broken Pipe\n");
      return (-1);
    }
  sh = xmalloc(sizeof(t_sh));
  sh->hard_path = xmalloc(sizeof(char) * 200);
  recup_term(&(sh->old_term));
  no_canonical_mode(sh->old_term);
  init_keys(&(sh->cst));
  sh->prev_dir = NULL;
  if (my_getenv("PATH", environ) == NULL)
    sh->hard_path = "PATH=/usr/school/sbin:/usr/school/bin:/usr/local/sbin:/usr/local/bin:/usr/bin:/usr/sbin:/sbin:/bin";
  else
    sh->hard_path = my_getenv("PATH", environ);
  sh->home = xmalloc(sizeof(char) * 200);
  if (my_getenv("HOME", environ) == NULL)
    sh->home = "./";
  else
    sh->home = my_getenv2("HOME", environ);
  my_discribe(environ);
  sh->bult = get_conf();
  sh->bult->histo = get_history();
  my_read(sh);
  restore_mode(sh->old_term);
  return (0);
}
