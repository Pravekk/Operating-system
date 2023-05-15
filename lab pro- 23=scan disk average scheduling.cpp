#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000

int main() 
{
    int requests[MAX_REQUESTS], num_requests, head_pos, direction, disk_size, total_head_movement = 0;

    printf("Enter number of disk requests (max %d): ", MAX_REQUESTS);
    scanf("%d", &num_requests);

    printf("Enter the requests:\n");
    for (int i = 0; i < num_requests; i++) 
	{
        scanf("%d", &requests[i]);
    }

    printf("Enter the current head position: ");
    scanf("%d", &head_pos);

    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    printf("Enter the initial direction of the head (1 for right, -1 for left): ");
    scanf("%d", &direction);
    requests[num_requests++] = head_pos;
    for (int i = 0; i < num_requests - 1; i++) 
	{
        for (int j = i + 1; j < num_requests; j++) 
		{
            if (requests[i] > requests[j]) 
			{
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
    int index = 0;
    while (index < num_requests && requests[index] < head_pos) 
	{
        index++;
    }
    printf("Head movement: %d", head_pos);
    if (direction == 1) 
	{ 
        for (int i = index; i < num_requests; i++) 
		{
            printf(" -> %d", requests[i]);
            total_head_movement += requests[i] - head_pos;
            head_pos = requests[i];
        }
        printf(" -> %d", disk_size - 1);
        total_head_movement += disk_size - head_pos - 1;
        head_pos = disk_size - 1;
        for (int i = index - 1; i >= 0; i--) 
		{
            printf(" -> %d", requests[i]);
            total_head_movement += head_pos - requests[i];
            head_pos = requests[i];
        }
    } else 
	{ 
        for (int i = index - 1; i >= 0; i--) 
		{
            printf(" -> %d", requests[i]);
            total_head_movement += head_pos - requests[i];
            head_pos = requests[i];
        }
        printf(" -> %d", 0);
        total_head_movement += head_pos;
        head_pos = 0;
        for (int i = index; i < num_requests; i++) 
		{
            printf(" -> %d", requests[i]);
            total_head_movement += requests[i] - head_pos;
            head_pos = requests[i];
        }
    }

    float avg_head_movement = (float)total_head_movement / num_requests;
    printf("\nAverage head movement: %.2f", avg_head_movement);

    return 0;
}

