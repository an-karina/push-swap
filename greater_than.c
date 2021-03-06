/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:53:38 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/23 15:32:10 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_eos_true(t_lst **tmp, t_lst **end_of_stack)
{
	(*tmp)->in_stack = TRUE;
	*end_of_stack = NULL;
	*tmp = (*tmp)->next;
}

void	if_true(t_lst **tmp, t_lst **end_of_stack)
{
	(*tmp)->in_stack = TRUE;
	if (!(*tmp)->next)
		*end_of_stack = *tmp;
	*tmp = (*tmp)->next;
}

int	loop(t_lst *tmp, t_lst *elem, t_lst *end_of_stack, t_lst *stack)
{
	int	amount;

	amount = 0;
	while (tmp != elem)
	{
		if (tmp && end_of_stack && end_of_stack->number < tmp->number)
			if_eos_true(&tmp, &end_of_stack);
		else if (tmp && tmp->previous && tmp->previous->number < tmp->number)
			if_true(&tmp, &end_of_stack);
		else if (!tmp)
			tmp = stack;
		else
		{
			while (tmp && tmp != elem)
			{
				tmp->in_stack = FALSE;
				++amount;
				tmp = tmp->next;
				if (!tmp)
					tmp = stack;
			}
			break ;
		}
	}
	return (amount);
}

int	greater_than(t_lst *stack, t_lst *elem)
{
	int		amount;
	t_lst	*tmp;
	t_lst	*end_of_stack;

	end_of_stack = NULL;
	elem->in_stack = TRUE;
	tmp = elem->next;
	if (tmp == NULL)
	{
		end_of_stack = elem;
		tmp = stack;
	}
	amount = loop(tmp, elem, end_of_stack, stack);
	return (amount);
}
