#include <stdio.h>

int main()
{
    int arr[3] = {1, 2, 3};

    printf("%d\n", arr[3]);  // 領域外アクセス

    return 0;
}
