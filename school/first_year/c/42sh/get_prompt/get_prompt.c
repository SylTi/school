/*
** get_prompt.c for colle2 in /u/all/jaspar_y/public/collissimo
** 
** Made by jean-philippe rey
** Login   <rey_e@epitech.net>
** 
** Started on  Fri May 16 21:26:13 2008 jean-philippe rey
** Last update Wed May 21 15:15:00 2008 yoann jaspar
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "colle.h"

#define RPROMPT 2
#define PROMPT 4

t_prompt	*cut_str(char *str, int mod, t_prompt *prompt)
{
  char	*ptr;

  ptr = str;
  while (*ptr && *ptr != '=')
    ptr++;
  if (mod == PROMPT)
    prompt->prompt = strdup(++ptr);
  else if (mod == RPROMPT)
    prompt->rprompt = strdup(++ptr);
  return (prompt);
}

void	get_prompt(t_prompt *prompt)
{
  char	*str;

  prompt->fd = xopen("/u/all/jaspar_y/cu/rendu/c/42sh/conf.txt", O_RDWR);
  prompt->prompt = 0;
  prompt->rprompt = 0;
  while ((str = get_next_line(prompt->fd)))
    {
      if (matchn("set prompt", str) == 1)
	prompt = cut_str(str, PROMPT, prompt);
      else if (matchn("set rprompt", str) == 1)
	prompt = cut_str(str, RPROMPT, prompt);
      free(str);
    }
  xlseek(prompt->fd, 0, SEEK_SET);
  if (prompt->prompt == 0 || prompt->rprompt == 0)
    {
      my_putstr("please define prompt in .mytcshrc\n");
      exit(-1);
    }
}
