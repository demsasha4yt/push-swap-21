/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:58:13 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/16 22:49:29 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int		main(int argc, char **argv)
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
		ft_printf("checker %s\n", current);
	}
	ft_strdel(&current);
	ps_destroy(&a, &b, NULL);
}
