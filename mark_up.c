/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:39:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/23 19:32:42 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_r(t_lst **stack_a, t_lst **stack_b, t_lst *cmd, t_cmd **lst_cmd)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = NULL;
	while (cmd->steps.rr--)
	{
		new_lst_add_back(lst_cmd, "rr\n");
		rotate(stack_a), rotate(stack_b);
	}
	while (cmd->steps.rrr--)
	{
		new_lst_add_back(lst_cmd, "rrr\n");
		r_rotate(stack_a), r_rotate(stack_b);
	}
	while (cmd->steps.ra--)
		new_lst_add_back(lst_cmd, "ra\n"), rotate(stack_a);
	while (cmd->steps.rb--)
		new_lst_add_back(lst_cmd, "rb\n"), rotate(stack_b);
	while (cmd->steps.rrb--)
		new_lst_add_back(lst_cmd, "rrb\n"), r_rotate(stack_b);
	while (cmd->steps.rra--)
		new_lst_add_back(lst_cmd, "rra\n"), r_rotate(stack_a);
}

t_lst	*find_header(t_lst **stack_a,
	int (*m_head)(t_lst *stack, t_lst *elem), t_lst **tmp_min)
{
	t_lst	*tmp;
	int		amount;
	int		amount_min;

	tmp = NULL;
	(*tmp_min) = NULL;
	tmp = *stack_a;
	amount_min = m_head(*stack_a, tmp);
	(*tmp_min) = tmp;
	tmp = tmp->next;
	while (tmp && amount_min)
	{
		amount = m_head(*stack_a, tmp);
		if (amount_min == amount)
			if ((*tmp_min)->index > tmp->index)
				(*tmp_min) = tmp;
		if (amount_min > amount)
		{
			amount_min = amount;
			(*tmp_min) = tmp;
		}
		tmp = tmp->next;
	}
	return (*tmp_min);
}

void	stack_b_smth(t_lst **stack_b, t_lst **stack_a,
	int *amount_min, t_cmd **cmd)
{
	t_lst	*tmp;
	t_lst	*tmp_min;

	while (*stack_b)
	{
		tmp = *stack_b;
		(tmp)->comands = command_calculator(*stack_a, *stack_b, tmp);
		*amount_min = (tmp)->comands;
		tmp_min = tmp;
		tmp = tmp->next;
		while (tmp)
		{
			(tmp)->comands = command_calculator(*stack_a, *stack_b, tmp);
			if (*amount_min > (tmp)->comands)
			{
				*amount_min = (tmp)->comands;
				tmp_min = tmp;
			}
			tmp = tmp->next;
		}
		do_r(stack_a, stack_b, tmp_min, cmd);
		push(stack_a, stack_b);
		new_lst_add_back(cmd, "pa\n");
	}
}

void	true_or_false(t_lst **st_a, t_lst **st_b, t_cmd **cmd, int *amount)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = NULL;
	if ((*st_a)->in_stack == FALSE)
	{
		push(st_b, st_a), new_lst_add_back(cmd, "pb\n");
		--(*amount);
	}
	if ((*st_a)->in_stack == TRUE && *amount)
		rotate(st_a), new_lst_add_back(cmd, "ra\n");
}

t_cmd	*mark_up(t_lst **stack_a, t_lst **stack_b,
	int (*m_head)(t_lst *stack, t_lst *elem))
{
	t_lst	*tmp_min;
	int		amount;
	int		amount_min;
	t_cmd	*cmd;

	cmd = NULL, find_header(stack_a, m_head, &tmp_min);
	amount_min = m_head(*stack_a, tmp_min);
	while (*stack_a && amount_min != 0)
	{
		if (swap(stack_a))
		{
			new_lst_add_back(&cmd, "sa\n"), amount_min = 0;
			break ;
		}
		amount = m_head(*stack_a, tmp_min);
		if (amount_min > amount)
			amount_min = amount, new_lst_add_back(&cmd, "sa\n");
		else
			swap(stack_a), amount = m_head(*stack_a, tmp_min);
		true_or_false(stack_a, stack_b, &cmd, &amount_min);
	}
	stack_b_smth(stack_b, stack_a, &amount_min, &cmd);
	while ((*stack_a)->index != 0)
		rotate(stack_a), new_lst_add_back(&cmd, "ra\n");
	return (cmd);
}
