/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 22:28:50 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 22:29:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "t_stack.h"
# include "t_pswap.h"

int		initialize_args(t_pswap *pswap, int argc, char **argv);
int		is_valid_arg(char *arg);
int		is_valid_number(char *arg);
int		is_arg_already_exist(t_stack *a, int arg);

#endif
