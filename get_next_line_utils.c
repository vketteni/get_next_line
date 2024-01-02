/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:05:52 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/02 16:06:31 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *old_memory, size_t new_size)
{
	char	*new_memory;
	size_t	i;

	new_memory = (char *)malloc(sizeof(char) * new_size);
	if (new_memory == 0)
		return (0);
	i = 0;
	if (old_memory)
	{
		while (old_memory[i] != '\0')
		{
			new_memory[i] = old_memory[i];
			i++;
		}
		free(old_memory);
	}
	while (i < new_size)
		new_memory[i++] = '\0';
	return (new_memory);
}

char	*ft_process_buffer_into_line(char *buffer, int *buff_pos, char *line,
		int bytes_read)
{
	int	line_length;
	int	new_end;

	new_end = *buff_pos;
	line_length = 0;
	while (line && line[line_length])
		line_length++;
	while (new_end < BUFFER_SIZE - 1 && new_end < bytes_read
		&& buffer[new_end] != '\0' && (buffer[new_end] != '\n'))
		new_end++;
	if (buffer[new_end] != '\0')
		new_end++;
	line = ft_realloc(line, line_length + (new_end - *buff_pos) + 1);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	while (*buff_pos < new_end)
		line[line_length++] = buffer[(*buff_pos)++];
	line[line_length] = '\0';
	return (line);
}

// int	ft_read_to_buffer(int fd, char *buffer, int buff_pos, char *line)
// {
// 	ssize_t	bytes_read;

// 	if (buff_pos == 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read <= 0)
// 		{
// 			if (bytes_read == 0 && line)
// 				return (END_OF_FUNCTION);
// 			return (ERROR);
// 		}
// 	}
// 	return (CONTINUE);
// }
