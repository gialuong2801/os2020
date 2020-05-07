#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
int Max = 1000000;

void *fibonacci(void *args) {
    int a = 2, b = 3, c;
    printf("Fibonacci Sequence from 2 to 1000000: %d, %d, ", a, b);
    c = a + b;
    while (c <= Max) {
        printf("%d, ", c);
        a = b;
        b = c;
        c = a + b;
    }
}

bool prime(int number){
  if(number <= 1)
    return false;
  for (int i = 2; i < number; i++)
  {
    if (number % i == 0)
    {
      return false;
    }
  }
  return true;
}

void *printprime(void *args){
  int count = 0;
  for (int i = 2; i <= Max; i++)
  {
    if(prime(i)){
      printf("%d - ", i);
      count = count + 1;
    }
  }
  printf("%d", count);
}

int main()
{
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, fibonacci, NULL);
  pthread_create(&tid2, NULL, printprime, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}