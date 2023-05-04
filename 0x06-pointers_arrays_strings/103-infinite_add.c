#include "main.h"
#include <stdio.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int carry = 0;

    if (len1 + 1 > size_r || len2 + 1 > size_r)
    {
        return 0;
    }

    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry != 0)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += n1[i] - '0';
            i--;
        }

        if (j >= 0)
        {
            sum += n2[j] - '0';
            j--;
        }

        if (k >= size_r)
        {
            return 0;
        }

        r[k] = (sum % 10) + '0';
        carry = sum / 10;
        k++;
    }

    r[k] = '\0';

    for (int i = 0; i < k / 2; i++)
    {
        char temp = r[i];
        r[i] = r[k - i - 1];
        r[k - i - 1] = temp;
    }

    return r;
}
