#include "main.h"

char *_memcpy(char *dest, char *src, unsigned int n)
{
    unsigned char *d = (unsigned char *)dest;
    unsigned char *s = (unsigned char *)src;
    while (n-- > 0)
    {
        *d++ = *s++;
    }
    return dest;
}
