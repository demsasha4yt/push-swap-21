/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:35:01 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 16:19:57 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *entity, int value){
	if (entity->length == entity->size_available)
		realloc_stack(entity);
	entity->values[entity->length] = value;
	entity->length += 1;
	return;
}

int		pop(t_stack *entity, int *value){
	if (entity->length == 0)
		return(1);
	*value = entity->values[entity->length - 1];
	entity->values[entity->length - 1] = 0;
	entity->length -= 1;
	return (0);
}


