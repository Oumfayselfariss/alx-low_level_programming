#include "main.h"

/**
 * rot13 - encodes a string using rot13
 *
 * @s: string to be encoded
 *
 * Return: pointer to the encoded string
 */
char *rot13(char *s)
{
        int i, j;
        char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

        for (i = 0; s[i] != '\0'; i++)
        {
                for (j = 0; alphabets[j] != '\0'; j++)
                {
                        if (s[i] == alphabets[j])
                        {
                                s[i] = rot13[j];
                                break;
                        }
                }
        }

        return s;
}

