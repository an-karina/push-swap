/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:39:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/21 20:20:07 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	greater_than(t_list *stack, t_list *elem)
// {
// 	int	amount;
// 	t_list *tmp;
	
// 	amount = 0;
// 	tmp = stack;
// 	while (stack != elem)
// 		stack = stack->next;
// 	stack->in_stack = TRUE;
// 	while (stack->next && stack->number <= stack->next->number)
// 	{
// 		stack->next->in_stack = TRUE;
// 		stack = stack->next;
// 	}
// 	if (stack->next ==  NULL)
// 	{
// 		if (stack->number <= tmp->number)
// 			stack->in_stack = TRUE;
// 		stack = tmp;
// 		while (stack != elem && stack->number <= stack->next->number)
// 		{
// 			stack->next->in_stack = TRUE;
// 			stack = stack->next;
// 		}
// 	}
// 	while (stack->next)
// 	{
// 		++amount;
// 		stack->next->in_stack = FALSE;
// 		stack = stack->next;
// 	}
// 	return (amount);
// }

int	get_index(t_list *stack, t_list *elem)
{
	int		amount;
	t_list	*tmp;
	int		index;

	elem->in_stack = TRUE;
	tmp = elem->next;
	amount = 0;
	index = elem->index;
	if (tmp == NULL)
		tmp = stack;
	while (tmp != elem)
	{
		if (tmp->index == index + 1)
		{
			++index;
			tmp->in_stack = TRUE;
		}
		else
		{
			tmp->in_stack = FALSE;
			++amount;
		}
		if (tmp->next == NULL)
			tmp = stack;
		else
			tmp = tmp->next;
	}
	return (amount);
}

void	mark_up(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_min;
	int		amount;
	int		amount_min;

	tmp = *stack_a;
	amount_min = get_index(*stack_a, tmp);
	
	tmp_min = tmp;
	tmp = tmp->next;
	while (tmp && amount_min)
	{
		amount = get_index(*stack_a, tmp);
		if	(amount_min == amount)
			if (tmp_min->index > tmp->index)
				tmp_min = tmp;
		if (amount_min > amount)
		{
			amount_min = amount;
			tmp_min = tmp;
		}
		tmp = tmp->next;
	}
	if (get_index(*stack_a, tmp_min) == 0)
		return ;
	while (*stack_a && amount_min)
	{
		swap(stack_a);
		amount = get_index(*stack_a, tmp_min);
		if (amount_min > amount)
		{
			amount_min = amount;
			write(1, "sa\n", 4);
		}
		else
			swap(stack_a);
		if ((*stack_a)->in_stack == FALSE)
		{
			push(stack_b, stack_a);
			write(1, "pb\n", 4);
			--amount_min;
		}
		if ((*stack_a)->in_stack == TRUE)
		{
			rotate(stack_a);
			write(1, "ra\n", 4);
		}
	}
	// while (amount_min && (*stack_a)->in_stack == TRUE)
	// 	rotate(stack_a);
	// while (*stack_a && (*stack_a)->in_stack == FALSE)
	// 	push(stack_b, stack_a);
		--amount_min;
	printf("___STACK_A___\n");
	print_lst(*stack_a);
	printf("___STACK_B___\n");
	print_lst(*stack_b);
}
