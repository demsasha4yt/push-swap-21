/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 07:02:33 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 11:28:01 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZE_H
# define VISUALIZE_H

# include "SDL.h"
# include "checker.h"

# define SCREEN_WIDTH 1080
# define TOOLBAR_WIDTH 200
# define SCREEN_HEIGHT 1300
# define STACK_A_X_START 20
# define STACK_A_X_END (SCREEN_WIDTH / 2 - 20)
# define STACK_A_Y_START 10
# define STACK_A_Y_END (SCREEN_HEIGHT - 40)
# define STACK_B_X_START (SCREEN_WIDTH / 2 + 20)
# define STACK_B_X_END (SCREEN_WIDTH - 20)
# define STACK_B_Y_START 10
# define STACK_B_Y_END (SCREEN_HEIGHT - 40)
# define CURRENT_X (SCREEN_WIDTH + 20)
# define CURRENT_Y (20)
# define COUNT_X (SCREEN_WIDTH + 20)
# define COUNT_Y (40)
# define DELAY_X (SCREEN_WIDTH + 20)
# define DELAY_Y (60)

typedef struct		s_visualizer
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*surface;
	SDL_Event		e;
	t_checker		*checker;
	t_stack			**a;
	t_stack			**b;
	t_history		*header;
	int				rect_height;
	int				rect_unit_width;
	int				value_min;
	int				value_max;
	int				count;
	int				run;
	int				visualizate;
	int				delay;
	int				arrowleft;
	int				arrowright;
}					t_visualizer;

void				init_sdl(t_visualizer *visualizer);
void				destroy_sdl(t_visualizer *visualizer);
void				handle_event(t_visualizer *visualizer);
void				render(t_visualizer *v, t_history *history);

#endif
