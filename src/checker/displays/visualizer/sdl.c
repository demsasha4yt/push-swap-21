/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 08:33:18 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 11:42:15 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"
#include "checker.h"

void	destroy_sdl(t_visualizer *visualizer)
{
	visualizer->run = 0;
	SDL_DestroyWindow(visualizer->window);
	SDL_DestroyRenderer(visualizer->renderer);
	SDL_Quit();
}

void	init_sdl(t_visualizer *visualizer)
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
		if ((visualizer->window = SDL_CreateWindow("Push Swap Visualizer",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH + TOOLBAR_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN)))
			if ((visualizer->renderer = SDL_CreateRenderer(
				visualizer->window, -1, SDL_RENDERER_ACCELERATED)))
				return ;
	ft_printf("%s\n", SDL_GetError());
	destroy_sdl(visualizer);
	default_display(visualizer->checker, visualizer->a, visualizer->b);
}

void	handle_key_down(t_visualizer *visualizer, SDL_Keycode key)
{
	if (key == SDLK_f)
		visualizer->visualizate = (visualizer->visualizate) ? 0 : 1;
	if (key == SDLK_LEFT)
		visualizer->arrowleft = 1;
	if (key == SDLK_RIGHT)
		visualizer->arrowright = 1;
	if (key == SDLK_MINUS)
		if (visualizer->delay >= 10)
			visualizer->delay -= 10;
	if (key == SDLK_PLUS <= 990)
		visualizer->delay += 10;
	if (key == SDLK_ESCAPE)
	{
		visualizer->checker->history = visualizer->header;
		render(visualizer, visualizer->checker->history);
	}
}

void	handle_key_up(t_visualizer *visualizer, SDL_Keycode key)
{
	if (key == SDLK_LEFT)
		visualizer->arrowleft = 0;
	if (key == SDLK_RIGHT)
		visualizer->arrowright = 0;
}

void	handle_event(t_visualizer *visualizer)
{
	if (visualizer->e.type == SDL_QUIT)
		visualizer->run = 0;
	if (visualizer->e.type == SDL_KEYDOWN)
		handle_key_down(visualizer, visualizer->e.key.keysym.sym);
	if (visualizer->e.type == SDL_KEYUP)
		handle_key_up(visualizer, visualizer->e.key.keysym.sym);
}
