/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:44:14 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/30 16:07:07 by bharrold         ###   ########.fr       */
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

typedef struct	s_insertion
{
	int			max;
	int			min;
	int			average;
	int			larger_average;
	int			lower_average;
	int			elements_in_bottom;
}				t_insertion;


int				push_swap_main(int argc, char **argv);
int				initialize_push_swap(t_pswap *pswap,
					int argc, char **argv);

int				algo_sort_start(t_pswap *pswap);

/*
	**	Sort utils
*/
int				basic_3sort(t_pswap *pswap);
int				is_resolved(t_pswap *pswap);

int				array_get_max_index(const int *array, const int len);
int				array_get_max(const int *array, const int len);
int				array_get_min_index(const int *array, const int len);
int				array_get_min(const int *array, const int len);
int				array_get_average(const int *array, const int len);

int				stack_get_median(t_stack *entity);
int				stack_get_max(t_stack *entity);
int				stack_get_min(t_stack *entity);
int				stack_get_average(t_stack *entity);

/*
	** Insertion sort algo
*/

int algo_insertion(t_pswap *pswap);

#endif
