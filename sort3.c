/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:59:29 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/07 21:32:05 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						sort3(t_stacks_state *arg, int len)
{
	if (len <= 1 || (arg->curstack == 'a' && !arg->a)
					|| (arg->curstack == 'b' && !arg->b))
		return (1);
	if (l_size(arg->curstack == 'a' ? arg->a : arg->b) <= 3)
		arg->curstack == 'a' ?
		sort3_a(arg, len) : sort3_b(arg, len);
	else
		arg->curstack == 'a' ?
		noshift_sort3_a(arg, len) : noshift_sort3_b(arg, len);
	return (1);
}

void					sort3_a(t_stacks_state *arg, int len)
{
	int					q;
	int					w;
	int					e;

	q = DATA(arg->a);
	w = len >= 2 ? DATA((arg->a)->next) : 0;
	e = len == 3 ? DATA((arg->a)->next->next) : 0;
	if (len == 2 && q > w)
		SA;
	else if (len == 3 && q > w && q > e)
	{
		RA;
		if (w > e)
			SA;
	}
	else if (len == 3 && w > e)
	{
		RRA;
		if (e > q)
			SA;
	}
	else if (len == 3 && q > w)
		SA;
}

void					sort3_b(t_stacks_state *arg, int len)
{
	int					q;
	int					w;
	int					e;

	q = DATA(arg->b);
	w = len >= 2 ? DATA((arg->b)->next) : 0;
	e = len == 3 ? DATA((arg->b)->next->next) : 0;
	if (len == 2 && q < w)
		SB;
	else if (len == 3 && q < w && q < e)
	{
		RB;
		if (w < e)
			SB;
	}
	else if (len == 3 && w < e)
	{
		RRB;
		if (e < q)
			SB;
	}
	else if (len == 3 && q < w)
		SB;
}

void					noshift_sort3_a(t_stacks_state *arg, int len)
{
	int					q;
	int					w;
	int					e;

	q = DATA(arg->a);
	w = len >= 2 ? DATA((arg->a)->next) : 0;
	e = len == 3 ? DATA((arg->a)->next->next) : 0;
	if (len == 3 && q > w && q > e)
	{
		SA;
		RA;
		SA;
		RRA;
		(w > e) ? SA : DONOTHING;
	}
	else if (q > w)
		SA;
	else if (len == 3 && w > e)
	{
		RA;
		SA;
		RRA;
		(q > e) ? SA : DONOTHING;
	}
}

void					noshift_sort3_b(t_stacks_state *arg, int len)
{
	int					q;
	int					w;
	int					e;

	q = DATA(arg->b);
	w = len >= 2 ? DATA((arg->b)->next) : 0;
	e = len == 3 ? DATA((arg->b)->next->next) : 0;
	if (len == 3 && q < w && q < e)
	{
		SB;
		RB;
		SB;
		RRB;
		(w < e) ? SB : DONOTHING;
	}
	else if (q < w)
		SB;
	else if (len == 3 && w < e)
	{
		RB;
		SB;
		RRB;
		(q < e) ? SB : DONOTHING;
	}
}
