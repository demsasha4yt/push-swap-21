/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:21:31 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 20:09:25 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		array_get_max_index(const int *array, const int len)
{
	int i;
	int max;
	int max_idx;

	max_idx = 0;
	max = array[0];
	i = -1;
	while (++i < len)
		if (array[i] >= max)
		{
			max_idx = i;
			max = array[i];
		}
	return (max_idx);
}

int		array_get_min_index(const int *array, const int len)
{
	int i;
	int min;
	int min_idx;

	min_idx = 0;
	min = array[0];
	i = -1;
	while (++i < len)
		if (array[i] < min)
		{
			min_idx = i;
			min = array[i];
		}
	return (min_idx);
}

int		array_get_max_value(const int *array, const int len)
{
	const int max_idx = array_get_max_index(array, len);

	return (array[max_idx]);
}

int		array_get_min_value(const int *array, const int len)
{
	const int min_idx = array_get_min_index(array, len);

	return (array[min_idx]);
}
