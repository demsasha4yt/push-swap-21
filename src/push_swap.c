/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:18:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 16:32:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			p;

	p = 0;
	(void)argc;
	(void)argv;
	if (initialize_basic_stack(&stack_a, DEFAULT_STACK_SIZE))
		return (1);
	if (initialize_basic_stack(&stack_b, DEFAULT_STACK_SIZE))
		return (1);
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);
	return (0);
}
