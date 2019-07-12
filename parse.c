/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:43:11 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:23:18 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						get_filename(const char *s, char **filename)
{
	int				len;

	len = ft_strlento(s, '$');
	if (len == 0 || s[len] != '$')
		return (-100);
	*filename = ft_strsub(s, 0, len);
	return (len);
}

int						after_num(const char *s)
{
	int					j;

	j = 0;
	if (s[j] == '-' || s[j] == '+')
		j++;
	while (ft_isdigit(s[j]))
		j++;
	return (j);
}

int						push_num(const char *argv, t_list **a)
{
	intmax_t			num;
	int					*p;

	num = ft_atoi(argv);
	EXITIF(!valid(argv, a, num));
	if (!ld_push_front(a, (p = ft_int_get_mass(num))))
		return (ft_int_free((void **)&p, 0));
	return (1);
}

int						fill_stack(char **arg, t_list **a)
{
	int					added;

	added = 0;
	while (*arg && (ft_isdigit(**arg)
			|| ((**arg == '-' || **arg == '+') && ft_isdigit(arg[0][1]))))
	{
		EXITIF(!(push_num(*arg, a)));
		if (arg[0][after_num(*arg)] != '\0')
			return (0);
		arg++;
		added = 1;
	}
	if (!added)
		return (0);
	return (1);
}

int						parse_arg(int argc, char const *argv[],
													t_list **a, char **filename)
{
	char				**arg;
	char				**r;
	int					i;
	int					mod;

	i = argc;
	mod = NOMODE;
	arg = 0;
	while (--i > 0)
	{
		ft_freemas(&arg, 0);
		arg = ft_strsplit(argv[i], ' ');
		r = arg;
		if (r && r[0][0] == '-' && !ft_isdigit(r[0][1]))
		{
			get_flags(*r++, &mod, filename);
			if (check_options(mod, USAGE) || mod == 0)
				return (ft_freemas(&arg, mod));
			if (!*r)
				continue;
		}
		if (!r || !fill_stack(r, a))
			return (ft_freemas(&arg, 0));
	}
	return (ft_freemas(&arg, mod));
}
