/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:31:37 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/30 17:58:00 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFF_SIZE];
	static int	buff_pos = 0;
	ssize_t		bytes_read;
	char		*line;

	line = NULL;
	while (1)
	{
		if (buff_pos == 0)
			bytes_read = ft_read_to_buffer(fd, buffer);
		if (bytes_read <= 0)
			return (NULL);
		line = ft_process_buffer_into_line(line, buffer, buff_pos);
		if (line == 0)
			return (NULL);
		while (buffer[buff_pos] && buffer[buff_pos] != '\n')
			buff_pos++;
		if (buffer[buff_pos] == '\n')
			return (line);
		if (buffer[buff_pos] == '\0')
			buff_pos = 0;
	}
}
