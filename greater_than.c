/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:53:38 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/01 12:43:25 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greater_than(t_list *stack, t_list *elem)
{
	int	amount;
	t_list *tmp;

	amount = 0;
	tmp = stack;
	while (stack != elem)
		stack = stack->next;
	stack->in_stack = TRUE;
	while (stack->next && stack->number <= stack->next->number)
	{
		stack->next->in_stack = TRUE;
		stack = stack->next;
	}
	if (stack->next ==  NULL)
	{
		if (stack->number <= tmp->number)
			stack->in_stack = TRUE;
		stack = tmp;
		while (stack != elem && stack->number <= stack->next->number)
		{
			stack->next->in_stack = TRUE;
			stack = stack->next;
		}
	}
	while (stack->next)
	{
		++amount;
		stack->next->in_stack = FALSE;
		stack = stack->next;
	}
	return (amount);
}
