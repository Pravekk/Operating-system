#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int isPrime(int num) 
{
    if (num <= 1) 
	{
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}
void generateFibonacci(int n)
{
    int prev = 0;
    int curr = 1;

    printf("Fibonacci Series:\n");

    for (int i = 0; i < n; i++) 
	{
        printf("%d ", prev);
        int next = prev + curr;
        prev = curr;
        curr = next;
    }

    printf("\n");
}

int main() 
{
    pid_t childPid = fork();

    if (childPid < 0) 
	{
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (childPid == 0) 
	{
        generateFibonacci(10);
    } else 
	{
        int status;
        waitpid(childPid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) 
		{
            printf("Prime Numbers:\n");

            for (int i = 2; i <= 30; i++) 
			{
                if (isPrime(i)) 
				{
                    printf("%d ", i);
                }
            }

            printf("\n");
        } else 
		{
            fprintf(stderr, "Child process exited abnormally.\n");
            return 1;
        }
    }

    return 0;
}

