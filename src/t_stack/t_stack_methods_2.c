/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_methods_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:40:40 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 17:35:29 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_is_reverse_sorted(t_stack *entity)
{
	t_stack		tmp_stack;
	int			prev;
	int			tmp;

	prev = 0;
	tmp = 0;
	copy_stack(&tmp_stack, entity);
	if (!stack_is_initialized(&tmp_stack) || stack_is_empty(&tmp_stack))
		return (0);
	pop(&tmp_stack, &prev);
	while (!stack_is_empty(&tmp_stack))
	{
		pop(&tmp_stack, &tmp);
		if (tmp >= prev)
		{
			destroy_stack(&tmp_stack);
			return (0);
		}
		prev = tmp;
	}
	destroy_stack(&tmp_stack);
	return (1);
}

int		*stack_to_array(t_stack *entity)
{
	if (!stack_is_initialized(entity) || stack_is_empty(entity))
		return (NULL);
	return (entity->values);
}
