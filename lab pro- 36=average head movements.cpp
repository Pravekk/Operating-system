#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_REQUESTS 100
int absDiff(int a, int b)
{
    return abs(a - b);
}

int findNearestTrack(int* tracks, int numTracks, int currentTrack, bool* visited)
{
    int minDiff = INT_MAX;
    int nearestTrackIndex = -1;

    for (int i = 0; i < numTracks; i++) 
	{
        if (!visited[i]) 
		{
            int diff = absDiff(tracks[i], currentTrack);
            if (diff < minDiff) 
			{
                minDiff = diff;
                nearestTrackIndex = i;
            }
        }
    }

    return nearestTrackIndex;
}

int calculateHeadMovementSSTF(int* tracks, int numTracks, int startTrack)
{
    bool visited[MAX_REQUESTS] = { false };
    int currentTrack = startTrack;
    int totalHeadMovement = 0;

    for (int i = 0; i < numTracks; i++)
	{
        int nearestTrackIndex = findNearestTrack(tracks, numTracks, currentTrack, visited);

        if (nearestTrackIndex != -1) 
		{
            visited[nearestTrackIndex] = true;
            totalHeadMovement += absDiff(tracks[nearestTrackIndex], currentTrack);
            currentTrack = tracks[nearestTrackIndex];
        }
    }

    return totalHeadMovement;
}

int main()
{
    int tracks[MAX_REQUESTS];
    int numTracks;
    int startTrack;

    printf("Enter the number of tracks: ");
    scanf("%d", &numTracks);

    if (numTracks <= 0 || numTracks > MAX_REQUESTS) 
	{
        printf("Invalid number of tracks.\n");
        return 0;
    }

    printf("Enter the track requests:\n");
    for (int i = 0; i < numTracks; i++) 
	{
        printf("Track %d: ", i + 1);
        scanf("%d", &tracks[i]);
    }

    printf("Enter the starting track: ");
    scanf("%d", &startTrack);

    if (startTrack < 0) 
	{
        printf("Invalid starting track.\n");
        return 0;
    }

    int totalHeadMovement = calculateHeadMovementSSTF(tracks, numTracks, startTrack);
    float averageHeadMovement = (float)totalHeadMovement / numTracks;

    printf("Total head movement using SSTF algorithm: %d\n", totalHeadMovement);
    printf("Average head movement using SSTF algorithm: %.2f\n", averageHeadMovement);

    return 0;
}

