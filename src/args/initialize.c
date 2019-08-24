/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 20:47:33 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 14:46:12 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_args(t_pswap *pswap, int argc, char **argv)
{
	int idx;
	int converted;

	idx = argc;
	if (argc < 2)
		return (8);
	while (--idx > 0)
	{
		if (!is_valid_arg(argv[idx]))
			return (16);
		converted = ft_atoi(argv[idx]);
		if (is_arg_already_exist(&pswap->a, converted))
			return (32);
		push(&pswap->a, converted);
	}
	return (0);
}
