/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:06:02 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/07 17:35:36 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		set_arg(int argc, char const *argv[], int *max, int *dig)
{
	*dig = 5;
	if (argc < 2)
		*max = 500;
	else
	{
		*max = atoi(argv[1]);
		if (argc == 3)
			*dig = atoi(argv[2]);
	}
	*dig = (int)ft_pow(10, *dig);
}

int			main(int argc, char const *argv[])
{
	int		c;
	t_stack	*s;
	int		max;
	int		dig;

	srand(time(NULL));
	set_arg(argc, argv, &max, &dig);
	if (dig < max)
	{
		ft_printf("Incorrect input!\n");
		return (-1);
	}
	s_init(&s);
	c = rand() % dig;
	s_push(s, ft_int_get_mass(c));
	while ((int)s_size(s) <= max)
		if (s_int_positon(s, (c = rand() % dig)) == -1)
		{
			s_push(s, ft_int_get_mass(c));
			ft_printf("%d\n", c);
		}
	return (s_destroy(&s));
}
