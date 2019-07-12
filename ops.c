/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:04:35 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:20:31 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						sx(t_stacks_state *arg, char name)
{
	t_list				**a;
	char				*str;
	int					buf;

	name == 'a' ? (a = &arg->a)
				: (a = &arg->b);
	if (!*a || !((*a)->next))
		return (1);
	buf = DATA(*a);
	DATA(*a) = DATA((*a)->next);
	DATA((*a)->next) = buf;
	if (!arg->silent)
	{
		EXITIF(!(str = ft_strnew(2)));
		str[0] = 's';
		str[1] = name;
		ld_push_back(&arg->ops, str);
	}
	return (1);
}

int						px(t_stacks_state *arg, char name)
{
	t_list				**dst;
	t_list				**src;
	char				*str;

	name == 'a' ? (dst = &arg->a)
				: (dst = &arg->b);
	name == 'a' ? (src = &arg->b)
				: (src = &arg->a);
	if (!arg->silent)
	{
		EXITIF(!(str = ft_strnew(2)));
		str[0] = 'p';
		str[1] = name;
		ld_push_back(&arg->ops, str);
	}
	if (src && *src)
		return (l_push_front(dst, l_pop_front(src)));
	return (1);
}

int						rx(t_stacks_state *arg, char name)
{
	t_list				**a;
	char				*str;

	name == 'a' ? (a = &arg->a)
				: (a = &arg->b);
	if (!arg->silent)
	{
		EXITIF(!(str = ft_strnew(2)));
		str[0] = 'r';
		str[1] = name;
		ld_push_back(&arg->ops, str);
	}
	if (!a || !*a)
		return (1);
	l_push_back(a, l_pop_front(a));
	return (1);
}

int						rrx(t_stacks_state *arg, char name)
{
	t_list				**a;
	char				*str;

	name == 'a' ? (a = &arg->a)
				: (a = &arg->b);
	if (!arg->silent)
	{
		EXITIF(!(str = ft_strnew(3)));
		str[0] = 'r';
		str[1] = 'r';
		str[2] = name;
		ld_push_back(&arg->ops, str);
	}
	if (!a || !*a)
		return (1);
	l_push_front(a, l_pop_back(a));
	return (1);
}
