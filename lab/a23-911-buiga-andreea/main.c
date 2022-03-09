#include <stdio.h>
#include "repository/repository.h"
#include "ui/ui.h"
#include "tests/tests.h"

int main()
{
    tests();
    EstateList *lst = repository_create();
    Service *serv = create_service(lst);
    UI *ui = create_ui(serv);
    undo_redo *undo;
    undo = create_undo_redo();
    ui_startup(ui, undo);
    undo->currentUndo = -1;
    undo->currentRedo = 1;
    int option;
    int running;
    running = 1;

    while (running)
    {
        print_menu();
        printf("\n");
        printf("Your choice: ");
        scanf("%d", &option);
        printf("\n");
        switch(option)
        {
            case 0:
                running = 0;
                break;

            case 1:
                ui_add_estate(ui, undo);
                break;

            case 2:
                ui_remove_estate(ui, undo);
                break;

            case 3:
                ui_modify_estate(ui, undo);
                break;

            case 4:
                print_estate(ui);
                break;

            case 5:
                ui_search_estate(ui, 1);
                break;

            case 6:
                ui_search_estate_by_type(ui);
                break;

            case 7:
                if (undo->currentUndo < 0)
                    printf("No more undoes\n");
                else
                    ui_undo(ui, undo);
                break;

            case 8:
                ui_redo(ui, undo);
                break;

            default:
                printf("Invalid command!\n");
        }

        printf ("\n");
    }
    destroy_ui(ui);
    return 0;
}