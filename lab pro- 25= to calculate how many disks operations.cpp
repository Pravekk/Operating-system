#include <stdio.h>
#define BLOCK_SIZE 1        
#define FILE_SIZE 100 
int calculateContiguousIO(int position) 
{
    int numIO = 0;

    int numBlocks = FILE_SIZE + 1; 

    if (position < 1 || position > numBlocks) 
	{
        return -1;  
    }
    int numOperations = (numBlocks - position) * BLOCK_SIZE;
    numIO += numOperations;

    return numIO;
}
int calculateLinkedIO(int position) 
{
    int numIO = 0;

    int numBlocks = FILE_SIZE + 1; 

    if (position < 1 || position > numBlocks) 
	{
        return -1;  
    }
    int numOperations = position - 1;
    numIO += numOperations;
    numOperations = 2;
    numIO += numOperations;

    return numIO;
}
int calculateIndexedIO(int position) 
{
    int numIO = 0;

    int numBlocks = FILE_SIZE + 1; 

    if (position < 1 || position > numBlocks) 
	{
        return -1;  
    }
    int numOperations = 1;
    numIO += numOperations;

    numOperations = 1;
    numIO += numOperations;

    return numIO;
}

int main() 
{
    printf("Test Case a: Block added at the beginning\n");
    int position_a = 1;
    int contiguousIO_a = calculateContiguousIO(position_a);
    if (contiguousIO_a >= 0) 
	{
        printf("Contiguous Allocation: %d disk I/O operations\n", contiguousIO_a);
    } else {
        printf("Contiguous Allocation: Invalid position\n");
    }
    int linkedIO_a = calculateLinkedIO(position_a);
    if (linkedIO_a >= 0) 
	{
        printf("Linked Allocation: %d disk I/O operations\n", linkedIO_a);
    } else {
        printf("Linked Allocation: Invalid position\n");
    }
    int indexedIO_a = calculateIndexedIO(position_a);
    if (indexedIO_a >= 0) 
	{
        printf("Indexed Allocation: %d disk I/O operations\n", indexedIO_a);
    } else {
        printf("Indexed Allocation: Invalid position\n");
    }
    printf("\nTest Case b: Block added in the middle\n");
    int position_b = 50;
    
    return 0;
}

   

