/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 17:28:04 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/04/02 17:50:06 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

char	*get_newline(char **all_read, int fd)
{
	int		br;
	char	*buf;
	char	*temp;
	
	while (!ft_strchr(*all_read, '\n'))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		br = read(fd, buf, BUFFER_SIZE);
		if (br == -1)
			return (free(buf), NULL);
		if (br == 0)
			return (free(buf), *all_read);
		buf[br] = '\0';
		temp = *all_read;
		*all_read = ft_strjoin(temp, buf);
		free(temp);
		free(buf);
	}
	return (*all_read);
}

char	*check_leftover(char **leftover, char **all_read)
{
	char	*line;
	int		i;

	i = 0;
	if (!ft_strchr(*all_read, '\n'))
		return (*all_read);
	while ((*all_read)[i] != '\n')
		i++;
	line = ft_strndup(*all_read, i + 1);
	*leftover = ft_strdup((*all_read) + i + 1);
	if (ft_strlen(*leftover) == 0)
	{
		free(*leftover);
		*leftover = NULL;
	}
	free(*all_read);
	return (line);
}

char *get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		*all_read;
	char		*line;

	if (fd < 0)
		return (NULL);
	all_read = leftover;
	leftover = NULL;
	if (!get_newline(&all_read, fd))
	{
		if (all_read)
			free(all_read);
		return (NULL);
	}
	line = check_leftover(&leftover, &all_read);
	return (line);
}

// int main()
// {
// 	// int fd = open("text.txt", O_RDONLY);
// 	int fd = open("only_nl.txt", O_RDONLY);
// 	// int fd = open("text2.txt", O_RDONLY);
// 	char *x;
// 	x = get_next_line(fd);
// 	int i = 0;
// 	while (x)
// 	{
// 		printf("%d: %s", i, x);
// 		free(x);
// 		x = get_next_line(fd);
// 		i++;
// 	}
// 	printf("%d: %s", i, x);
// }