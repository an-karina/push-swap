/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:16:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/22 20:12:03 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack) // tmp1 tmp2 3
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = *stack;
	tmp_2 = (*stack)->next;
	(*stack)->next = tmp_2->next;
	tmp_2->previous = NULL;
	tmp_2->next = tmp_1;
	tmp_2->next->previous = tmp_1;
	*stack = tmp_2;
}

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	tmp = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = (*stack_2)->next;
	if (*stack_2)
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
	if (!tmp || !tmp->next)
		return;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	tmp->next->previous = NULL;
	(*stack)->previous = tmp->next;
	*stack = tmp->next;
	tmp->next = NULL;
}
