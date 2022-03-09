#ifndef A23_911_BUIGA_ANDREEA_REPO_UNDO_REDO_H
#define A23_911_BUIGA_ANDREEA_REPO_UNDO_REDO_H

#include "../domain/darray.h"
#include "../domain/agency.h"

typedef struct {
    DArray *elements[50];
    int size;
    int capacity;
    int currentUndo;
    int currentRedo;
}undo_redo;

undo_redo* create_undo_redo();
void add_undo_redo(undo_redo*, DArray*);

#endif
