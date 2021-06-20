/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:02:07 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/18 15:27:48 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	int				number;
	int				index;
	int				in_stack;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

int		new_lst(t_list **lst, int number);
int		add_back_lst(t_list **lst, t_list **lst_new);
void	print_lst(t_list *lst);
void	free_list(t_list **lst);

#endif