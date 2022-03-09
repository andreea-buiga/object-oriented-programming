/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "dogs_file_repository.h"

std::ostream &operator<<(std::ostream &out, const DogsFileRepositoryException &except) {
    out << except.errors;
    return out;
}

DogsFileRepository::DogsFileRepository(std::string filename) {
    this->filename = std::move(filename);
    read_data();
}

Dog DogsFileRepository::add_dog(const Dog& dog) {
    auto it = find_if(this->dogs.begin(), this->dogs.end(), [&dog](const Dog& d) {
        return d == dog;
    });
    if(it != this->dogs.end())
        throw DogsFileRepositoryException("\nthe dog with the name " + dog.get_name_dog() + " already exists!\n");
    this->dogs.push_back(dog);
    this->write_data();
    return dog;
}

Dog DogsFileRepository::remove_dog(const std::string& name) {
    auto it = find_if(this->dogs.begin(), this->dogs.end(), [&name](const Dog& d) {
        return d.get_name_dog() == name;
    });
    if(it == this->dogs.end())
        throw DogsFileRepositoryException("\nthe dog with the name " + name + " does not exists!\n");
    auto dog_copy = *it;
    this->dogs.erase(it);
    this->write_data();
    return dog_copy;
}

Dog DogsFileRepository::update_dog(const Dog& dog) {
    auto it = find_if(this->dogs.begin(), this->dogs.end(), [&dog](const Dog& d) {
        return d == dog;
    });
    if(it == this->dogs.end())
        throw DogsFileRepositoryException("\nthe dog with the name " + dog.get_name_dog() + " does not exists!\n");
    auto dog_copy = *it;
    this->dogs[it - this->dogs.begin()] = dog;
    write_data();
    return dog_copy;
}

int DogsFileRepository::get_size() {
    return (int)dogs.size();
}

std::vector<Dog> DogsFileRepository::get_all_dogs() {
    std::vector<Dog> copy_dogs;
    copy_dogs.reserve(this->get_size());
    for (int index = 0; index < this->get_size(); index++)
        copy_dogs.push_back(this->get_element(index));
    return copy_dogs;
}

Dog DogsFileRepository::get_element(int position) {
    return this->dogs[position];
}

void DogsFileRepository::read_data() {
    std::ifstream in_file(this->filename);
    if(!in_file.is_open())
        throw DogsFileRepositoryException("\nthe file could not be opened!\n");
    Dog dog;
    while(in_file >> dog) {
        this->add_dog(dog);
    }
    in_file.close();
}

void DogsFileRepository::write_data() {
    std::ofstream out_file(this->filename);
    for (const auto& dog : this->dogs)
        out_file << dog;
    out_file.close();
}
