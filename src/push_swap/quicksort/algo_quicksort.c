/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:15:22 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 20:10:23 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_quicksort(t_pswap *pswap)
{
	int pivot;
	int ret;

	ret = 0;
	pivot = 0;
	ret += stack_get_median(&pswap->a, &pivot);
	return (ret);
}
