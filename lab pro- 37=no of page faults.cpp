#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10
bool isPageExists(int page, int* frame, int numFrames)
{
    for (int i = 0; i < numFrames; i++) 
	{
        if (frame[i] == page) 
		{
            return true;
        }
    }
    return false;
}
int findOptimalPage(int* pages, int numPages, int* frame, int numFrames, int currentIndex)
{
    int optimalPage = -1;
    int farthestIndex = currentIndex;
    int farthestPageIndex;

    for (int i = 0; i < numFrames; i++) 
	{
        int page = frame[i];
        int j;

        for (j = currentIndex + 1; j < numPages; j++) 
		{
            if (pages[j] == page) 
			{
                if (j > farthestIndex) 
				{
                    farthestIndex = j;
                    farthestPageIndex = i;
                }
                break;
            }
        }

        if (j == numPages) 
		{
            return i;
        }
    }

    return farthestPageIndex;
}
int optimalPageReplacement(int* pages, int numPages, int numFrames)
{
    int frame[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < numFrames; i++) 
	{
        frame[i] = -1; 
    }

    for (int i = 0; i < numPages; i++) 
	{
        int page = pages[i];

        if (!isPageExists(page, frame, numFrames)) 
		{
            int replaceIndex = findOptimalPage(pages, numPages, frame, numFrames, i);
            frame[replaceIndex] = page;
            pageFaults++;
        }
    }

    return pageFaults;
}

int main()
{
    int pages[MAX_PAGES];
    int numPages;
    int numFrames;

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    if (numPages <= 0 || numPages > MAX_PAGES) 
	{
        printf("Invalid number of pages.\n");
        return 0;
    }

    printf("Enter the page references:\n");
    for (int i = 0; i < numPages; i++) 
	{
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    if (numFrames <= 0 || numFrames > MAX_FRAMES) 
	{
        printf("Invalid number of frames.\n");
        return 0;
    }

    int pageFaults = optimalPageReplacement(pages, numPages, numFrames);

    printf("Number of page faults using Optimal method: %d\n", pageFaults);

    return 0;
}

