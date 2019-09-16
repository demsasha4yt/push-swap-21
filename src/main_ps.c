/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:44:14 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 01:48:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_pushswap	*ps;

	a = NULL;
	b = NULL;
	ps = NULL;
	if (argc < 2)
		exit(0);
	initialize_stacks(argc, argv, &a, &b);
	ps = (t_pushswap*)malloc(sizeof(t_pushswap));
	ps->count = initialize_count(stack_get_length(a));
	ps->commands = NULL;
	ps->max_count = stack_get_length(a);
	ps->count_a = stack_get_length(a);
	ps->sorted_count = 0;
	ps->i = -1;
	if (stack_get_length(a) <= 3)
		basic_3sort(&a, &ps);
	else
		algo_quicksort(&a, &b, &ps);
	print_result(ps->commands);
	ps_destroy(&a, &b, &ps);
	return (0);
}
