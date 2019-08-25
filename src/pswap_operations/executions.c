/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:24:27 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 16:26:05 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_exec_ntimes(t_pswap *pswap, t_pfuncs func, int n)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	while (++i < n)
		ret += ps_exec(pswap, func);
	return (ret);
}
