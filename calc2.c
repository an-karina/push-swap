/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:12:48 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/20 10:14:15 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_lst(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		++size;
		lst = lst->next;
	}
	return (size);
}

int	place_in_satck(t_list *stack, int index)
{
	int	place;

	place = 1;
	while (stack && stack->index != index)
	{
		++place;
		stack = stack->next;
	}
	return (place);
}

int	find_index(t_list *stack, int index)
{
	int	ind_min;
	int	ind_max;

	ind_max = -1;
	ind_min = -1;
	while (stack)
	{
		if (stack->index == index - 1)
			return (stack->index);
		if (stack->index > ind_min && stack->index < index)
			ind_min = stack->index;
		if (stack->index > ind_max && stack->index > index)
			ind_max = stack->index;
		stack = stack->next;
	}
	if (ind_min != -1 && ind_min < index)
		return (ind_min);
	return (ind_max);
}

int	rr(int *place_in_a, int *place_in_b)
{
	int	amount;

	amount = 0;
	while (*place_in_a != 0 && *place_in_b != 1)
	{
		++amount;
		--(*place_in_a);
		--(*place_in_b);
	}
	return (amount);
}

int	rrr(int *place_in_a, int *place_in_b, int a, int b)
{
	int	amount;

	amount = 0;
	while (*place_in_b < b && *place_in_a < a)
	{
		++amount;
		++(*place_in_a);
		++(*place_in_b);
	}
	return (amount);
}
