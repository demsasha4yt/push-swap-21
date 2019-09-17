/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_minmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 08:48:16 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 11:16:43 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"
#include "limits.h"

int		stack_get_max(t_stack *a)
{
	int	max;

	max = INT_MIN;
	while (a)
	{
		if (a->number > max)
			max = a->number;
		a = a->next;
	}
	return (max);
}

int		stack_get_min(t_stack *a)
{
	int	min;

	min = INT_MAX;
	while (a)
	{
		if (a->number < min)
			min = a->number;
		a = a->next;
	}
	return (min);
}
