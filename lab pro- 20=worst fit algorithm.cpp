#include <stdio.h>
#include <stdlib.h>

#define MAX_MEM_SIZE 100

int memory[MAX_MEM_SIZE];
int num_processes;

struct process 
{
    int pid;
    int size;
    int allocated;
};

struct process processes[MAX_MEM_SIZE];

int worst_fit(int size) 
{
    int i, j = -1;
    for (i = 0; i < MAX_MEM_SIZE; i++) 
	{
        if (memory[i] == 0) 
		{
            int k = i;
            while (memory[k] == 0 && k < MAX_MEM_SIZE) 
			{
                k++;
            }
            if ((k - i) > size && (j == -1 || (k - i) > (j - i))) 
			{
                j = i;
            }
            i = k;
        }
    }
    return j;
}

void allocate_memory(struct process p) 
{
    int i, j;
    j = worst_fit(p.size);
    if (j != -1) {
        for (i = j; i < j + p.size; i++) 
		{
            memory[i] = p.pid;
        }
        p.allocated = 1;
        printf("Process %d with size %d has been allocated to memory.\n", p.pid, p.size);
    } else 
	{
        printf("Memory allocation failed for Process %d with size %d.\n", p.pid, p.size);
    }
}

void print_memory() 
{
    int i;
    printf("Memory Layout: ");
    for (i = 0; i < MAX_MEM_SIZE; i++) 
	{
        if (memory[i] == 0) 
		{
            printf(".");
        } else {
            printf("%d", memory[i]);
        }
    }
    printf("\n");
}

int main() 
{
    int i;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter process size for each process:\n");
    for (i = 0; i < num_processes; i++) 
	{
        processes[i].pid = i + 1;
        scanf("%d", &processes[i].size);
        processes[i].allocated = 0;
    }
    for (i = 0; i < MAX_MEM_SIZE; i++) 
	{
        memory[i] = 0;
    }
    for (i = 0; i < num_processes; i++) 
	{
        allocate_memory(processes[i]);
        print_memory();
    }
    return 0;
}

