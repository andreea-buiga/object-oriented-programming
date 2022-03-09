#ifndef A23_911_BUIGA_ANDREEA_REPOSITORY_H
#define A23_911_BUIGA_ANDREEA_REPOSITORY_H

#include "../domain/agency.h"
#include "../domain/darray.h"
#include "repo_undo_redo.h"

typedef struct
{
    DArray* estates;
    void(*destroy_estate)(Element);
    Element(*copy_estate)(Element);
} EstateList;

EstateList* repository_create();
void repository_store(EstateList*, Estate*, undo_redo *);
void repository_remove(EstateList*, char*, undo_redo *);
void repository_modify(EstateList*, char*, char*, int, int, undo_redo *);
int repository_size(EstateList*);
void repo_search_by_type(EstateList *, char*, int, Estate *, int*);
void repo_search_by_address(EstateList *, char*,  Estate *, int*);
void repo_search_by_type_2(EstateList *, char*,  Estate *, int*);
Estate* repository_get_by_index(EstateList*, int);
void destroy_repo(EstateList*);
void repo_undo(EstateList *, undo_redo*);
void repo_redo(EstateList *, undo_redo*);
void test_repo();

#endif
