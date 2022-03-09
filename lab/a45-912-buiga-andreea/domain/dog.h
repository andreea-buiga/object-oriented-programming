/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A45_912_BUIGA_ANDREEA_DOG_H
#define A45_912_BUIGA_ANDREEA_DOG_H

#include <iostream>
#include <string>

using std::string;

class Dog {
private:
    string breed;
    string name;
    int age;
    string photograph;
public:
    /*
     * Dog class constructor - default
    */
    Dog();

    /*
     * Dog class constructor
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     * :post: there'll be the attributes of a new dog created
    */
    Dog(const string &breed, const string &name, int age, const string &photograph);

    /*
     * Dog class copy - constructor
     * :param breed: the breed of the dog
     * :param name: the name of the dog
     * :param age: the age of the dog
     * :param photograph: a link towards an online resource
     * :post: a copy of a dog
    */
    Dog(Dog &other_dog);

    /*
     * Dog class destructor
     */
    ~Dog() = default;

    /*
     * getters for the dogs attributes
     */
    string get_breed_dog() const {return this->breed;}
    string get_name_dog() const {return this->name;}
    int get_age_dog() const {return this->age;}
    string get_photograph_dog() const {return this->photograph;}

    /*
     * setters for the dog's attributes
     */
    void set_breed(const string &new_breed);
    void set_age(const int &new_age);
    void set_photograph(const string &new_photograph);

    /*
     * overwriting the operator =
     */
    Dog &operator=(const Dog &other_dog);

    /*
     * overwriting the operator ==
     * two dogs would be equal if they have the same breed, name, age and same photograph
     */
    bool operator ==(const Dog &other_dog) const {
        return this->breed == other_dog.breed && this->name == other_dog.name
                && this->age == other_dog.age && this->photograph == other_dog.photograph;
    }

    /*
     * overwriting the operator <<
     */
    friend std::ostream& operator<<(std::ostream& os, const Dog& dog);
};

#endif //A45_912_BUIGA_ANDREEA_DOG_H
