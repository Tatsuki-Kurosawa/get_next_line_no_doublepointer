/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:53 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/02/21 01:15:46 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*join(char *str, char *read_str, ssize_t num_of_byte)
{
	char	*return_ptr;

	if (num_of_byte == 0)
		return (str);
	else
	{
		if (!str)
			return_ptr = ft_substr(read_str, 0, ft_strlen(read_str));
		else
		{
			return_ptr = ft_strjoin(str, read_str);
			free(str);
			str = NULL;
		}
		return (return_ptr);
	}
}

static char	*setline(int fd, char *str)
{
	char	*read_str;
	ssize_t	num_of_byte;

	read_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_str)
		return (NULL);
	num_of_byte = 1;
	while (num_of_byte)
	{
		num_of_byte = read(fd, read_str, BUFFER_SIZE);
		read_str[num_of_byte] = '\0';
		if (num_of_byte == -1)
		{
			free(read_str);
			read_str = NULL;
			return (NULL);
		}
		else
			str = join(str, read_str, num_of_byte);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(read_str);
	read_str = NULL;
	return (str);
}

static char	*getbeforenewline(char *str)
{
	char	*before_newline;
	char	*newline_ptr;

	newline_ptr = ft_strchr(str, '\n');
	if (!newline_ptr)
		before_newline = ft_substr(str, 0, ft_strlen(str));
	else
		before_newline = ft_substr(str, 0, newline_ptr - str + 1);
	if (!before_newline)
		return (NULL);
	return (before_newline);
}

static char	*getafternewline(char *str)
{
	char	*after_newline;
	char	*newline_ptr;

	newline_ptr = ft_strchr(str, '\n');
	if (!newline_ptr)
		return (NULL);
	if (ft_strlen(newline_ptr) == 1)
		after_newline = NULL;
	else
		after_newline = ft_substr(newline_ptr, 1, ft_strlen(newline_ptr) - 1);
	if (!after_newline)
		return (NULL);
	free(str);
	return (after_newline);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*return_ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = setline(fd, str);
	if (!str)
		return (NULL);
	return_ptr = getbeforenewline(str);
	if (!return_ptr)
		return (NULL);
	str = getafternewline(str);
	return (return_ptr);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	size_t	i;

// 	i = 0;
// 	fd = open("./test.txt", O_RDONLY);
// 	while (i < 6)
// 	{
// 		// printf("%lu回目\n", i + 1);
// 		line = get_next_line(fd);
// 		printf("203|%s|\n", line);
// 		i ++;
// 	}
// 	return (0);
// }

// gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
// -g -fsanitize=address -fsanitize=undefined
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c 
//get_next_line_utils.c -g -fsanitize=address -fsanitize=undefined
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c 
//get_next_line_utils.c -g -fsanitize=address -fsanitize=undefined