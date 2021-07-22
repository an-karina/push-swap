/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:09:09 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/22 13:46:57 by jhleena          ###   ########.fr       */
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

	length = check_length(cmd_ind, cmd_gt);
	if (length == 0)
		alg_write(cmd_ind);
	else
		alg_write(cmd_gt);
}

int	create_list(int argc, char *argv[])
{
	t_cmd		*cmd_ind;
	t_cmd		*cmd_gt;
	char		**tmp_argv;

	cmd_ind = NULL;
	cmd_gt = NULL;
	if (argc == 1)
		return (write(2, "\n", 1), FALSE);
	if (argc == 4)
	{
		algo_for_three(argv);
		return (0);
	}
	tmp_argv = argv;
	cmd_ind = using_algo(argv, &get_index);
	if (cmd_ind == NULL)
		return (0);
	cmd_gt = using_algo(argv, &greater_than);
	write_cmd(cmd_ind, cmd_gt);
	free_cmd_lst(&cmd_gt);
	free_cmd_lst(&cmd_ind);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	if (!create_list(argc, argv + 1))
		return (-1);
	return (0);
}
