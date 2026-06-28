#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_LIMIT 256

void screen_clear(void)
{
    printf("\033[H\033[J");
}

void sceen_print_menu(void)
{
    printf("Please choose an option:\n\n");
    printf("1 - Add an Item\n");
    printf("2 - Remove an Item\n");
    printf("3 - Print To-Do List\n");
    printf("4 - Clear To-Do List\n");
    printf("5 - Exit\n\n");
}

typedef struct entry
{
    char description[BUFFER_LIMIT];
} entry;

typedef struct list
{
    int count;
    int entry_amount;
    entry entries[10];
} list;

void list_instanstiate(list *list)
{
    list->count = 10;
    list->entry_amount = 0;

    for (int i = 0; i < list->count; i++)
    {
        strcpy(list->entries[i].description, "EMPTY");
    }
}

void list_print(list *list)
{
    int count = list->count;

    for (int i = 0; i < count; i++)
    {
        printf("Item #%d is: %s\n", i + 1, list->entries[i].description);
    }
}

void list_add(list *list)
{
    char string_buffer[BUFFER_LIMIT];
    int key = list->entry_amount;
    bool check_overwrite = false;
    if (key >= 9)
    {
        key = 0;
        list->entry_amount = 0;
        check_overwrite = true;
    }

    printf("The key is: %d\n", key);

    if (check_overwrite)
    {
        char check_overwrite_answer;
        printf("Do you want to overwite the value in the #%d spot on the To-Do List? (Y/N)\n", key + 1);
        fgets(check_overwrite_answer, 1, stdin);

        if (check_overwrite_answer != 'Y' || check_overwrite_answer != 'y')
        {
            printf("You choose to not overwrite your previous entry in the To-Do List.\n");
            return;
        }
    }

    printf("What do you want to put into the To-Do List? (Enter [exit] to leave)\n");

    fgets(string_buffer, BUFFER_LIMIT, stdin);

    if (string_buffer == "exit" || string_buffer == "[exit]")
    {
        return;
    }

    strcpy(list->entries[key].description, string_buffer);

    if (check_overwrite)
    {
        printf("The old value in the #%d spot of the list was overwritten!\n", key + 1);
    }

    list->entry_amount = key + 1;
}

void list_remove(list *list, int item)
{
    char string_buffer[BUFFER_LIMIT];
    list_print(list);
    printf("\n");

    printf("Which item do you want to remove from the list (Enter [exit] to leave)\n");

    fgets(string_buffer, BUFFER_LIMIT, stdin);

    if (string_buffer == "exit" || string_buffer == "[exit]")
    {
        return;
    }

    int key = item;
    char stringtest[256];
    printf("The key is: %d\n", key);

    printf("What do you want to put into the To-Do List?\n");

    fgets(list->entries[key].description, BUFFER_LIMIT, stdin);

    list->entry_amount = key + 1;
}

int main(void)
{
    list todolist;
    bool running = true;

    list_instanstiate(&todolist);

    printf("This is Anthony's To-Do App!\n");

    do
    {

        screen_clear();

    } while (running);

    list_add(&todolist);
    list_print(&todolist);

    return 0;
}