#include "service.h"
#include <stdlib.h>

#define INIT_CAPACITY 10

/// Creates the service
/// \param estate_list the estates list
/// \return the service
Service* create_service(EstateList* estate_list)
{
    Service *serv = (Service *)malloc(sizeof(Service));
    serv->estate_list = estate_list;
    return serv;
}

/// Adds an estate to the list
/// \param lst the list
/// \param type the given type
/// \param address the given address
/// \param surface the given surface
/// \param price the given price
void add_estate(Service *serv, char* type, char* address, int surface, int price, undo_redo *undo)
{
    Estate* e = create_estate(type, address, surface, price);
    repository_store(serv->estate_list, e, undo);
}

/// Modifies an estate from the list
/// \param lst the list
/// \param type the new type
/// \param address the given address
/// \param surface the new surface
/// \param price the new price
void modify_estate(Service* serv, char* type, char* address, int surface, int price, undo_redo *undo)
{
    repository_modify(serv->estate_list, type, address, surface, price, undo);
}

/// Removes an expense from the list
/// \param lst the list
/// \param address the given address
void remove_estate(Service* serv, char* address, undo_redo *undo)
{
    repository_remove(serv->estate_list, address, undo);
}

/// Gives the size of the service
/// \param serv the service
/// \return the length
int service_size(Service* serv)
{
    return repository_size(serv->estate_list);
}

/// Gives the index of an element
/// \param serv the service
/// \param index the index of the element
/// \return the index
Estate* service_get_by_index(Service* serv, int index)
{
    return repository_get_by_index(serv->estate_list, index);
}

/// The given vector has the estates filtered by type
/// \param lst the list
/// \param type the given type
/// \param surface the given surface
/// \param v the vector where the estates are
/// \param dim the dimension of the vector
void search_by_type(Service * serv, char* type, int surface, Estate v[100], int *dim)
{
    repo_search_by_type(serv->estate_list, type, surface, v, dim);
}

/// The given vector has the estates filtered by address
/// \param lst the service
/// \param address the given address
/// \param v the vector where the estates are
/// \param dim the dimension of the vector
void search_by_address(Service * serv, char* address, Estate v[100], int *dim)
{
    repo_search_by_address(serv->estate_list, address, v, dim);
}

/// The given vector has the estates filtered by type
/// \param serv the service
/// \param type the given type
/// \param v the vector where the estates are
/// \param dim the dimension of the vector
void search_by_type_2(Service * serv, char* type, Estate v[100], int *dim)
{
    repo_search_by_type_2(serv->estate_list, type, v, dim);
}

/// Sorts the list by price
/// \param lst the list
/// \param dir the way it is sorted 1-ascending, 2-descending
void sort_by_price(Service * serv, int dir)
{
    int c, d;
    Estate swap;

    for (c = 0; c < (repository_size(serv->estate_list) - 1 ); c++)
        for (d = c + 1; d < repository_size (serv->estate_list); d++)
        {
            Estate *e1 = repository_get_by_index (serv->estate_list, c);
            Estate *e2 = repository_get_by_index (serv->estate_list, d);

            if (e1->price > e2->price && dir == 1)
            {
                swap = *e1;
                *e1 = *e2;
                *e2 = swap;
            }
            if (e1->price < e2->price && dir == 2)
            {
                swap = *e1;
                *e1 = *e2;
                *e2 = swap;
            }
        }
}

/// Sorts the list by surface
/// \param lst the list
/// \param dir the way it is sorted 1-ascending, 2-descending
void sort_by_surface(Service * serv, int dir)
{
    int c, d;
    Estate swap;

    for (c = 0; c < (repository_size(serv->estate_list) - 1 ); c++)
        for (d = c + 1; d < repository_size (serv->estate_list); d++)
        {
            Estate *e1 = repository_get_by_index (serv->estate_list, c);
            Estate *e2 = repository_get_by_index (serv->estate_list, d);

            if (e1->surface > e2->surface && dir == 1)
            {
                swap = *e1;
                *e1 = *e2;
                *e2 = swap;
            }
            if (e1->surface < e2->surface && dir == 2)
            {
                swap = *e1;
                *e1 = *e2;
                *e2 = swap;
            }
        }
}
/// The startup estates are given here
/// \param lst the list
void startup(Service* lst, undo_redo* undo)
{
    add_estate(lst, "house", "Calea.Floresti", 200, 100, undo);
    add_estate(lst, "apartment", "Calea.Padurii", 300, 300, undo);
    add_estate(lst, "penthouse", "Str.Parisului", 400, 250, undo);
    add_estate(lst, "house", "1.Decembrie", 1000, 525, undo);
    add_estate(lst, "apartment", "Floresti", 300, 200, undo);
    add_estate(lst, "apartment", "Regionala", 500, 450, undo);
    add_estate(lst, "house", "Str.Albac", 600, 400, undo);
    add_estate(lst, "penthouse", "Str.Amurg", 1200, 1000, undo);
    add_estate(lst, "house", "Str.Fundatura", 100, 50, undo);
    add_estate(lst, "apartment", "Str.Luminii", 200, 150, undo);
}

/// Destroys the service
/// \param serv the service
void destroy_service(Service* serv)
{
    destroy_repo(serv->estate_list);
    free(serv);
}

/// Does the undo
/// \param serv the service
/// \param undo the undo operation
void serv_undo(Service* serv, undo_redo* undo)
{
    repo_undo(serv->estate_list, undo);
}

/// Does the redo
/// \param serv the service
/// \param redo the redo operation
void serv_redo(Service* serv, undo_redo* redo)
{
    repo_redo(serv->estate_list, redo);
}

void test_serv()
{
    int dim=0, dim2=0, dim3=0;
    Estate v[20];
    EstateList * lst = repository_create();
    Service * serv = create_service(lst);
    undo_redo *undo = create_undo_redo();
    DArray *da = darray_create();
    da->capacity = INIT_CAPACITY;
    add_estate(serv, "house", "Calea.Floresti", 200, 100, undo);
    assert(repository_size(lst) == 1);

    remove_estate(serv, "Calea.Floresti", undo);
    assert(repository_size(lst) == 0);

    add_estate(serv, "penthouse", "Regionala", 400, 200, undo);
    assert(repository_size(lst) == 1);

    add_estate(serv, "apartment", "Floresti", 300, 500, undo);
    assert(repository_size(lst) == 2);

    remove_estate(serv, "Floresti", undo);
    assert(repository_size(lst) == 1);

    add_estate(serv, "apartment", "Floresti", 300, 200, undo);
    assert(repository_size(lst) == 2);

    add_estate(serv, "house", "Str.Albac", 600, 400, undo);
    assert(repository_size(lst) == 3);

    add_estate(serv, "penthouse", "Str.Amurg", 1200, 1000, undo);
    assert(repository_size(lst) == 4);

    search_by_type(serv, "penthouse", 300, v, &dim);
    assert(dim == 2);

    add_estate(serv, "house", "Str.Fundatura", 100, 50, undo);
    assert(repository_size(lst) == 5);

    search_by_type_2(serv, "house", v, &dim2);
    assert(dim2 == 4);

    add_estate(serv, "apartment", "Str.Luminii", 200, 150, undo);
    assert(repository_size(lst) == 6);

    search_by_address(serv, "Str", v, &dim3);
    assert(dim3 == 4);

}

