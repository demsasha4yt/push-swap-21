/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 20:59:36 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/01 20:59:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_pivot(t_stack *a, int count)
{
	long	summ;
	int		i;
	int		result;

	i = 0;
	summ = 0;
	while (i < count)
	{
		summ += a->number;
		a = a->next;
		i++;
	}
	result = count == 0 ? 0 : summ / count;
	result = (summ % count != 0) ? result + 1 : result;
	return (result);
}
