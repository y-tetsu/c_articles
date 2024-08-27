#include <stdio.h>
#include <pthread.h>

int shared_data = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // ミューテックスの初期化

void* thread_func(void* arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);    // クリティカルセクションの開始
        shared_data++;                 // 共有データへの書き込み
        pthread_mutex_unlock(&mutex);  // クリティカルセクションの終了
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

    // ミューテックスの破棄
    pthread_mutex_destroy(&mutex);

    return 0;
}
