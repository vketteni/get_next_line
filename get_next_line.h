/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:32:36 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/30 17:58:48 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_realloc(char *str, size_t new_size);
char	*ft_process_buffer_into_line(char *line, char *buffer, int buff_pos);
ssize_t	ft_read_to_buffer(int fd, char *buffer);

#endif