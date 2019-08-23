/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:44:14 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 17:51:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "t_stack.h"

typedef struct	s_pswap
{
	t_stack a;
	t_stack b;
}				t_pswap;

int				push_swap_main(int argc, char **argv);
int				pa(t_pswap *pswap);
int				pb(t_pswap *pswap);
int				sa(t_pswap *pswap);
int				sb(t_pswap *pswap);
int				ss(t_pswap *pswap);
int				ra(t_pswap *pswap);
int				rb(t_pswap *pswap);
int				rr(t_pswap *pswap);
int				rra(t_pswap *pswap);
int				rrb(t_pswap *pswap);
int 			rrr(t_pswap(*pswap));

#endif
