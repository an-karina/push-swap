/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:39:51 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/30 13:55:58 by jhleena          ###   ########.fr       */
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

void	do_r(t_list **stack_a, t_list **stack_b, t_list *cmd, t_commands **lst_cmd)
{
	t_commands *tmp_cmd;
	
	tmp_cmd = NULL;
	while (cmd->steps.rr--)
	{
		//write(1, "rr\n", 3);
		new_lst_command(&tmp_cmd, "rr\n");
		add_back_lst_commands(lst_cmd, &tmp_cmd);
		rotate(stack_a);
		rotate(stack_b);
	}
	while (cmd->steps.rrr--)
	{
		//write(1, "rrr\n", 4);
		new_lst_command(&tmp_cmd, "rrr\n");
		add_back_lst_commands(lst_cmd, &tmp_cmd);
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
	while (cmd->steps.ra--)
	{
		//write(1, "ra\n", 3);
		new_lst_command(&tmp_cmd, "ra\n");
		add_back_lst_commands(lst_cmd, &tmp_cmd);
		rotate(stack_a);
	}
	while (cmd->steps.rb--)
	{
		//write(1, "rb\n", 3);
		new_lst_command(&tmp_cmd, "rb\n");
		add_back_lst_commands(lst_cmd, &tmp_cmd);
		rotate(stack_b);
	}
	while (cmd->steps.rrb--)
	{
		//write(1, "rrb\n", 4);
		new_lst_command(&tmp_cmd, "rrb\n");
		add_back_lst_commands(lst_cmd, &tmp_cmd);
		r_rotate(stack_b);
	}
	while (cmd->steps.rra--)
	{
		//write(1, "rra\n", 4);
		new_lst_command(&tmp_cmd, "rra\n");
		add_back_lst_commands(lst_cmd, &tmp_cmd);
		r_rotate(stack_a);
	}
}

t_commands	*mark_up(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_min;
	int		amount;
	int		amount_min;
	int		length;
	char	*tmp_c;
	t_commands	*cmd;
	t_commands	*tmp_cmd;

	tmp = NULL;
	tmp_min = NULL;
	tmp_cmd = NULL;
	cmd = NULL;
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
	while (*stack_a && amount_min != 1)
	{
		swap(stack_a);
		amount = get_index(*stack_a, tmp_min);
		if (amount_min > amount)
		{
			amount_min = amount;
			//write(1, "sa\n", 3);
			new_lst_command(&tmp_cmd, "sa\n");
			add_back_lst_commands(&cmd, &tmp_cmd);
		}
		else
		{
			swap(stack_a);
			amount = get_index(*stack_a, tmp_min);
		}
		if ((*stack_a)->in_stack == FALSE)
		{
			push(stack_b, stack_a);
			//write(1, "pb\n", 3);
			new_lst_command(&tmp_cmd, "pb\n");
			add_back_lst_commands(&cmd, &tmp_cmd);
			--amount_min;
		}
		if ((*stack_a)->in_stack == TRUE)
		{
			rotate(stack_a);
			//write(1, "ra\n", 3);
			new_lst_command(&tmp_cmd, "ra\n");
			add_back_lst_commands(&cmd, &tmp_cmd);
		}
	}
	while (*stack_b)
	{
		tmp = *stack_b;
		amount_min = (tmp)->comands = command_calculator(*stack_a, *stack_b, tmp);
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
		do_r(stack_a, stack_b, tmp_min, &cmd);
		push(stack_a, stack_b);
		//write(1, "pa\n", 3);
		new_lst_command(&tmp_cmd, "pa\n");
		add_back_lst_commands(&cmd, &tmp_cmd);
	}
	while ((*stack_a)->index != 0)
	{
		rotate(stack_a);
		//write(1, "ra\n", 3);
		new_lst_command(&tmp_cmd, "ra\n");
		add_back_lst_commands(&cmd, &tmp_cmd);
	}
	// while (cmd)
	// {
	// 	length = 0;
	// 	tmp_c = cmd->command;
	// 	while (*tmp_c)
	// 	{
	// 		++length;
	// 		++tmp_c;
	// 	}
	// 	write(1, cmd->command, length);
	// 	//printf("%s", cmd->command);
	// 	cmd = cmd->next;
	// }
	return (cmd);
}
