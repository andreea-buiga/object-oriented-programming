/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "dogs_service.h"


Dog DogsService::add_dog_service(const string &breed, const string &name, const int &age, const string &photograph) {
    Dog dog{breed, name, age, photograph};
    this->dog_validator.validate_dog(dog);
    return this->dogs_repository.add_dog(dog);
}

Dog DogsService::remove_dog_service(const string &name) {
    return this->dogs_repository.remove_dog(name);
}

Dog DogsService::update_dog_service(const string &breed, const string &name, const int &age, const string &photograph) {
    Dog dog{breed, name, age, photograph};
    this->dog_validator.validate_dog(dog);
    return this->dogs_repository.update_dog(dog);
}

int DogsService::get_size_service() {
    return this->dogs_repository.get_size();
}

std::vector<Dog> DogsService::get_all_dogs_service() {
    return this->dogs_repository.get_all_dogs();
}

Dog DogsService::get_current_dog(vector<Dog> &dogs) {
    if(dogs.empty())
        return Dog{};
    if(this->current == dogs.size())
        this->current = 0;
    return dogs[this->current];
}

void DogsService::next_dog(vector<Dog> &dogs) {
    this->current = this->current + 1;
    if(dogs.empty())
        return;
    if(this->current == dogs.size())
        this->current = 0;
    Dog current_dog = dogs[this->current];
}




