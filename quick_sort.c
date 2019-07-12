/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:51:34 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:50:31 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				goback(t_stacks_state *arg, size_t spinned)
{
	size_t				size;

	size = l_size(arg->curstack == 'a' ? arg->a : arg->b);
	if (spinned > size / 2)
	{
		spinned = size - spinned;
		while (spinned-- > 0)
			arg->curstack == 'a' ? RA : RB;
	}
	else
		while (spinned-- > 0)
			arg->curstack == 'a' ? RRA : RRB;
}

static int				is_anything_to_push(t_stacks_state *arg, int len, int p)
{
	t_list				*a;

	a = arg->a;
	if (a)
		while (len--)
		{
			if (arg->curstack == 'a' && DATA(a) < p)
				return (1);
			else if (arg->curstack == 'b' && DATA(a) > p)
				return (1);
			a = a->next;
		}
	return (0);
}

static void				qsort_split(t_stacks_state *arg, int len,
														int pushed, int spinned)
{
	if (arg->curstack == 'a')
	{
		goback(arg, spinned);
		quick_sort(arg, len - pushed);
		arg->curstack = 'b';
		quick_sort(arg, pushed);
		arg->curstack = 'a';
	}
	else
	{
		arg->curstack = 'a';
		quick_sort(arg, pushed);
		arg->curstack = 'b';
		goback(arg, spinned);
		quick_sort(arg, len - pushed);
	}
}

static void				partition(t_stacks_state *arg, int *spinned,
														int *pushed, int pivot)
{
	if (arg->curstack == 'a' ? (DATA(arg->a) < pivot) : (DATA(arg->b) > pivot))
	{
		arg->curstack == 'a' ? PB : PA;
		(*pushed)++;
	}
	else
	{
		arg->curstack == 'a' ? RA : RB;
		(*spinned)++;
	}
}

int						quick_sort(t_stacks_state *arg, int len)
{
	int					p;
	int					i;
	int					pushed;
	int					spinned;

	if (len <= 3)
		return (sort3(arg, len));
	pushed = 0;
	spinned = 0;
	p = get_pivot(arg->curstack == 'a' ? arg->a : arg->b, len);
	i = 0;
	while (is_anything_to_push(arg, len - i, p) && i++ < len)
		partition(arg, &spinned, &pushed, p);
	qsort_split(arg, len, pushed, spinned);
	while (pushed--)
		arg->curstack == 'a' ? PA : PB;
	return (1);
}
