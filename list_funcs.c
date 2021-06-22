/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:01:45 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/22 19:42:54 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_lst(t_list **lst, int number)
{
	if (number < -2147483648 || number > 2147483647)
		return (write(2, "Error: overflow\n", 17), FALSE);
	*lst = (t_list *)malloc(sizeof(t_list));
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

int	add_back_lst(t_list **lst, t_list **lst_new)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = *lst_new;
		return (TRUE);
	}
	tmp = *lst;
	while ((*lst)->next != NULL)
	{
		if ((*lst_new)->number == (*lst)->number)
			return (write(2, "Error: duplicated number\n", 26), FALSE);
		if ((*lst_new)->number > (*lst)->number)
			++((*lst_new)->index);
		else
			++((*lst)->index);
		*lst = (*lst)->next;
	}
	if ((*lst_new)->number == (*lst)->number)
		return (write(2, "Error: duplicated number\n", 26), FALSE);
	if ((*lst_new)->number > (*lst)->number)
		++((*lst_new)->index);
	else
		++((*lst)->index);
	(*lst)->next = *lst_new;
	(*lst_new)->previous = *lst;
	*lst = tmp;
	return (TRUE);
}

void	free_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%d index = %d ", lst->number, lst->index);
		(lst->in_stack == TRUE) ? printf("true ") : printf("false ");
		printf("%d\n", lst->comands);
		lst = lst->next;
	}
}
