/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:58:54 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 19:33:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_push_swap(t_pswap *pswap, int argc, char **argv)
{
	int ret;

	pswap->debug_mode = 0;
	ret = 0;
	ret += pfuncs_initialize(pswap);
	ret += initialize_basic_stack(&pswap->a, DEFAULT_STACK_SIZE);
	ret += initialize_basic_stack(&pswap->b, DEFAULT_STACK_SIZE);
	ret += initialize_args(pswap, argc, argv);
	return (ret);
}

int	initialize_args(t_pswap *pswap, int argc, char **argv)
{
	int idx;

	idx = 0;
	if (argc < 2)
		return (8);
	while (++idx < argc)
	{
		if (!is_valid_arg(argv[idx]))
			return (16);
		push(&pswap->a, ft_atoi(argv[idx]));
	}
	return (0);
}

