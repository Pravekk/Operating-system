#include <stdio.h>

#define TOTAL_BLOCKS 16
#define INODE_BLOCKS 8
#define MIN_FILE_SIZE 1
#define BLOCK_SIZE 1024
int checkBlocksFree(int startBlock, int numBlocks, int* disk)
{
    for (int i = startBlock; i < startBlock + numBlocks; i++) 
	{
        if (disk[i] != -1) 
		{
            return 0; 
        }
    }
    return 1; 
}

void allocateBlocks(int startBlock, int numBlocks, int* disk, int* fileAllocation)
{
    for (int i = startBlock; i < startBlock + numBlocks; i++) 
	{
        disk[i] = *fileAllocation;
        (*fileAllocation)++;
    }
}

void printDiskStatus(int* disk)
{
    printf("Disk Status:\n");
    for (int i = 0; i < TOTAL_BLOCKS; i++) 
	{
        printf("Block %d: ", i);
        if (disk[i] == -1) {
            printf("Free\n");
        } else {
            printf("Allocated to File %d\n", disk[i]);
        }
    }
}

int main()
{
    int disk[TOTAL_BLOCKS]; 
    int fileAllocation = 0; 
    int fileSize; 
    int startBlock; 
    int numBlocks;
    for (int i = 0; i < TOTAL_BLOCKS; i++) 
	{
        disk[i] = -1; 
    }
    while (1) 
	{
        printf("Enter the file size (in KB) to allocate (or 0 to exit): ");
        scanf("%d", &fileSize);

        if (fileSize == 0) 
		{
            break; 
        }

        if (fileSize < MIN_FILE_SIZE) {
            printf("Minimum file size is 1 KB.\n");
            continue;
        }

        numBlocks = (fileSize + BLOCK_SIZE - 1) / BLOCK_SIZE; 

        if (numBlocks > TOTAL_BLOCKS - INODE_BLOCKS) 
		{
            printf("Insufficient space on the disk.\n");
            break;
        }

        startBlock = INODE_BLOCKS; 
        int foundBlocks = 0;

        while (startBlock <= TOTAL_BLOCKS - numBlocks) 
		{
            if (checkBlocksFree(startBlock, numBlocks, disk)) 
			{
                allocateBlocks(startBlock, numBlocks, disk, &fileAllocation);
                printf("File allocated successfully. Starting block: %d\n", startBlock);
                printDiskStatus(disk);
                foundBlocks = 1;
                break;
            } else 
			{
                startBlock++;
            }
        }

        if (!foundBlocks) 
		{
            printf("No contiguous blocks available for allocation.\n");
            break; 
        }
    }

    return 0;
}

