#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[20] = "Hello";
    const char str2 = " world!";
    charptr;

    ptr = str1 + strlen(str1);
    while (*str2 != '\0') {
        ptr++ =str2++;
    }
    *ptr = '\0';

    printf("Concatenated string: %s\n", str1);
    return 0;
}
