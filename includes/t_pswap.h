/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:07:53 by bharrold          #+#    #+#             */
/*   Updated: 2019/08/24 18:42:22 by bharrold         ###   ########.fr       */
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
	char			*psfuncs_name[PFUNCTION_COUNT];
	int				debug_mode;
}					t_pswap;

#endif
