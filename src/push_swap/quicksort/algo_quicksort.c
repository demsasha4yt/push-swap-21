/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:15:22 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 17:35:16 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		algo_quicksort(t_pswap *pswap)
{
	int pivot;
	int ret;

	ret = 0;
	pivot = 0;
	ret += get_median(&pswap->a, &pivot);
	return (ret);
}
