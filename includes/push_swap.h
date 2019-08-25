/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:44:14 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/25 13:19:17 by bharrold         ###   ########.fr       */
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

typedef enum	e_stack_name
{
	STACK_A,
	STACK_B
}				t_stack_name;

typedef	struct	s_minmax_idx
{
	int			min_idx;
	int			max_idx;
}				t_minmax_idx;

typedef	struct	s_2idxs
{
	int			idx;
	int			idx2;
}				t_2idxs;



int		push_swap_main(int argc, char **argv);
int		initialize_push_swap(t_pswap *pswap,
					int argc, char **argv);

int		algo_sort_start(t_pswap *pswap);

/*
	**	Sort utils
*/

int		is_resolved(t_pswap *pswap);
int		stack_get_median(t_stack *entity, int *median);
int		array_get_max_index(const int *array, const int len);
int		array_get_min_index(const int *array, const int len);
int		array_get_max_value(const int *array, const int len);
int		array_get_min_value(const int *array, const int len);

/*
	**	Quicksort alog
*/

int		algo_quicksort(t_pswap *pswap);
int		algo_quicksort_first_split(t_pswap *pswap);
int		algo_quicksort_split_by_median(t_pswap *pswap,
			t_stack_name stack_name);
int		try_swap_a(t_pswap *pswap);
int		try_swap_b(t_pswap *pswap);
int		try_swaps(t_pswap *pswap);

#endif
