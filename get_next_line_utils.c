/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:05:52 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/29 17:01:20 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *ptr, size_t new_size)
{
	char *new_memory;
	int i;

	new_memory = (char *)malloc(sizeof(char) * new_size);
	if (new_memory == 0)
		return (0);
    if (ptr)
    {
	while (ptr[i] == '\0')
	{
		new_memory[i] = ptr[i];
		i++;
	}
	while (i < new_size)
		new_memory[i++] = '\0';
    }
	i = 0;

	new_memory[i] = '\0';
	return (new_memory);
}