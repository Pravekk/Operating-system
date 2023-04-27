#include <stdio.h>

int main() {
    int partitions[] = {300, 600, 350, 200, 750, 125};
    int num_partitions = 6;

    int processes[] = {115, 500, 358, 200, 375};
    int num_processes = 5;

    int allocation[num_processes];
    for (int i = 0; i < num_processes; i++) 
	{
        allocation[i] = -1;
    }
    for (int i = 0; i < num_processes; i++) 
	{
        for (int j = 0; j < num_partitions; j++) 
		{
            if (partitions[j] >= processes[i]) 
			{
                allocation[i] = j;
                partitions[j] -= processes[i];
                break;
            }
        }
    }
    printf("Process\tSize\tPartition\n");
    for (int i = 0; i < num_processes; i++) 
	{
        printf("%d\t%d\t", i+1, processes[i]);
        if (allocation[i] != -1) 
		{
            printf("%d\n", allocation[i]+1);
        } else {
            printf("Not allocated\n");
        }
    }

    return 0;
}
