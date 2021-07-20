/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:20:32 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/21 00:55:18 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_lst_command(t_cmd **lst, char *str)
{
	int		leangth;
	int		i;
	char	*tmp_str;

	leangth = 0;
	i = 0;
	tmp_str = str;
	while (*str)
	{
		++leangth;
		++str;
	}
	*lst = (t_cmd *)malloc(sizeof(t_cmd));
	(*lst)->command = (char *)malloc(sizeof(char) * leangth + 1);
	while (*tmp_str)
	{
		(*lst)->command[i] = *tmp_str;
		++i;
		tmp_str++;
	}
	(*lst)->command[i] = '\0';
	(*lst)->next = NULL;
}

void	add_back_lst_cmd(t_cmd **lst, t_cmd **new_lst)
{
	t_cmd	*tmp;

	if (*lst == NULL)
	{
		*lst = *new_lst;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *new_lst;
	return ;
}

void	new_lst_add_back(t_cmd **lst_cmd, char *s)
{
	t_cmd	*tmp_cmd;

	tmp_cmd = NULL;
	new_lst_command(&tmp_cmd, s);
	add_back_lst_cmd(lst_cmd, &tmp_cmd);
}
