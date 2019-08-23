/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 16:52:49 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 20:52:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_int_rotate(int *array, int length)
{
	int half;
	int i;

	i = 0;
	half = length / 2;
	while (++i < half)
	{
		array[i] = array[i] ^ array[length - i];
		array[length - 1] = array[length - 1] ^ array[i];
		array[i] = array[i] ^ array[length - 1];
	}
}
