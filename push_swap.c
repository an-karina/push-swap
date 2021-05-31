/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:43:53 by jhleena           #+#    #+#             */
/*   Updated: 2021/05/31 23:57:40 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_input(char **argv)
{
	while (*argv)
	{
		while (**argv)
		{
			if (!(**argv >= '0' && **argv <= '9'))
				return (FALSE);
			++(*argv);
		}
		++argv;
	}
	return (TRUE);
}

void	fill_satck_a(t_list **stack, char **argv)
{
	t_list	*tmp;

	tmp = *stack;
	(*stack) = (*stack)->next;
	while (*argv)
	{
		
	}
}

int		main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*amount_b;
	int		*amount_a;

	if (check_input(argv + 1) == FALSE)
	{
		write(2,"Error\n", 6);
		return (0);
	}
	*amount_b = 0;
	*amount_a = argc - 1;
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lstnew(amount_a);
	stack_b = ft_lstnew(amount_b);
	fill_stack_a(&stack_a, argv + 1);
	return (0);
}