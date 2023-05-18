#include <stdio.h>
#include <stdlib.h>
void sort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n-1; i++) 
	{
        for (j = 0; j < n-i-1; j++) 
		{
            if (arr[j] > arr[j+1])
			{
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int calculateHeadMovement(int req[], int n, int head) 
{
    int i, index, totalMovement = 0;

    sort(req, n);

    for (i = 0; i < n; i++) 
	{
        if (req[i] >= head) 
		{
            index = i;
            break;
        }
    }
    for (i = index; i < n; i++) 
	{
        totalMovement += abs(head - req[i]);
        head = req[i];
    }
    for (i = 0; i < index; i++) 
	{
        totalMovement += abs(head - req[i]);
        head = req[i];
    }

    return totalMovement;
}

int main() 
{
    int n, head, i;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the requests:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &req[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int totalMovement = calculateHeadMovement(req, n, head);
    float averageMovement = (float)totalMovement / n;

    printf("Total head movement: %d\n", totalMovement);
    printf("Average head movement: %.2f\n", averageMovement);

    return 0;
}

