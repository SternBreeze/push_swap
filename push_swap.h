/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:16:31 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/08 18:55:48 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

# define EXITIF(x)		if (x) return (0)

# define DATA(X)		*(int *)(X)->data
# define ISOP(X, Y)		ft_strcmp((char *)(X)->data, Y) == 0

# define DONOTHING		(void)0;

# define PA				px(arg, 'a')
# define PB				px(arg, 'b')
# define RA				rx(arg, 'a')
# define RB				rx(arg, 'b')
# define RRA			rrx(arg, 'a')
# define RRB			rrx(arg, 'b')
# define SA				sx(arg, 'a')
# define SB				sx(arg, 'b')
# define SS				ss(arg)
# define RR				rr(arg)
# define RRR			rrr(arg)

# define INTERACTIVE	(1 << 0)
# define SELECTSORT		(1 << 1)
# define QUICKSORT		(1 << 2)
# define BUBBLESORT		(1 << 3)
# define PRINTRES		(1 << 4)
# define FILEFLAG		(1 << 5)
# define USAGE			(1 << 6)
# define NOMODE			(1 << 7)

typedef struct			s_stacks_state
{
	t_list				*a;
	t_list				*b;
	t_list				*ops;
	char				curstack;
	int					silent;
}						t_stacks_state;
/*
** ./gen 1000 > test;./push_swap -q $(cat test) | ./checker -p $(cat test)
** ./gen 1000 > t1;./push_swap $(cat t1) > ops; ./checker " -fops$" $(cat t1)
*/
/*
** 						op.c
*/
int						sx(t_stacks_state *arg, char name);
int						px(t_stacks_state *arg, char name);
int						rx(t_stacks_state *arg, char name);
int						rrx(t_stacks_state *arg, char name);
/*
** 						dual_ops
*/
int						ss(t_stacks_state *arg);
int						rr(t_stacks_state *arg);
int						rrr(t_stacks_state *arg);
/*
**						cmd.c
*/
char					cmd_is(char *s, char *cmd);
int						do_cmd(char *cmd, t_stacks_state *arg, char mod);
/*
** 						service.c
*/
int						get_filename(const char *s, char **filename);
void					error(t_stacks_state *arg, char **filename);
int						valid(const char *s, t_list **stack, intmax_t num);
void					print(t_stacks_state *arg);
void					print_ops(t_stacks_state *arg);
/*
** 						parse.c
*/
int						push_num(const char *argv, t_list **a);
int						fill_stack(char **arg, t_list **a);
int						parse_arg(int argc, char const *argv[], t_list **a,
															char **filename);
/*
** 						sort3.c
*/
int						sort3(t_stacks_state *arg, int len);
void					sort3_a(t_stacks_state *arg, int len);
void					sort3_b(t_stacks_state *arg, int len);
void					noshift_sort3_a(t_stacks_state *arg, int len);
void					noshift_sort3_b(t_stacks_state *arg, int len);
/*
** 						flags.c
*/
int						usage(const char *s, int *mod);
int						check_options(int flags, int flag);
int						set_option(int *flags, int flag);
int						get_flags(const char *s, int *mod, char **filename);
/*
** 						is_sorted.c
*/
int						nearly_reverse_sorted(t_list *a);
int						nearly_sorted(t_list *a);
int						try_sort(t_stacks_state *arg, int mod, char *filename);
int						sorted(t_stacks_state *arg);
/*
** 						select_sort.c
*/
void					select_sort(t_stacks_state *arg);
/*
**						quick_sort.c
*/
int						quick_sort(t_stacks_state *arg, int len);
/*
**						optimize.c
*/
void					rm_useless_ops(t_list **t);
void					replace_rarb(t_list **t);
void					replace_rrarrb(t_list **t);
void					replace_sasb(t_list **t);
/*
**						bubble_sort.c
*/
void					bubble_sort(t_stacks_state *arg);
void					int_bubble_sort(int m[], size_t i);
/*
**						stacks_state.c
*/
int						arg_init(t_stacks_state *arg);
int						arg_destroy(t_stacks_state *arg);
t_stacks_state			arg_copy(t_stacks_state *arg);
/*
** 						pivot.c
*/
int						get_pivot(t_list *a, size_t len);
#endif
