/*
** verif_ref.c for verif_ref in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 15:54:44 2008 yoann jaspar
** Last update Wed Apr 23 15:33:54 2008 yoann jaspar
*/

#include "sh.h"

int	verif_ref(char **ref)
{
  int	i;

  i = 0;
  while (ref[i] != NULL)
    i++;
  return (i);
}
