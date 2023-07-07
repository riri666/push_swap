/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:53:15 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/31 16:05:55 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_stack
{
	int				element;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int			ft_printf(const char *str, ...);
int			ft_write_c(char c, va_list	param);
int			ft_write_s(va_list param);
int			ft_write_d(va_list param, char *base, int test);
void		ft_putchar(char c);
void		ft_putstr(char *s);
int			ft_strlen(char *s);
int			ft_isprint(int c);
char		*ft_strchr(const char *s, int c);
long int	ft_atoi(char *s);
int			ft_isnum(char *s);
int			ft_strcmp(char *s1, char *s2);
int			ch_num(int size, char **s);
int			ch_lim(int size, char **s);
int			ch_dup(int size, char **s);
t_stack		*s_new_stack(int first);
int			s_size(t_stack **s);
void		ft_switch(t_stack	**a, t_stack **b, int size);
int			s_sorted(t_stack **s);
void		ft_print_stack(t_stack **s, char *str);
void		s_insert_end(t_stack **s, t_stack *new);
void		s_insert_start(t_stack **s, t_stack *new);
void		s_delete_start(t_stack **s);
void		s_delete_end(t_stack **s);
void		ft_free_stack(t_stack **a);
void		swap_stack(t_stack **s, int i);
void		push_stack(t_stack **a, t_stack **b, int i);
void		rotate_stack(t_stack **a, int i);
void		reverse_rotate(t_stack **s, int i);
void		ft_double_op(t_stack **a, t_stack **b, int test);
void		s_sort_2(t_stack **s);
void		s_sort_3(t_stack **s);
void		s_sort_5(t_stack **a, t_stack **b);
void		s_big_sort(t_stack **a, t_stack **b, int i, int j);
t_stack		*s_min(t_stack **s);
int			closest_min(t_stack **s, t_stack *min);
int			*ft_pack_min(t_stack **a);
int			ft_exists(int *tab, int size, int element);
int			ft_indx(int *tab, int size, int element, int index);
void		ft_closest(t_stack **a, int *tab, int pack_size, int index);
t_stack		*s_max_stack(t_stack **a);
void		ft_init(t_stack **a, t_stack **b, int *tab);
int			ft_variable(t_stack **a, t_stack **b, int test);
int			ft_max_range(t_stack **s, int range);
void		ft_b_range(t_stack **s, int max, int range);
void		ft_closest(t_stack **a, int *tab, int pack_size, int index);
int			ft_s_clos(int i, int nb_pack, int nb_elements, int pack_size);
void		ft_last_sort(t_stack **a, t_stack **b, int *tab_min, int range);

#endif