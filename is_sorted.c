/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:20:20 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:19:28 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						nearly_reverse_sorted(t_list *a)
{
	t_list				*t;
	int					sortfactor;
	int					size;

	size = 1;
	sortfactor = 1;
	t = a;
	while (t->next)
	{
		if (DATA(t) > DATA(t->next))
			sortfactor++;
		t = t->next;
		size++;
	}
	if (size - sortfactor <= ft_sqrt(size) / 2)
		return (1);
	return (0);
}

int						nearly_sorted(t_list *a)
{
	t_list				*t;
	int					sortfactor;
	int					size;

	size = 1;
	sortfactor = 1;
	t = a;
	while (t->next)
	{
		if (DATA(t) < DATA(t->next))
			sortfactor++;
		t = t->next;
		size++;
	}
	return (size - sortfactor < ft_sqrt(size));
}

int						sorted(t_stacks_state *arg)
{
	t_list				*a;

	a = arg->a;
	while (a->next)
	{
		if (DATA(a) > DATA(a->next))
			return (0);
		a = a->next;
	}
	return (arg->b == NULL);
}

int						try_sort(t_stacks_state *arg, int mod, char *filename)
{
	char				*cmd;
	int					commands;
	int					fd;

	fd = 0;
	commands = 0;
	cmd = 0;
	if (check_options(mod, INTERACTIVE))
		print(arg);
	if (check_options(mod, FILEFLAG))
		EXITIF((fd = open(filename, O_RDONLY)) < 0);
	while (ft_int_free((void **)&cmd, 1) && (get_next_line(fd, &cmd) > 0))
	{
		EXITIF(!do_cmd(cmd, arg, mod));
		if (check_options(mod, INTERACTIVE))
		{
			commands++;
			ft_printf(CYN"Executed: %s\n"RESET, cmd);
			print(arg);
		}
	}
	close(fd);
	if (check_options(mod, INTERACTIVE))
		ft_printf(CYN"%d command(s) used"RESET"\n", commands);
	return (ft_int_free((void **)&cmd, 1));
}
