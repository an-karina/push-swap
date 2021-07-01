/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhleena <jhleena@student.42.f>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 09:58:49 by jhleena           #+#    #+#             */
/*   Updated: 2021/06/24 11:44:28 by jhleena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static int	_sign(char symb)
{
	if (symb == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str, int *number)
{
	int			i;
	long int	result;
	int			sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\r')
		|| (str[i] == '\v') || (str[i] == '\n') || (str[i] == '\f'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		sign = _sign(str[i]);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		if ((result > 2147483647) && (sign == 1))
			return (FALSE);
		if ((result > 2147483648) && (sign == -1))
			return (FALSE);
		result = 10 * result + (str[i] - '0');
		i++;
	}
	if ((result > 2147483647) && (sign == 1))
		return (FALSE);
	if ((result > 2147483648) && (sign == -1))
		return (FALSE);
	*number = result * sign;
	return (TRUE);
}
