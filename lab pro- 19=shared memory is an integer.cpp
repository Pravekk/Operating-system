#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 10

int shared_int = 5; 
sem_t mutex;

void *thread1(void *arg) {
  int doubled_value;
  sem_wait(&mutex);
  doubled_value = 2 * shared_int;
  printf("Doubled value: %d\n", doubled_value);
  sem_post(&mutex);
  pthread_exit(NULL);
}

void *thread2(void *arg) {
  int five_times_value;
  sem_wait(&mutex);
  five_times_value = 5 * shared_int;
  printf("Five times value: %d\n", five_times_value);
  sem_post(&mutex);
  pthread_exit(NULL);
}

int main() {
  pthread_t t1, t2;
  sem_init(&mutex, 0, 1);

  if (pthread_create(&t1, NULL, thread1, NULL)) {
    printf("Error creating thread 1\n");
    return 1;
  }

  if (pthread_create(&t2, NULL, thread2, NULL)) {
    printf("Error creating thread 2\n");
    return 1;
  }

  if (pthread_join(t1, NULL)) {
    printf("Error joining thread 1\n");
    return 1;
  }

  if (pthread_join(t2, NULL)) {
    printf("Error joining thread 2\n");
    return 1;
  }

  sem_destroy(&mutex);
  return 0;
}
