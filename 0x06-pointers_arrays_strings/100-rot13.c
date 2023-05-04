/**
 * rot13 - encodes a string using rot13
 * @s: string to encode
 *
 * Return: pointer to encoded string
 */
char *rot13(char *s)
{
  char *p = s;
  int i;

  while (*p)
  {
    for (i = 0; (*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'); i++)
    {
      if ((*p >= 'a' && *p <= 'm') || (*p >= 'A' && *p <= 'M'))
        *p += 13;
      else
        *p -= 13;
      p++;
    }
    p++;
  }

  return s;
}
