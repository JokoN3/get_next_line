/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/29 18:17:56 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/29 20:24:23 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	
}

int main()
{
	char *x;
	x = get_next_line(1);
	printf("%s", x);
	free(x);
}