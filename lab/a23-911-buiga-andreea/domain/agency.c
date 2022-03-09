#include <string.h>
#include <stdlib.h>
#include "agency.h"
#include "utils.h"
#include "assert.h"

/// Creates an estate
/// \param type the type of the estate
/// \param address the address of the estate
/// \param surface the surface of the estate
/// \param price the price of the estate
/// \return the estate
Estate* create_estate(char* type, char* address, int surface, int price)
{
    Estate* e=(Estate*)malloc(sizeof(Estate));
    strcpy (e->type, type);
    strcpy (e->address, address);
    e->surface = surface;
    e->price = price;
    return e;
}
/*
void destroy_estate(Estate *e) {
    free(e->address);
    free(e);
}
*/

/// Makes a copy of the estate
/// \param original the original estate
/// \return the copy of the estate
Estate * copy_estate(Estate* original) {
    Estate *copy;
    copy = malloc(sizeof(Estate));
    strcpy(copy->type,original->type);
    strcpy(copy->address,original->address);
    copy->price = original->price;
    copy->surface = original->surface;
    return copy;
}

/// Gets the type of the estate
/// \param e the estate
/// \return the type of the estate
char* get_type(Estate* e)
{
    return copy_string (e->type);
}

/// Gets the address of the estate
/// \param e the estate
/// \return the address of the estate
char* get_address(Estate *e)
{
    return copy_string (e->address);
}

/// Gets the surface of the estate
/// \param e the estate
/// \return the surface of the estate
int get_surface(Estate *e)
{
    return e->surface;
}

/// Gets the price of the estate
/// \param e the estate
/// \return the price of the estate
int get_price(Estate *e)
{
    return e->price;
}

/// Sets the type of the estate
/// \param e the estate
/// \param type the new type of the estate
void set_type(Estate* e, char* type)
{
    strcpy (e->type, type);
}

/// Sets the surface of the estate
/// \param e the estate
/// \param surface the new surface of the estate
void set_surface(Estate* e, int surface)
{
    e->surface = surface;
}

/// Sets the price of the estate
/// \param e the estate
/// \param price the new price of the estate
void set_price(Estate* e, int price)
{
    e->price = price;
}

void test_estate()
{
    Estate *e = create_estate("house", "Str.Norm", 400, 100);
    assert(strcmp(get_type(e),"house")==0);
    assert(strcmp(get_address(e),"Str.Norm")==0);
    assert(get_surface(e)==400);
    assert(get_price(e)==100);

    Estate *e2 = create_estate("penthouse", "Str.Lux", 1000, 900);
    assert(strcmp(get_type(e2),"penthouse")==0);
    assert(strcmp(get_address(e2),"Str.Lux")==0);
    assert(get_surface(e2)==1000);
    assert(get_price(e2)==900);
}

