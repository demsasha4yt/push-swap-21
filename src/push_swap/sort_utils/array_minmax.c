/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_minmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:32:37 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/30 14:55:23 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		array_get_max_index(const int *array, const int len)
{
	int	max;
	int	max_idx;
	int	i;

	if (len == 0)
		return (-1);
	max = array[0];
	max_idx = 0;
	i = -1;
	while (++i < len)
		if (array[i] > max)
		{
			max = array[i];
			max_idx = i;
		}
	return (max_idx);
}

int		array_get_min_index(const int *array, const int len)
{
	int	min;
	int	min_idx;
	int	i;

	if (len == 0)
		return (-1);
	min = array[0];
	min_idx = 0;
	i = -1;
	while (++i < len)
		if (array[i] < min)
		{
			min = array[i];
			min_idx = i;
		}
	return (min_idx);
}

int		array_get_max(const int *array, const int len)
{
	return array[array_get_max_index(array, len)];
}

int		array_get_min(const int *array, const int len)
{
	return array[array_get_min_index(array, len)];
}

int		array_get_average(const int *array, const int len)
{
	int		sum;
	int		i;
	sum = 0;
	i = -1;
	while (++i < len)
		sum += array[i];
	if (len != 0)
		return (sum / len);
	return (0);
}
