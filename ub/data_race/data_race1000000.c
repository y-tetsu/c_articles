#include <stdio.h>
#include <pthread.h>

int shared_data = 0;

void* thread_func(void* arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        shared_data++;  // 共有データへの書き込み
    }

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    // 2つのスレッドを作成
    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);

    // スレッドの終了を待機
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // 結果を表示
    printf("shared_data: %d\n", shared_data);

    return 0;
}
