/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:29:17 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 17:58:33 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						main(int argc, char const *argv[])
{
	t_stacks_state		arg;
	char				*filename;
	int					mod;

	arg_init(&arg);
	filename = 0;
	if ((mod = parse_arg(argc, argv, &arg.a, &filename)) == 0)
		error(&arg, &filename);
	if (check_options(mod, USAGE))
		return (ft_int_free((void**)&filename, 1) && arg_destroy(&arg));
	if (arg.a)
	{
		if (!(try_sort(&arg, mod, filename)))
			error(&arg, &filename);
		if (check_options(mod, PRINTRES))
			print(&arg);
		if (sorted(&arg))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (ft_int_free((void**)&filename, 1) && arg_destroy(&arg));
}
