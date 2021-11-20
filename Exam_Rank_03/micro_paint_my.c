#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char	*map;
int 	width, height;
float	x, y, r;
char	b_g, type, square;

void	print(void)
{
	int	j = -1;

	while (++j < height)
	{
		write(1, map + j * width, width);
		write(1, "\n", 1);
	}
}

int	check(float i, float j)
{
	float	numb = sqrtf((i - x) * (i - x) + (j - y) * (j - y));

	if (numb <= r)
	{
		if (numb - r < 0)
			return (1);
		return (2);
	}
	return (0);
}

void	draw(void)
{
	int	i = -1, j, temp;

	while (++i < width)
	{
		j = -1;
		while (++j < height)
		{
			temp = check((float)i, (float)j);
			if (temp == 2 || (temp == 1 && type == 'C'))
				map[i + j * width] = square;
		}
	}
}

int	pars(FILE *file)
{
	int	temp = -1;

	if (fscanf(file, "%d %d %c\n", &width, &height, &b_g) != 3)
		return (1);
	if (width < 1 || width > 300 || height < 1 || height > 300)
		return (1);
	if (!(map = malloc(width * height)))
		return (1);
	while (++temp < width * height)
		map[temp] = b_g;
	while ((temp = fscanf(file, "%c %f %f %f %c\n", &type, &x, &y, &r,
	&square)) == 5)
	{
		if (r < 1 || (type != 'c' && type != 'C'))
			return (1);
		draw();
	}
	if (temp != -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	FILE	*file;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	else
	{
		if (!(file = fopen(argv[1], "r")) || pars(file))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		print();
		fclose(file);
		free(map);
	}
	return (0);
}




























//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//char	*map;
//int		width, height;
//float	x, y, w, h;
//char	b_g, type, square;
//
//int	check(float i, float j)
//{
//	if (i < x || j < y || x + w < i || y + h < j)
//		return (0);
//	if (i - x < 1 || j - y < 1 || x + w - i < 1 || y + h - j < 1)
//		return (2);
//	return (1);
//}
//
//void	draw(void)
//{
//	int	i = -1, j, temp;
//
//	while (++i < width)
//	{
//		j = -1;
//		while (++j < height)
//		{
//			temp = check((float)i, (float)j);
//			if (temp == 2 || (temp == 1 && type == 'R'))
//				map[i + j * width] = square;
//		}
//	}
//}
//
//int	pars(FILE *file)
//{
//	int	temp, i = -1;
//
//	if (fscanf(file, "%d %d %c\n", &width, &height, &b_g) != 3)
//		return (1);
//	if (width < 1 || height > 300 || width < 1 || width > 300)
//		return (1);
//	if (!(map = malloc(width * height)))
//		return (1);
//	while (++i < width * height)
//		map[i] = b_g;
//	while ((temp = fscanf(file, "%c %f %f %f %f %c\n", &type, &x, &y, &w, &h,
//						  &square)) == 6)
//	{
//		if (w < 1 || h < 1 || (type != 'r' && type != 'R'))
//			return (1);
//		draw();
//	}
//	if (temp != -1)
//		return (1);
//	return (0);
//}
//
//void	print(void)
//{
//	int	j = -1;
//
//	while(++j < height)
//	{
//		write(1, map + j * width, width);
//		write(1, "\n", 1);
//	}
//}
//
//int	main(int argc, char **argv)
//{
//	FILE	*file;
//
//	if (argc != 2)
//	{
//		write(1, "Error: argument\n", 16);
//		return (0);
//	}
//	else
//	{
//		if (!(file = fopen(argv[1], "r")) || pars(file))
//		{
//			write(1, "Error: Operation file corrupted\n", 32);
//			return (1);
//		}
//		print();
//		fclose(file);
//		free(map);
//	}
//	return (0);
//}