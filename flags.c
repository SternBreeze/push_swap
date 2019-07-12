/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:46:31 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/07 17:30:06 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						usage(const char *s, int *mod)
{
	if (s[2] != '\0')
		return ((*mod = 0));
	ft_printf("usage:\t\t./checker %s <numbers> <commands>\n",
			"-[i | [s | q | b] | p | fFILE$]");
	ft_printf("\t\t./push_swap <numbers> <commands>\n");
	ft_printf("\t\tARG=\"<numbers>\"; ./push_swap $ARG | ./checker $ARG\n");
	ft_printf("\t\t./push_swap -fops$ %1$s; ./checker -fops$ %1$s\n",
															"$(cat <file>)");
	ft_printf("\nflags:\t\t-h\tprint usage\n");
	ft_printf("\t\t-i\tinteractive checker's mode\n");
	ft_printf("\t\t-s\tuse select sort to generate sorting commands\n");
	ft_printf("\t\t-q\tuse quick sort to generate sorting commands\n");
	ft_printf("\t\t-b\tuse bubble sort to generate sorting commands\n");
	ft_printf("\t\t-p\tprint stack state\n");
	ft_printf("\t\t-ffile$ to print (push_swap) or read (checker)\n");
	ft_printf("\t\t\tsorting commands to / from file\n");
	ft_printf("\ngen:\t\t./gen <amount of numbers> > <file>\n");
	ft_printf("\ntest:\t\t./test.sh [-h] quick sort auto test\n\n");
	return (set_option(mod, USAGE));
}

int						get_flags(const char *s, int *mod, char **filename)
{
	int					i;

	i = 1;
	if (s[i] == 'h')
		return (usage(s, mod));
	if (s[i] == 'i' && i++)
		set_option(mod, INTERACTIVE);
	if (s[i] == 's' && !check_options(*mod, QUICKSORT | BUBBLESORT) && i++)
		set_option(mod, SELECTSORT);
	if (s[i] == 'q' && !check_options(*mod, SELECTSORT | BUBBLESORT) && i++)
		set_option(mod, QUICKSORT);
	if (s[i] == 'b' && !check_options(*mod, SELECTSORT | QUICKSORT) && i++)
		set_option(mod, BUBBLESORT);
	if (s[i] == 'p' && !check_options(*mod, INTERACTIVE) && i++)
		set_option(mod, PRINTRES);
	if (s[i] == 'f')
	{
		if ((i += get_filename(s + i + 1, filename) + 2) < 0)
			return ((*mod = 0));
		set_option(mod, FILEFLAG);
	}
	if (i != 1 && s[i] == '\0')
		return (1);
	return ((*mod = 0));
}

int						check_options(int flags, int flag)
{
	return ((flags & flag) != 0);
}

int						set_option(int *flags, int flag)
{
	int				i;

	i = 0;
	while (flag > 1)
	{
		i++;
		flag >>= 1;
	}
	return ((*flags += (int)ft_pow(2, i)));
}
