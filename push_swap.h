/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:09:19 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/18 12:05:03 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "ps_commands.h"


int			ft_is_digit(char c);
int			ft_atoi(const char *str, int *number);
t_commands	*mark_up(t_list **stack_a, t_list **stack_b, int (*markup_header)(t_list *stack, t_list *elem));
int			get_index(t_list *stack, t_list *elem);
int			command_calculator(t_list *stack_a, t_list *stack_b, t_list *elem);
int			greater_than(t_list *stack, t_list *elem);
int			create_stack_a(char *str, t_list **stack_a);
int			check_length(t_commands *cmd_ind, t_commands *cmd_gt);

#endif