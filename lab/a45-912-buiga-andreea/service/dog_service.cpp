/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "dog_service.h"

int DogService::add_dog_service(const string &breed, const string &name, const int &age, const string &photograph) {
    /*
     * adding a new dog to the service
     * will validate the dog before adding it to the repo
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     */
    Dog dog(breed, name, age, photograph);
    this->dog_val.validate_dog(dog);
    return this->dog_repo.add_dog(dog);
}

int DogService::remove_dog_service(const string &breed, const string &name, const int &age, const string &photograph) {
    /*
     * removing dog to the service
     * will validate the dog before removing it from the repo
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     */
    Dog dog(breed, name, age, photograph);
    this->dog_val.validate_dog(dog);
    return this->dog_repo.remove_dog(dog);
}

int DogService::update_dog_service(const string &breed, const string &name, const int &age, const string &photograph) {
    /*
     * updating a dog from the service
     * will validate the dog before updating it in the repo
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     */
    Dog dog(breed, name, age, photograph);
    this->dog_val.validate_dog(dog);
    return this->dog_repo.update_dog(dog);
}

DynamicArray<Dog> DogService::get_all_dogs_service() {
    /*
     * getting all the dogs in the repo
     */
    return this->dog_repo.get_all_dogs_repo();
}

int DogService::add_dog_to_adoption_list(const int &position) {
    DynamicArray<Dog> all_dogs = this->get_all_dogs_service();
    int i;
    for(i = 0; i < all_dogs.get_size(); i++)
        if(i == position)
            return this->adoption_list.add_to_adoption_list(all_dogs[i]);
}

int DogService::add_dog_to_adoption_list_filter(const int &position, const string &breed, const int &age) {
    DynamicArray<Dog> all_dogs = this->filter_breed_and_age_service(breed, age);
    int i;
    for(i = 0; i < all_dogs.get_size(); i++)
        if(i == position)
            return this->adoption_list.add_to_adoption_list(all_dogs[i]);
}

Dog DogService::get_dog_one_by_one(const int &position) {
    DynamicArray<Dog> all_dogs = this->get_all_dogs_service();
    int i;
    for(i = 0; i < all_dogs.get_size(); i++)
        if(i == position)
            return all_dogs[i];
}

Dog DogService::get_dog_one_by_one_filter(const int &position, const string &breed, const int &age) {
    DynamicArray<Dog> all_dogs = this->filter_breed_and_age_service(breed, age);
    int i;
    for(i = 0; i < all_dogs.get_size(); i++)
        if(i == position)
            return all_dogs[i];
}

DynamicArray<Dog> DogService::filter_breed_and_age_service(const string &breed, const int &age) {
    DynamicArray<Dog> filtered_dogs = this->get_all_dogs_service();
    int i;
    if(breed == "none") {
        for(i = 0 ; i < filtered_dogs.get_size(); i++)
            if(filtered_dogs[i].get_age_dog() >= age)
                filtered_dogs.remove_element(i);
    }
    else {
        for(i = 0 ; i < filtered_dogs.get_size(); i++)
            if(filtered_dogs[i].get_breed_dog() != breed || filtered_dogs[i].get_age_dog() >= age)
                filtered_dogs.remove_element(i);
    }
    return filtered_dogs;
}


DynamicArray<Dog> DogService::get_adoption_list_service() {
    /*
     * getting all the dogs in the adoption list
     */
    return this->adoption_list.get_adoption_list();
}
