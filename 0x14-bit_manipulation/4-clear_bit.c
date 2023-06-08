#include "main.h"
/**
* clear_bit - sets the value of a bit to 0 at a given index
* @n: unsigned long to change
* @index: index to change to zero
* Return: 1 if it worked or -1 if an error occurred
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 63 || !n)
return (-1);

*n &= ~(1UL << index);
return (1);
}
