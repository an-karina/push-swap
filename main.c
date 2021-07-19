/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:09:09 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/18 12:56:47 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_list(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*tmp_stack_a;
	t_list		*stack_b;
	t_commands	*cmd_ind;
	t_commands	*cmd_gt;
	char		*tmp_c;
	char		**tmp_argv;
	int			length;

	stack_a = NULL;
	stack_b = NULL;
	tmp_stack_a = NULL;
	if (argc == 1)
		return (write(2, "Error: Wrong number of arguments\n", 34), FALSE);
	tmp_argv = argv;
	while (*argv)
	{
		if (!create_stack_a(*argv, &stack_a))
			return (free_list(&stack_a), FALSE);
		++argv;
	}
	cmd_ind = mark_up(&stack_a, &stack_b, &get_index);
	while (*tmp_argv)
	{
		if (!create_stack_a(*tmp_argv, &tmp_stack_a))
			return (free_list(&tmp_stack_a), FALSE);
		++tmp_argv;
	}
	cmd_gt = mark_up(&tmp_stack_a, &stack_b, &greater_than);
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
