/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:16:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/19 14:36:57 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	int	tmp;

	tmp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = tmp;
}

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	tmp = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = (*stack_2)->next;
	(*stack_2)->previous = NULL;
	(*stack_1)->next = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	tmp->next->next = NULL;
	tmp->next->previous = tmp;
}

void	r_rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	tmp->next->previous = NULL;
	(*stack)->previous = tmp->next;
	*stack = tmp->next;
	tmp->next = NULL;
}
