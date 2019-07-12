/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:11:41 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:51:01 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						get_pivot(t_list *a, size_t len)
{
	int					*m;
	t_list				*t;
	size_t				i;
	int					res;

	i = 0;
	t = a;
	EXITIF(!(m = (int *)malloc(sizeof(int) * l_size(a))));
	while (t && i < len)
	{
		m[i++] = DATA(t);
		t = t->next;
	}
	int_bubble_sort(m, i);
	res = m[i / 2];
	free(m);
	return (res);
}
