/*
** main.c for main.c in /u/epitech_2012/jaspar_y/public/52sh/autocomlet
** 
** Made by maxime dumez
** Login   <dumez_m@epitech.net>
** 
** Started on  Fri May 30 17:58:20 2008 maxime dumez
** Last update Thu Jun 12 17:05:55 2008 maxime dumez
*/

#include "sh.h"

void	auto_put_in_list(t_auto **list_possib, struct dirent *actual_dat)
{
  t_auto	*snext;

  if (!(snext = malloc(sizeof(*snext))))
    return ;
  snext->data = actual_dat;
  snext->next = *list_possib;
  *list_possib = snext;
}

t_auto	*make_my_possib_list(char *dir_name)
{
  DIR	*dir_fd;
  struct dirent *actual_dat;
  t_auto *list_possib;

  list_possib = NULL;
  dir_fd = opendir(dir_name);
  while ((actual_dat = readdir(dir_fd)))
    auto_put_in_list(&list_possib, actual_dat);
  closedir(dir_fd);
  return (list_possib);
}

char	*check_and_aff_possib(t_auto *list_possib, char *str)
{
  char	tmp;
  int	len;
  int	nb_of_solution;
  char	*last_soluc;

  last_soluc = NULL;
  nb_of_solution = 0;
  len = strlen(str);
  while (list_possib)
    {
      if (strlen(list_possib->data->d_name) >= len)
	{
	  tmp = list_possib->data->d_name[len];
	  list_possib->data->d_name[len] = '\0';
	  if (strcmp(list_possib->data->d_name, str) == 0)
	    {
	      list_possib->data->d_name[len] = tmp;
	      my_putstr(list_possib->data->d_name);
	      my_putchar('\t');
	      last_soluc = strdup(list_possib->data->d_name);
	      nb_of_solution++;
	    }
	  else
	    list_possib->data->d_name[len] = tmp;
	}
      list_possib = list_possib->next;
    }
  if (nb_of_solution > 1)
    my_putchar('\n');
  if (nb_of_solution == 1)
    return (last_soluc);
  else
    return (NULL);
}

char	*choose_path(char *str)
{
  int	rang;
  int	i;
  char	*path_search;

  i = 0;
  rang = 0;
  while (str[i] && str[i] == ' ')
    i++;
  while (str[i])
    {
      if (str[i] == ' ')
	{
	  while (str[i] && str[i] == ' ')
	    i++;
	  rang++;
	}
      i++;
    }
  if (!rang)
    path_search = strdup("/bin");
  else
    {
      while (i > 0 && str[i] != ' ')
	i--;
      path_search = find_slash(&str[i]);
    }
  return (path_search);
}

char	*find_slash(char *str)
{
  int	poz;
  int	i;
  char	tmp;
  char	*path_find;

  i = 0;
  poz = 0;
  while (str[i])
    {
      if (str[i] ==  '/')
	poz = i;
      i++;
    }
  if (!poz)
    path_find = strdup("./");
  else
    {
      tmp = str[poz];
      str[poz] = '\0';
      path_find = strdup(str);
      str[poz] = tmp;
    }
  return (path_find);
}

char	*auto_complet(char *str)
{
  t_auto	*list_possib;
  char		*alone_possib;
  int		i;
  int		j;
  char		*path_search;
  char		*final_str;

  i = 0;
  path_search = choose_path(str);
  list_possib = make_my_possib_list(path_search);
  free(path_search);
  while (str[i])
    i++;
  while (str[i] != ' ' && i > 0)
    i--;
  if (str[i] == ' ')
    i++;
  alone_possib = check_and_aff_possib(list_possib, &str[i]);
  j = 0;
  if (alone_possib)
    {
      while (alone_possib[j] == str[i + j])
	j++;
      final_str = strdup(&alone_possib[j]);
      free(alone_possib);
    }
  else
    final_str = NULL;
  return (final_str);
}
