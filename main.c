/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:09:09 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/20 10:08:08 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_write(t_cmd *cmd)
{
	int		length;
	char	*tmp;

	length = 0;
	while (cmd)
	{
		length = 0;
		tmp = cmd->command;
		while (*tmp)
		{
			++length;
			++tmp;
		}
		write(1, cmd->command, length);
		cmd = cmd->next;
	}
}

void	write_cmd(t_cmd *cmd_ind, t_cmd *cmd_gt)
{
	int			length;
	char		*tmp_c;

	length = check_length(cmd_ind, cmd_gt);
	if (length == 0)
		alg_write(cmd_ind);
	else
		alg_write(cmd_gt);
}

int	create_list(int argc, char *argv[])
{
	t_list		*tmp_stack_a;
	t_cmd		*cmd_ind;
	t_cmd		*cmd_gt;
	char		**tmp_argv;

	tmp_stack_a = NULL;
	cmd_ind = NULL;
	cmd_gt = NULL;
	if (argc == 1)
		return (write(2, "Error: Wrong number of arguments\n", 34), FALSE);
	if (argc == 4)
	{
		algo_for_three(argv);
		return (0);
	}
	tmp_argv = argv;
	cmd_ind = using_algo(argv, &get_index);
	cmd_gt = using_algo(argv, &greater_than);
	write_cmd(cmd_ind, cmd_gt);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	if (!create_list(argc, argv + 1))
		return (-1);
	return (0);
}
