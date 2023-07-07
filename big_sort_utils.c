/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:54:13 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/27 17:21:24 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exists(int *tab, int size, int element)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (element == tab[i])
			return (1);
		i++;
	}
	return (0);
}

int	*ft_pack_min(t_stack **a)
{
	t_stack	*first_a;
	int		min;
	int		*tab_min;
	int		i;		

	i = 0;
	first_a = *a;
	tab_min = malloc(sizeof(int) * s_size(a));
	if (!tab_min)
		return (NULL);
	while (i < s_size(a))
	{
		while (ft_exists(tab_min, i, (*a)->element))
			*a = (*a)->next;
		min = (*a)->element;
		*a = (*a)->next;
		while (*a != first_a)
		{
			if ((*a)->element < min && !ft_exists(tab_min, i, (*a)->element))
				min = (*a)->element;
			*a = (*a)->next;
		}
		tab_min[i++] = min;
	}
	return (tab_min);
}

static int	ft_count_rotate(t_stack **a, int *tab, int pack_size, int index)
{
	t_stack	*first_a;
	int		count_rotate;

	first_a = *a;
	count_rotate = 0;
	while (!ft_indx(tab, pack_size, (*a)->element, index))
	{
		count_rotate++;
		*a = (*a)->next;
	}
	*a = first_a;
	return (count_rotate);
}

static int	ft_count_reverse(t_stack **a, int *tab, int pack_size, int index)
{
	t_stack	*first_a;
	int		count_reverse;

	first_a = *a;
	count_reverse = 0;
	(*a) = (first_a)->prev;
	while (!ft_indx(tab, pack_size, (*a)->element, index))
	{
		count_reverse++;
		*a = (*a)->prev;
	}
	*a = first_a;
	return (count_reverse);
}

void	ft_closest(t_stack **a, int *tab, int pack_size, int index)
{
	int		i;
	int		count_rotate;
	int		count_reverse;

	count_rotate = ft_count_rotate(a, tab, pack_size, index);
	if (count_rotate == 0)
		return ;
	count_reverse = ft_count_reverse(a, tab, pack_size, index);
	if (count_rotate <= count_reverse)
	{
		i = 0;
		while (i++ < count_rotate)
			rotate_stack(a, 1);
	}
	else
	{
		i = 0;
		while (i++ <= count_reverse)
			reverse_rotate(a, 1);
	}
}
