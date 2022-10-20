#include <stdio.h>
#include <unistd.h>

int main(void)
{
    while(1)
        printf("%d Infinite Loop\n", getpid());
}