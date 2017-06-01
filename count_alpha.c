/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:02:39 by exam              #+#    #+#             */
/*   Updated: 2017/02/07 10:39:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		vd_str_tolower(char *str)
{
	while (*str != '\0')
	{
		if ('A' <= *str && *str <= 'Z')
		{
			*str += 32;
		}
		str++;
	}
}

int			vd_count(char *str, char c)
{
	int		res;

	res = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			*str = '*';
			res++;
		}
		str++;
	}
	return (res);
}

int			ft_print_stuff(int res, char symb)
{
	int flag;

	printf("%d", res);
	printf("%c", symb);
	flag = 1;
	return (flag);
}

int			main(int argc, char **argv)
{
	int		i;
	int		res;
	int		flag;
	char	symb;

	if (argc == 2)
	{
		vd_str_tolower(argv[1]);
		i = 0;
		flag = 0;
		while (argv[1][i] != '\0')
		{
			if (flag == 1 && ('a' <= argv[1][i] && argv[1][i] <= 'z'))
				printf(", ");
			if ('a' <= argv[1][i] && argv[1][i] <= 'z')
			{
				symb = argv[1][i];
				res = vd_count(argv[1], argv[1][i]);
				flag = ft_print_stuff(res, symb);
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
