#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

int MAX = 1000000;
void *prime_number(void *param) {
    int i,j;
    printf("Prime number from 2 to 1000000:\n");
    for (i=2; i<= MAX; i++) {
        for (j=2; j<=i; j++) {
            if (i%j==0) {
                break;
            }
        }
        if (i==j) {
            pthread_mutex_lock(&lock);
            printf("%d \n",i);
            pthread_mutex_unlock(&lock);
        }
    }
}

void *fibonacci(void *param) {
    int a = 2, b = 3, c;
    printf("Fibonacci Sequence from 2 to 1000000: %d, %d, ", a, b);
    c = a + b;
    while (c <= MAX) {
        pthread_mutex_lock(&lock);
        printf("%d, ", c);
        a = b;
        b = c;
        c = a + b;
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    pthread_t tid1;
	pthread_t tid2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&tid1, NULL, prime_number, NULL);
    pthread_create(&tid2, NULL, fibonacci, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}