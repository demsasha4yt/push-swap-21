/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:38:17 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/27 16:26:52 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int		algo_quicksort_split_by_pivot(t_pswap *pswap,
						t_stack_name name, int length, int pivot)
{
	int	idx;
	int	ret;

	(void)length;
	idx = 0;
	ret = 0;
	while (!stack_nearest_lower_value_idx((name == STACK_A) ?
		&pswap->a : &pswap->b, pivot, &idx))
	{
		ret++;
		while (idx != 0)
		{
			ps_exec(pswap, (name == STACK_A) ? RA_FUNC : RB_FUNC);
			idx--;
		}
		ps_exec(pswap, (name == STACK_A) ? PB_FUNC : PA_FUNC);
	}

	return (ret);
}

static int		algo_quicksort_split(t_pswap *pswap, t_stack_name name,
					int length)
{
	int		pivot;
	t_stack	*current;

	current = (name == STACK_A) ? &pswap->a : &pswap->b;
	pivot = stack_get_length(current);
	(void)length;
	while(stack_get_length(current) > 2)
	{
		pivot = stack_get_median(current);
		algo_quicksort_split_by_pivot(pswap, name, stack_get_length(current), pivot);
	}
	return (0);
}

int		algo_quicksort(t_pswap *pswap)
{
	algo_quicksort_split(pswap, STACK_A, stack_get_length(&pswap->a));
	return (0);
}
