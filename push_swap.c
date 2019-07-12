/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:16:18 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:45:35 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				optimize(t_stacks_state *arg)
{
	t_list				*t;

	if (!arg->ops)
		return ;
	t = arg->ops;
	while (t)
	{
		rm_useless_ops(&t);
		replace_rrarrb(&t);
		replace_rarb(&t);
		replace_sasb(&t);
		t = t->next;
	}
}

void					choose_best(t_stacks_state *arg)
{
	t_stacks_state		arg1;
	t_stacks_state		arg2;
	t_stacks_state		arg3;
	size_t				minops;

	arg1 = arg_copy(arg);
	arg2 = arg_copy(arg);
	arg3 = arg_copy(arg);
	bubble_sort(&arg1);
	optimize(&arg1);
	select_sort(&arg2);
	optimize(&arg2);
	quick_sort(&arg3, l_size(arg3.a));
	optimize(&arg3);
	arg_destroy(arg);
	minops = ft_min3(l_size(arg1.ops), l_size(arg2.ops), l_size(arg3.ops));
	if (minops == l_size(arg1.ops))
		*arg = arg_copy(&arg1);
	else if (minops == l_size(arg2.ops))
		*arg = arg_copy(&arg2);
	else
		*arg = arg_copy(&arg3);
	arg_destroy(&arg1);
	arg_destroy(&arg2);
	arg_destroy(&arg3);
}

static void				sort(t_stacks_state *arg, int mod)
{
	size_t				size;

	size = l_size(arg->a);
	if (size <= 3 && !check_options(mod, SELECTSORT | QUICKSORT | BUBBLESORT))
		sort3_a(arg, size);
	else if ((size < 30
			|| nearly_sorted(arg->a) || nearly_reverse_sorted(arg->a))
			&& !check_options(mod, SELECTSORT | QUICKSORT | BUBBLESORT))
	{
		arg->curstack = 'a';
		choose_best(arg);
		return ;
	}
	else if (check_options(mod, BUBBLESORT)
							&& !check_options(mod, SELECTSORT | QUICKSORT))
		bubble_sort(arg);
	else if (check_options(mod, SELECTSORT) && !check_options(mod, QUICKSORT))
		select_sort(arg);
	else
		quick_sort(arg, size);
	optimize(arg);
}

static int				ops_to_file(t_stacks_state *arg, char *filename)
{
	t_list				*ops;
	int					fd;
	char				*str;

	ops = arg->ops;
	fd = 1;
	if (!ops)
		return (0);
	EXITIF((fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0666)) < 0);
	while (ops)
	{
		str = (char *)ops->data;
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		ops = ops->next;
	}
	close(fd);
	return (1);
}

int						main(int argc, char const *argv[])
{
	t_stacks_state		arg;
	int					mod;
	char				*filename;

	filename = 0;
	arg_init(&arg);
	if ((mod = parse_arg(argc, argv, &arg.a, &filename)) == 0)
		error(&arg, &filename);
	if (check_options(mod, USAGE))
		exit(ft_int_free((void **)&filename, 1) && arg_destroy(&arg));
	if (!arg.a || sorted(&arg))
		return (ft_int_free((void **)&filename, 1) && arg_destroy(&arg));
	sort(&arg, mod);
	print_ops(&arg);
	if (check_options(mod, PRINTRES))
		print(&arg);
	if (check_options(mod, FILEFLAG) && !(ops_to_file(&arg, filename)))
		error(&arg, &filename);
	ft_memdel((void **)&filename);
	return (arg_destroy(&arg));
}
