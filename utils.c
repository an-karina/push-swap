/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:00:34 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/23 15:32:10 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stack_a(char *str, t_lst **stack_a)
{
	int		number;
	char	*tmp;
	t_lst	*lst;

	tmp = str;
	if (*str == '-' && ft_is_digit(*(str + 1)))
		++(str);
	while (*str)
	{
		if (!ft_is_digit(*str))
			return (write(2, "Error: invalid argument", 24), FALSE);
		++(str);
	}
	if (!ft_atoi(tmp, &number))
		return (write(2, "Error: the number is too long\n", 31), FALSE);
	if (!new_lst(&lst, number))
		return (FALSE);
	if (!add_back_lst(stack_a, &lst))
		return (FALSE);
	return (TRUE);
}

int	check_length(t_cmd *cmd_ind, t_cmd *cmd_gt)
{
	int	length_ind;
	int	length_gt;

	length_ind = 0;
	length_gt = 0;
	while (cmd_ind)
	{
		++length_ind;
		cmd_ind = cmd_ind->next;
	}
	while (cmd_gt)
	{
		++length_gt;
		cmd_gt = cmd_gt->next;
	}
	if (length_gt > length_ind)
		return (0);
	if (length_gt <= length_ind)
		return (1);
	return (2);
}
