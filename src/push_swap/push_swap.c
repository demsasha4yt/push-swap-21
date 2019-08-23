/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:18:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 18:53:06 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_main(int argc, char **argv)
{
	t_pswap pswap;

	(void)argc;
	(void)argv;
	if (initialize_push_swap(&pswap))
		return (1);

	print_stack(&pswap.a);
	push(&pswap.a, 1);
	push(&pswap.a, 2);

	print_stack(&pswap.a);
	print_stack(&pswap.b);
	ps_exec(&pswap, PB_FUNC);
	print_stack(&pswap.a);
	print_stack(&pswap.b);
	destroy_stack(&pswap.a);
	destroy_stack(&pswap.b);
	return (0);
}

int	initialize_push_swap(t_pswap *pswap)
{
	int ret;

	ret = 0;
	ret += pfuncs_initialize(pswap);
	ret += initialize_basic_stack(&pswap->a, DEFAULT_STACK_SIZE);
	ret += initialize_basic_stack(&pswap->b, DEFAULT_STACK_SIZE);
	return (ret);
}
