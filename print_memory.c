#include <unistd.h>

void				space(size_t i)
{
	if (i % 2 != 0)
	{
		write(1, " ", 1);
	}
}

void				hex(size_t j, unsigned char *ptr, size_t size)
{
	size_t			i;
	int				k;
	char			*base;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16 && i + j < size)
	{
		k = *(ptr + i + j);
		write(1, &base[(k / 16) % 16], 1);
		write(1, &base[k % 16], 1);
		space(i);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		space(i);
		i++;
	}
}

void				ascii(size_t j, unsigned char *ptr, size_t size)
{
	size_t			i;
	int				k;

	i = 0;
	while (i < 16 && i + j < size)
	{
		k = *(ptr + i + j);
		if (32 <= k && k <= 126)
		{
			write(1, &k, 1);
		}
		else
		{
			write(1, ".", 1);
		}
		i++;
	}
}

void				print_memory(const void *addr, size_t size)
{
	size_t			j;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	j = 0;
	while (j < size)
	{
		hex(j, ptr, size);
		ascii(j, ptr, size);
		write(1, "\n", 1);
		j += 16;
	}
}
