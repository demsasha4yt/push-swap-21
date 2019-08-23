/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:37:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 13:52:24 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *entity)
{
	int idx;

	idx = -1;
	ft_printf("STACK DEBUG\n");
	ft_printf("________________\n");
	if (entity->length == 0)
		ft_printf("NO ELEMENTS IN STACK\n");
	while (++idx < entity->length)
		ft_printf("%10d\n", entity->values[idx]);
}
