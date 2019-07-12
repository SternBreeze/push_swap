/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dual_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:39:25 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/07 21:03:59 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						ss(t_stacks_state *arg)
{
	char				*str;

	EXITIF(!(str = ft_strdup("ss")));
	ld_push_back(&arg->ops, str);
	arg->silent = 1;
	SA;
	SB;
	arg->silent = 0;
	return (1);
}

int						rr(t_stacks_state *arg)
{
	char				*str;

	EXITIF(!(str = ft_strdup("rr")));
	ld_push_back(&arg->ops, str);
	arg->silent = 1;
	RA;
	RB;
	arg->silent = 0;
	return (1);
}

int						rrr(t_stacks_state *arg)
{
	char				*str;

	EXITIF(!(str = ft_strdup("rrr")));
	ld_push_back(&arg->ops, str);
	arg->silent = 1;
	RRA;
	RRB;
	arg->silent = 0;
	return (1);
}
