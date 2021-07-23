/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:02:07 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/23 15:32:10 by jhleena          ###   ########.fr       */
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
}					t_lst;

typedef struct s_commands
{
	char				*command;
	struct s_commands	*next;
}						t_cmd;

int		new_lst(t_lst **lst, int number);
int		add_back_lst(t_lst **lst, t_lst **lst_new);
void	print_lst(t_lst *lst);
void	free_list(t_lst **lst);
void	new_lst_command(t_cmd **lst, char *str);
void	add_back_lst_cmd(t_cmd **lst, t_cmd **new_lst);
void	new_lst_add_back(t_cmd **lst_cmd, char *s);
void	free_cmd_lst(t_cmd **lst);

#endif
