#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int c;
    long nc = 0;


    while((c = getchar()) != EOF )
    {
        putchar(c);
        nc++;
    }
    printf("nc = %ld\n", nc);
    printf("LONG_MAX = %ld\n", LONG_MAX);
}
