/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:29:56 by edelage           #+#    #+#             */
/*   Updated: 2022/11/19 00:20:47 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include <limits.h>

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	convert_number(const char *str, int sign, int index)
{
	int		result;
	size_t	len_nb;

	result = 0;
	len_nb = 0;
	while (ft_isdigit(str[index]))
	{
		if (len_nb == 9 && ((result != (result * 10 + (str[index] - '0')) / 10)
				|| ft_isdigit(str[index + 1])))
		{
			ft_put_str_fd("Error pid\n", 2);
			exit(EOVERFLOW);
		}
		result = result * 10 + (str[index] - '0');
		len_nb++;
		index++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int		index;
	int		sign;

	index = 0;
	sign = 1;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	return (convert_number(str, sign, index));
}
