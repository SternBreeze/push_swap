/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:12:19 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 13:36:19 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char					cmd_is(char *s, char *cmd)
{
	int					i;
	char				res;

	EXITIF(!cmd);
	res = 0;
	i = 0;
	while (ft_isalpha(cmd[i]))
		if (cmd[i] == s[i])
			i++;
		else if (!res && s[i] == 'x' && (cmd[i] == 'a' || cmd[i] == 'b'))
		{
			res = cmd[i];
			i++;
		}
		else
			break ;
	if (s[i] != '\0' || cmd[i] != '\0')
		return (0);
	return (res ? res : 1);
}

int						do_cmd(char *cmd, t_stacks_state *arg, char mod)
{
	char				x;

	arg->silent = 1;
	if ((x = cmd_is("sx", cmd)))
		x == 'a' ? SA : SB;
	else if ((x = cmd_is("px", cmd)))
		x == 'a' ? PA : PB;
	else if (cmd_is("ss", cmd))
		SS;
	else if ((x = cmd_is("rx", cmd)))
		x == 'a' ? RA : RB;
	else if (cmd_is("rr", cmd))
		RR;
	else if ((x = cmd_is("rrx", cmd)))
		x == 'a' ? RRA : RRB;
	else if (cmd_is("rrr", cmd))
		RRR;
	else if (!check_options(mod, INTERACTIVE))
		return ((arg->silent = 0));
	arg->silent = 0;
	return (1);
}
