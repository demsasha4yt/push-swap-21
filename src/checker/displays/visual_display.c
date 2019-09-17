/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 07:04:26 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 11:20:43 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "visualize.h"

void	count_rectandle_units(t_visualizer *visualizer)
{
	visualizer->rect_height =
		(STACK_A_Y_END - STACK_A_Y_START) / stack_get_length(*visualizer->a)
			+ 1;
	visualizer->value_min = stack_get_min(*visualizer->a);
	visualizer->value_max = stack_get_max(*visualizer->a);
	visualizer->rect_unit_width =
		(STACK_A_X_END - STACK_A_X_START) / ft_abs((visualizer->value_max -
			visualizer->value_min)) / ft_abs(visualizer->value_max -
				visualizer->value_min) + 1;
}

void	initialize_vizualizer(t_visualizer *visualizer)
{
	t_history *ptr;

	visualizer->run = 1;
	visualizer->visualizate = 0;
	visualizer->arrowleft = 0;
	visualizer->arrowright = 0;
	visualizer->delay = 100;
	visualizer->count = 0;
	visualizer->header = visualizer->checker->history;
	ptr = visualizer->checker->history;
	while (ptr)
	{
		visualizer->count++;
		ptr = ptr->next;
	}
}

void	do_tick(t_visualizer *v)
{
	while (SDL_PollEvent(&v->e))
		handle_event(v);
	if (v->visualizate && v->checker->history->next != NULL)
	{
		render(v, v->checker->history);
		if (v->checker->history->next == NULL)
			v->visualizate = 0;
		else
			v->checker->history = v->checker->history->next;
	}
	if (!v->visualizate && v->arrowright && v->checker->history->next != NULL)
	{
		v->checker->history = v->checker->history->next;
		render(v, v->checker->history);
	}
	if (!v->visualizate && v->arrowleft && v->checker->history->prev != NULL)
	{
		v->checker->history = v->checker->history->prev;
		render(v, v->checker->history);
	}
	SDL_Delay(v->delay);
}

void	visual_display(t_checker *checker, t_stack **a, t_stack **b)
{
	t_visualizer visualizer;

	visualizer.a = a;
	visualizer.b = b;
	visualizer.checker = checker;
	initialize_vizualizer(&visualizer);
	count_rectandle_units(&visualizer);
	ft_printf("%d %d %d %d", visualizer.rect_height, visualizer.rect_unit_width,
				visualizer.value_min, visualizer.value_max);
	init_sdl(&visualizer);
	render(&visualizer, visualizer.checker->history);
	while (visualizer.run)
	{
		do_tick(&visualizer);
	}
	visualizer.checker->history = visualizer.header;
	destroy_sdl(&visualizer);
}
