#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000

int main() 
{
    int queue[MAX_REQUESTS], n;
    int head, total_head_movement = 0;
    float avg_head_movement;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk queue: ");
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &queue[i]);
    }
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);
    for (int i = 0; i < n; i++) 
	{
        total_head_movement += abs(head - queue[i]);
        head = queue[i];
    }
    avg_head_movement = (float)total_head_movement / n;

    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %f\n", avg_head_movement);

    return 0;
}

