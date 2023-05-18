#include <stdio.h>
#include <stdlib.h>
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void cscan(int arr[], int n, int head, int max)
{
    int distance = 0;
    int current = head;
    int direction = 1; 
    sort(arr, n); 
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= head)
            break;
    }
    for (; i < n; i++)
    {
        distance += abs(arr[i] - current);
        current = arr[i];
    }
    if (arr[i - 1] != max)
    {
        distance += abs(max - current);
        current = max;
    }
    for (int j = 0; j < i - 1; j++)
    {
        distance += abs(arr[j] - current);
        current = arr[j];
    }
    float avg_movement = (float)distance / n;
    printf("Average Head Movement: %.2f\n", avg_movement);
}

int main()
{
    int n; 
    int head; 
    int max; 

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the disk requests (track numbers):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the maximum track number: ");
    scanf("%d", &max);

    cscan(arr, n, head, max);

    return 0;
}

