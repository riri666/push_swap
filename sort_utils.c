/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:53:31 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/29 17:48:09 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*s_min(t_stack **s)
{
	t_stack	*min;
	t_stack	*first;

	min = *s;
	first = *s;
	while ((*s)->next != first)
	{
		*s = (*s)->next;
		if ((*s)->element < min->element)
			min = *s;
	}
	*s = first;
	return (min);
}

int	s_size(t_stack **s)
{
	int		size;
	t_stack	*first;

	if (*s == NULL)
		return (0);
	size = 1;
	first = *s;
	while ((*s)->next != first)
	{
		size++;
		*s = (*s)->next;
	}
	*s = (*s)->next;
	return (size);
}

int	closest_min(t_stack **s, t_stack *min)
{
	int		count;
	t_stack	*first;
	int		size;

	count = 0;
	first = *s;
	size = s_size(s);
	while ((*s)->element != (min)->element)
	{
		count++;
		*s = (*s)->next;
	}
	*s = first;
	if (count > size / 2)
		return (1);
	else
		return (0);
}

int	ft_variable(t_stack **a, t_stack **b, int test)
{
	if (test == 1)
	{
		if (s_size(a) <= 100)
			return (5);
		else
			return (8);
	}
	else if (test == 2)
	{
		if (s_size(a) == 5)
		{
			s_sort_5(a, b);
			return (1);
		}
		else
			return (0);
	}
	else
	{
		push_stack(b, a, 2);
		if (s_size(b) != 0)
			rotate_stack(b, 2);
		return (0);
	}
}

int	ft_s_clos(int i, int nb_pack, int nb_elements, int pack_size)
{
	int	size_closest;

	if ((i == nb_pack) && (nb_elements % nb_pack != 0))
	{
		size_closest = nb_elements - 5;
		pack_size = nb_elements - ((pack_size * (i - 1)));
	}
	else
		size_closest = i * pack_size;
	return (size_closest);
}
