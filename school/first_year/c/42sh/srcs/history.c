/*
** history.c for history in /u/epitech_2012/jaspar_y/public/42sh/bultins
** 
** Made by sylvain tissier
** Login   <tissie_s@epitech.net>
** 
** Started on  Wed May 28 18:40:50 2008 sylvain tissier
** Last update Thu Jun 12 19:27:30 2008 sylvain tissier
*/

#include "sh.h"

#define UP 0
#define DOWN 1

char	**get_history()
{
  char	**histo;
  char	*line;
  int	i;
  int	fd;
  
  histo = xmalloc(sizeof(histo) * MAX_HISTO + 1);
  i = 0;
  fd = open(HI, O_RDONLY | O_CREAT);
  while ((line = get_next_line(fd)) != NULL && i < MAX_HISTO)
    histo[i++] = strdup(line);
  histo[i] = NULL;
  xclose(fd);
  free(line);
  return (histo);
}

char	**add_line_histo(char *line, char **histo)
{
  char	**ret;
  int	a;

 
  ret = xmalloc(sizeof(*histo) + 2);
  a = count_tab(histo); 
  ret = copy_tab(histo, ret);
  ret[a + 1] = strdup(line);
  /*  xwrite(fd, line, strlen(line));*/
  ret[a + 2] = '\0';
  return (ret);
}

void	add_histo_to_file(char **histo)
{
  int	fd;
  int	i;

  fd = xopen(HI, O_CREAT | O_TRUNC | O_WRONLY);
  i = 0;
  while (histo[i] != NULL)
    {
      fprintf(fd, "%s\n", histo[i]);
      i++;
    }
  xclose(fd);
  return ;
}

t_bultin	*histo_up(t_bultin *bult)
{
  int	a;
  int	b;
  
  a = count_tab(bult->histo);
  if (bult->flag_histo <= a)
    {
      if (bult->flag_histo != -1)
	{
	  b = a - bult->flag_histo;
	  bult->flag_histo = b;
	  return (bult);
	}
      else
	{
	  bult->flag_histo = a;
	  return (bult);
	}
    }
  return (NULL);
}

t_bultin	*histo_down(t_bultin *bult)
{
  int	a;
  
  a = count_tab(bult->histo);
  if ((bult->flag_histo != -1) && (bult->flag_histo != a))
    {
      bult->flag_histo--;
      return (bult);
    }
  return (NULL);
}

char		*ret_histo(t_bultin *bult)
{
  if (UP)
    {
      bult = histo_up(bult);
      return (bult->histo[bult->flag_histo]);
    }
  if (DOWN)
    {
      bult = histo_down(bult);
      return (bult->histo[bult->flag_histo]);
    }
}
