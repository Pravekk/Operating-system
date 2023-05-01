#include<stdio.h>

struct process 
{
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

void round_robin(struct process p[], int n, int quantum_time) 
{
    int i, j, time = 0, completed = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    for(i=0; i<n; i++) 
	{
        p[i].remaining_time = p[i].burst_time;
    }

    while(completed != n) 
	{
        for(i=0; i<n; i++) 
		{
            if(p[i].remaining_time > 0) 
			{
                if(p[i].remaining_time > quantum_time) 
				{
                    time += quantum_time;
                    p[i].remaining_time -= quantum_time;
                }
                else 
				{
                    time += p[i].remaining_time;
                    p[i].waiting_time = time - p[i].burst_time;
                    p[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }

    for(i=0; i<n; i++) 
	{
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }

    avg_waiting_time = avg_waiting_time/n;
    avg_turnaround_time = avg_turnaround_time/n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) 
	{
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f ms", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f ms", avg_turnaround_time);
}

int main() 
{
    int n = 3, quantum_time = 4;
    struct process p[] = {{24, 0, 0, 0}, {3, 0, 0, 0}, {3, 0, 0, 0}};
    round_robin(p, n, quantum_time);
    return 0;
}

