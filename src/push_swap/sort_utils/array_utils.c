/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:32:37 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/26 19:36:03 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		array_get_max_index(int *array, int len)
{
	int	max;
	int	max_idx;
	int	i;

	if (len == 0)
		return (-1);
	max = array[0];
	max_idx = 0;
	i = -1;
	while (++i < len)
		if (array[i] > max)
		{
			max = array[i];
			max_idx = i;
		}
	return (max_idx);
}
