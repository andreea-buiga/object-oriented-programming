#ifndef A23_911_BUIGA_ANDREEA_DARRAY_H
#define A23_911_BUIGA_ANDREEA_DARRAY_H

#include <assert.h>

typedef void* Element;

typedef struct
{
    Element* elements;
    int length;
    int capacity;
} DArray;


DArray* darray_create ();
void darray_destroy (DArray*);
void darray_add (DArray*, Element);
void darray_delete (DArray*, int);
Element darray_get (DArray*, int);
int darray_size (DArray*);
void size_dec(DArray*);
void copy_darray(DArray *, DArray *, Element(*makeCopy)(Element));

#endif
