/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:06:24 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/31 15:55:32 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ch_num(int size, char **s)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (!ft_isnum(s[i]))
			return (0);
	}
	return (1);
}

int	ch_lim(int size, char **s)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if ((ft_atoi(s[i]) > 2147483647) || (ft_atoi(s[i]) < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

int	ch_dup(int size, char **s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if ((i != j) && (ft_strcmp(s[i], s[j]) == 0))
				return (0);
		}
	}
	return (1);
}

void	ft_init(t_stack **a, t_stack **b, int *tab)
{
	tab[0] = s_size(a);
	tab[1] = ft_variable(a, b, 1);
	tab[2] = (tab[0] / tab[1]) + (tab[0] % tab[1] != 0);
}

void	ft_switch(t_stack	**a, t_stack **b, int size)
{
	if (s_sorted(a))
		return ;
	if (size <= 3)
		s_sort_3(a);
	else if (size <= 5)
		s_sort_5(a, b);
	else
		s_big_sort(a, b, 0, 0);
}
