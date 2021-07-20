/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:02:07 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/21 00:55:54 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_step
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_step;

typedef struct s_list
{
	int				number;
	int				index;
	int				in_stack;
	int				comands;
	t_step			steps;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

typedef struct s_commands
{
	char				*command;
	struct s_commands	*next;
}						t_cmd;

int		new_lst(t_list **lst, int number);
int		add_back_lst(t_list **lst, t_list **lst_new);
void	print_lst(t_list *lst);
void	free_list(t_list **lst);
void	new_lst_command(t_cmd **lst, char *str);
void	add_back_lst_cmd(t_cmd **lst, t_cmd **new_lst);
void	new_lst_add_back(t_cmd **lst_cmd, char *s);

#endif
