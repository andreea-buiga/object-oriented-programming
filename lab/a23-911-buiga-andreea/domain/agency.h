#ifndef A23_911_BUIGA_ANDREEA_AGENCY_H
#define A23_911_BUIGA_ANDREEA_AGENCY_H

typedef struct
{
    char type[20];
    char address[100];
    int surface, price;

} Estate;

Estate* create_estate(char*, char*, int, int);

Estate* copy_estate(Estate*);
char* get_type(Estate*);
char* get_address(Estate*);
int get_surface(Estate*);
int get_price(Estate*);
void set_type(Estate*, char*);
void set_surface(Estate*, int);
void set_price(Estate*, int);
//void destroy_estate(Estate*);
void test_estate();

#endif