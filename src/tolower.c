#include "ctype.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char* argv[])
{
    for(int i = 1; i < argc; ++i)
    {
        int len = strlen(argv[i]);
        
        for(int j = 0; j < len; ++j)
        {
            *(argv[i]+j) = tolower(*(argv[i]+j));
        }

        printf("%s ", argv[i]);
    }

    printf("\n");
}