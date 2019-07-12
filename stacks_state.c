/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:30:31 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:15:20 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						arg_init(t_stacks_state *arg)
{
	arg->a = 0;
	arg->b = 0;
	arg->ops = 0;
	arg->curstack = 'a';
	arg->silent = 0;
	return (1);
}

int						arg_destroy(t_stacks_state *arg)
{
	arg->curstack = 0;
	arg->silent = 0;
	return (l_destroy(&arg->a) && l_destroy(&arg->b) && l_destroy(&arg->ops));
}

t_stacks_state			arg_copy(t_stacks_state *arg)
{
	t_stacks_state		copy;

	copy.a = l_copy(arg->a);
	copy.b = l_copy(arg->b);
	copy.ops = l_copy(arg->ops);
	copy.curstack = arg->curstack;
	copy.silent = arg->silent;
	return (copy);
}
