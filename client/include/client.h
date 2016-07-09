/*
** client.h for  in /home/frasse_l/Projets/jetpack2Tek3
** 
** Made by loic frasse-mathon
** Login   <frasse_l@epitech.net>
** 
** Started on  Fri Jul  8 15:51:20 2016 loic frasse-mathon
** Last update Sat Jul  9 14:39:27 2016 loic frasse-mathon
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <ctype.h>
# include <SDL/SDL.h>

# define SIZE		19

enum			tile_type
  {
    EMPTY,
    COIN,
    LASER
  };

typedef struct		s_str
{
  char			*str;
  struct s_str		*next;
}			t_str;

typedef struct		s_map
{
  int			width;
  int			height;
  char			**data;
}			t_map;

typedef struct 		s_client
{
  char *		ip;
  int 			port;
  int 			socket_cli;
  int 			id;
  t_map			*map;
} 			t_client;

void 				my_pause();
int 				my_display();
void				display_map(char **, int, int);
void 				my_exit(char *, int);
int 				digit_to_int(char);
void 				get_client_id(t_client *);
void				read_map(t_client *);

#endif /* !CLIENT_H_ */
