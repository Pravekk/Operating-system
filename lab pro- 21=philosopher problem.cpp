#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

pthread_mutex_t chopsticks[N];
pthread_t philosophers[N];
sem_t table;
int state[N];

void *philosopher(void *arg) 
{
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % N;
    while (1) 
	{
        printf("Philosopher %d is thinking...\n", id);
        state[id] = 0;
        sleep(rand() % 5); 
        sem_wait(&table);
        pthread_mutex_lock(&chopsticks[left]);
        printf("Philosopher %d is picking up chopstick %d\n", id, left);
        pthread_mutex_lock(&chopsticks[right]);
        printf("Philosopher %d is picking up chopstick %d\n", id, right);
        state[id] = 1;
        printf("Philosopher %d is hungry...\n", id);
        if (state[left] != 2 && state[(right+N-1)%N] != 2) 
		{
            state[id] = 2;
            printf("Philosopher %d is eating...\n", id);
            sleep(rand() % 5); 
            pthread_mutex_unlock(&chopsticks[left]);
            printf("Philosopher %d is putting down chopstick %d\n", id, left);
            pthread_mutex_unlock(&chopsticks[right]);
            printf("Philosopher %d is putting down chopstick %d\n", id, right);
            state[id] = 0; 
            sem_post(&table);
        } else 
		{
            pthread_mutex_unlock(&chopsticks[left]);
            printf("Philosopher %d is putting down chopstick %d\n", id, left);
            pthread_mutex_unlock(&chopsticks[right]);
            printf("Philosopher %d is putting down chopstick %d\n", id, right);
            sleep(rand() % 5); 
        }
    }
}

int main() 
{
    int i, cycles;
    int ids[N];
    printf("Enter number of cycles to run simulation for: ");
    scanf("%d", &cycles);
    for (i = 0; i < N; i++) 
	{
        pthread_mutex_init(&chopsticks[i], NULL);
        state[i] = 0; 
    }
    sem_init(&table, 0, N-1);
    for (i = 0; i < N; i++) 
	{
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }
    for (i = 0; i < N; i++) 
	{
        pthread_join(philosophers[i], NULL);
    }
    for (i = 0; i < N; i++) 
	{
        pthread_mutex_destroy(&chopsticks[i]);
    }
    sem_destroy(&table);
    return 0;
}

