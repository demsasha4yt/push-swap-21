/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 21:34:19 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 14:41:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_is_initialized(t_stack *entity)
{
	return (entity->size_available != 0);
}

int		stack_is_empty(t_stack *entity)
{
	return (stack_get_length(entity) == 0);
}

int		copy_stack(t_stack *dest, t_stack *source)
{
	if (initialize_basic_stack(dest, source->size_available))
		return (1);
	ft_memcpy(dest->values, source->values, sizeof(int) * source->length);
	dest->length = source->length;
	return (0);
}

int		stack_get_length(t_stack *entity)
{
	return (entity->length);
}

int		stack_is_sorted(t_stack *entity)
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
		if (tmp <= prev)
		{
			destroy_stack(&tmp_stack);
			return (0);
		}
		prev = tmp;
	}
	destroy_stack(&tmp_stack);
	return (1);
}
