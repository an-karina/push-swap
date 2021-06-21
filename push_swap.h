/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:09:19 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/21 15:47:25 by jhleena          ###   ########.fr       */
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

int		ft_is_digit(char c);
int		ft_atoi(const char *str);
void	mark_up(t_list **stack_a, t_list **stack_b);
int		get_index(t_list *stack, t_list *elem);

#endif