#include "get_next_line.h"

int	get_next_line(char **line)
{
	char	*buf;
	int		b_r;
	char	c;
	int		i;

	i = 0;
	buf = malloc(sizeof(char) * 1024);
	if (!buf)
		return (-1);
	c = '\0';
	*line = buf;
	while ((b_r = read(0, &c, 1)) > 0 && c != '\n')
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	return (b_r);
}

//int get_next_line(int fd, char **line) /** для проверки с fd */
//{
//	char *buf;
//	char c;
//	int i;
//	int br;
//
//	i = 0;
//	buf = malloc(sizeof(char) * 1025);
//	if (!buf)
//		return (-1);
//	*line = buf;
//	c = '\0';
//	while ((br = read(fd, &c, 1)) > 0 && c != '\n')
//	{
//		buf[i] = c;
//		i++;
//	}
//	buf[i] = '\0';
//	return (br);
//}
//
//# include <fcntl.h>
//# include <stdio.h>
//
//int 	main(void)
//{
//	char *line;
//	int fd;
//
//	fd = open("text.txt", O_RDONLY);
//	while (get_next_line(fd, &line))
//		printf("%s\n", line);
//	printf("%s\n", line);
//	return (0);
//}

