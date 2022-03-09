/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A67_912_BUIGA_ANDREEA_ADOPTION_LIST_H
#define A67_912_BUIGA_ANDREEA_ADOPTION_LIST_H

#include <string>
#include <utility>
#include <vector>
#include <utility>
#include <algorithm>
#include "../domain/dog.h"

using namespace std;

class AdoptionListException: public exception {
    string errors;
public:
    explicit AdoptionListException(string error): errors{move(error)} {}
    string get_errors() {
        return errors;
    }
    friend ostream& operator<<(ostream& out, const AdoptionListException& except);
};

class AdoptionList {
protected:
    vector<Dog> adoption_list;
public:
    virtual ~AdoptionList() = default;
    /**
     * function that adds a new dog to the adoption list
     */
    Dog add_dog_adoption_list(const Dog& dog);
    /**
     * function that returns all the dogs in the adoption list
     */
    vector<Dog> get_all_dogs_adoption_list();
    virtual void write_to_file() = 0;
    virtual void open_in_app() = 0;
};

#endif //A67_912_BUIGA_ANDREEA_ADOPTION_LIST_H
