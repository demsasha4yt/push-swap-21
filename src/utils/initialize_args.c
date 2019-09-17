/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:25:45 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 06:28:54 by bharrold         ###   ########.fr       */
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

	i = 1;
	while (i < argc)
	{
		if (*argv[i] == '\0')
			error(a, NULL, NULL);
		num = put_number(a, argv[i]);
		if (exist(*b, num))
			error(a, b, NULL);
		push(b, num);
		i++;
	}
}

static void	initialize_from_str(char *str, t_stack **a, t_stack **b)
{
	char	**numbers;
	char	**ptr;
	int		num;

	numbers = ft_strsplit(str, ' ');
	ptr = numbers;
	while (ptr && *ptr)
	{
		num = put_number(a, *ptr);
		if (exist(*b, num))
			error(a, b, NULL);
		push(b, num);
		ptr++;
	}
	ft_strsplit_free(&numbers);
}

void		initialize_args(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (argc == 2 && !ft_isnum(argv[1], 10))
		initialize_from_str(argv[1], a, b);
	else
		initialize_from_argv(argc, argv, a, b);
	while (*b != NULL)
	{
		push(a, (*b)->number);
		pop(b);
	}
}
