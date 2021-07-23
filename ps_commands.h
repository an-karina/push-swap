/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:33:30 by jhleena           #+#    #+#             */
/*   Updated: 2021/07/23 19:22:53 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_COMMANDS_H
# define PS_COMMANDS_H

# include "list.h"

int		swap(t_lst **stack);
void	push(t_lst **stack_1, t_lst **stack_2);
void	rotate(t_lst **stack);
void	r_rotate(t_lst **stack);

#endif