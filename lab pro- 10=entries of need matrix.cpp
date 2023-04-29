#include<stdio.h>

int main() 
{
    int n = 5; 
    int m = 3; 

    int allocation[n][m] = {{1, 1, 2}, {2, 1, 2}, {3, 0, 1}, {0, 2, 0}, {1, 1, 2}};
    int max[n][m] = {{5, 4, 4}, {4, 3, 3}, {9, 1, 3}, {8, 6, 4}, {2, 2, 3}};
    int available[m] = {3, 3, 2};

    int need[n][m];
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < m; j++) 
		{
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Need matrix:\n");
    for (int i = 0; i < n; i++) 
	{
        printf("P%d:\t", i);
        for (int j = 0; j < m; j++) 
		{
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}
