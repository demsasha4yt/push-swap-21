/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:58:13 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/16 23:49:03 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"


static void	handle_dual_operation(t_stack **a, t_stack **b, char *operation)
{
	if (!ft_strcmp(operation, "ss"))
	{
		command_s(*a, NULL, NULL);
		command_s(*b, NULL, NULL);
	}
	if (!ft_strcmp(operation, "rr"))
	{
		command_r(a, NULL, NULL);
		command_r(b, NULL, NULL);
	}
	if (!ft_strcmp(operation, "rrr"))
	{
		command_rr(a, NULL, NULL);
		command_rr(b, NULL, NULL);
	}
}

static void	handle_operation(t_stack **a, t_stack **b, char *operation)
{
	if (!ft_strcmp(operation, "sa"))
		command_s(*a, NULL, NULL);
	else if (!ft_strcmp(operation, "sb"))
		command_s(*b, NULL, NULL);
	else if (!ft_strcmp(operation, "pa"))
		command_p(a, b, NULL, NULL);
	else if (!ft_strcmp(operation, "pb"))
		command_p(b, a, NULL, NULL);
	else if (!ft_strcmp(operation, "ra"))
		command_r(a, NULL, NULL);
	else if (!ft_strcmp(operation, "rb"))
		command_r(b, NULL, NULL);
	else if (!ft_strcmp(operation, "rra"))
		command_rr(a, NULL, NULL);
	else if (!ft_strcmp(operation, "rrb"))
		command_rr(b, NULL, NULL);
	else
		handle_dual_operation(a, b, operation);
}

int				main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char	*current;

	a = NULL;
	b = NULL;
	current = NULL;
	initialize_stacks(argc, argv, &a, &b);
	while (get_next_line(0, &current))
	{
		if (!ft_strcmp(current, "Error"))
			error(&a, &b, NULL);
		ft_printf("checker %s\n", current);
		handle_operation(&a, &b, current);
	}
	ft_strdel(&current);
	ps_destroy(&a, &b, NULL);
}
