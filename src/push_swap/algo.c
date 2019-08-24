/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 22:26:29 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 17:35:07 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		basic_3sort(t_pswap *pswap)
{
	int		len;
	int		*array;

	len = stack_get_length(&pswap->a);
	array = stack_to_array(&pswap->a);
	if (len == 1)
		return (0);
	if (len == 2)
		if (array[1] > array[0])
			ps_exec(pswap, SA_FUNC);
	if (len == 3)
	{
		len = array_get_max_index(array, len);
		ft_printf("%d\n", len);
		if (len == 1)
			ps_exec(pswap, RRA_FUNC);
		if (len == 2)
			ps_exec(pswap, RA_FUNC);
		array = stack_to_array(&pswap->a);
		ft_printf("%d %d %d\n", array[0], array[1], array[2]);
		if (array[1] < array[2])
			ps_exec(pswap, SA_FUNC);
	}
	return (0);
}

int		algo_sort_start(t_pswap *pswap)
{
	int ret;

	ret = 0;
	if (is_resolved(pswap))
		return (ret);
	debug_print_stacks(pswap);
	if (stack_get_length(&pswap->a) <= 3)
		ret = basic_3sort(pswap);
	else
		ret = algo_quicksort(pswap);
	debug_print_stacks(pswap);
	return (ret);
}
