/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:05:09 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/20 18:36:19 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_sorted(t_list *stack_a)
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
	t_list		*st_a;

	st_a = NULL;
	while (*argv)
	{
		if (!create_stack_a(*argv, &st_a))
			return (free_list(&st_a));
		++argv;
	}
	while (is_not_sorted(st_a))
	{
		if (st_a->next->index == 2 && st_a->index == 1)
			write(1, "rra\n", 4), r_rotate(&st_a);
		else if (st_a->number > st_a->next->number
			&& st_a->number > st_a->next->next->number)
			write(1, "ra\n", 3), rotate(&st_a);
		else
			write(1, "sa\n", 3), swap(&st_a);
	}
}

t_cmd	*using_algo(char **argv,
	int (*markup_head)(t_list *stack, t_list *elem))
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_cmd		*cmd_ind;
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
	cmd_ind = mark_up(&stack_a, &stack_b, markup_head);
	argv = argv_beg;
	return (cmd_ind);
}
