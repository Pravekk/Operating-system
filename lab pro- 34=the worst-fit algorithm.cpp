#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESS 100
struct Block 
{
    int blockId;
    int size;
    int allocated;
};

struct Process 
{
    int processId;
    int size;
    int blockId;
};

void worstFit(struct Block blocks[], int numBlocks, struct Process processes[], int numProcesses) 
{
    for (int i = 0; i < numProcesses; i++) 
	{
        int worstBlockIndex = -1;
        for (int j = 0; j < numBlocks; j++) 
		{
            if (blocks[j].size >= processes[i].size && blocks[j].allocated == 0) 
			{
                if (worstBlockIndex == -1 || blocks[j].size > blocks[worstBlockIndex].size) 
				{
                    worstBlockIndex = j;
                }
            }
        }

        if (worstBlockIndex != -1)
		{
            blocks[worstBlockIndex].allocated = 1;
            processes[i].blockId = blocks[worstBlockIndex].blockId;
        }
    }
}

int main() 
{
    int numBlocks, numProcesses;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    struct Block blocks[MAX_BLOCKS];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < numBlocks; i++) 
	{
        blocks[i].blockId = i;
        blocks[i].allocated = 0;
        scanf("%d", &blocks[i].size);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    struct Process processes[MAX_PROCESS];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < numProcesses; i++) 
	{
        processes[i].processId = i;
        scanf("%d", &processes[i].size);
    }

    worstFit(blocks, numBlocks, processes, numProcesses);

    printf("\nProcess Allocation:\n");
    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < numProcesses; i++) 
	{
        printf("%d\t%d\t", processes[i].processId, processes[i].size);
        if (processes[i].blockId != -1) 
		{
            printf("%d\n", processes[i].blockId);
        } else 
		{
            printf("Not Allocated\n");
        }
    }

    return 0;
}

