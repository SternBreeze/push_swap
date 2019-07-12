/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:57:55 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:25:05 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					rm_useless_ops(t_list **t)
{
	if ((t && (*t) && (*t)->next)
		&& ((ISOP((*t), "rrb") && ISOP((*t)->next, "rb"))
		|| (ISOP((*t), "rra") && ISOP((*t)->next, "ra"))
		|| (ISOP((*t), "ra") && ISOP((*t)->next, "rra"))
		|| (ISOP((*t), "rb") && ISOP((*t)->next, "rrb"))
		|| (ISOP((*t), "pa") && ISOP((*t)->next, "pb"))
		|| (ISOP((*t), "pb") && ISOP((*t)->next, "pa"))
		|| (ISOP((*t), "sa") && ISOP((*t)->next, "sa"))
		|| (ISOP((*t), "sb") && ISOP((*t)->next, "sb"))))
	{
		l_remove(t);
		l_remove(t);
		(*t) = (*t)->prev ? (*t)->prev : (*t);
		(*t) = (*t)->prev ? (*t)->prev : (*t);
	}
}

void					replace_rarb(t_list **t)
{
	if ((t && (*t) && (*t)->next)
		&& ((ISOP((*t), "ra") && ISOP((*t)->next, "rb"))
		|| (ISOP((*t), "rb") && ISOP((*t)->next, "ra"))))
	{
		l_remove(t);
		free((*t)->data);
		(*t)->data = ft_strdup("rr");
	}
}

void					replace_rrarrb(t_list **t)
{
	if ((t && (*t) && (*t)->next)
		&& ((ISOP((*t), "rra") && ISOP((*t)->next, "rrb"))
		|| (ISOP((*t), "rrb") && ISOP((*t)->next, "rra"))))
	{
		l_remove(t);
		free((*t)->data);
		(*t)->data = ft_strdup("rrr");
	}
}

void					replace_sasb(t_list **t)
{
	if ((t && (*t) && (*t)->next)
		&& ((ISOP((*t), "sa") && ISOP((*t)->next, "sb"))
		|| (ISOP((*t), "sb") && ISOP((*t)->next, "sa"))))
	{
		l_remove(t);
		free((*t)->data);
		(*t)->data = ft_strdup("ss");
	}
}
