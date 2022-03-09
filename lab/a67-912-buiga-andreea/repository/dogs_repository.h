/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A67_912_BUIGA_ANDREEA_DOGS_REPOSITORY_H
#define A67_912_BUIGA_ANDREEA_DOGS_REPOSITORY_H

#include <utility>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
#include "../domain/dog.h"

using namespace std;

class DogsRepository {
protected:
    vector<Dog> dogs;
public:
    DogsRepository() = default;
    virtual Dog add_dog(const Dog&) = 0;
    virtual Dog remove_dog(const std::string&) = 0;
    virtual Dog update_dog(const Dog&) = 0;
    virtual int get_size() = 0;
    virtual std::vector<Dog> get_all_dogs() = 0;
    virtual ~DogsRepository() = default;
};



#endif //A67_912_BUIGA_ANDREEA_DOGS_REPOSITORY_H
