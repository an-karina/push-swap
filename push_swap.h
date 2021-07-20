/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:09:19 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/20 23:58:41 by jhleena          ###   ########.fr       */
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

int			size_of_lst(t_list *lst);
int			place_in_satck(t_list *stack, int index);
int			find_index(t_list *stack, int index);
int			rr(int *place_in_a, int *place_in_b);
int			rrr(int *place_in_a, int *place_in_b, int a, int b);
int			ft_is_digit(char c);
int			ft_atoi(const char *str, int *number);
int			get_index(t_list *stack, t_list *elem);
t_cmd		*mark_up(t_list **stack_a, t_list **stack_b,
				int (*markup_head)(t_list *stack, t_list *elem));
int			get_index(t_list *stack, t_list *elem);
int			command_calculator(t_list *stack_a, t_list *stack_b, t_list *elem);
int			greater_than(t_list *stack, t_list *elem);
int			create_stack_a(char *str, t_list **stack_a);
int			check_length(t_cmd *cmd_ind, t_cmd *cmd_gt);
int			is_not_sorted(t_list *stack_a);
void		algo_for_three(char **argv);
t_cmd		*using_algo(char **argv,
				int (*markup_head)(t_list *stack, t_list *elem));

#endif