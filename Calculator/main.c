#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void numbers_input(int *count, int *number_arr)
{
    for (int x = 0; x < *count; x++)
    {
        // FIXME - I need the arrary to take the values from scanf
        printf("What is the next number in the list?\n");
        printf(">");
        scanf("%d", &number_arr + x);
    }
}

void counter_set(int *counter, int *number_arr)
{
    bool running = true;
    while (running)
    {
        if (*counter == 0)
        {
            printf("How many numbers do you want to add to the list?\n");
            printf(">");
            scanf("%d", counter);
            printf("\n");
        }
        else
        {
            running = false;
        }
    }

    number_arr = malloc((*counter) * sizeof(int));

    if (number_arr == NULL)
    {
        printf("The assignment of memory failed!");
        exit(1);
    }
}

int addition_function(int *count, int *number_arr)
{
    int result = 0;
    for (int x = 0; x < *count; x++)
    {
        printf("Number %d is: %d\n", x + 1, *(number_arr + x));
        result = result + (*(number_arr + x));
    }
    return result;
}

int main()
{
    bool running = true;

    int count = 0;
    int *p_count = &count;
    int *number_list;

    int result = 0;
    int operation = 0;
    int loop_counter = 0;

    while (running)
    {
        printf("This is a small calculator!\n");

        while (operation == 0)
        {
            printf("What operator do you want to use?\n");
            printf("1 - Addition\n");
            printf("2 - Subraction\n");
            printf("3 - Division\n");
            printf("4 - Multiplication\n");
            printf("5 - Exit\n\n");
            printf(">");

            scanf("%d", &operation);

            if (operation == 1)
            {
                printf("You have choosen addition!\n");

                counter_set(p_count, number_list);
                numbers_input(p_count, number_list);
                result = addition_function(p_count, number_list);

                printf("The result is: %d", result);
            }
            else if (operation == 2)
            {
                printf("You have choosen subtraction!\n");
            }
            else if (operation == 3)
            {
                printf("You have choosen division!\n");
            }
            else if (operation == 4)
            {
                printf("You have choosen multiplication!\n");
            }
            else if (operation == 5)
            {
                break;
            }
            else
            {
                operation = 0;
                printf("That is an invalid input!\n");
            }
        }

        running = false;
    }

    return 0;
}