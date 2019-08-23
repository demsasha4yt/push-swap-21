/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:35:01 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 21:53:39 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push(t_stack *entity, int value)
{
	if (entity->length == entity->size_available)
		if (realloc_stack(entity))
			return (1);
	entity->values[entity->length] = value;
	entity->length += 1;
	return (0);
}

int		pop(t_stack *entity, int *value)
{
	if (entity->length == 0)
		return (1);
	*value = entity->values[entity->length - 1];
	entity->values[entity->length - 1] = 0;
	entity->length -= 1;
	return (0);
}

int		swap(t_stack *entity)
{
	if (entity->length < 2)
		return (1);
	ft_swap_int(&entity->values[entity->length - 1],
		&entity->values[entity->length - 2]);
	return (0);
}

int		rotate(t_stack *entity)
{
	int top;
	int tmp;
	t_stack tmp_stack;

	top = 0;
	tmp = 0;
	initialize_basic_stack(&tmp_stack, DEFAULT_STACK_SIZE);
	pop(entity, &top);
	while (!stack_is_empty(entity))
	{
		pop(entity, &tmp);
		push(&tmp_stack, tmp);
	}
	push(entity, top);
	while (!stack_is_empty(&tmp_stack))
	{
		pop(&tmp_stack, &tmp);
		push(entity, tmp);
	}
	destroy_stack(&tmp_stack);
	return (0);
}

int		rrotate(t_stack *entity)
{
	(void)entity;
	return (0);
}
