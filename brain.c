#include <unistd.h>

void brainfuck(char *str)
{
	char buf[2048];
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '>')
			j++;
		else if (str[i] == '<')
			j--;
		else if (str[i] == '+')
			buf[j]++;
		else if (str[i] == '-')
			buf[j]--;
		else if (str[i] == '.')
			write(1, &buf[j], 1);
		else if (str[i] == '[')
		{
			if (buf[j] == 0)
			{
				flag = 1;
				while (flag > 0)
				{
					i++;
					if (str[i] == '[')
						flag++;
					if (str[i] == ']')
						flag--;
				}
			}
		}
		else if (str[i] == ']')
		{
			if (buf[j] != 0)
			{
				flag = 1;
				while (flag > 0)
				{
					i--;
					if (str[i] == '[')
						flag--;
					if (str[i] == ']')
						flag++;
				}
			}
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
