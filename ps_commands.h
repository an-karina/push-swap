/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:33:30 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/19 14:28:11 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_COMMANDS_H
# define PS_COMMANDS_H

# include "list.h"

void	swap(t_list *stack);
void	push(t_list **stack_1, t_list **stack_2);
void	rotate(t_list **stack);
void	r_rotate(t_list **stack);

#endif