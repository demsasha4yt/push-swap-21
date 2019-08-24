/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:44:14 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 18:23:16 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "t_pswap.h"
# include "t_stack.h"
# include "args.h"
# include "pswap_operations.h"

int		push_swap_main(int argc, char **argv);
int		initialize_push_swap(t_pswap *pswap,
					int argc, char **argv);

int		algo_sort_start(t_pswap *pswap);

/*
	**	Sort utils
*/

int		is_resolved(t_pswap *pswap);
int		get_median(t_stack *entity, int *median);
int		array_get_max_index(const int *array, const int len);

/*
	**	Quicksort alog
*/

int		algo_quicksort(t_pswap *pswap);

#endif
