#include<stdio.h>
void fcfs(int processes[], int n, int burst_time[]) 
{
    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    waiting_time[0] = 0;
    for (int i = 1; i < n ; i++) 
	{
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    for (int i = 0; i < n; i++) 
	{
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    for (int i = 0; i < n; i++) 
	{
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) 
	{
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_waiting_time/n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time/n);
}

int main() 
{
    int n = 3;
    int processes[] = {0, 1, 2};
    int burst_time[] = {2, 4, 8};
    fcfs(processes, n, burst_time);
    return 0;
}
