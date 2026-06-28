#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    printf("Enter the number of grades: ");
    scanf("%d", &number);

    char *grades = malloc(number * sizeof(char));

    if (grades == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    for (int i = 0; i < number; i++)
    {
        printf("Enter grade #%d: ", i + 1);
        scanf(" %c", &grades[i]);
    }

    for (int i = 0; i < number; i++)
    {
        printf("%c ", grades[i]);
    }

    free(grades);  // returning the rented space back to the OS
    grades = NULL; // avoides dangling pointers

    return 0;
}