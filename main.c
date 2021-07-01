/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:09:09 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/01 12:54:32 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_stack_a(char *str, t_list **stack_a)
{
	int		*number;
	char	*tmp;
	t_list	*lst;

	tmp = str;
	if (*str == '-' && ft_is_digit(*(str + 1)))
		++(str);
	while (*str)
	{
		if (!ft_is_digit(*str))
			return (write(2, "Error: invalid argument", 24), FALSE);
		++(str);
	}
	number = (int *)malloc(sizeof(int));
	if (!ft_atoi(tmp, number))
		return (write(2, "Error: the number is too long\n", 31), FALSE);
	if (!new_lst(&lst, *number))
		return (FALSE);
	if (!add_back_lst(stack_a, &lst))
		return (FALSE);
	return (TRUE);
}

static int	create_list(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_commands	*cmd_ind;
	t_commands	*cmd_gt;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (write(2, "Error: Wrong number of arguments\n", 34), FALSE);
	while (*argv)
	{
		if (!create_stack_a(*argv, &stack_a))
			return (free_list(&stack_a), FALSE);
		++argv;
	}
	cmd_ind = mark_up(&stack_a, &stack_b, &get_index);
	//print_lst(stack_a);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	if (!create_list(argc, argv + 1))
		return (-1);
	return (0);
}
