/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:39:08 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/27 16:26:58 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_get_median(t_stack *entity)
{
	const int	*array = stack_to_array(entity);
	const int	len = stack_get_length(entity);

	return (array_get_max(array, len) + array_get_min(array, len) / 2);
}

int		stack_nearest_larger_value_idx(t_stack *entity, int value, int *dest)
{
	t_stack		tmp_stack;
	int			idx;
	int			tmp;
	int			found;

	idx = -1;
	found = 0;
	copy_stack(&tmp_stack, entity);
	while (!pop(&tmp_stack, &tmp))
	{
		idx++;
		if (tmp > value)
		{
			found = 1;
		}
	}
	destroy_stack(&tmp_stack);
	if (!found)
		return (1);
	*dest = tmp;
	return (0);
}

int		stack_nearest_lower_value_idx(t_stack *entity, int value, int *dest)
{
	t_stack		tmp_stack;
	int			idx;
	int			tmp;
	int			found;

	idx = -1;
	found = 0;
	copy_stack(&tmp_stack, entity);
	while (!pop(&tmp_stack, &tmp))
	{
		idx++;
		if (tmp <= value)
		{
			found = 1;
		}
	}
	destroy_stack(&tmp_stack);
	if (!found)
		return (1);
	*dest = tmp;
	return (0);
}
