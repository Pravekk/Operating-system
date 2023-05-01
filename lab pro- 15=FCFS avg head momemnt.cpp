#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int abs(int x) {
    if (x < 0) return -x;
    return x;
}

int main() 
{
    int queue[100], head, n, i, total = 0;
    float avg;
    printf("Enter the size of queue : ");
    scanf("%d", &n);
    printf("Enter the queue\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial head position : ");
    scanf("%d", &head);
    total += abs(head - queue[0]);
    printf("%d -> %d", head, queue[0]);
    for (i = 1; i < n; i++) 
	{
        total += abs(queue[i] - queue[i - 1]);
        printf(" -> %d", queue[i]);
    }
    printf("\nTotal head movement : %d", total);
    avg = (float) total / n;
    printf("\nAverage head movement : %.2f", avg);
    getch();
}

