#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h> // Include for open

int main() {
    // Open the file in read-only mode
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1; // Return non-zero value to indicate error
    }

    char *line = get_next_line(0);
    while (line != NULL) {
        printf("%s", line);
        free(line);
        line = get_next_line(0);
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
