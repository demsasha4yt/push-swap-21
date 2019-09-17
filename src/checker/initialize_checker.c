/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 02:26:22 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 02:42:25 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

static int	try_to_apply_option(char *str, t_checker *checker)
{
	if (!ft_strcmp(str, "-v"))
	{
		checker->v_option = 1;
		return (1);
	}
	if (!ft_strcmp(str, "-c"))
	{
		checker->c_option = 1;
		return (1);
	}
	if (!ft_strcmp(str, "-d"))
	{
		checker->d_option = 1;
		return (1);
	}
	return (0);
}

static int	parse_options(t_checker *checker, int argc, char **argv)
{
	int	result;
	int	i;

	result = 0;
	i = 1;
	while (i < 4 && argc - i > 0)
	{
		result += try_to_apply_option(argv[i], checker);
		i++;
	}
	return (result);
}

t_checker	initialize_checker(int argc, char **argv, t_stack **a, t_stack **b)
{
	t_checker	checker;
	int			options_cnt;

	checker.v_option = 0;
	checker.c_option = 0;
	checker.d_option = 0;

	options_cnt = parse_options(&checker, argc, argv);
	argv += options_cnt;
	argc -= options_cnt;
	initialize_stacks(argc, argv, a, b);
	return (checker);
}
