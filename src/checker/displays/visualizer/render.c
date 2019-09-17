/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 08:35:25 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 11:41:53 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualize.h"
#include "checker.h"

void	render_a(t_visualizer *v, t_history *history)
{
	int			i;
	SDL_Rect	rect;

	i = 0;
	while (i < history->a_cnt)
	{
		rect.x = STACK_A_X_START;
		rect.y = STACK_A_Y_START + i * (v->rect_height);
		rect.w = history->a_state[i] * v->rect_unit_width + 1;
		rect.h = v->rect_height;
		SDL_RenderFillRect(v->renderer, &rect);
		i++;
	}
}

void	render_b(t_visualizer *v, t_history *history)
{
	int			i;
	SDL_Rect	rect;

	i = history->b_cnt - 1;
	while (i >= 0)
	{
		rect.x = STACK_B_X_START;
		rect.y = STACK_B_Y_START + i * (v->rect_height);
		rect.w = history->b_state[i] * v->rect_unit_width + 1;
		rect.h = v->rect_height;
		SDL_RenderFillRect(v->renderer, &rect);
		i--;
	}
}

void	render(t_visualizer *v, t_history *history)
{
	SDL_SetRenderDrawColor(v->renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(v->renderer);
	SDL_SetRenderDrawColor(v->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	render_a(v, history);
	render_b(v, history);
	SDL_RenderPresent(v->renderer);
}
