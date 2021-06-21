/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:09:09 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/20 19:46:18 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_stack_a(char *str, t_list **stack_a)
{
	int		number;
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
	if (!new_lst(&lst, ft_atoi(tmp)))
		return (FALSE);
	if (!add_back_lst(stack_a, &lst))
		return (FALSE);
	return (TRUE);
}

static int	create_list(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	if (argc == 1)
		return (write(2, "Error: Wrong number of arguments\n", 34), FALSE);
	while (*argv)
	{
		if (!create_stack_a(*argv, &stack_a))
			return (free_list(&stack_a), FALSE);
		++argv;
	}
	mark_up(&stack_a, &stack_b);
	//print_lst(stack_a);
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	if (!create_list(argc, argv + 1))
		return (-1);
	return (0);
}
