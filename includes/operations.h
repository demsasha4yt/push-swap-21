/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 20:25:51 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/01 20:27:30 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "t_stack.h"
# include "libft.h"

void	command_s(t_stack *a, t_list **commands, char *str);
void	command_p(t_stack **a, t_stack **b, t_list **commands, char *str);
void	command_r(t_stack **a, t_list **commands, char *str);
void	command_rr(t_stack **a, t_list **commands, char *str);

#endif
