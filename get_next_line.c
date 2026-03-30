/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/29 18:17:56 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/30 20:40:11 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*r;
	char	*start;

	len = ft_strlen(s);
	r = malloc(len + 1);
	if (!r)
		return (NULL);
	start = r;
	while (*s)
	{
		*r = *s;
		r++;
		s++;
	}
	*r = '\0';
	return (start);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	char	*start;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	start = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (start);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	check_new_line(char *leftover)
{
	
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	int			br;
	char		*buf;
	char		*line;

	if (leftover && ft_strchr(leftover, '\n'))
	{
		line = ft_strndup(leftover, (ft_strchr(leftover, '\n') - leftover));
		buf = leftover;
		leftover = ft_strdup(ft_strchr(leftover, '\n'));
		free(buf);
		return (line);
	}
	while (!buf || !ft_strchr(buf, '\n'))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		br = read(fd, buf, BUFFER_SIZE);
		if (br == -1)
		{
			// free
			return (NULL);
		}
		buf[br] = '\0';
		line = ft_strjoin(leftover, buf); // ...
	}
	return NULL;
}

int main()
{
	// char *x;
	// x = get_next_line(0);
	// printf("%s", x);
	// free(x);
}
