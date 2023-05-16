#include <stdio.h>

struct Process 
{
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

void computeWaitingTime(struct Process processes[], int n) 
{
    processes[0].waitingTime = 0;

    for (int i = 1; i < n; i++) 
	{
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
    }
}

void computeTurnaroundTime(struct Process processes[], int n) 
{
    for (int i = 0; i < n; i++) 
	{
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void computeAverageTimes(struct Process processes[], int n, float *avgWaitingTime, float *avgTurnaroundTime) 
{
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    computeWaitingTime(processes, n);
    computeTurnaroundTime(processes, n);

    for (int i = 0; i < n; i++) 
	{
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    *avgWaitingTime = (float) totalWaitingTime / n;
    *avgTurnaroundTime = (float) totalTurnaroundTime / n;
}

void displayProcessDetails(struct Process processes[], int n) 
{
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) 
	{
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, processes[i].burstTime, processes[i].priority,
               processes[i].waitingTime, processes[i].turnaroundTime);
    }
}

int main() 
{
    int n;
    float avgWaitingTime, avgTurnaroundTime;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter the burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) 
	{
        printf("Process %d:\n", i+1);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }

    computeAverageTimes(processes, n, &avgWaitingTime, &avgTurnaroundTime);

    printf("\nAverage Waiting Time: %.2f", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);

    printf("\n\nProcess Details:\n");
    displayProcessDetails(processes, n);

    return 0;
}

