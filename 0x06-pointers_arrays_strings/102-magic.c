#include <stdio.h>

/**
 * main - prints the third element of an array and a new line
 *
 * Return: Always 0.
 */
int main(void)
{
    int a[3] = { 0, 1, 98 };
    int *p;

    p = &a[2];
    printf("a[2] = %d\n", *p);
    return (0);
}
