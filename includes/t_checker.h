/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_checker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:03:13 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/17 02:57:44 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CHECKER_H
# define T_CHECKER_H

# include "t_history.h"

typedef struct	s_checker
{
	int			v_option;
	int			c_option;
	int			d_option;
	t_history	*history;
}				t_checker;

#endif
