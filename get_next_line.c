/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:31:37 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/29 19:01:37 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	process_line(const char *line)
{
    while (*line)
        write(1, line++, 1);
}

char    *get_next_line(int fd)
{
	size_t	bytes_read;
	char	buffer[BUFF_SIZE];
	char	*line;
	size_t	line_length;
    size_t  i;

	line = NULL;
	line_length = 0;

    bytes_read = read(fd, buffer, BUFF_SIZE);
	while ((bytes_read ) > 0)
	{
        i = 0;
		while (i < bytes_read)
		{
			line = ft_realloc(line, line_length + 1);
            if (line == 0)
                return (0);
			line[line_length++] = buffer[i];
			if (buffer[i] == '\n')
			{
				line[line_length] = '\0';
				process_line(line);
				free(line);
				line = NULL;
				line_length = 0;
			}
            i++;
		}
        bytes_read = read(fd, buffer, BUFF_SIZE);
	}
	if (bytes_read <= 0)
        return (0);
}

