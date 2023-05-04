#include "main.h"
#include <stdio.h>
#include <ctype.h>

/**
 * print_buffer - prints the content of a buffer
 * @b: the buffer to print
 * @size: the number of bytes to print
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
    int i, j;

    for (i = 0; i < size; i += 10)
    {
        printf("%08x: ", i);

        for (j = 0; j < 10; j++)
        {
            if (i + j < size)
                printf("%02x", *(b + i + j));
            else
                printf("  ");

            if (j % 2 == 1)
                printf(" ");
        }

        for (j = 0; j < 10 && i + j < size; j++)
        {
            char c = *(b + i + j);

            if (isprint(c))
                putchar(c);
            else
                putchar('.');
        }

        printf("\n");
    }
    if (size <= 0)
        printf("\n");
}
