#include "main.h"

char *_strstr(char *haystack, char *needle)
{
    while (*haystack != '\0')
    {
        char *tempHaystack = haystack;
        char *tempNeedle = needle;

        while (*tempNeedle != '\0' && *tempHaystack == *tempNeedle)
	{
            tempHaystack++;
            tempNeedle++;
        }

        if (*tempNeedle == '\0')
	{
            return haystack;
        }
        haystack++;
    }
    return NULL;
}
