#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

_Atomic int counter = 0;

void *thread_func(void* arg)
{
    for (int i=0; i<1000000; i++)
    {
        atomic_fetch_add(&counter, 1); // カウンタをアトミックにインクリメント
    }

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    // 2つのスレッドを作成
    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);

    // スレッドの終了を待つ
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // 結果を表示
    printf("counter: %d\n", counter);

    return 0;
}
