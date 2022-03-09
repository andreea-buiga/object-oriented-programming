/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "adoption_list.h"

std::ostream &operator<<(std::ostream &out, const AdoptionListException &except) {
    out << except.errors;
    return out;
}

Dog AdoptionList::add_dog_adoption_list(const Dog &dog) {
    auto it = find_if(this->adoption_list.begin(), this->adoption_list.end(), [&dog](const Dog& d) {
        return d == dog;
    });
    if(it != this->adoption_list.end())
        throw AdoptionListException("\nthe dog with the name " + dog.get_name_dog() + " was already adopted!\n");
    this->adoption_list.push_back(dog);
    return dog;
}

vector<Dog> AdoptionList::get_all_dogs_adoption_list() {
    return this->adoption_list;
}
