/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "dog_repository.h"

int DogRepository::search_dog_in_repo(Dog &dog) {
    /*
     * searching for a certain dog in the repo
     * return: the position if found
     *         -1, otherwise
     */
    int i;
    for(i = 0; i < this->dogs.get_size(); i++)
        if(this->dogs[i] == dog)
            return i;

    return -1;
}

int DogRepository::add_dog(Dog &dog) {
    /*
     * adding a new dog to the repo
     * return: 1 if the dog was successfully added
     *         throwing an exception otherwise
     */
    int position = search_dog_in_repo(dog);
    if(position < 0) {
        this->dogs.add_element(dog);
        return 1;
    }
    else
        throw DogRepositoryException();
}

int DogRepository::remove_dog(Dog &dog) {
    /*
     * removing dog to the repo
     * return: 1 if the dog was successfully removed
     *         throwing an exception otherwise
     */
    int position = search_dog_in_repo(dog);
    if(position < 0)
        throw DogRepositoryException();
    else {
        this->dogs.remove_element(position);
        return 1;
    }
}

int DogRepository::update_dog(Dog &dog) {
    /*
     * updating dog to the repo
     * return: 1 if the dog was successfully updated
     *         throwing an exception otherwise
     */
    DogValidator::validate_dog(dog);
    int position = -1;
    int i;
    for(i = 0; i < this->dogs.get_size(); i++)
        if(this->dogs[i].get_name_dog() == dog.get_name_dog()) {
            position = i;
            break;
        }
    if(position < 0)
        throw DogRepositoryException();
    else {
        this->dogs[i].set_breed(dog.get_breed_dog());
        this->dogs[i].set_age(dog.get_age_dog());
        this->dogs[i].set_photograph(dog.get_photograph_dog());
        return 1;
    }
}

DynamicArray<Dog> DogRepository::get_all_dogs_repo() {
    /*
     * getting all the dogs in the repo
     */
    return this->dogs;
}
