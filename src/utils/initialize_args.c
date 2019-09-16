/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:25:45 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 00:40:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_number(t_stack **a, char *str)
{
	if (!is_valid_arg(str))
		error(a, NULL, NULL);
	return (ft_atoi(str));
}

static void	initialize_from_argv(int argc, char **argv,
				t_stack **a, t_stack **b)
{
	int		i;
	int		num;
	char	**args;

	i = 1;
	while (i < argc)
	{
		if (*argv[i] == '\0')
			error(a, NULL, NULL);
		args = ft_strsplit(argv[i], ' ');
		num = put_number(a, argv[i]);
		if (exist(*b, num))
			error(a, b, NULL);
		push(b, num);
		i++;
	}
	while (*b != NULL)
	{
		push(a, (*b)->number);
		pop(b);
	}
}

void		initialize_args(int argc, char **argv, t_stack **a, t_stack **b)
{
	initialize_from_argv(argc, argv, a, b);
}
