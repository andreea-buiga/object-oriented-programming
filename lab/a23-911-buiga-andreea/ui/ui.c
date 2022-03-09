#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "ui.h"

// Creates the UI
UI* create_ui(Service* estate_service)
{
    UI *ui = (UI*)malloc(sizeof(UI));
    ui->estate_service = estate_service;
    return ui;
}

void print_one(Estate *e)
{
    printf("The type of the estate is: %s \n", get_type(e));
    printf("The address of the estate is: %s \n", get_address(e));
    printf("The surface of the estate is: %d \n", get_surface(e));
    printf("The price of the estate is: %d \n", get_price(e));
    printf("\n");
}

// Prints an estate
void print_estate(UI *ui)
{
    int i;
    for(i = 0; i < service_size(ui->estate_service); i++)
    {
        printf("Estate number %d\n", i+1);
        Estate * e = service_get_by_index(ui->estate_service, i);
        print_one(e);
    }
}

void print(Estate v[100], int dim)
{
    int i;
    for(i = 0; i < dim; i++)
        print_one(&v[i]);
}

// Adds an estate
void ui_add_estate(UI* ui, undo_redo *undo)
{
    char type[20];
    char address[100];
    int price, surface;

    printf ("Estate type: ");
    scanf ("%s",type);

    printf ("Estate address: ");
    scanf("%s",address);

    printf ("Estate surface: ");
    scanf ("%d", &surface);

    printf ("Estate price: ");
    scanf ("%d", &price);

    if (strcmp(type,"house")!=0 && strcmp(type,"apartment")!=0 && strcmp(type,"penthouse")!=0)
        printf ("The given type does not exist!\n");
    else
        add_estate(ui->estate_service, type, address, surface, price, undo);
}

// Modifies an estate
void ui_modify_estate(UI* ui, undo_redo* undo)
{
    char type[20];
    char address[100];
    int price, surface;
    printf ("Estate's address: ");
    scanf("%s",address);

    printf ("Estate new price: ");
    scanf ("%d", &price);

    printf ("Estate new surface: ");
    scanf ("%d", &surface);

    printf ("Estate new type: ");
    scanf ("%s", type);

    if (strcmp(type,"house")!=0 && strcmp(type,"apartment")!=0 && strcmp(type,"penthouse")!=0)
        printf ("The given type does not exist!\n");

    else
        modify_estate(ui->estate_service, type, address, surface, price, undo);
}

// Deletes an estate
void ui_remove_estate(UI* ui, undo_redo* undo)
{
    char address[100];
    printf ("Give address: ");
    scanf("%s",address);
    remove_estate(ui->estate_service, address, undo);
    if (errno)
        perror ("Error removing estate!");
}

// Search an estate by its address or type
void ui_search_estate(UI* ui, int dir)
{
    char address[100], type[20];
    int way, dim=0, way2;
    Estate v[100];
    printf("Choose: \n1->address, 2->type: ");
    scanf("%d", &way2);
    printf("\n");
    printf("Choose: \n1->price, 2->surface: ");
    scanf("%d", &way);
    printf("\n");
    if (way2==1) {
        printf ("Give address: ");
        scanf("%s",address);
        if (way == 1) {
            sort_by_price(ui->estate_service, dir);
            search_by_address(ui->estate_service, address, v, &dim);
            print(v, dim);
        }
        if (way == 2) {
            sort_by_surface(ui->estate_service, dir);
            search_by_address(ui->estate_service, address, v, &dim);
            print(v, dim);
        }
    }
    if (way2 == 2)
    {
        printf ("Give type: ");
        scanf("%s",type);
        if (way == 1) {
            sort_by_price(ui->estate_service, dir);
            search_by_type_2(ui->estate_service, type, v, &dim);
            print(v, dim);
        }
        if (way == 2) {
            sort_by_surface(ui->estate_service, dir);
            search_by_type_2(ui->estate_service, type, v, &dim);
            print(v, dim);
        }
    }
}

// Search an estate by its type
void ui_search_estate_by_type(UI* ui)
{
    char type[20];
    int surface, dim=0, way;
    Estate v[100];
    printf ("Give type: ");
    scanf("%s",type);
    printf ("Give surface: ");
    scanf("%d",&surface);
    printf ("Choose the type of sort: \n1->ascending, 2->descending (price): ");
    scanf("%d", &way);
    printf("\n");
    sort_by_price(ui->estate_service, way);
    search_by_type(ui->estate_service, type, surface, v, &dim);
    print(v, dim);
}

// The startup values
void ui_startup(UI* ui, undo_redo* undo)
{
    startup(ui->estate_service, undo);
}

// Destroys the UI
void destroy_ui(UI* ui)
{
    destroy_service(ui->estate_service);
    free(ui);
}

// Prints the UI menu
void print_menu()
{
    printf("          ∞ MENU ∞ \n");
    printf("\t 1| • add an estate •\n");
    printf("\t 2| • delete an estate •\n");
    printf("\t 3| • update an estate •\n");
    printf("\t 4| • list estates •\n");
    printf("\t 5| • search an estate, sorted ascending by their price or surface •\n");
    printf("\t 6| • search estate by type, having the surface greater than a user provided value •\n");
    printf("\t 7| • undo •\n");
    printf("\t 8| • redo •\n");
    printf("\t 0| • exit •\n");
    printf("\n");
}

// Makes the undo operation
void ui_undo(UI* ui, undo_redo* undo)
{
    serv_undo(ui->estate_service, undo);
}

// Makes the redo operation
void ui_redo(UI* ui, undo_redo* redo)
{
    serv_redo(ui->estate_service, redo);
}