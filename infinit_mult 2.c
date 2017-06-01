#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strnew(int size)
{
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (size >= 0)
	{
		ptr[size] = '\0';
		size--;
	}
	return (ptr);
}

int		main(int argc, char **argv)
{
	int max_len;
	char *res;
	int i;
	int j;
	int temp;

	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	max_len = ft_strlen(argv[1]) + ft_strlen(argv[2]);
	if (!(res = ft_strnew(max_len)))
	{
		return (2);
	}
	i = ft_strlen(argv[1]) - 1;
	while (i >= 0 && argv[1][i] != '-')
	{
		argc = max_len + i - ft_strlen(argv[1]);
		j = ft_strlen(argv[2]) - 1;
		while (j >= 0 && argv[2][j] != '-')
		{
			res[argc] += (argv[2][j] - 48) * (argv[1][i] - 48);
			temp = max_len - 1;
			while (temp >= 0)
			{
				if (res[temp] > 9)
				{
					res[temp - 1] += (res[temp] / 10);
					res[temp] %= 10;
				}
				temp--;
			}
			argc--;
			j--;
		}
		i--;
	}
	argc = 0;
	while (argc < max_len)
	{
		res[argc] += 48;
		argc++;
	}
	argc = 0;
	while (res[argc] == '0')
	{
		argc++;
	}
	if ((argv[1][0] == '-' && argv[2][0] != '-') || (argv[1][0] != '-' && argv[2][0] == '-'))
	{
		write(1, "-", 1);
	}
	ft_putstr(&res[argc]);
	write(1, "\n", 1);
	free(res);
	return (0);
}
