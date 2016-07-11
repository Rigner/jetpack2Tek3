/*
** utils2.c for  in /home/frasse_l/Projets/jetpack2Tek3
** 
** Made by loic frasse-mathon
** Login   <frasse_l@epitech.net>
** 
** Started on  Mon Jul 11 10:15:35 2016 loic frasse-mathon
** Last update Mon Jul 11 15:16:39 2016 loic frasse-mathon
*/

#include "client.h"

int	my_atoi(char *str)
{
  int	i;
  int	n;
  int	sig;

  i = 0;
  n = 0;
  sig = 1;
  if (!str)
    my_exit("Invalid number.", 1);
  while (str[i])
    {
      if (i == 0 && str[i] == '-')
	sig = -1;
      else if (str[i] < '0' || str[i] > '9')
	my_exit("Invalid number.", 1);
      if (i != 0 || str[i] != '-')
	n = n * 10 + str[i] - '0';
      i++;
    }
  return (n * sig);
}

int	my_strcmp_case(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1 && str2 && str1[i] && str2[i] &&
	 tolower(str1[i]) == tolower(str2[i]))
    i++;
  return (tolower(str1[i]) - tolower(str2[i]));
}

void  set_window_pos(t_client *client)
{
  if (client->id == 1)
    putenv("SDL_VIDEO_WINDOW_POS=0,0");
  else
    putenv("SDL_VIDEO_WINDOW_POS=0,400");
}

int	get_nb_elem(t_client *client, char c)
{
  int	i;
  int	j;
  int	nb;

  i = 0;
  nb = 0;
  while (client->map && client->map->data && i < client->map->height)
    {
      j = 0;
      while (j < client->map->width)
	{
	  if (client->map->data[i][j] == c)
	    nb++;
	  j++;
	}
      i++;
    }
  return (nb);
}

double		my_atof(char *str)
{
  double	n;
  int		exp;
  int		ch;

  n = 0;
  exp = 0;
  ch = 0;
  while ((ch = *str++) && isdigit(ch))
    n = n * 10.0 + (ch - '0');
  if (ch == '.')
    while ((ch = *str++) && isdigit(ch))
      {
	n = n * 10.0 + (ch - '0');
	exp = exp - 1;
      }
  while (exp > 0)
    {
      n *= 10.0;
      exp--;
    }
  while (exp < 0)
    {
      n *= 0.1;
      exp++;
    }
  return (n);
}
