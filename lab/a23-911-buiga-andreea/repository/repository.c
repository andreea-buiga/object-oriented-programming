#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "repository.h"

#define INIT_CAPACITY 10

/// Creates the estate list
/// \return the list
EstateList* repository_create()
{
    EstateList *lst = (EstateList*)malloc(sizeof(EstateList));
    lst->estates = darray_create();
    //lst->destroy_estate = (void (*)(Element)) destroy_estate;
    lst->copy_estate = (Element (*)(Element)) copy_estate;
    return lst;
}

/// Adds an estate to the list
/// \param lst the list
/// \param e the new estate
void repository_store(EstateList* lst, Estate *e, undo_redo *undo)
{
    darray_add(lst->estates, e);
    add_undo_redo(undo, lst->estates);
}

/// Removes an estate from the list
/// \param lst the list
/// \param address the address given
void repository_remove(EstateList* lst, char* address, undo_redo *undo)
{
    int i, ok=0;
    for (i = 0; i < repository_size(lst); i++)
    {
        Estate *e = repository_get_by_index(lst, i);
        if (strcmp(e->address, address)==0)
        {
            ok=1;
            darray_delete(lst->estates, i);
            break;
        }
    }
    if (ok == 0)
    {
        errno = EINVAL;
        return;
    }
    add_undo_redo(undo, lst->estates);
}

/// Modifies an estate from the list
/// \param lst the list
/// \param type the new type
/// \param address the given address
/// \param surface the new surface
/// \param price the new price
void repository_modify(EstateList* lst, char* type, char* address, int surface, int price, undo_redo *undo)
{
    for (int i = 0; i < repository_size(lst); i++) {
        Estate *e = repository_get_by_index(lst, i);
        if (strcmp(e->address, address)==0){
            set_type(e, type);
            set_surface(e, surface);
            set_price(e, price);

        }
    }
    add_undo_redo(undo, lst->estates);
}

/// Searches for an estates with a given type and surface
/// \param lst the list
/// \param type the given type
/// \param surface the surface given
/// \param v the vector where the estates are
/// \param dim the dimension of the vector
void repo_search_by_type(EstateList * lst, char* type, int surface, Estate v[100], int *dim)
{
    int i;
    for (i = 0; i < repository_size(lst); i++)
    {
        Estate *e = repository_get_by_index (lst, i);
        if (strcmp (e->type, type) == 0 && surface<=get_surface(e))
        {
            v[*dim] = *e;
            (*dim)++;
        }
    }
}

/// Searches for an estates with a given address
/// \param lst the list
/// \param address the given address
/// \param v the vector where the estates are
/// \param dim the dimension of the vector
void repo_search_by_address(EstateList * lst, char* address, Estate v[100], int *dim)
{
    int i;
    if(strcmp(address, ".")==0)
    {
        for(int j = 0; j < repository_size(lst); j++) {
            Estate *e = repository_get_by_index(lst, j);
            v[*dim] = *e;
            (*dim)++;
        }
    }
    else
        for (i = 0; i < repository_size(lst); i++)
        {
            Estate *e = repository_get_by_index (lst, i);
            if (strstr (e->address, address) != 0)
            {
                v[*dim] = *e;
                (*dim)++;
            }
        }
}

/// Searches for an estates with a given type
/// \param lst the list
/// \param address the given type
/// \param v the vector where the estates are
/// \param dim the dimension of the vector
void repo_search_by_type_2(EstateList * lst, char* type, Estate v[100], int *dim)
{
    int i;
    if(strcmp(type, ".")==0)
    {
        for(int j = 0; j < repository_size(lst); j++) {
            Estate *e = repository_get_by_index(lst, j);
            v[*dim] = *e;
            (*dim)++;
        }
    }
    else
        for (i = 0; i < repository_size(lst); i++)
        {
            Estate *e = repository_get_by_index (lst, i);
            if (strstr (e->type, type) != 0)
            {
                v[*dim] = *e;
                (*dim)++;
            }
        }
}

/// Finds an estate by its index
/// \param lst the list
/// \param index the index of the estate
/// \return the estates
Estate* repository_get_by_index(EstateList* lst, int index)
{
    return darray_get(lst->estates, index);
}

/// Returns the number of estates in the list
/// \param lst the list
/// \return the length
int repository_size(EstateList * lst)
{
    return darray_size(lst->estates);
}

/// Destroys the repo
/// \param lst the list
void destroy_repo(EstateList* lst)
{
    darray_destroy(lst->estates);
    free(lst);
}

/// Make the undo operation
/// \param lst the list
/// \param undo the undo operation
void repo_undo(EstateList *lst, undo_redo *undo) {
    lst->estates = undo->elements[undo->currentUndo];
    undo->currentUndo--;
    undo->currentRedo = undo->currentUndo + 1;

}

/// Make the redo operation
/// \param lst the list
/// \param redo the redo operation
void repo_redo(EstateList *lst, undo_redo *redo) {

    lst->estates = redo->elements[redo->currentRedo + 1];
    redo->currentRedo++;
    redo->currentUndo = redo->currentRedo - 1;

}

void test_repo()
{
    int dim=0, dim2=0, dim3=0;
    Estate v[20];
    EstateList * lst = repository_create();
    undo_redo *undo = create_undo_redo();
    DArray *da = darray_create();
    da->capacity = INIT_CAPACITY;
    Estate *e = create_estate("house", "Calea.Floresti", 200, 100);
    repository_store(lst, e, undo);
    assert(repository_size(lst) == 1);

    repository_remove(lst, e->address, undo);
    assert(repository_size(lst) == 0);

    Estate *e1 = create_estate("apartment", "Calea.Padurii", 300, 300);
    repository_store(lst, e1, undo);
    assert(repository_size(lst) == 1);

    Estate *e2 = create_estate("penthouse", "Str.Parisului", 400, 250);
    repository_store(lst, e2, undo);
    assert(repository_size(lst) == 2);

    repository_remove(lst, e2->address, undo);
    assert(repository_size(lst) == 1);

    Estate *e3 = create_estate("house", "Calea.Floresti", 200, 100);
    repository_store(lst, e3, undo);
    assert(repository_size(lst) == 2);

    Estate *e4 = create_estate("apartment", "Str.Luminii", 200, 150);
    repository_store(lst, e4, undo);
    assert(repository_size(lst) == 3);

    Estate *e5 = create_estate("house", "Str.Fundatura", 100, 50);
    repository_store(lst, e5, undo);
    assert(repository_size(lst) == 4);

    repo_search_by_type(lst, "apartment", 100, v, &dim);
    assert(dim == 2);

    Estate *e6 = create_estate("penthouse", "Str.Amurg", 1200, 1000);
    repository_store(lst, e6, undo);
    assert(repository_size(lst) == 5);

    repo_search_by_address(lst, "tr", v, &dim2);
    assert(dim2 == 3);

    Estate *e7 = create_estate("apartment", "Str.Albac", 600, 400);
    repository_store(lst, e7, undo);
    assert(repository_size(lst) == 6);

    repo_search_by_type_2(lst, "ap", v, &dim3);
    assert(dim3 == 3);

    repo_undo(lst, undo);
    assert(repository_size(lst) == 5);

    repo_redo(lst, undo);
    assert(repository_size(lst) == 6);

}


