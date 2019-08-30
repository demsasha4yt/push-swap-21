/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:39:08 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/30 14:56:22 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_get_median(t_stack *entity)
{
	const int	*array = stack_to_array(entity);
	const int	len = stack_get_length(entity);

	return (array_get_max(array, len) + array_get_min(array, len) / 2);
}

int		stack_get_max(t_stack *entity)
{
	const int	*array = stack_to_array(entity);
	const int	len = stack_get_length(entity);

	return (array_get_max(array, len));
}

int		stack_get_min(t_stack *entity)
{
	const int	*array = stack_to_array(entity);
	const int	len = stack_get_length(entity);

	return (array_get_min(array, len));
}

int		stack_get_average(t_stack *entity)
{
	const int	*array = stack_to_array(entity);
	const int	len = stack_get_length(entity);

	return (array_get_average(array, len));
}


