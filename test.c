#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    char *foo = "abcdef";
    foo += 2;
    printf("%s", foo += 1);
    foo -= 2;
    printf("\n%s", foo);
}