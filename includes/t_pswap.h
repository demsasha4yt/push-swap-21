/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:07:53 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/23 18:37:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PSWAP_H
# define T_PSWAP_H
# include "t_stack.h"

# define PFUNCTION_COUNT 11

typedef struct		s_pswap
{
	t_stack			a;
	t_stack			b;
	int				(*psfuncs[PFUNCTION_COUNT])\
					(struct s_pswap*);
}					t_pswap;

#endif
