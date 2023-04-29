#include <stdio.h>

#define NUM_PROCESSES 3
#define NUM_RESOURCES 3

int main() 
{
    int max_matrix[NUM_PROCESSES][NUM_RESOURCES] = 
	{
        {3, 6, 8},
        {4, 3, 3},
        {3, 4, 4}
    };
    int allocation_matrix[NUM_PROCESSES][NUM_RESOURCES] = 
	{
        {3, 3, 3},
        {2, 0, 3},
        {1, 2, 4}
    };
    int available_resources[NUM_RESOURCES] = {1, 2, 0};
    int processes[NUM_PROCESSES] = {0, 1, 2};
    int deadlocked_processes[NUM_PROCESSES];
    int num_deadlocked_processes = 0;
    int finished_processes[NUM_PROCESSES] = {0};
    int work_matrix[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; i++) 
	{
        work_matrix[i] = available_resources[i];
    }
    int finish_matrix[NUM_PROCESSES] = {0};
    int num_finished_processes = 0;
    while (num_finished_processes < NUM_PROCESSES) 
	{
        int found_process = 0;
        for (int i = 0; i < NUM_PROCESSES; i++) 
		{
            if (!finished_processes[i]) 
			{
                int can_allocate = 1;
                for (int j = 0; j < NUM_RESOURCES; j++) 
				{
                    if (max_matrix[i][j] - allocation_matrix[i][j] > work_matrix[j]) 
					{
                        can_allocate = 0;
                        break;
                    }
                }
                if (can_allocate) 
				{
                    found_process = 1;
                    finished_processes[i] = 1;
                    num_finished_processes++;
                    for (int j = 0; j < NUM_RESOURCES; j++) 
					{
                        work_matrix[j] += allocation_matrix[i][j];
                    }
                }
            }
        }
        if (!found_process) 
		{
            for (int i = 0; i < NUM_PROCESSES; i++) 
			{
                if (!finished_processes[i]) 
				{
                    deadlocked_processes[num_deadlocked_processes] = processes[i];
                    num_deadlocked_processes++;
                }
            }
            break;
        }
    }
    if (num_deadlocked_processes > 0) 
	{
        printf("System is deadlocked.\n");
        printf("Deadlocked processes: ");
        for (int i = 0; i < num_deadlocked_processes; i++) 
		{
            printf("P%d ", deadlocked_processes[i]);
        }
        printf("\n");
    } else 
	{
        printf("System is not deadlocked.\n");
    }

    return 0;
}

