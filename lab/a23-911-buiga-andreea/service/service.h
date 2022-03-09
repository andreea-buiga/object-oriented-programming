#ifndef A23_911_BUIGA_ANDREEA_SERVICE_H
#define A23_911_BUIGA_ANDREEA_SERVICE_H

#include "../repository/repository.h"

typedef struct
{
    EstateList* estate_list;
}Service;

Service* create_service(EstateList*);
void add_estate(Service*, char*, char*, int, int, undo_redo*);
void modify_estate(Service*, char*, char*, int, int, undo_redo*);
void remove_estate(Service*, char*, undo_redo*);
int service_size(Service*);
Estate* service_get_by_index(Service*, int);
void search_by_type(Service *, char*, int, Estate *, int*);
void search_by_address(Service *, char*, Estate *, int*);
void search_by_type_2(Service *, char*, Estate *, int*);
void sort_by_price(Service*, int);
void sort_by_surface(Service*, int);
void startup(Service*, undo_redo*);
void destroy_service(Service*);
void serv_undo(Service*, undo_redo*);
void serv_redo(Service*, undo_redo*);
void test_serv();

#endif
