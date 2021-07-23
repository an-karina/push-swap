/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:16:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/23 19:23:38 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_lst **stack)
{
	t_lst	*tmp_1;
	t_lst	*tmp_2;

	tmp_1 = *stack;
	tmp_2 = (*stack)->next;
	if (!tmp_2)
		return (0);
	(*stack)->next = tmp_2->next;
	tmp_2->previous = NULL;
	tmp_2->next = tmp_1;
	tmp_2->next->previous = tmp_1;
	*stack = tmp_2;
	if (!is_not_sorted(*stack))
		return (1);
	return (0);
}

void	push(t_lst **stack_1, t_lst **stack_2)
{
	t_lst	*tmp;

	tmp = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = (*stack_2)->next;
	if (*stack_2)
		(*stack_2)->previous = NULL;
	(*stack_1)->next = tmp;
}

void	rotate(t_lst **stack)
{
	t_lst	*tmp;

	tmp = *stack;
	if (!tmp->next)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	tmp->next->next = NULL;
	tmp->next->previous = tmp;
}

void	r_rotate(t_lst **stack)
{
	t_lst	*tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	tmp->next->previous = NULL;
	(*stack)->previous = tmp->next;
	*stack = tmp->next;
	tmp->next = NULL;
}
