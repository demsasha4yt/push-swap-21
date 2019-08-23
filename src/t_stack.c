/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:02:54 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 16:30:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		create_stack(t_stack *entity, size_t size)
{
	size_t		real_size;

	real_size = (size / DEFAULT_STACK_SIZE) * size;
	if (real_size == 0)
		real_size = DEFAULT_STACK_SIZE;
	if (real_size < size)
		real_size = size;
	if (!(entity->values = (int*)malloc(sizeof(int) * real_size)))
		return (1);
	entity->size_available = real_size;
	return (0);
}

void	destroy_values_stack(int *values)
{
	free(values);
	values = NULL;
}

void	destroy_stack(t_stack *entity)
{
	destroy_values_stack(entity->values);
	entity->values = NULL;
	entity->size_available = 0;
	entity->length = 0;
}

int		realloc_stack(t_stack *entity)
{
	int *old_values;
	int old_size_available;
	int old_length;

	old_values = entity->values;
	old_size_available = entity->size_available;
	old_length = entity->length;
	if (create_stack(entity, entity->size_available * 2))
		return (1);
	ft_memcpy(entity->values, old_values, sizeof(int) * entity->length);
	destroy_values_stack(old_values);
	if (entity->length != old_length ||
		entity->size_available < old_size_available)
		return (2);
	return (0);
}

int		initialize_basic_stack(t_stack *entity, size_t size)
{
	if (create_stack(entity, size))
		return (1);
	entity->length = 0;
	return (0);
}
