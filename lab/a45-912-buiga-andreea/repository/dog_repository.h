/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A45_912_BUIGA_ANDREEA_DOG_REPOSITORY_H
#define A45_912_BUIGA_ANDREEA_DOG_REPOSITORY_H

#include "../domain/dog.h"
#include "../validator/validator.h"
#include "../dynamic_array/dynamic_array.h"

class DogRepositoryException {

};

class DogRepository {
private:
    DynamicArray<Dog> dogs;
public:
    /*
     * DogRepository constructor
     */
    DogRepository() = default;

    /*
     * DogRepository destructor
     */
    ~DogRepository() = default;

    /*
     * searching for a certain dog in the repo
     * return: the position if found
     *         -1, otherwise
     */
    int search_dog_in_repo(Dog &dog);
    /*
     * adding a new dog to the repo
     * return: 1 if the dog was successfully added
     *         throwing an exception otherwise
     */
    int add_dog(Dog &dog);
    /*
     * removing dog to the repo
     * return: 1 if the dog was successfully removed
     *         throwing an exception otherwise
     */
    int remove_dog(Dog &dog);
    /*
     * updating dog to the repo
     * return: 1 if the dog was successfully updated
     *         throwing an exception otherwise
     */
    int update_dog(Dog &dog);

    /*
     * getting all the dogs in the repo
     */
    DynamicArray<Dog> get_all_dogs_repo();
};

#endif //A45_912_BUIGA_ANDREEA_DOG_REPOSITORY_H
