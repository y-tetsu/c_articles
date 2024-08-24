#include <stdio.h>

int global_var;
static int static_var;

int main()
{
    int local_var1;
    int local_var2 = local_var1;

    printf("global : %d\n", global_var);
    printf("static : %d\n", static_var);
    printf("local1 : %d\n", local_var1);  // 未初期化の自動変数へアクセス
    printf("local2 : %d\n", local_var2);  // 未初期化の自動変数へアクセス

    return 0;
}
