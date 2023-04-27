#include <stdio.h>
#include <stdbool.h>

#define NUM_PROCESSES 4
#define NUM_RESOURCES 3

int available[NUM_RESOURCES] = {9, 3, 6};
int allocation[NUM_PROCESSES][NUM_RESOURCES] = 
{
    {1, 0, 0},
    {6, 1, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int claim[NUM_PROCESSES][NUM_RESOURCES] = 
{
    {3, 2, 2},
    {6, 1, 3},
    {3, 1, 4},
    {4, 2, 2}
};

bool is_safe_state() 
{
    bool finish[NUM_PROCESSES] = {false};
    int work[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; i++) 
	{
        work[i] = available[i];
    }
    bool found;
    do 
	{
        found = false;
        for (int i = 0; i < NUM_PROCESSES; i++) 
		{
            if (!finish[i]) 
			{
                bool can_be_allocated = true;
                for (int j = 0; j < NUM_RESOURCES; j++) 
				{
                    if (claim[i][j] > work[j]) 
					{
                        can_be_allocated = false;
                        break;
                    }
                }
                if (can_be_allocated) 
				{
                    finish[i] = true;
                    found = true;
                    for (int j = 0; j < NUM_RESOURCES; j++) 
					{
                        work[j] += allocation[i][j];
                    }
                }
            }
        }
    } while (found);
    for (int i = 0; i < NUM_PROCESSES; i++) 
	{
        if (!finish[i]) 
		{
            return false;
        }
    }
    return true;
}

int main() 
{
    if (is_safe_state()) 
	{
        printf("The system is in a safe state.\n");
    } else 
	{
        printf("The system is in an unsafe state.\n");
    }
    return 0;
}
