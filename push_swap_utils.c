/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:58:45 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/31 16:29:58 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '-' || s[i] == '+') && s[i + 1])
		i++;
	while (s[i] != '\0')
	{
		if (((s[i] < '0') || (s[i] > '9')))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	cmp_1;
	unsigned char	cmp_2;

	i = 0;
	if ((!s1 || !s2) && (!*s1 || !*s2))
		return (0);
	cmp_1 = *s1;
	cmp_2 = *s2;
	while ((s1[i] || s2[i]) && (cmp_1 || cmp_2))
	{
		cmp_1 = (unsigned char)s1[i];
		cmp_2 = (unsigned char)s2[i];
		if (cmp_1 != cmp_2)
			return (cmp_1 - cmp_2);
		i++;
	}
	return (cmp_1 - cmp_2);
}

long int	ft_atoi(char *s)
{
	int			i;
	int			minus;
	long int	res;

	i = 0;
	res = 0;
	minus = 1;
	while (s[i] == '0')
		i++;
	if (ft_strlen(s + i) > 11)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (s[i] == '+')
		i++;
	if (s[i] == '-')
	{
		minus = -1;
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
		res = res * 10 + s[i++] - '0';
	return (res * minus);
}

t_stack	*s_new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack) * 1);
	if (!new)
		return (NULL);
	(new)->next = new;
	(new)->prev = new;
	(new)->element = content;
	return (new);
}

int	s_sorted(t_stack **s)
{
	t_stack	*first_s;

	first_s = *s;
	while (1)
	{
		if ((*s)->element > ((*s)->next)->element)
		{
			*s = first_s;
			return (0);
		}
		*s = (*s)->next;
		if ((*s)->next == first_s)
		{
			*s = (*s)->next;
			return (1);
		}
	}
}
