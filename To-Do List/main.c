#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_LIMIT 256
#define LIST_SIZE 10
#define EMPTY_ENTRY "EMPTY"

typedef struct entry
{
    char description[BUFFER_LIMIT];
} entry;

typedef struct list
{
    int count;
    int entry_amount;
    entry entries[LIST_SIZE];
} list;

void list_instanstiate(list *list)
{
    list->count = LIST_SIZE;
    list->entry_amount = 0;

    for (int i = 0; i < list->count; i++)
    {
        strcpy(list->entries[i].description, EMPTY_ENTRY);
    }
}

void list_print(list *list)
{
    int count = list->count;

    for (int i = 0; i < count; i++)
    {
        printf("Item #%d is: %s\n", i + 1, list->entries[i].description);
    }
    printf("\n");
}

void list_add(list *list)
{
    int key = list->entry_amount;
    bool check_overwrite = false;
    if (key >= LIST_SIZE)
    {
        key = 0;
        list->entry_amount = 0;
        check_overwrite = true;
    }

    printf("The key is: %d\n", key);

    if (check_overwrite)
    {
        char check_overwrite_answer[1];
        printf("Do you want to overwite the value in the #%d spot on the To-Do List? (Y/N)\n", key + 1);
        fgets(check_overwrite_answer, 1, stdin);

        if (check_overwrite_answer[0] != 'Y' || check_overwrite_answer[0] != 'y')
        {
            printf("You choose to not overwrite your previous entry in the To-Do List.\n");
            return;
        }
    }

    printf("What do you want to put into the To-Do List?\n");
    printf(">");

    // FIXME - I need to remove the newline from fgets
    char string_buffer[BUFFER_LIMIT];
    fgets(string_buffer, BUFFER_LIMIT, stdin);
    printf("\n");

    strcpy(list->entries[key].description, string_buffer);

    if (check_overwrite)
    {
        printf("The old value in the #%d spot of the list was overwritten!\n", key + 1);
    }

    list->entry_amount = key + 1;
}

void list_remove(list *list)
{
    int key = 0;
    char key_string[10];
    char *key_string_endpoint;
    list_print(list);

    printf("Which item do you want to remove from the list?\n\n");
    printf(">");

    scanf("%d", &key);

    // getchar grabs the \n from scanf so it doesn't mess with fgets
    getchar();

    strcpy(list->entries[key - 1].description, EMPTY_ENTRY);
    list->entry_amount = list->entry_amount - 1;

    printf("Item #%d was removed from the To-Do List\n\n", key);
}

void list_remove_all(list *list)
{
    list->count = LIST_SIZE;
    list->entry_amount = 0;

    for (int i = 0; i < list->count; i++)
    {
        strcpy(list->entries[i].description, EMPTY_ENTRY);
    }
    printf("All items have been removed from the To-Do List\n\n");
}

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
    printf(">");
}

int main(void)
{
    list todolist;
    bool running = true;
    int input = 0;

    list_instanstiate(&todolist);

    printf("This is Anthony's To-Do App!\n");

    while (running)
    {

        sceen_print_menu();
        scanf("%d", &input);

        // getchar grabs the \n from scanf so it doesn't mess with fgets
        getchar();

        printf("\n");
        printf("Option #%d selected!\n\n", input);

        switch (input)
        {
        case 1:
            list_add(&todolist);
            input = 0;
            break;

        case 2:
            list_remove(&todolist);
            input = 0;
            break;

        case 3:
            list_print(&todolist);
            input = 0;
            break;

        case 4:
            list_remove_all(&todolist);
            input = 0;
            break;

        case 5:
            running = false;
            printf("Exiting the To-Do App!\n");
            input = 0;
            break;

        default:
            printf("Invalid input detected!\n");
            input = 0;
            break;
        }
    }
    list_instanstiate(&todolist);

    return 0;
}