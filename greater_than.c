/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:53:38 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/14 12:49:56 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	greater_than(t_list *stack, t_list *elem)
{
	int		amount;
	t_list	*tmp;
	t_list	*end_of_stack;
	
	amount = 0;
	end_of_stack = NULL;
	elem->in_stack = TRUE;
	tmp = elem->next;
	if (tmp == NULL)
	{
		end_of_stack = elem;
		tmp = stack;
	}
	while (tmp != elem)
	{
		if (tmp && end_of_stack && end_of_stack->number < tmp->number)
		{
			tmp->in_stack = TRUE;
			end_of_stack = NULL;
			tmp = tmp->next;
		}
		else if (tmp && tmp->previous && tmp->previous->number < tmp->number)
		{
			tmp->in_stack = TRUE;
			if (!tmp->next)
				end_of_stack = tmp;
			tmp = tmp->next;
		}
		else if (!tmp)
		{
			//end_of_stack = tmp;
			tmp = stack;
		}
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
			break;
		}
	}
	return (amount);
}