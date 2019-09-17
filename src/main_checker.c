/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:58:13 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 06:28:32 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	else
		error(a, b, NULL);
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

void		count_stacks(t_checker *checker, t_stack **a, t_stack **b)
{
	char		*current;

	current = NULL;
	add_to_history(checker, *a, *b, "init");
	while (get_next_line(0, &current))
	{
		if (!ft_strcmp(current, "Error"))
			error(a, b, NULL);
		handle_operation(a, b, current);
		add_to_history(checker, *a, *b, current);
		ft_strdel(&current);
	}
	add_to_history(checker, *a, *b, "done");
}

int			main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_checker	checker;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(0);
	checker = initialize_checker(argc, argv, &a, &b);
	count_stacks(&checker, &a, &b);
	display(&checker, &a, &b);
	destroy_checker(&checker);
	ps_destroy(&a, &b, NULL);
}
