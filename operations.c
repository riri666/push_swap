/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:54:00 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/21 13:28:13 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **s, int i)
{
	t_stack	*second;

	if (*s == NULL)
		return ;
	second = (*s)->next;
	(((*s)->next)->next)->prev = *s;
	(*s)->next = ((*s)->next)->next;
	s_insert_start(s, second);
	if (i == 1)
		ft_printf("sa\n");
	if (i == 2)
		ft_printf("sb\n");
}

void	push_stack(t_stack **a, t_stack **b, int i)
{
	t_stack	*b_head;

	if (*b == NULL)
		return ;
	b_head = s_new_stack((*b)->element);
	if (*b == NULL)
		return ;
	s_delete_start(b);
	s_insert_start(a, b_head);
	if (i == 1)
		ft_printf("pa\n");
	if (i == 2)
		ft_printf("pb\n");
}

void	rotate_stack(t_stack **s, int i)
{
	t_stack	*head;

	if (*s == NULL || ((*s)->next == *s))
		return ;
	head = s_new_stack((*s)->element);
	s_delete_start(s);
	s_insert_end(s, head);
	if (i == 1)
		ft_printf("ra\n");
	if (i == 2)
		ft_printf("rb\n");
}

void	reverse_rotate(t_stack **s, int i)
{
	t_stack	*end;

	if (*s == NULL || ((*s)->next == *s))
		return ;
	end = s_new_stack(((*s)->prev)->element);
	s_delete_end(s);
	s_insert_start(s, end);
	if (i == 1)
		ft_printf("rra\n");
	if (i == 2)
		ft_printf("rrb\n");
}

void	ft_double_op(t_stack **a, t_stack **b, int test)
{
	if (test == 1)
	{
		swap_stack(a, 0);
		swap_stack(b, 0);
	}
	if (test == 2)
	{
		rotate_stack(a, 0);
		rotate_stack(b, 0);
	}
	if (test == 3)
	{
		reverse_rotate(a, 0);
		reverse_rotate(b, 0);
	}
}
