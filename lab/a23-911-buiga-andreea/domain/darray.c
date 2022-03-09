#include <stdlib.h>
#include "darray.h"

#define INIT_CAPACITY 10

// Initialises the array
DArray* darray_create()
{
    DArray *v = (DArray*)malloc (sizeof (DArray));
    v->elements = (Element*)malloc (INIT_CAPACITY * sizeof (Element));
    v->capacity = INIT_CAPACITY;
    v->length = 0;
    return v;
}

// Destroys the array
void darray_destroy(DArray* da)
{
    int i;

    for (i = 0; i < da->length; i++)
        free(da->elements[i]);

    free (da->elements);
    free (da);
}

// Increases the array size
void darray_resize(DArray *da)
{
    int nCap = 2 * da->capacity;
    Element* nElems = malloc (nCap * sizeof (Element));
    //copy the existent vector
    int i;
    for (i = 0; i < da->length; i++)
        nElems[i] = da->elements[i];

    //freeing the memory
    free(da->elements);
    da->elements = nElems;
    da->capacity = nCap;
}

// Decrements the size of the dynamic array
void size_dec(DArray *da)
{
    da->length = da->length-1;
}

// Appends an element
void darray_add(DArray* da, Element el)
{
    if (da->length == da->capacity)
        darray_resize (da);

    da->elements[da->length] = el;
    da->length++;
}

// Deletes an element
void darray_delete(DArray* da, int poz)
{
    int i;
    for (i = poz; i < da->length; i++)
    {
        da->elements[i]=da->elements[i+1];
    }
    size_dec(da);
}

// Returns an element by index
Element darray_get(DArray* da, int index)
{
    return da->elements[index];
}

// Returns the elements count of the array
int darray_size(DArray* da)
{
    return da->length;
}

// Creates a copy for the dynamic array
void copy_darray(DArray *orig, DArray *fake, Element(*makeCopy)(Element)) {
    int i;
    fake->capacity = orig->capacity;
    fake->length = orig->length;
    for (i = 0; i < fake->length; i++) {
        fake->elements[i] = makeCopy(orig->elements[i]);

    }
}