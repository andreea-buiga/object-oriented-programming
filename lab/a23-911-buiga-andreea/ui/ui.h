#ifndef A23_911_BUIGA_ANDREEA_UI_H
#define A23_911_BUIGA_ANDREEA_UI_H

#include "../service/service.h"
#include "../repository/undo_redo.h"

typedef struct
{
    Service* estate_service;
} UI;

UI* create_ui(Service*);
void print_estate(UI *);
void print_one(Estate *);
void print(Estate* , int);
void ui_add_estate(UI*, undo_redo*);
void ui_modify_estate(UI*, undo_redo*);
void ui_remove_estate(UI*, undo_redo*);
void ui_search_estate(UI*,  int);
void ui_search_estate_by_type(UI*);
void ui_startup(UI*, undo_redo*);
void destroy_ui(UI*);
void print_menu();
void ui_undo(UI*, undo_redo*);
void ui_redo(UI*, undo_redo*);

#endif
