#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void print_error(const char *error_message) {
    dprintf(STDERR_FILENO, "Error: %s\n", error_message);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_error("Usage: cp file_from file_to");
        exit(97);
    }

    const char *file_from = argv[1];
    const char *file_to = argv[2];

    int fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        print_error("Can't read from file");
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        exit(98);
    }

    int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1) {
        print_error("Can't write to file");
        dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
        exit(99);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    while ((bytesRead = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(fd_to, buffer, bytesRead);
        if (bytesWritten == -1) {
            print_error("Can't write to file");
            dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
            exit(99);
        }
    }

    if (bytesRead == -1) {
        print_error("Can't read from file");
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        exit(98);
    }

    if (close(fd_from) == -1) {
        print_error("Can't close fd");
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    if (close(fd_to) == -1) {
        print_error("Can't close fd");
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return 0;
}
