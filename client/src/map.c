/*
** map.c for  in /home/frasse_l/Projets/jetpack2Tek3
** 
** Made by loic frasse-mathon
** Login   <frasse_l@epitech.net>
** 
** Started on  Fri Jul  8 15:56:05 2016 loic frasse-mathon
** Last update Sat Jul  9 14:35:24 2016 loic frasse-mathon
*/

#include "client.h"

void	get_map_infos(char *buffer, t_map *map)
{
  int	i;
  char	size[10];
  int	x;

  i = 0;
  x = 0;
  while (buffer[i++] != '_')
    {
      if (buffer[i] == 'P')
  	{
  	  i++;
  	  while (isdigit(buffer[++i]))
  	    size[x++] = buffer[i];
  	  size[x] = '\0';
  	  map->width = atoi(size);
  	  i++;
  	  x = 0;
  	  while (isdigit(buffer[i]))
  	    size[x++] = buffer[i++];
  	  size[x] = '\0';
  	  map->height = atoi(size);
  	}
    }
}

char  *get_first_line(char *buffer, t_map *map, int *i)
{
  int   x;
  char  *str;

  x = 0;
  str = malloc(sizeof(char) * map->width + 1);
  while (x < map->width)
  {
    if (buffer[*i] == '_' || buffer[*i] == 'e' || buffer[*i] == 'c')
      str[x++] = buffer[*i];
    (*i)++;
  }
  str[x] = '\0';
  return (str);
}

void	get_map_data(char *buffer, t_map *map)
{
  char	**tab;
  int	i;
  int	j;
  int	x;

  i = 1;
  x = 0;
  tab = malloc(sizeof(char *) * map->height);
  tab[0] = get_first_line(buffer, map, &x);
  while (i < map->height)
    {
      j = 0;
      tab[i] = malloc(sizeof(char) * map->width);
      while (buffer[x] && j < map->width)
    	{
    	  tab[i][j] = buffer[x];
    	  j++;
    	  x++;
    	}
      i++;
    }
  map->data = tab;
}

void	display_map(char **map, int width, int height)
{
  int	i;
  int	j;

  i = 1;
  while (i < height)
    {
      j = 0;
      while (j <= width && i >= 0)
	{
	  printf("%c", map[i][j]);
	  j++;
	}
      printf("\n");
      i++;
    }
  printf("\n");
}

void	read_map(t_client *client)
{
  char	buffer[4096];
  int	nb;

  if (client->map)
    my_exit("Map already loaded.", 1);
  if (send(client->socket_cli , "MAP\n", strlen("MAP\n") , 0) < 0)
    my_exit("Send map failed", 1);
  if ((nb = recv(client->socket_cli, buffer , 4096 , 0)) < 0)
    my_exit("Recv map failed", 1);
  buffer[nb] = '\0';
  client->map = malloc(sizeof(t_map));

  get_map_infos(buffer, client->map);
  printf("%i\n%i\n", client->map->width, client->map->height);
  get_map_data(buffer, client->map);
}
