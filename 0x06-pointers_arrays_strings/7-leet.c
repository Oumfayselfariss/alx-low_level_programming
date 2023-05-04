#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @s: input string
 *
 * Return: pointer to encoded string
 */
char *rot13(char *s)
{
	int i;
	char *str = s;
	char *org = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = rot[str[i] - 'a' + 26];
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = rot[str[i] - 'A'];
	}
	return (s);
}
