#include <stdio.h>

int main()
{
    int n = 4;
    int burst_time[] = {6, 8, 7, 3};
    int waiting_time[n], turnaround_time[n], completion_time[n];
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < n; i++) 
	{
        int min_idx = i;
        for (int j = i + 1; j < n; j++) 
		{
            if (burst_time[j] < burst_time[min_idx]) 
			{
                min_idx = j;
            }
        }
        int temp = burst_time[i];
        burst_time[i] = burst_time[min_idx];
        burst_time[min_idx] = temp;
    }
    completion_time[0] = burst_time[0];
    for (int i = 1; i < n; i++) 
	{
        completion_time[i] = completion_time[i-1] + burst_time[i];
    }
    for (int i = 0; i < n; i++) 
	{
        turnaround_time[i] = completion_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Process\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("Average Waiting Time = %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time = %.2f\n", avg_turnaround_time);

    return 0;
}
