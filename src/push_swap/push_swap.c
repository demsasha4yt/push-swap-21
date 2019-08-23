/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:18:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 22:16:06 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_main(int argc, char **argv)
{
	t_pswap		pswap;
	int			ret;
	t_stack		tmp_stack;

	ret = 0;
	ret += initialize_push_swap(&pswap, argc, argv);
	if (ret != 0)
	{
		ft_printf("Error\n");
		exit(ret);
	}
	print_stack(&pswap.a);
	rotate(&pswap.a);
	print_stack(&pswap.a);
	rrotate(&pswap.a);
	print_stack(&pswap.a);
	copy_stack(&tmp_stack, &pswap.a);
	print_stack(&tmp_stack);
	destroy_stack(&tmp_stack);
	destroy_stack(&pswap.a);
	destroy_stack(&pswap.b);
	return (0);
}
