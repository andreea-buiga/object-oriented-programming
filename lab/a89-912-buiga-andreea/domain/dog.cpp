/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "dog.h"

Dog::Dog():age{-1} {

}

Dog::Dog(const std::string &breed, const std::string &name, int age, const std::string &photograph): breed{breed}, name{name}, age{age}, photograph{photograph} {

}

Dog::Dog(const Dog &dog): breed{dog.breed}, name{dog.name}, age{dog.age}, photograph{dog.photograph}{

}

const std::string &Dog::get_breed_dog() const {
    return this->breed;
}

const std::string &Dog::get_name_dog() const {
    return this->name;
}

int Dog::get_age_dog() const {
    return this->age;
}

const std::string &Dog::get_photograph_dog() const {
    return this->photograph;
}

void Dog::set_breed_dog(const std::string &new_breed) {
    this->breed = new_breed;
}

void Dog::set_age_dog(int new_age) {
    this->age = new_age;
}

void Dog::set_photograph_dog(const std::string &new_photograph) {
    this->photograph = new_photograph;
}

Dog &Dog::operator=(const Dog &dog) {
    this->breed = dog.breed;
    this->name = dog.name;
    this->age = dog.age;
    this->photograph = dog.photograph;
    return *this;
}

bool Dog::operator==(const Dog &dog) const {
    return this->name == dog.name;
}

std::vector<std::string> tokenize(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);
    return result;
}

std::istream &operator>>(std::istream &is, Dog &dog) {
    std::string line;
    getline(is, line);

    std::vector<std::string> tokens = tokenize(line, ',');
    if (tokens.size() != 4) /// make sure all the dog data was valid
        return is;

    dog.breed = tokens[0];
    dog.name = tokens[1];
    dog.age = stoi(tokens[2]);
    dog.photograph = tokens[3];

    return is;
}

std::ostream &operator<<(std::ostream& os, const Dog& dog) {
    os << dog.breed << "," << dog.name << "," << dog.age << "," << dog.photograph << "\n";
    return os;
}

void Dog::show_photograph() const {
    ShellExecuteA(nullptr, nullptr, "chrome.exe", this->get_photograph_dog().c_str(), nullptr, SW_SHOWMAXIMIZED);
}

std::string Dog::to_string_dog() {
    std::string dog_str = "breed: " + this->breed + " | name: " + this->name + " | age: " + std::to_string(this->age) + " | photograph: " + this->photograph;
    return dog_str;
}




