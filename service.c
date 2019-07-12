/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:14:20 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 16:22:33 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					error(t_stacks_state *arg, char **filename)
{
	arg_destroy(arg);
	ft_memdel((void**)filename);
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(1);
}

int						valid(const char *s, t_list **stack, intmax_t num)
{
	size_t				len;

	if (!s || !*s)
		return (0);
	len = 0;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(s[len]))
		len++;
	if (len > ft_digs(INT_MAX)
		|| num > INT_MAX || num < INT_MIN
		|| l_int_find(*stack, num))
		return (0);
	return (1);
}

void					print(t_stacks_state *arg)
{
	t_list				*a;
	t_list				*b;
	int					len;

	a = arg->a;
	b = arg->b;
	ft_printf(RED"a:\t\t\t"BLU"\tb:\n"RESET);
	while (a || b)
	{
		if (a)
		{
			len = ft_nlen(DATA(a), 10);
			ft_printf(RED"%d"RESET, DATA(a));
			a = a->next;
		}
		else
			len = 0;
		if (b)
		{
			ft_printf(BLU"%*d\n"RESET, 34 - len, DATA(b));
			b = b->next;
		}
		else
			ft_printf("\n");
	}
}

void					print_ops(t_stacks_state *arg)
{
	t_list				*ops;

	ops = arg->ops;
	if (!ops)
		return ;
	while (ops)
	{
		ft_putstr((char *)ops->data);
		ft_putchar('\n');
		ops = ops->next;
	}
}
