/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:21:31 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 17:23:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		array_get_max_index(const int *array, const int len)
{
	int i;
	int max;
	int max_idx;

	max_idx = 0;
	max = array[0];
	i = -1;
	while (++i < len)
		if (array[i] >= max)
		{
			max_idx = i;
			max = array[i];
		}
	return (max_idx);
}
