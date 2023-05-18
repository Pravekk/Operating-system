#include<stdio.h>
#include<stdlib.h>

void sortRequests(int req[], int n) 
{
    int i, j, temp;

    for (i = 0; i < n-1; i++) 
	{
        for (j = 0; j < n-i-1; j++) 
		{
            if (req[j] > req[j+1]) 
			{
               
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }
}
int calculateHeadMovement(int req[], int n, int currentPos, int direction) 
{
    int i, pos, totalMovement = 0;

    sortRequests(req, n);
    for (i = 0; i < n; i++) 
	{
        if (req[i] >= currentPos) 
		{
            pos = i;
            break;
        }
    }

    for (i = pos; i < n; i++) 
	{
        totalMovement += abs(req[i] - currentPos);
        currentPos = req[i];
    }
    if (direction == 1) 
	{
        totalMovement += abs(req[n-1] - req[pos-1]);
        currentPos = req[n-1];

        for (i = pos-1; i >= 0; i--) 
		{
            totalMovement += abs(req[i] - currentPos);
            currentPos = req[i];
        }
    }

    return totalMovement;
}

int main() 
{
    int n, i, currentPos, direction, totalMovement;
    float avgMovement;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the disk requests:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &req[i]);
    }

    printf("Enter the current position of the disk head: ");
    scanf("%d", &currentPos);

    printf("Enter the direction of disk movement (0 for left, 1 for right): ");
    scanf("%d", &direction);

    totalMovement = calculateHeadMovement(req, n, currentPos, direction);
    avgMovement = (float)totalMovement / n;

    printf("Total head movement: %d\n", totalMovement);
    printf("Average head movement: %.2f\n", avgMovement);

    return 0;
}

