#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *file;
    char filename[100];
    char data[100];

    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "w");
    if (file == NULL) 
	{
        printf("Error opening file. Exiting...\n");
        exit(1);
    }

    printf("Enter the data to write to the file (max 100 characters): ");
    scanf(" %[^\n]s", data);
    fprintf(file, "%s", data);
    fclose(file);
    file = fopen(filename, "r");
    if (file == NULL) 
	{
        printf("Error opening file. Exiting...\n");
        exit(1);
    }

    printf("Data read from file:\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) 
	{
        printf("%c", ch);
    }
    fclose(file);

    return 0;
}

