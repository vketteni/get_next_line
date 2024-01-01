/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:31:37 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/01 18:39:55 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE] = {0};
	static int	buff_pos = 0;
	int			return_code;
	char		*line;

	line = NULL;
	while (1)
	{
		return_code = ft_read_to_buffer(fd, buffer, buff_pos, line);
		if (return_code == END_OF_FUNCTION)
			return (line);
		else if (return_code == ERROR)
			return (NULL);
		line = ft_process_buffer_into_line(line, buffer, buff_pos);
		if (line == 0)
			return (NULL);
		while (buffer[buff_pos] && buffer[buff_pos] != '\n')
			buff_pos++;
		if (buffer[buff_pos] == '\n' && (buff_pos++ >= 0))
			return (line);
		if (buffer[buff_pos] == '\0')
			buff_pos = 0;
	}
}
