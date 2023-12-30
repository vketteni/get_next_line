/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:05:52 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/30 17:57:49 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *ptr, size_t new_size)
{
	char	*new_memory;
	int		i;

	new_memory = (char *)malloc(sizeof(char) * new_size);
	if (new_memory == 0)
		return (0);
	i = 0;
	if (ptr)
	{
		while (ptr[i] != '\0')
		{
			new_memory[i] = ptr[i];
			i++;
		}
		while (i < new_size)
			new_memory[i++] = '\0';
	}
	new_memory[i] = '\0';
	return (new_memory);
}

char	*ft_process_buffer_into_line(char *line, char *buffer, int buff_pos)
{
	int	line_length;
	int	i;
	int	j;

	line_length = 0;
	while (line[line_length])
		line_length++;
	i = buff_pos;
	while (buffer[i] && buffer[i] != '\n')
		line_length++;
	line = ft_realloc(line, line_length + 1);
	if (line == NULL)
		return (NULL);
	j = 0;
	while (buff_pos < i)
		line[j++] = buffer[buff_pos++];
	return (line);
}

ssize_t	ft_read_to_buffer(int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (bytes_read);
}
