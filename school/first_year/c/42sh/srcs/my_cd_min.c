/*
** my_cd_min.c for cd moins in /u/epitech_2012/jaspar_y/public/52sh
** 
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
** 
** Started on  Fri May 30 16:07:30 2008 maxime dumez
** Last update Fri May 30 16:47:11 2008 maxime dumez
*/

#include "sh.h"

void	save_the_last(t_sh *sh, char *str)
{
  if (sh->prev_dir)
    free(sh->prev_dir);
  sh->prev_dir = str;
}

void	its_cd_moins(t_sh *sh, char **str)
{
  if (sh->prev_dir)
    {
      if (*str)
	free(*str);
      *str = strdup(sh->prev_dir);
    }
}
