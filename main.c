#include "get_next_line.h"
#include <fcntl.h> // Include for open
#include <stdio.h>

#ifndef INPUT_FILE
 #define INPUT_FILE "tests/43_nl.txt"
#endif

int	main(void)
{
	int		fd;
	char	*line;

	// Open the file in read-only mode
	fd = open(INPUT_FILE, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1); // Return non-zero value to indicate error
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	// Close the file descriptor
	close(fd);
	return (0);
}


