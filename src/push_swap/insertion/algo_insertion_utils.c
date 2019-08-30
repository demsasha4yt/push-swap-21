/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_insertion_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:00:39 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/30 16:05:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		insertion_get_idx_for_insert(t_pswap *pswap, int value)
{
	const int	*array = stack_to_array(&pswap->a);
	const int	len = stack_get_length(&pswap->a);
	int			i;

	i = len;
	while (--i > 0)
	{
		if (i == len - 1 && array[i - 1] < value)
			return (i);
		if (array[i] > value && array[i - 1] < value)
			return (i - 1);
	}
	return (i);
}
