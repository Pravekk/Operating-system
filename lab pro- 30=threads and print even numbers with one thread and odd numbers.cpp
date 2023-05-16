#include <stdio.h>
#include <pthread.h>

#define MAX_NUMBER 20
void* printEvenNumbers(void* arg) 
{
    printf("Even numbers: ");
    for (int i = 2; i <= MAX_NUMBER; i += 2) 
	{
        printf("%d ", i);
    }
    printf("\n");

    pthread_exit(NULL);
}
void* printOddNumbers(void* arg) 
{
    printf("Odd numbers: ");
    for (int i = 1; i <= MAX_NUMBER; i += 2) 
	{
        printf("%d ", i);
    }
    printf("\n");

    pthread_exit(NULL);
}

int main() 
{
    pthread_t evenThread, oddThread;
    if (pthread_create(&evenThread, NULL, printEvenNumbers, NULL) != 0) 
	{
        printf("Error creating even thread.\n");
        return 1;
    }
    if (pthread_create(&oddThread, NULL, printOddNumbers, NULL) != 0) 
	{
        printf("Error creating odd thread.\n");
        return 1;
    }
    if (pthread_join(evenThread, NULL) != 0) 
	{
        printf("Error joining even thread.\n");
        return 1;
    }
    if (pthread_join(oddThread, NULL) != 0) 
	{
        printf("Error joining odd thread.\n");
        return 1;
    }

    return 0;
}

