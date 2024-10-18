#include "get_next_line.h"

int main() {
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}