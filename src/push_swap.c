/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:18:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 16:23:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap_main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	int p;

	p = 0;

	(void)argc;
	(void)argv;
	initialize_basic_stack(&stack_a, DEFAULT_STACK_SIZE);
	initialize_basic_stack(&stack_b, DEFAULT_STACK_SIZE);

	print_stack(&stack_a);
	push(&stack_a, 1);
	push(&stack_a, 2);
	push(&stack_a, 3);
	print_stack(&stack_a);
	pop(&stack_a, &p);
	pop(&stack_a, &p);
	pop(&stack_a, &p);
	pop(&stack_a, &p);
	pop(&stack_a, &p);
	push(&stack_a, 3);
	push(&stack_a, 4);
	print_stack(&stack_a);
	destroy_stack(&stack_a);
	destroy_stack(&stack_b);

	return (0);
}
