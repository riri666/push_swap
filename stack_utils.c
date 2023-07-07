/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:35:41 by rchbouki          #+#    #+#             */
/*   Updated: 2023/03/27 13:53:10 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_insert_end(t_stack **s, t_stack *new)
{
	if (*s == NULL)
	{
		*s = new;
		(*s)->next = *s;
		(*s)->prev = *s;
		return ;
	}
	((*s)->prev)->next = new;
	(new)->prev = (*s)->prev;
	(new)->next = (*s);
	(*s)->prev = new;
}

void	s_insert_start(t_stack **s, t_stack *new)
{
	if (*s == NULL)
	{
		*s = new;
		(*s)->next = *s;
		(*s)->prev = *s;
		return ;
	}
	((*s)->prev)->next = new;
	(new)->prev = (*s)->prev;
	(new)->next = (*s);
	(*s)->prev = new;
	*s = new;
}

void	s_delete_end(t_stack **s)
{
	t_stack	*last;
	t_stack	*ex;

	if (*s == NULL)
		return ;
	if ((*s)->next == *s)
	{
		free(*s);
		*s = NULL;
		return ;
	}
	last = (*s)->prev;
	ex = (*s)->prev;
	((last)->prev)->next = *s;
	(*s)->prev = (last)->prev;
	free(ex);
	ex = NULL;
}

void	s_delete_start(t_stack **s)
{
	t_stack	*head;
	t_stack	*ex;

	if (*s == NULL)
		return ;
	if ((*s)->next == *s)
	{
		free(*s);
		*s = NULL;
		return ;
	}
	head = (*s)->next;
	ex = *s;
	((*s)->prev)->next = head;
	(head)->prev = (*s)->prev;
	*s = head;
	free(ex);
	ex = NULL;
}

void	ft_free_stack(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*head;

	if (*s == NULL)
		return ;
	if ((*s)->next == *s)
	{
		free(*s);
		*s = NULL;
		return ;
	}
	head = (*s);
	tmp = (*s)->next;
	while (tmp != head)
	{
		tmp = (tmp)->next;
		free(tmp->prev);
	}
	free(head);
	*s = NULL;
}
