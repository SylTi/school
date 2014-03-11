/*
** my_exec_cmd_2.c for my_exec_cmd in /u/epitech_2012/jaspar_y/public/62sh
** 
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
** 
** Started on  Sun Jun  1 00:39:45 2008 maxime dumez
** Last update Sun Jun  1 00:40:19 2008 maxime dumez
*/

#include "sh.h"

int	my_access(char *file)
{
  if (!access(file, X_OK))
    return (1);
  return (0);
}
