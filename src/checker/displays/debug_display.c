/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 03:51:41 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 06:23:17 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_stacks(t_history *history)
{
	int i;

	i = 0;
	ft_printf("( %s )\n", history->cmd);
	ft_printf("%11c%4c|%11c\n", 'A', ' ', 'B');
	while (i < history->a_cnt || i < history->b_cnt)
	{
		if (i < history->a_cnt && i < history->b_cnt)
			ft_printf("%11d%4c|%11d\n", history->a_state[i], ' ',
				history->b_state[i]);
		else if (i < history->a_cnt)
			ft_printf("%11d%4c|%11c\n", history->a_state[i], ' ', ' ');
		else if (i < history->b_cnt)
			ft_printf("%11c%4c|%11d\n", ' ', ' ', history->b_state[i]);
		i++;
	}
	ft_printf("%.10c\n", '-');
}

void		debug_display(t_checker *checker, t_stack **a, t_stack **b)
{
	t_history *history;

	history = checker->history;
	while (history)
	{
		print_stacks(history);
		history = history->next;
	}
	if (is_all_sorted(*a) && stack_get_length(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("Error\n");
}
