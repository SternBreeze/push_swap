/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmors-um <gmors-um@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 18:28:50 by gmors-um          #+#    #+#             */
/*   Updated: 2018/12/25 18:29:06 by gmors-um         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_clear_int(int *mas, int size)
{
	while (size--)
		mas[size] = 0;
}
