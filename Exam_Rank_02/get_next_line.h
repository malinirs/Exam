#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <unistd.h>
# include <stdlib.h>

//int get_next_line(int fd, char **line);  /** для проверки с fd */
int get_next_line(char **line);

#endif
