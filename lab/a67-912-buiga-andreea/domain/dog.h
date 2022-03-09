/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A67_912_BUIGA_ANDREEA_DOG_H
#define A67_912_BUIGA_ANDREEA_DOG_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <shellapi.h>

class Dog {
private:
    std::string breed;
    std::string name;
    int age;
    std::string photograph;
public:
    /**
     * constructors
     */
    Dog();
    Dog(const std::string&, const std::string&, int, const std::string&);
    Dog(const Dog&);

    /**
     * getters
     */
    const std::string& get_breed_dog() const;
    const std::string& get_name_dog() const;
    int get_age_dog() const;
    const std::string& get_photograph_dog() const;

    /**
     * setters
     */
    void set_breed_dog(const std::string& new_breed);
    void set_age_dog(int new_age);
    void set_photograph_dog(const std::string& new_photograph);
    /**
     * overwriting the operator =
     */
    Dog& operator=(const Dog&);
    /**
    * overwriting the operator ==
    * two dogs would be equal if they have the same breed, name, age and same photograph
    */
    bool operator==(const Dog&) const;

    void show_photograph() const;
    /**
     * overwriting the operator >> / <<
     */
    friend std::istream& operator>>(std::istream&, Dog&);
    friend std::ostream& operator<<(std::ostream&, const Dog&);
};

#endif //A67_912_BUIGA_ANDREEA_DOG_H
