/*
** my_displayer.c for  in /home/frasse_l/Projets/jetpack2Tek3
** 
** Made by loic frasse-mathon
** Login   <frasse_l@epitech.net>
** 
** Started on  Fri Jul  8 15:58:11 2016 loic frasse-mathon
** Last update Fri Jul  8 16:02:46 2016 loic frasse-mathon
*/

#include "client.h"

int		my_display(t_client *client)
{
  SDL_Surface	*ecran;

  ecran = NULL;
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(client->map->width * 30,
			   client->map->height * 30, 32, SDL_RESIZABLE);
  if (ecran == NULL)
    {
      fprintf(stderr, "Impossible de charger le mode vidéo : %s\n",
	      SDL_GetError());
      exit(EXIT_FAILURE);
    }
  SDL_WM_SetCaption("JetPack2Tek3", NULL);
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 102));
  SDL_Flip(ecran);
  my_pause();
  SDL_Quit();

  return (EXIT_SUCCESS);
}

void		my_pause()
{
  int		continuer;
  SDL_Event	event;

  continuer = 1;
  while (continuer)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	continuer = 0;
    }
}