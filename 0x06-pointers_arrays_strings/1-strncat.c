#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[20] = "Hello ";
    char s2[] = "world";
    char *ptr;

    ptr = _strncat(s1, s2, 3);

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("ptr: %s\n", ptr);

    return (0);
}

