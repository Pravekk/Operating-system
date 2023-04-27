#include<stdio.h>

int main() 
{
    int frames, pages, page_faults = 0, i, j, k, flag;
    int frame_arr[10], page_arr[30];

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page reference sequence: ");
    for(i = 0; i < pages; ++i)
	{
        scanf("%d", &page_arr[i]);
    }

    for(i = 0; i < frames; ++i)
	{
        frame_arr[i] = -1;
    }

    j = 0;
    printf("\nPage Frames\tPage Faults\n");
    for(i = 0; i < pages; ++i)
	{
        printf("\t");

        flag = 0;
        for(k = 0; k < frames; ++k)
		{
            if(frame_arr[k] == page_arr[i])
			{
                flag = 1;
            }
        }

        if(flag == 0)
		{
            frame_arr[j] = page_arr[i];
            j = (j+1) % frames;
            page_faults++;
            for(k = 0; k < frames; ++k)
			{
                if(frame_arr[k] != -1)
				{
                    printf("%d\t", frame_arr[k]);
                }
            }
            printf("\tPage Fault");
        } 
		else 
		{
            for(k = 0; k < frames; ++k)
			{
                if(frame_arr[k] != -1)
				{
                    printf("%d\t", frame_arr[k]);
                }
            }
            printf("\tNo Page Fault");
            
        }
        printf("\n");
    }
    printf("\nTotal number of page faults: %d\n", page_faults);
    return 0;
}
