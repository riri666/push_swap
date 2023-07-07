/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:32:51 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/28 18:19:23 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*s_max_stack(t_stack **a)
{
	t_stack	*max;
	t_stack	*first;

	max = *a;
	first = *a;
	*a = (*a)->next;
	while (*a != first)
	{
		if ((max)->element < (*a)->element)
			max = *a;
		*a = (*a)->next;
	}
	return (max);
}

int	ft_indx(int *tab, int size, int element, int index)
{
	int	i;

	i = index;
	while (i < size)
	{
		if (tab[i] == element)
			return (1);
		i++;
	}
	return (0);
}

int	ft_max_range(t_stack **s, int range)
{
	t_stack	*first;
	int		max;
	int		i;

	i = 0;
	first = *s;
	max = (*s)->element;
	*s = (*s)->next;
	while (i++ < range - 1)
	{
		if ((*s)->element > max)
			max = (*s)->element;
		*s = (*s)->next;
	}
	*s = (first)->prev;
	i = 0;
	while (i++ < range)
	{
		if ((*s)->element > max)
			max = (*s)->element;
		*s = (*s)->prev;
	}
	*s = first;
	return (max);
}

void	ft_b_range(t_stack **s, int max, int range)
{
	t_stack	*first;
	int		i;

	i = -1;
	first = *s;
	while (++i < range)
	{
		if ((*s)->element == max)
			break ;
		*s = (*s)->next;
	}
	*s = first;
	if (i == range)
	{
		while ((*s)->element != max)
			reverse_rotate(s, 2);
	}
	else
	{
		range = 0;
		while (range++ < i)
			rotate_stack(s, 2);
	}
}

void	ft_last_sort(t_stack **a, t_stack **b, int *tab_min, int range)
{
	int	a_max;
	int	max;
	int	i;

	i = 0;
	a_max = (s_max_stack(a))->element;
	while (tab_min[i] != a_max)
		i++;
	while (s_size(b) - 1)
	{
		max = ft_max_range(b, range);
		if (((*b)->next)->element == max)
			swap_stack(b, 2);
		else
			ft_b_range(b, max, range);
		while ((*b)->element > (*a)->element)
			rotate_stack(a, 1);
		while ((*b)->element < ((*a)->prev)->element
			&& ((*a)->prev)->element != tab_min[i])
			reverse_rotate(a, 1);
		push_stack(a, b, 1);
	}
	push_stack(a, b, 1);
	free(tab_min);
}
