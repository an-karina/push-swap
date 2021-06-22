/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:39:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/22 23:19:56 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	get_index(t_list *stack, t_list *elem)
{
	int		amount;
	t_list	*tmp;
	int		index;

	elem->in_stack = TRUE;
	tmp = elem->next;
	amount = 1;
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

void	do_r(t_list **stack_a, t_list **stack_b, t_list *cmd)
{
	while (cmd->steps.rr--)
	{
		printf("rr\n");
		rotate(stack_a);
		rotate(stack_b);
	}
	while (cmd->steps.rrr--)
	{
		printf("rrr\n");
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
	while (cmd->steps.ra--)
	{
		printf("ra\n");
		rotate(stack_a);
	}
	while (cmd->steps.rb--)
	{
		printf("rb\n");
		rotate(stack_b);
	}
	while (cmd->steps.rrb--)
	{
		printf("rrb\n");
		r_rotate(stack_b);
	}
	while (cmd->steps.rra--)
	{
		printf("rra\n");
		r_rotate(stack_a);
	}
}

void	mark_up(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_min;
	int		amount;
	int		amount_min;

	tmp = *stack_a;
	amount_min = get_index(*stack_a, tmp);
	printf("amount of false %d\n", amount_min);
	tmp_min = tmp;
	// tmp = tmp->next;
	while (tmp && amount_min)
	{
		amount = get_index(*stack_a, tmp);
		printf("| amount %d| amount_min %d|\n", amount, amount_min);
		if	(amount_min == amount)
		{
			printf("| tmp_min %d| tmp %d|\n", tmp_min->index, tmp->index);
			if (tmp_min->index > tmp->index)
			{
				// printf("|   %d   |", tmp_min->number);
				tmp_min = tmp;
			}
		}
		if (amount_min > amount)
		{
			amount_min = amount;
			tmp_min = tmp;
		}
		tmp = tmp->next;
	}
	//printf("|||   tmp_min    %d|||\n", tmp_min->index);
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
	while (*stack_b)
	{
		tmp = *stack_b;
		amount_min = (tmp)->comands = command_calculator(*stack_a, *stack_b, tmp);
		printf("\n______________________\n");
		printf("___STACK_A___\n");
		print_lst(*stack_a);
		printf("___STACK_B___\n");
		print_lst(*stack_b);
		printf("\n______________________\n");
		tmp_min = tmp;
		tmp = tmp->next;
		while (tmp)
		{
			(tmp)->comands = command_calculator(*stack_a, *stack_b, tmp);
			if (amount_min > (tmp)->comands)
			{
				amount_min =  (tmp)->comands;
				tmp_min = tmp;
			}
			tmp = tmp->next;
		}
		do_r(stack_a, stack_b, tmp_min);
		push(stack_a, stack_b);
		printf("___STACK_A___\n");
		print_lst(*stack_a);
		printf("___STACK_B___\n");
		print_lst(*stack_b);
	}
}
