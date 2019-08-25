/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:46:48 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 18:37:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

int		stack_get_median(t_stack *entity, int *median)
{
	int			max;
	int			min;
	int			len;
	const int	*array = stack_to_array(entity);

	len = stack_get_length(entity);
	min = INT_MAX;
	max = INT_MIN;
	if (array == NULL || len == 0)
		return (64);
	while (--len > 0)
	{
		if (array[len] <= min)
			min = array[len];
		if (array[len] >= max)
			max = array[len];
	}
	*median = (max + min) / 2;
	return (0);
}

int		stack_get_median_of_n_top_elems(t_stack *entity, int n, int *median)
{
	int			max;
	int			min;
	const int	len = stack_get_length(entity);
	const int	*array = stack_to_array(entity);

	min = INT_MAX;
	max = INT_MIN;
	if (array == NULL || len == 0 || n > len)
		return (64);
	while (n--)
	{
		if (array[len - 1 - n] <= min)
			min = array[len - 1 -n];
		if (array[len - 1 -n] >= max)
			max = array[len - 1 - n];
	}
	*median = (max + min) / 2;
	return (0);
}
