/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A45_912_BUIGA_ANDREEA_DOG_SERVICE_H
#define A45_912_BUIGA_ANDREEA_DOG_SERVICE_H

#include "dog_service.h"
#include "../adoption_list/adoption_list.h"
#include "../domain/dog.h"
#include "../validator/validator.h"
#include "../repository/dog_repository.h"

class DogService {
private:
    DogRepository &dog_repo;
    DogValidator &dog_val;
    AdoptionList &adoption_list;
public:
    /*
     * DogService constructor
     * dog_repo - the repository that stores the dogs
     * dog_val - will validate a dog's attributes before going to the repo
     */
    explicit DogService(DogRepository &dog_repo, DogValidator &dog_val, AdoptionList &adoption_list):dog_repo(dog_repo), dog_val (dog_val), adoption_list(adoption_list) {}
    /*
     * adding a new dog to the service
     * will validate the dog before adding it to the repo
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     */
    int add_dog_service(const string &breed, const string &name, const int &age, const string &photograph);
    /*
     * removing a dog from the service
     * will validate the dog before removing it from the repo
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     */
    int remove_dog_service(const string &breed, const string &name, const int &age, const string &photograph);
    /*
     * updating a dog from the service
     * will validate the dog before updating it in the repo
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     */
    int update_dog_service(const string &breed, const string &name, const int &age, const string &photograph);
    /*
     * getting all the dogs in the repo
     */
    DynamicArray<Dog> get_all_dogs_service();
    /*
     * get a dog one by one from the database
     */
    Dog get_dog_one_by_one(const int &position);
    /*
     * get a dog one by one from the filter applied
     */
    Dog get_dog_one_by_one_filter(const int &position, const string &breed, const int &age);
    /*
     * from the database, add to adoption
     */
    int add_dog_to_adoption_list(const int &position);
    /*
     * from the filtered list, add to adoption
     */
    int add_dog_to_adoption_list_filter(const int &position, const string &breed, const int &age);
    /*
     * filtering all the dogs in the database having a certain breed and a smaller age
     */
    DynamicArray<Dog> filter_breed_and_age_service(const string &breed, const int &age);
    /*
     * getting all the dogs in the adoption list
     */
    DynamicArray<Dog> get_adoption_list_service();
};

#endif //A45_912_BUIGA_ANDREEA_DOG_SERVICE_H
