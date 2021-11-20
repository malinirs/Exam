#include <unistd.h>

int check2(char *str, char c, int j)
{
	int		i;

	i = 0;
	while (str[i] && i < j)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return(1);
}

int	main(int argc, char **argv)
{
	int 	i;
	int 	j;

	j = 0;
	i = 0;
	if (argc == 3)
	{
		if (argv[1][j++])
			write(1, &argv[1][0], 1);
		while (argv[1][j])
		{
			if (check2(argv[1], argv[1][j], j))
				write(1, &argv[1][j], 1);
			j++;
		}
		while (argv[2][i])
		{
			if (check2(argv[2], argv[2][i], i) && check2(argv[1], argv[2][i], j))
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
