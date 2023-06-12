#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int create_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }

    int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file == -1) {
        return -1;
    }

    if (text_content != NULL) {
        ssize_t bytesWritten = write(file, text_content, strlen(text_content));
        if (bytesWritten == -1) {
            close(file);
            return -1;
        }
    }

    close(file);
    return 1;
}

