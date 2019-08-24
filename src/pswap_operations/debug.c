/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 22:41:03 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 14:53:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		debug_print_stacks(t_pswap *pswap)
{
	int i;

	i = pswap->a.length;
	if (pswap->b.length > i)
		i = pswap->b.length;
	ft_printf("%6s | %6s\n", "A", "B");
	ft_printf("---------------\n");
	while (--i > -1)
	{
		if (i < pswap->a.length && i < pswap->b.length)
			ft_printf("%6d | %6d\n", pswap->a.values[i], pswap->b.values[i]);
		else if (i < pswap->a.length)
			ft_printf("%6d | %6c\n", pswap->a.values[i], ' ');
		else if (i < pswap->b.length)
			ft_printf("%6c | %6d\n", ' ', pswap->b.values[i]);
	}
	ft_printf("---------------");
	return (0);
}

int		display_error_and_exit(int error_code)
{
	write(2, "Error\n", 6);
	exit(error_code);
	return (0);
}
