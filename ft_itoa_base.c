/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 15:42:27 by vdoroshy          #+#    #+#             */
/*   Updated: 2016/12/24 16:01:22 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	long tempnbr;
	int size;
	char *result;
	int neg;
	long nbr;
	char *sbase;

	nbr = value;
	sbase = "0123456789ABCDEF";
	neg = 0;
	size = 0;
	tempnbr = nbr;
	while ((nbr = nbr / base) != 0)
		size++;
	size++;
	if (tempnbr == 0)
	{
		result = (char *)malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (tempnbr < 0 && base == 10)
	{
		neg = 1;
		size++;
	}
	if (tempnbr < 0)
		tempnbr = -tempnbr;
	result = (char *)malloc(sizeof(char) * size + 1);
	result[size] = '\0';
	size--;
	if (neg == 1)
		result[0] = '-';
	while (tempnbr != 0)
	{
		result[size] = sbase[(tempnbr % base)];
		tempnbr = tempnbr / base;
		size--;
	}
	return (result);
}

int		main()
{
	printf("%s\n", ft_itoa_base(255, 2));
	return (0);
}
