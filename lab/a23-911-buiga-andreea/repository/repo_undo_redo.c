#include<stdlib.h>
#include "repo_undo_redo.h"

undo_redo * create_undo_redo() {
    undo_redo *arr = (undo_redo*) malloc(sizeof(undo_redo));
    arr->capacity = 50;
    for (int i = 0; i < 50; i++)
        arr->elements[i] = darray_create();
    arr->currentRedo = 1;
    arr->currentUndo = -1;
    arr->size = 0;
    return arr;
}

void add_undo_redo(undo_redo *arr, DArray *da) {
    copy_darray(da, arr->elements[arr->size], (Element (*)(Element)) copy_estate);
    arr->size++;
    arr->currentRedo = arr->size-1;
    arr->currentUndo = arr->size-2;
}
