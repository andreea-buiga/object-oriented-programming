/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A45_912_BUIGA_ANDREEA_VALIDATOR_H
#define A45_912_BUIGA_ANDREEA_VALIDATOR_H

#include "../domain/dog.h"
#include <vector>
#include <string>

using namespace std;

class ValidatorException {
private:
    vector<string> exceptions;
public:
    /*
     * general exception class constructor
     * :param exceptions: string - string of errors
    */
    explicit ValidatorException(vector<std::string> exceptions):exceptions{std::move(exceptions)} {}
    /*
     * getter for the errors
     */
    vector<string> get_errors() const {return this->exceptions;}
};

class DogValidator {
public:
    /* function which checks if a dog is valid
    * :param dog: the dog to be checked
    * :post: raises ValidatorException if the dog is not correct
    */
    static void validate_dog(const Dog &dog);
};

#endif //A45_912_BUIGA_ANDREEA_VALIDATOR_H
