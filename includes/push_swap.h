/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:44:14 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 19:07:22 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "t_pswap.h"
# include "t_stack.h"
# include "pswap_operations.h"

int		push_swap_main(int argc, char **argv);
int		initialize_push_swap(t_pswap *pswap,
					int argc, char **argv);

/*
	** Args init and validations
*/
int		initialize_args(t_pswap *pswap, int argc, char **argv);
int		is_valid_arg(char *arg);
#endif
