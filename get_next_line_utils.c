/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:57 by kurosawaits       #+#    #+#             */
/*   Updated: 2023/02/20 16:57:58 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		len = 0;
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	return_ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!return_ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		return_ptr[i] = s[start + i];
		i++;
	}
	return_ptr[i] = '\0';
	return (return_ptr);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// joinとfreeを合わせる
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*return_ptr;
	size_t		str_size;
	size_t		check;

	if (!s1 || !s2)
		return (NULL);
	str_size = ft_strlen(s1) + ft_strlen(s2);
	return_ptr = (char *)malloc(sizeof(char) * (str_size + 1));
	if (!return_ptr)
		return (NULL);
	check = ft_strlcpy(return_ptr, s1, ft_strlen(s1) + 1);
	if (check != ft_strlen(return_ptr))
	{
		free(return_ptr);
		return (NULL);
	}
	check = ft_strlcpy(return_ptr + check, s2, ft_strlen(s2) + 1);
	if (check != ft_strlen(s2))
	{
		free(return_ptr);
		return (NULL);
	}
	return (return_ptr);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
