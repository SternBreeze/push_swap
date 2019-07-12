/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:48:19 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:52:04 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				is_anything_to_swap(t_list *a, size_t len)
{
	t_list				*t;

	t = a;
	while (len-- > 0 && t && t->next)
	{
		if (DATA(t) > DATA(t->next))
			return (1);
		t = t->next;
	}
	return (0);
}

static void				spinn_back(t_stacks_state *arg)
{
	int					min;

	min = l_int_min(arg->a);
	if ((l_int_positon(arg->a, min)) < l_size(arg->a) / 2)
	{
		while (DATA(arg->a) != min)
			RRA;
	}
	else
		while (DATA(arg->a) != min)
			RA;
}

void					int_bubble_sort(int m[], size_t i)
{
	int					stop;
	size_t				j;
	int					b;

	stop = 0;
	while (!stop)
	{
		stop = 1;
		j = -1;
		while (++j < i - 1)
			if (m[j] > m[j + 1])
			{
				b = m[j];
				m[j] = m[j + 1];
				m[j + 1] = b;
				stop = 0;
			}
	}
}

void					bubble_sort(t_stacks_state *arg)
{
	size_t				len;

	len = l_size(arg->a);
	while (1)
		if (is_anything_to_swap(arg->a, len - 1))
		{
			if (DATA(arg->a) > DATA((arg->a)->next))
				SA;
			else
				while (DATA(arg->a) < DATA((arg->a)->next))
				{
					RA;
					len--;
				}
		}
		else
		{
			spinn_back(arg);
			if (!(is_anything_to_swap(arg->a, len = l_size(arg->a))))
				break ;
		}
	spinn_back(arg);
}
