/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quicksort_swaps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:03:03 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 13:23:56 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		try_swap_a(t_pswap *pswap)
{
	const int	*array = stack_to_array(&pswap->a);
	const int	len = stack_get_length(&pswap->a);

	if (len < 2)
		return (0);
	if (array[len - 1] > array[len -2])
		ps_exec(pswap, SA_FUNC);
	return (0);
}

int		try_swap_b(t_pswap *pswap)
{
	const int	*array = stack_to_array(&pswap->b);
	const int	len = stack_get_length(&pswap->b);

	if (len < 2)
		return (0);
	if (array[len - 1] < array[len -2])
		ps_exec(pswap, SB_FUNC);
	return (0);
}

int		try_swaps(t_pswap *pswap)
{
	int ret;

	ret = 0;
	ret += try_swap_a(pswap);
	ret += try_swap_b(pswap);
	return (ret);
}
