#include <string.h>
#include <stdlib.h>

char* copy_string(char* s)
{
    if(s != 0)
    {
        char* clone = (char*)malloc ((strlen (s) + 1)*sizeof (char));
        strcpy (clone, s);
        return clone;
    }
    else
        return 0;
}