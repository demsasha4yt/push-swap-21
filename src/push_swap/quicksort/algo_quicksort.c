/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:15:22 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 15:44:20 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_quicksort_first_split(t_pswap *pswap)
{
	int		ret;
	int		pivot;

	pivot = 0;
	ret = 0;
	stack_get_median(&pswap->a, &pivot);
	return (0);
}

int		algo_quicksort(t_pswap *pswap)
{
	int		ret;

	ret = 0;
	try_swaps(pswap);
	algo_quicksort_first_split(pswap);
	return (ret);
}
