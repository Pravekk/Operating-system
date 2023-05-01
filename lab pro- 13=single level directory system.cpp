#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

struct file 
{
    char name[50];
    int size;
};

struct directory 
{
    struct file files[MAX_FILES];
    int count;
    char name[50];
};

void print_directory(struct directory* dir) 
{
    printf("Directory '%s' contents:\n", dir->name);
    for (int i = 0; i < dir->count; i++) 
	{
        printf("%s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

void add_file(struct directory* dir, char* name, int size) 
{
    if (dir->count == MAX_FILES) 
	{
        printf("Error: Directory '%s' is full.\n", dir->name);
        return;
    }
    for (int i = 0; i < dir->count; i++) 
	{
        if (strcmp(dir->files[i].name, name) == 0) 
		{
            printf("Error: File '%s' already exists in directory '%s'.\n", name, dir->name);
            return;
        }
    }
    struct file new_file = {0};
    strcpy(new_file.name, name);
    new_file.size = size;
    dir->files[dir->count] = new_file;
    dir->count++;
    printf("File '%s' added to directory '%s'.\n", name, dir->name);
}

void delete_file(struct directory* dir, char* name) 
{
    int index = -1;
    for (int i = 0; i < dir->count; i++) 
	{
        if (strcmp(dir->files[i].name, name) == 0) 
		{
            index = i;
            break;
        }
    }

    if (index == -1) 
	{
        printf("Error: File '%s' not found in directory '%s'.\n", name, dir->name);
        return;
    }
    for (int i = index; i < dir->count - 1; i++) 
	{
        dir->files[i] = dir->files[i+1];
    }
    dir->count--;
    printf("File '%s' deleted from directory '%s'.\n", name, dir->name);
}

int main() 
{
    struct directory cse_dir = {0};
    strcpy(cse_dir.name, "CSE");

    add_file(&cse_dir, "A", 100);
    add_file(&cse_dir, "B", 50);
    add_file(&cse_dir, "C", 200);

    print_directory(&cse_dir);

    delete_file(&cse_dir, "B");

    print_directory(&cse_dir);

    return 0;
}

