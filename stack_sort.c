/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:53:42 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/28 18:21:27 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_sort_2(t_stack **s)
{
	if ((*s)->element > ((*s)->next)->element)
		swap_stack(s, 1);
}

void	s_sort_3(t_stack **s)
{
	if (s_size(s) == 2)
		s_sort_2(s);
	else if ((*s)->element > ((*s)->next)->element
		&& ((*s)->element < ((*s)->prev)->element))
		swap_stack(s, 1);
	else if ((*s)->element > ((*s)->next)->element
		&& ((*s)->next)->element < ((*s)->prev)->element)
		rotate_stack(s, 1);
	else if ((*s)->element < ((*s)->next)->element
		&& (*s)->element > ((*s)->prev)->element)
		reverse_rotate(s, 1);
	else if ((*s)->element > ((*s)->next)->element
		&& ((*s)->next)->element > ((*s)->prev)->element)
	{
		swap_stack(s, 1);
		reverse_rotate(s, 1);
	}
	else if ((*s)->element < ((*s)->next)->element
		&& ((*s)->next)->element > ((*s)->prev)->element)
	{
		swap_stack(s, 1);
		rotate_stack(s, 1);
	}
}

void	s_sort_5(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		i;

	i = 0;
	if (s_sorted(a))
		return ;
	while (++i <= 2)
	{
		min = s_new_stack((s_min(a))->element);
		if (closest_min(a, min))
			while ((*a)->element != (min)->element)
				reverse_rotate(a, 1);
		else
			while ((*a)->element != (min)->element)
				rotate_stack(a, 1);
		if (s_sorted(a) && i == 1)
			return (free(min));
		free(min);
		push_stack(b, a, 2);
	}
	s_sort_3(a);
	push_stack(a, b, 1);
	push_stack(a, b, 1);
}

static void	ft_check_max(t_stack **a, int *tab_min, int nb_elements)
{
	int	index;

	index = nb_elements - 5;
	while (ft_indx(tab_min, nb_elements, (*a)->element, index))
		rotate_stack(a, 1);
}

void	s_big_sort(t_stack **a, t_stack **b, int i, int j)
{
	int	k;
	int	*tab;
	int	tab_var[3];
	int	pack;
	int	size_closest;

	ft_init(a, b, tab_var);
	tab = ft_pack_min(a);
	pack = tab_var[0] / tab_var[1] + (tab_var[0] % tab_var[1] != 0);
	while (i++ < tab_var[1])
	{
		k = 0;
		while (k++ < pack && !ft_variable(a, b, 2))
		{
			size_closest = ft_s_clos(i, tab_var[1], tab_var[0], pack);
			ft_closest(a, tab, size_closest, size_closest - pack);
			ft_check_max(a, tab, tab_var[0]);
			if (ft_indx(tab, j + (9 * pack / 20), (*a)->element, j))
				ft_variable(a, b, 3);
			else if (ft_indx(tab, j + pack, (*a)->element, j + (9 * pack / 20)))
				push_stack(b, a, 2);
		}
		j += pack;
	}
	ft_last_sort(a, b, tab, (pack / 9) + (pack % 9 != 0));
}
