/**
           .•° ✿ °•.
     created on 27-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A45_912_BUIGA_ANDREEA_ADOPTION_LIST_H
#define A45_912_BUIGA_ANDREEA_ADOPTION_LIST_H

#include "../domain/dog.h"
#include "../dynamic_array/dynamic_array.h"

class AdoptionListException {

};

class AdoptionList {
private:
    DynamicArray<Dog> adoption_list;
public:
    int search_in_adoption_list(Dog &dog);

    int add_to_adoption_list(Dog &dog);

    DynamicArray<Dog> get_adoption_list();
};

#endif //A45_912_BUIGA_ANDREEA_ADOPTION_LIST_H
