/**
           .•° ✿ °•.
     created on 27-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "adoption_list.h"

int AdoptionList::search_in_adoption_list(Dog &dog) {
    int i;
    for(i = 0; i < this->adoption_list.get_size(); i++)
        if(this->adoption_list[i] == dog)
            return i;
    return -1;
}

int AdoptionList::add_to_adoption_list(Dog &dog) {
    int position = this->search_in_adoption_list(dog);
    if(position < 0) {
        this->adoption_list.add_element(dog);
        return 1;
    }
    else
        throw AdoptionListException();
}

DynamicArray<Dog> AdoptionList::get_adoption_list() {
    return this->adoption_list;
}


