#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_INSTANCES 4
#define NUM_PROCESSES 4
sem_t semaphore;
void* waiting_thread(void* arg) 
{
    int process_id = *(int*)arg;

    printf("P%d: Waiting...\n", process_id);
    sem_wait(&semaphore);

    printf("P%d: Got the resource!\n", process_id);

    sem_post(&semaphore); 

    pthread_exit(NULL);
}

int main() 
{
    sem_init(&semaphore, 0, NUM_INSTANCES);
    int process_ids[NUM_PROCESSES];
    for (int i = 0; i < NUM_PROCESSES; i++) 
	{
        process_ids[i] = i + 1;
    }
    pthread_t waitingThreads[NUM_PROCESSES];
    for (int i = 0; i < NUM_PROCESSES; i++) 
	{
        pthread_create(&waitingThreads[i], NULL, waiting_thread, (void*)&process_ids[i]);
    }

    for (int i = 0; i < NUM_PROCESSES; i++) 
	{
        pthread_join(waitingThreads[i], NULL);
    }
    int process_id = 5;

    printf("P%d: Waiting...\n", process_id);

    sem_wait(&semaphore);

    printf("P%d: Got the resource!\n", process_id);

    sem_post(&semaphore); 
    sem_destroy(&semaphore);

    return 0;
}

