/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:24:03 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 03:24:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include "push_swap.h"
# include "t_checker.h"
# include "t_history.h"

t_checker	initialize_checker(int argc, char **argv,
				t_stack **a, t_stack **b);
t_history	*create_history_node(t_stack *a,
				t_stack *b, char *cmd);
t_history	*get_last_node(t_checker *checker);
void		add_to_history(t_checker *checker,
				t_stack *a, t_stack *b, char *cmd);
void		history_node_clear(t_history *node);

#endif
