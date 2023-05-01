#include <stdio.h>

#define MAX_PAGES 100

int pages[MAX_PAGES];
int page_faults = 0;

int find_optimal_page(int* page_table, int page_table_size, int* reference_string, int reference_string_size, int start_index) 
{
    int max_future_distance = -1;
    int page_to_replace = -1;

    for (int i = 0; i < page_table_size; i++) 
	{
        int page = page_table[i];
        int future_distance = 0;

        for (int j = start_index; j < reference_string_size; j++) 
		{
            if (reference_string[j] == page) 
			{
                future_distance = j - start_index;
                break;
            }
        }

        if (future_distance > max_future_distance) 
		{
            max_future_distance = future_distance;
            page_to_replace = page;
        }
    }

    return page_to_replace;
}

void simulate_optimal(int* reference_string, int reference_string_size, int page_table_size) 
{
    int page_table[page_table_size];
    int page_table_index = 0;

    for (int i = 0; i < reference_string_size; i++) 
	{
        int page = reference_string[i];
        int page_found = 0;

        for (int j = 0; j < page_table_index; j++) 
		{
            if (page_table[j] == page) 
			{
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            if (page_table_index < page_table_size) 
			{
                page_table[page_table_index] = page;
                page_table_index++;
            } else {
                int page_to_replace = find_optimal_page(page_table, page_table_size, reference_string, reference_string_size, i);
                for (int j = 0; j < page_table_size; j++) 
				{
                    if (page_table[j] == page_to_replace) 
					{
                        page_table[j] = page;
                        break;
                    }
                }
            }
            page_faults++;
        }
    }
}

int main() 
{
    int reference_string[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int reference_string_size = 20;
    int page_table_size = 3;

    simulate_optimal(reference_string, reference_string_size, page_table_size);

    printf("Page faults: %d\n", page_faults);

    return 0;
}

