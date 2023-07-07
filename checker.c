/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:32:26 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/31 16:16:25 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_final(t_stack **a, t_stack **b)
{
	if ((s_size(a) != 0) && s_sorted(a) && (s_size(b) == 0))
	{
		ft_printf("OK\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("KO\n");
		exit(EXIT_FAILURE);
	}
}

static void	ft_options(t_stack **a, t_stack **b, char *buf)
{
	if (ft_strcmp(buf, "sa\n") == 0)
		swap_stack(a, 0);
	else if (ft_strcmp(buf, "sb\n") == 0)
		swap_stack(a, 0);
	else if (ft_strcmp(buf, "pa\n") == 0)
		push_stack(a, b, 0);
	else if (ft_strcmp(buf, "pb\n") == 0)
		push_stack(b, a, 0);
	else if (ft_strcmp(buf, "ra\n") == 0)
		rotate_stack(a, 0);
	else if (ft_strcmp(buf, "rb\n") == 0)
		rotate_stack(b, 0);
	else if (ft_strcmp(buf, "rra\n") == 0)
		reverse_rotate(a, 0);
	else if (ft_strcmp(buf, "rrb\n") == 0)
		reverse_rotate(b, 0);
	else if (ft_strcmp(buf, "ss\n") == 0)
		ft_double_op(a, b, 1);
	else if (ft_strcmp(buf, "rr\n") == 0)
		ft_double_op(a, b, 2);
	else if (ft_strcmp(buf, "rrr\n") == 0)
		ft_double_op(a, b, 3);
	else
		ft_printf("Invalid input, try again.\n");
}

static void	ft_checker(t_stack **a, t_stack **b)
{
	char	*op;
	int		res;

	while (1)
	{
		op = malloc(sizeof(char) * 50);
		if (!op)
			return ;
		res = read(STDOUT_FILENO, op, 50);
		op[res] = '\0';
		if (res <= 0)
			ft_final(a, b);
		ft_options(a, b, op);
		free(op);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!ch_num(argc, argv) || !ch_lim(argc, argv) || !ch_dup(argc, argv))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	a = NULL;
	b = NULL;
	i = 0;
	while (++i < argc)
		s_insert_end(&a, s_new_stack(ft_atoi(argv[i])));
	ft_checker(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
}
