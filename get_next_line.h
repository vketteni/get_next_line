/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:32:36 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/31 16:58:00 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# define ERROR 0
# define CONTINUE 1
# define END_OF_FUNCTION 2

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_realloc(char *str, size_t new_size);
char	*ft_process_buffer_into_line(char *line, char *buffer, int buff_pos);
int		ft_read_to_buffer(int fd, char *buffer, int buff_pos, char *line);

#endif