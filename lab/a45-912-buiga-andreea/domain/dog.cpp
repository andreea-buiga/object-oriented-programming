/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "dog.h"

Dog::Dog(): age(0) {}

Dog::Dog(const string &breed, const string &name, int age, const string &photograph) {
    /*
     * Dog class constructor
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     * :post: there'll be the attributes of a new dog created
    */
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photograph = photograph;
}

Dog::Dog(Dog &other_dog) {
    /*
     * Dog class copy - constructor
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     * :post: a copy of a dog
    */
    this->breed = other_dog.breed;
    this->name = other_dog.name;
    this->age = other_dog.age;
    this->photograph = other_dog.photograph;
}

/*
 * setters for the dog's attributes
*/
void Dog::set_breed(const string &new_breed) {
    this->breed = new_breed;
}

void Dog::set_age(const int &new_age) {
    this->age = new_age;
}

void Dog::set_photograph(const string &new_photograph) {
    this->photograph = new_photograph;
}

/*
* overwriting the operator =
*/
Dog &Dog::operator=(const Dog &other_dog) {
    this->breed = other_dog.breed;
    this->name = other_dog.name;
    this->age = other_dog.age;
    this->photograph = other_dog.photograph;
    return *this;
}

/*
* overwriting the operator <<
* for printing
*/
std::ostream& operator<<(std::ostream& os, const Dog &dog) {
    os << " breed: " << dog.breed << " | name: " << dog.name
        << " | age: " << dog.age << " | photograph: " << dog.photograph;
    return os;
}





