#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the number of memory partitions: ");
    scanf("%d", &n);

    int memory[n]; 
    printf("Enter the memory partitions (in KB):\n");
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &memory[i]);
    }

    int m; 
    printf("Enter the number of processes: ");
    scanf("%d", &m);

    int process[m]; 
    printf("Enter the memory requirements of processes (in KB):\n");
    for (int i = 0; i < m; i++) 
	{
        scanf("%d", &process[i]);
    }

    int allocation[m]; 
    for (int i = 0; i < m; i++) 
	{
        allocation[i] = -1; 
    }
    for (int i = 0; i < m; i++) 
	{
        int best_index = -1; 
        for (int j = 0; j < n; j++) 
		{
            if (memory[j] >= process[i]) 
			{
                if (best_index == -1 || memory[j] < memory[best_index]) 
				{
                    best_index = j;
                }
            }
        }
        if (best_index != -1) 
		{
            allocation[i] = best_index;
            memory[best_index] -= process[i];
        }
    }
    printf("Process\tMemory Allocated (in KB)\n");
    for (int i = 0; i < m; i++) 
	{
        if (allocation[i] != -1) 
		{
            printf("%d\t%d\n", i, process[i]);
        } else 
		{
            printf("%d\tNot Allocated\n", i);
        }
    }

    return 0;
}
