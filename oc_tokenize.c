#include "ocarina.h"
#include <stdlib.h>

char *oc_tokenize(char *str, const char *delim)
{
    static char *buffer;
    char *sep, *b;
    const char *d;
    
    if (str != NULL)
    	buffer = str;
   
	if(buffer[0] == '\0')
    	return NULL;
 
    sep = buffer;
 
    for (b = buffer; *b !='\0'; b++)
    {
        for (d = delim; *d != '\0'; d++)
        {
            if (*b == *d)
            {
                *b = '\0';
                buffer = b + 1;
 
                if (b == sep)
                { 
                    sep++; 
                    continue; 
                }
                return sep;
            }
        }
    }
 
    return (sep);
}
