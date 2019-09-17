/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:41:05 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 08:52:54 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H

typedef struct		s_stack
{
	int				number;
	struct s_stack	*next;
}					t_stack;

void				push(t_stack **a, int number);
void				pop(t_stack **a);
int					exist(t_stack *a, int number);
void				del(t_stack **a);
int					is_sorted(t_stack *a, int count);
int					is_all_sorted(t_stack *a);
void				print_stack(t_stack *a);
int					stack_get_length(t_stack *a);
int					*stack_to_array(t_stack *a);
int					stack_get_max(t_stack *a);
int					stack_get_min(t_stack *a);

#endif
