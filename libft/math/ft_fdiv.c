/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:13:36 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/26 17:13:50 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_fdiv(long double f, int len)
{
	while (len-- > 0)
		f /= 10;
	return ((int)f);
}
