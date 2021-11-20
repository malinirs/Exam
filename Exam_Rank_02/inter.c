#include <unistd.h>

//open -a clion

int check(char *str, int j)
{
	int 	i;

	i = 0;
	while (str[i] && i < j)
	{
		if (str[i] == str[j])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int 	i;
	int 	j;

	j = 0;
	if (argc == 3)
	{
		while (argv[1][j])
		{
			i = 0;
			while (argv[2][i])
			{
				if (argv[1][j] == argv[2][i] && check(argv[1], j))
				{
					write(1, &argv[1][j], 1);
					break;
				}
				i++;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
