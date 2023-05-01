#include<stdio.h>

int main() 
{
    int n = 3;
    int burst_time[] = {10, 15, 25};
    int wait_time[n], turn_time[n];
    int total_wait_time = 0, total_turn_time = 0;

    wait_time[0] = 0; 
    for (int i = 1; i < n; i++) 
	{
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
    }
    for (int i = 0; i < n; i++) 
	{
        turn_time[i] = wait_time[i] + burst_time[i];
    }
    for (int i = 0; i < n; i++) 
	{
        total_wait_time += wait_time[i];
        total_turn_time += turn_time[i];
    }
    float avg_wait_time = (float)total_wait_time / n;
    float avg_turn_time = (float)total_turn_time / n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) 
	{
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i], turn_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\nAverage Turnaround Time: %.2f", avg_wait_time, avg_turn_time);
}

