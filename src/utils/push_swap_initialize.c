/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:54:12 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 00:38:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*initialize_count(int count)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * (count));
	while (i < count)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

void		initialize_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	initialize_args(argc, argv, a, b);
}
