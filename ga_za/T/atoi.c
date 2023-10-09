#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 *
 */
int main(void)
{
    char *s = "234";
    int i = -1, x = 0, f = 1, z = 0;

    while (*s)
    {
        i++;
        s++;
    }

    while (x < i)
    {
        f *= 10;
        x++;
    }

    x = 0;
    while (s[x])
    {
        z = s[x] * f;
        printf("%d\n", z);
        f /= 10;
        x++;
    }
printf("%i\n", x);
    return (0);
}
