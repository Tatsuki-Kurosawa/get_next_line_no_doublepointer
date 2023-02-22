#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	// fd = open("./test.txt", O_RDONLY);
	fd = open("./nl", O_RDONLY);
	while (i < 6)
	{
		line = get_next_line(fd);
		printf("203|%s|\n", line);
		i ++;
	}
	return (0);
}

// gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -g -fsanitize=address -fsanitize=undefined
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -g -fsanitize=address -fsanitize=undefined
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -g -fsanitize=address -fsanitize=undefined

// BUFFER_SIZEは何型？