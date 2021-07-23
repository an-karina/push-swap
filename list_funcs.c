/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:01:45 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/23 15:32:10 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_lst(t_lst **lst, int number)
{
	if (number < -2147483648 || number > 2147483647)
		return (write(2, "Error: overflow\n", 17), FALSE);
	*lst = (t_lst *)malloc(sizeof(t_lst));
	(*lst)->number = number;
	(*lst)->in_stack = FALSE;
	(*lst)->index = 0;
	(*lst)->comands = 0;
	(*lst)->steps.ra = 0;
	(*lst)->steps.rb = 0;
	(*lst)->steps.rr = 0;
	(*lst)->steps.rra = 0;
	(*lst)->steps.rrb = 0;
	(*lst)->steps.rrr = 0;
	(*lst)->next = NULL;
	(*lst)->previous = NULL;
	return (TRUE);
}

int	make_ind(t_lst **lst, t_lst **lst_new)
{
	if ((*lst_new)->number == (*lst)->number)
		return (write(2, "Error: duplicated number\n", 26), FALSE);
	if ((*lst_new)->number > (*lst)->number)
		++((*lst_new)->index);
	else
		++((*lst)->index);
	return (1);
}

int	add_back_lst(t_lst **lst, t_lst **lst_new)
{
	t_lst	*tmp;

	if (*lst == NULL)
	{
		*lst = *lst_new;
		return (TRUE);
	}
	tmp = *lst;
	while ((*lst)->next != NULL)
	{
		if (!make_ind(lst, lst_new))
			return (FALSE);
		*lst = (*lst)->next;
	}
	if (!make_ind(lst, lst_new))
		return (FALSE);
	(*lst)->next = *lst_new;
	(*lst_new)->previous = *lst;
	*lst = tmp;
	return (TRUE);
}

void	free_list(t_lst **lst)
{
	t_lst	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}
