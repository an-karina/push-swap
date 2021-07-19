/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:09:09 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/19 23:12:37 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_not_sorted(t_list	*stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->index != stack_a->next->index - 1)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	algo_for_three(char **argv)
{
	t_list		*stack_a;

	stack_a = NULL;
	while (*argv)
	{
		if (!create_stack_a(*argv, &stack_a))
			return (free_list(&stack_a));
		++argv;
	}
	while (is_not_sorted(stack_a))
	{
		if (stack_a->next->index == 2 && stack_a->index == 1)
		{
			write(1, "rra\n", 4);
			r_rotate(&stack_a);
		}
		else if (stack_a->number > stack_a->next->number && stack_a->number > stack_a->next->next->number)
		{
			write(1, "ra\n", 3);
			rotate(&stack_a);
		}
		else if (stack_a->number > stack_a->next->number || stack_a->number < stack_a->next->number && stack_a->next->number > stack_a->next->next->number)
		{
			write(1, "sa\n", 3);
			swap(&stack_a);
		}
	}
}

t_commands	*using_algorithm(char **argv,int (*markup_header)(t_list *stack, t_list *elem))
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_commands	*cmd_ind;
	char		**argv_beg;
	
	stack_a = NULL;
	stack_b = NULL;
	argv_beg = argv;
	while (*argv)
	{
		if (!create_stack_a(*argv, &stack_a))
			return (free_list(&stack_a), NULL);
		++argv;
	}
	cmd_ind = mark_up(&stack_a, &stack_b, markup_header);
	argv =  argv_beg;
	return (cmd_ind);
}

int	create_list(int argc, char *argv[])
{
	t_list		*tmp_stack_a;
	t_commands	*cmd_ind;
	t_commands	*cmd_gt;
	char		*tmp_c;
	char		**tmp_argv;
	int			length;

	tmp_stack_a = NULL;
	if (argc == 1)
		return (write(2, "Error: Wrong number of arguments\n", 34), FALSE);
	if (argc == 4)
	{
		algo_for_three(argv);
		return (0);
	}
	tmp_argv = argv;
	cmd_ind = using_algorithm(argv, &get_index);
	cmd_gt = using_algorithm(argv, &greater_than);
	length = check_length(cmd_ind, cmd_gt);
	if (length == 0)
	{
		length = 0;
		while (cmd_ind)
		{
			length = 0;
			tmp_c = cmd_ind->command;
			while (*tmp_c)
			{
				++length;
				++tmp_c;
			}
			write(1, cmd_ind->command, length);
			cmd_ind = cmd_ind->next;
		}
	}
	else
	{
		length = 0;
		while (cmd_gt)
		{
			length = 0;
			tmp_c = cmd_gt->command;
			while (*tmp_c)
			{
				++length;
				++tmp_c;
			}
			write(1, cmd_gt->command, length);
			cmd_gt = cmd_gt->next;
		}
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	if (!create_list(argc, argv + 1))
		return (-1);
	return (0);
}
