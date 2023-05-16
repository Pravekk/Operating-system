#include <stdio.h>
#include <stdbool.h>

#define NUM_PARTITIONS 4
typedef struct 
{
    int size;
    bool allocated;
}
 MemoryPartition;
void initializeMemory(MemoryPartition* memory, int* partition_sizes) 
{
    for (int i = 0; i < NUM_PARTITIONS; i++) 
	{
        memory[i].size = partition_sizes[i];
        memory[i].allocated = false;
    }
}
void displayMemory(MemoryPartition* memory) 
{
    printf("Memory Partitions:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) 
	{
        printf("Partition %d: Size: %d KB, Allocated: %s\n", i + 1, memory[i].size,
               memory[i].allocated ? "Yes" : "No");
    }
    printf("\n");
}
void allocateMemoryFirstFit(MemoryPartition* memory, int process_size) 
{
    for (int i = 0; i < NUM_PARTITIONS; i++) 
	{
        if (!memory[i].allocated && memory[i].size >= process_size) 
		{
            memory[i].allocated = true;
            printf("Process allocated to Partition %d\n", i + 1);
            return;
        }
    }

    printf("Memory allocation failed for process size %d KB\n", process_size);
}

int main() 
{
    int partition_sizes[NUM_PARTITIONS] = {40, 10, 30, 60};
    MemoryPartition memory[NUM_PARTITIONS];
    initializeMemory(memory, partition_sizes);
    displayMemory(memory);

    int process_sizes[] = {100, 50, 30, 120, 35};
    int num_processes = sizeof(process_sizes) / sizeof(process_sizes[0]);

    for (int i = 0; i < num_processes; i++) 
	{
        int process_size = process_sizes[i];
        allocateMemoryFirstFit(memory, process_size);

        displayMemory(memory);
    }

    return 0;
}

