/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 21:34:19 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 22:21:19 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_is_empty(t_stack *entity)
{
	return (entity->length == 0);
}

int		copy_stack(t_stack *dest, t_stack *source)
{
	if (initialize_basic_stack(dest, source->size_available))
		return (1);
	ft_memcpy(dest->values, source->values, sizeof(int) * source->length);
	dest->length = source->length;
	return (0);
}
