/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:53:02 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/31 16:29:31 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!ch_num(argc, argv) || !ch_lim(argc, argv) || !ch_dup(argc, argv))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	a = NULL;
	b = NULL;
	i = 0;
	while (++i < argc)
		s_insert_end(&a, s_new_stack(ft_atoi(argv[i])));
	ft_switch(&a, &b, s_size(&a));
	ft_free_stack(&a);
	ft_free_stack(&b);
}
