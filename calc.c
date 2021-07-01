/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:51:41 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/24 14:07:14 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_lst(t_list *lst)
{
	int size;

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

int	find_index(t_list *stack, int index)//8
{
	int	ind_min;
	int ind_max;

	ind_max = -1;
	ind_min = -1;
	while (stack)
	{
		if (stack->index == index - 1)
			return (stack->index);
		if (stack->index > ind_min && stack->index < index)//10>10//1> 10
			ind_min = stack->index;
		if (stack->index > ind_max && stack->index > index)//10>10//
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

int	ra(int *place_in_a)
{
	int amount;

	amount = 0;
	while (*place_in_a != 0)
	{
		++amount;
		--(*place_in_a);
	}
	return (amount);
}

int	rb(int *place_in_b)
{
	int amount;

	amount = 0;
	while (*place_in_b != 1)
	{
		++amount;
		--(*place_in_b);
	}
	return (amount);
}

int	rra(int *place_in_a, int max)
{
	int	amount;

	amount = 0;
	while (*place_in_a < max)
	{
		++amount;
		++(*place_in_a);
	}
	return (amount);
}

int	rrb(int *place_in_b, int max)
{
	int	amount;

	amount = 0;
	while (*place_in_b <= max)
	{
		++amount;
		++(*place_in_b);
	}
	return (amount);
}

int	command_calculator(t_list *stack_a, t_list *stack_b, t_list *elem)
{
	int	place_in_a;
	int	place_in_b;
	int	size_of_a;
	int	size_of_b;
	int	result;

	elem->steps =(t_step){0, 0, 0, 0, 0, 0};
	place_in_b = place_in_satck(stack_b, elem->index);
	place_in_a = place_in_satck(stack_a, find_index(stack_a, elem->index));
	size_of_a = size_of_lst(stack_a);
	size_of_b = size_of_lst(stack_b);
	if (place_in_a <= (size_of_a / 2) && place_in_b <= (size_of_b / 2))
		elem->steps.rr = rr(&place_in_a, &place_in_b);
	if (place_in_a > (size_of_a / 2) && place_in_b > (size_of_b / 2))
		elem->steps.rrr = rrr(&place_in_a, &place_in_b, size_of_a, size_of_b);
	if (place_in_a != 0 && place_in_a <= (size_of_a / 2))
		elem->steps.ra = ra(&place_in_a);
	if (place_in_b != 1 && place_in_b <= (size_of_b / 2))
		elem->steps.rb = rb(&place_in_b);
	if (place_in_a != size_of_a && place_in_a > (size_of_a / 2))
		elem->steps.rra = rra(&place_in_a, size_of_a);
	if (place_in_b != 1 && place_in_b > (size_of_b / 2))
		elem->steps.rrb = rrb(&place_in_b, size_of_b);
	elem->comands = elem->steps.rr + elem->steps.rrr + elem->steps.ra + elem->steps.rb + elem->steps.rra + elem->steps.rrb;
	return (elem->comands); 
}
