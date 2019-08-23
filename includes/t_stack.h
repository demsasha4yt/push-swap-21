/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 13:00:43 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 17:55:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H

# define DEFAULT_STACK_SIZE 2

typedef struct	s_stack
{
	int			*values;
	int			length;
	int			size_available;
}				t_stack;

int				create_stack(t_stack *entity, size_t size);
int				initialize_basic_stack(t_stack *entity, size_t size);
void			destroy_stack(t_stack *entity);
int				realloc_stack(t_stack *entity);

int				push(t_stack *entity, int value);
int				pop(t_stack *entity, int *dest);
int				swap(t_stack *entity);
int				rotate(t_stack *entity);
int				rrotate(t_stack *entity);

void			print_stack(t_stack *entity);

#endif
