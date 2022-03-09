/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A67_912_BUIGA_ANDREEA_DOGS_SERVICE_H
#define A67_912_BUIGA_ANDREEA_DOGS_SERVICE_H

#include <vector>
#include "../repository/dogs_repository.h"
#include "../validator/validator.h"

class DogsService {
private:
    DogsRepository& dogs_repository;
    DogValidator& dog_validator;
    int current = 0;
public:
    /**
    * DogService constructor
    * dog_repo - the repository that stores the dogs
    * dog_val - will validate a dog's attributes before going to the repo
    */
    explicit DogsService(DogsRepository& dogs_repository, DogValidator& dog_validator):
                dogs_repository(dogs_repository), dog_validator(dog_validator) {
        this->current = 0;
    }
    ~DogsService() = default;
    /**
     * adding a new dog to the service
     * will validate the dog before adding it to the repo
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     */
    Dog add_dog_service(const string &breed, const string &name, const int &age, const string &photograph);
    /**
     * removing a dog from the service
     * :param name: the name of the dog
     */
    Dog remove_dog_service(const string &name);
    /**
     * updating a dog from the service
     * will validate the dog before updating it in the repo
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     */
    Dog update_dog_service(const string &breed, const string &name, const int &age, const string &photograph);
    int get_size_service();
    /**
     * get the current dog
     */
    Dog get_current_dog(std::vector<Dog>& dogs);
    /**
     * move to the next one
     */
    void next_dog(std::vector<Dog>& dogs);
    /**
     * getting all the dogs in the repo
     */
    std::vector<Dog> get_all_dogs_service();
};

#endif //A67_912_BUIGA_ANDREEA_DOGS_SERVICE_H
