#include <stdio.h>

struct Process {
    int processId;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};
void sortProcesses(struct Process* processes, int numProcesses)
{
    for (int i = 0; i < numProcesses - 1; i++) 
	{
        for (int j = 0; j < numProcesses - i - 1; j++) 
		{
            if (processes[j].burstTime > processes[j + 1].burstTime) 
			{
               
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
void calculateAverageTimes(struct Process* processes, int numProcesses)
{
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    processes[0].waitingTime = 0; 

    for (int i = 1; i < numProcesses; i++) 
	{
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        totalWaitingTime += processes[i].waitingTime;
    }

    for (int i = 0; i < numProcesses; i++) 
	{
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    float avgWaitingTime = (float)totalWaitingTime / numProcesses;
    float avgTurnaroundTime = (float)totalTurnaroundTime / numProcesses;

    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main()
{
    struct Process processes[3];
    int numProcesses = 3;

    for (int i = 0; i < numProcesses; i++) 
	{
        processes[i].processId = i;
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        processes[i].arrivalTime = 0; 
    }

    sortProcesses(processes, numProcesses);
    calculateAverageTimes(processes, numProcesses);

    return 0;
}

