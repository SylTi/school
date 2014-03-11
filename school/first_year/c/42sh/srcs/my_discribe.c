/*
** my_discribe.c for my_discribe in /u/epitech_2012/jaspar_y/cu/rendu/c/minishell/v1
** 
** Made by yoann jaspar
** Login   <jaspar_y@epitech.net>
** 
** Started on  Thu Feb 28 15:48:25 2008 yoann jaspar
** Last update Mon Apr 21 14:45:46 2008 yoann jaspar
*/

#include "sh.h"

void	my_discribe(char **environ)
{
  my_putstr("\nVous etes connecte sur : ");
  if (my_getenv("HOST", environ) != NULL)
    my_putstr_env(my_getenv("HOST", environ));
  my_putchar('\n');
  my_putstr("Vous etes connecte sous le nom : ");
  if (my_getenv("USER", environ) != NULL)
    my_putstr_env(my_getenv("USER", environ));
  my_putchar('\n');
  my_putstr("Machine de type : ");
  if (my_getenv("MACHTYPE", environ) != NULL)
    my_putstr_env(my_getenv("MACHTYPE", environ));
  my_putchar('\n');
  my_putstr("UNIX de type : ");
  if (my_getenv("OSTYPE", environ) != NULL)
    my_putstr_env(my_getenv("OSTYPE", environ));
  my_putstr(" \n\n");
}
