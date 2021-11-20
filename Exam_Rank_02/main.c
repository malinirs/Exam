#include "get_next_line.h"
# include <stdio.h>

int	main()
{
	char	*line;

	while (get_next_line(&line))
		printf("%s\n", line);
	printf("%s\n", line);
	return (0);
}