/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:18:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 14:02:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap_main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_stack *stack = create_stack(DEFAULT_STACK_SIZE);
	print_stack(stack);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	print_stack(stack);
	int a = pop(stack);
	print_stack(stack);
	ft_printf("%d", a);
	destroy_stack(stack);
	return (0);
}
