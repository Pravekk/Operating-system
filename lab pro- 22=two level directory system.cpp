#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 3
#define MAX_FILES 3
#define MAX_NAME_LEN 20
struct file 
{
    char name[MAX_NAME_LEN];
};
struct directory 
{
    char name[MAX_NAME_LEN];
    int num_files;
    struct file files[MAX_FILES];
};
struct user 
{
    char name[MAX_NAME_LEN];
    struct directory dir;
};
int main() 
{
    struct user users[MAX_USERS];
    int i, j;
    for (i = 0; i < MAX_USERS; i++) 
	{
        sprintf(users[i].name, "user%d", i+1);
        sprintf(users[i].dir.name, "%s_dir", users[i].name);
        users[i].dir.num_files = 0;
    }
    for (i = 0; i < MAX_USERS; i++) 
	{
        for (j = 0; j < i+1; j++) 
		{
            struct file new_file;
            sprintf(new_file.name, "%s_file%d", users[i].name, j+1);
            if (users[i].dir.num_files < MAX_FILES) 
			{
                users[i].dir.files[users[i].dir.num_files] = new_file;
                users[i].dir.num_files++;
            }
        }
    }
    for (i = 0; i < MAX_USERS; i++) 
	{
        printf("User %d: %s\n", i+1, users[i].name);
        printf("  Directory: %s\n", users[i].dir.name);
        printf("  Files:\n");
        for (j = 0; j < users[i].dir.num_files; j++) 
		{
            printf("    %s\n", users[i].dir.files[j].name);
        }
    }
}
