/*
** Lemin V.2.0 /u/epitech_2012/bonsal_n/cu/rendu/c/lem-in
** 
** Made by nicolas bonsall
** Login   <bonsal_n@epitech.net>
** 
** Started on  Thu Apr  3 21:38:44 2008 nicolas bonsall
** Last update Fri Jun 13 14:17:46 2008 nicolas bonsall
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#ifndef __MY_H__
#define __MY_H__

int     my_put_nbr(int nb);
void	my_putstr(char *str);
int     my_getnbr(char *str);
int     my_strlen(char *str);
int	my_strncmp(char *s1, char *s2, int n);

void	*xmalloc(int size);

/*
static int	read_from_file(int fd);
static char	*add_to_line(char *line, int cur);
*/
char		*get_next_line(int fd);

#endif
