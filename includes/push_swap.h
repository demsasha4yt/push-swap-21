/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:49:46 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/01 21:03:31 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>

#include "t_stack.h"
#include "t_pushswap.h"
#include "operations.h"

void	initialize_stacks(int argc, char **argv, t_stack **a, t_stack **b);
int		*initialize_count(int count);
void	ps_destroy(t_stack **a, t_stack **b, t_pushswap **ps);
void	destroy_content(t_list **alst);
void	error(t_stack **a, t_stack **b, t_pushswap **ps);

void	basic_3sort(t_stack **a, t_pushswap **ps);
void	basic_sort(t_stack **a, t_stack **b, t_pushswap **ps);
void	rev_b(t_stack **a, t_stack **b, t_pushswap **ps, int count_b);

void	print_result(t_list *commands);
void	merge_commands(int flag_1, t_list **commands, t_list **p,
							t_list **prev);
int		get_flag(const char *content);

void	algo_quicksort(t_stack **a, t_stack **b, t_pushswap **ps);
int		get_pivot(t_stack *a, int count);

#endif
