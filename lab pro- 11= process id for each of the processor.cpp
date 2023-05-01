#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    int i, pid[4];
    for (i = 0; i < 4; i++) 
	{
        pid[i] = fork();

        if (pid[i] < 0) 
		{
            printf("Error: Failed to fork process.\n");
            exit(1);
        } else if (pid[i] == 0) 
		{
            
            printf("Child process %d with pid %d: ", i+1, getpid());

            switch (i+1) 
			{
                case 1:
                    for (int j = 1; j <= 10; j += 2) 
					{
                        printf("%d ", j);
                    }
                    break;

                case 2:
                    for (int j = 2; j <= 10; j += 2) 
					{
                        printf("%d ", j);
                    }
                    break;

                case 3:
                    for (int j = 3; j <= 30; j += 3) 
					{
                        printf("%d ", j);
                    }
                    break;

                case 4:
                    for (int j = 5; j <= 50; j += 5) 
					{
                        printf("%d ", j);
                    }
                    break;
            }

            printf("\n");
            exit(0);
        }
    }
    for (i = 0; i < 4; i++) 
	{
        waitpid(pid[i], NULL, 0);
    }

    printf("Parent process with pid %d exiting.\n", getpid());
    return 0;
}

