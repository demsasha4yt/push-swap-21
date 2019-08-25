/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:35:41 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 15:40:08 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

t_2idxs		array_get_max_2_idxs(const int *array, const int len)
{
	t_2idxs result;
	int		max;
	int		prevmax;
	int		i;

	max = INT_MIN + 1;
	prevmax = INT_MIN;
	result.idx = 0;
	result.idx2 = 0;
	i = -1;
	while (++i < len)
		if (array[i] > max)
		{
			result.idx2 = result.idx;
			prevmax = max;
			result.idx = i;
			max = array[i];
		}
		else if (array[i] >= prevmax)
		{
			prevmax = array[i];
			result.idx2 = i;
		}
	return (result);
}

t_2idxs		array_get_min_2_idxs(const int *array, const int len)
{
	t_2idxs result;
	int		min;
	int		prevmin;
	int		i;

	min = INT_MAX;
	prevmin = INT_MAX - 1;
	result.idx = 0;
	result.idx2 = 0;
	i = -1;
	while (++i < len)
		if (array[i] > min)
		{
			result.idx2 = result.idx;
			prevmin = min;
			result.idx = i;
			min = array[i];
		}
		else if (array[i] >= prevmin)
		{
			prevmin = array[i];
			result.idx2 = i;
		}
	return (result);
}

t_2idxs		array_get_lower_of_pivot_idxs(const int *array,
				const int len, int pivot)
{
	t_2idxs		result;
	const int	half = len / 2;
	int			i;

	i = len;
	result.idx = -1;
	result.idx2 = -1;
	while (--i >= half && (result.idx == -1 || result.idx2 == -1))
	{
		if (array[i] <= pivot)
		{
			if (result.idx == -1)
				result.idx = i;
			else if (result.idx2 == -1)
				result.idx2 = i;
		}
		if (array[len - 1 - i] <= pivot)
		{
			if (result.idx == -1)
				result.idx = len - 1 - i;
			else if (result.idx2 == -1)
				result.idx2 = len - 1 - i;
		}
	}
	return (result);
}

t_2idxs		array_get_bigger_of_pivot_idxs(const int *array,
				const int len, int pivot)
{
	t_2idxs		result;
	const int	half = len / 2;
	int			i;

	i = len;
	result.idx = -1;
	result.idx2 = -1;
	while (--i >= half && (result.idx == -1 || result.idx2 == -1))
	{
		if (array[i] > pivot)
		{
			if (result.idx == -1)
				result.idx = i;
			else if (result.idx2 == -1)
				result.idx2 = i;
		}
		if (array[len - 1 - i] > pivot)
		{
			if (result.idx == -1)
				result.idx = len - 1 - i;
			else if (result.idx2 == -1)
				result.idx2 = len - 1 - i;
		}
	}
	return (result);
}
