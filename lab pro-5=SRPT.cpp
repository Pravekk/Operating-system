#include <stdio.h>

typedef struct Process 
{
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int finish_time;
} Process;

int main() 
{
    Process processes[] = 
	{
        {0, 5, 5, 0, 0},
        {1, 3, 3, 0, 0},
        {2, 3, 3, 0, 0},
        {4, 1, 1, 0, 0}
    };
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    int clock = 0;
    int finished_processes_size = 0;
    Process *finished_processes[num_processes];

    while (finished_processes_size < num_processes) 
	{
        int shortest_index = -1;
        int shortest_time = 1000000;
        for (int i = 0; i < num_processes; i++) 
		{
            if (processes[i].arrival_time <= clock && processes[i].remaining_time < shortest_time && processes[i].remaining_time > 0) 
			{
                shortest_index = i;
                shortest_time = processes[i].remaining_time;
            }
        }
        if (shortest_index == -1) 
		{
            int next_arrival_time = 1000000;
            for (int i = 0; i < num_processes; i++) 
			{
                if (processes[i].arrival_time < next_arrival_time && processes[i].remaining_time > 0) 
				{
                    next_arrival_time = processes[i].arrival_time;
                }
            }
            clock = next_arrival_time;
        } else 
	{
            processes[shortest_index].remaining_time--;
            clock++;
            if (processes[shortest_index].remaining_time == 0) 
			{
                processes[shortest_index].finish_time = clock;
                finished_processes[finished_processes_size] = &processes[shortest_index];
                finished_processes_size++;
            }
        }
    }
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) 
	{
        int waiting_time = finished_processes[i]->start_time - finished_processes[i]->arrival_time;
        int turnaround_time = finished_processes[i]->finish_time - finished_processes[i]->arrival_time;
        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;
    }
    float avg_waiting_time = (float)total_waiting_time / num_processes;
    float avg_turnaround_time = (float)total_turnaround_time / num_processes;
    printf("Average waiting time: %f\n", avg_waiting_time);
    printf("Average turnaround time: %f\n", avg_turnaround_time);

    return 0;
}
