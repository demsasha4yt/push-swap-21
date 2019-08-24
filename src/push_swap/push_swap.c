/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:18:28 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 18:38:26 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_main(int argc, char **argv)
{
	t_pswap		pswap;
	int			ret;

	ret = 0;
	ret += initialize_push_swap(&pswap, argc, argv);
	if (ret != 0)
		display_error_and_exit(ret);
	ret = algo_sort_start(&pswap);
	if (ret != 0)
		display_error_and_exit(ret);
	pfuncs_destroy_names(&pswap);
	destroy_stack(&pswap.a);
	destroy_stack(&pswap.b);
	return (0);
}
