#include <stdio.h>

int main()
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i<5) continue;
        counter ++;
    }
    printf("counter = %d \n", counter);
    return 0;
}