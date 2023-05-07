#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0; 
int out = 0; 

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) 
{
    int i;
    int *data = (int*) arg;

    for (i = 0; i < 4; i++) 
	{
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) 
		{
            printf("Buffer is full, waiting for consumer...\n");
            pthread_cond_wait(&full, &mutex);
        }
        buffer[in] = data[i];
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Produced item: %d\n", data[i]);
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) 
{
    int i;
    int *data = (int*) arg;

    for (i = 0; i < 1; i++) 
	{
        pthread_mutex_lock(&mutex);
        while (count == 0) 
		{
            printf("Buffer is empty, waiting for producer...\n");
            pthread_cond_wait(&empty, &mutex);
        }
        data[i] = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumed item: %d\n", data[i]);
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() 
{
    pthread_t prod_tid, cons_tid;
    int prod_data[] = {1, 2, 3, 4};
    int cons_data[1];

    pthread_create(&prod_tid, NULL, producer, prod_data);
    pthread_create(&cons_tid, NULL, consumer, cons_data);

    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);

    return 0;
}

