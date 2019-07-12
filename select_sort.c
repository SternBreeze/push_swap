/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:47:15 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 19:18:31 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				go_to_swap(t_stacks_state *arg)
{
	int					min;
	int					max;

	min = l_int_min(arg->a);
	max = l_int_max(arg->a);
	if ((l_int_positon(arg->a, min)) < l_size(arg->a) / 2)
		while (DATA(arg->a) != min && DATA(arg->a) != max)
			RRA;
	else
		while (DATA(arg->a) != min && DATA(arg->a) != max)
			RA;
}

static void				spinn_back(t_stacks_state *arg)
{
	int					max;

	max = l_int_max(arg->b);
	if ((l_int_positon(arg->b, max)) < l_size(arg->b) / 2)
		while (DATA(arg->b) != max)
			RRB;
	else
		while (DATA(arg->b) != max)
			RB;
}

void					select_sort(t_stacks_state *arg)
{
	int					min;

	min = INT_MAX;
	while (arg->a)
		if (l_size(arg->a) == 3)
		{
			sort3_a(arg, 3);
			PB;
			PB;
			PB;
			break ;
		}
		else if (DATA(arg->a) == (min = l_int_min(arg->a)))
			PB;
		else if (DATA(arg->a) == (l_int_max(arg->a)))
		{
			PB;
			RB;
		}
		else
			go_to_swap(arg);
	spinn_back(arg);
	while (arg->b)
		PA;
}
