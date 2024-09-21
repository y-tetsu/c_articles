#include <stdio.h>

int main()
{
    int a = 5;
    //　↓ 余計な括弧
    if ((a = 10))
    {
        printf("a is 10\n");
    }
    else
    {
        printf("a is not 10\n");
    }
    return 0;
}
