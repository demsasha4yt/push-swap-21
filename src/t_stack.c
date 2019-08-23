/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:02:54 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 14:15:56 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack		*create_stack(size_t size)
{
	t_stack		*entity;
	size_t		real_size;

	real_size = (size / DEFAULT_STACK_SIZE) * DEFAULT_STACK_SIZE;
	if (real_size == 0)
		real_size = DEFAULT_STACK_SIZE;
	if (real_size < size)
		real_size = size;
	entity = malloc(sizeof(t_stack));
	entity->length = 0;
	entity->size_available = real_size;
	entity->values = malloc(sizeof(entity->values) * real_size);
	ft_bzero(entity->values, real_size * sizeof(entity->length));
	return (entity);
}

void		destroy_stack(t_stack *entity)
{
	free(entity->values);
	free(entity);
}

void		realloc_stack(t_stack **entity)
{
	t_stack		*old_entity = *entity;

	*entity = create_stack(old_entity->size_available * 2);
	(*entity)->length = old_entity->length;
	ft_memcpy((*entity)->values, old_entity->values,
		sizeof(int) * old_entity-> length);
	destroy_stack(old_entity);
}
