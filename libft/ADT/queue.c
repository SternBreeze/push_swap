/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:39:45 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/29 14:20:45 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					q_init(t_queue **q)
{
	if (!(q = (t_queue**)malloc(sizeof(t_queue))))
		return (0);
	if (!(s_init(&(*q)->in) || !(s_init(&(*q)->out))))
		return (0);
	return (1);
}

int					q_is_empty(t_queue *q)
{
	return (s_is_empty(q->in) && s_is_empty(q->out));
}

void				*q_pop(t_queue *q)
{
	if (q && !q_is_empty(q))
	{
		if (s_is_empty(q->out))
			while (!s_is_empty(q->in))
				if (!(s_push(q->out, s_pop(q->in))))
					return (NULL);
		return (s_pop(q->out));
	}
	return (NULL);
}

int					q_push(t_queue *q, void *data)
{
	return (s_push(q->in, data));
}

void				q_destroy(t_queue **q)
{
	s_destroy(&(*q)->in);
	s_destroy(&(*q)->out);
	free(*q);
}
