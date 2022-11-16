/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:12:29 by edelage           #+#    #+#             */
/*   Updated: 2022/11/16 11:41:19 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

/**
 * @brief		This function decompose a char (1 byte) to 8 bits
 *
 * @param c		Char to decompose
 */
void	decompose_char(char c)
{
	int		bit;
	int		division;
	size_t	index_bit;

	index_bit = 8;
	division = 0b10000000;
	while (index_bit != 0)
	{
		if ((c & division) != 0)
			bit = 1;
		else
			bit = 0;
		printf("%d ", bit);
		division >>= 1;
		index_bit--;
	}
}

int	main(void)
{
	for (int i = 0; i < 127; i++)
	{
		decompose_char(i);
		printf(": %i\n", i);
	}
}
