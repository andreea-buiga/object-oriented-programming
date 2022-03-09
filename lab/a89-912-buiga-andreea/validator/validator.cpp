/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "validator.h"

#include "validator.h"
#include <regex>

void DogValidator::validate_dog(const Dog &dog) {
    /* function which checks if a dog is valid
    * :param dog: the dog to be checked
    * :post: raises ValidatorException if the dog is not correct
    */
    vector<string> errors;
    const auto& breed = dog.get_breed_dog();
    const auto& name = dog.get_name_dog();
    auto age = dog.get_age_dog();
    const auto& photograph = dog.get_photograph_dog();
    const regex pattern(R"(((http|https)://)(www.)?[a-zA-Z0-9@:%._\+~#?&//=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%._\+~#?&//=]*))");

    if(breed.empty())
        errors.emplace_back("the breed cannot be empty!\n");

    if(name.empty())
        errors.emplace_back("the name cannot be empty!\n");

    if(age <= 0)
        errors.emplace_back("age has to be a positive integer. (age > 0)\n");

    if(photograph.empty())
        errors.emplace_back("the photograph cannot be empty!\n");

    if(!regex_match(photograph, pattern))
        errors.emplace_back("the photograph is not a valid link!\n");

    if(!errors.empty())
        throw ValidatorException(errors);
}