#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int append_text_to_file(const char *filename, char *text_content) {
    if (filename == NULL) {
        return -1;
    }

    if (text_content == NULL) {
        return 1;  // Nothing to add, so return 1 if the file exists
    }

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        return -1;  // Unable to open the file for appending
    }

    size_t length = strlen(text_content);
    size_t bytesWritten = fwrite(text_content, sizeof(char), length, file);

    fclose(file);

    if (bytesWritten != length) {
        return -1;  // Failed to write the entire text content
    }

    return 1;
}
