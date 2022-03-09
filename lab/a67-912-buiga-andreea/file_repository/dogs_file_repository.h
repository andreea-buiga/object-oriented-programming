/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A67_912_BUIGA_ANDREEA_DOGS_FILE_REPOSITORY_H
#define A67_912_BUIGA_ANDREEA_DOGS_FILE_REPOSITORY_H

#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include "../domain/dog.h"
#include "../repository/dogs_repository.h"

using namespace std;

class DogsFileRepositoryException: public exception {
    string errors;
public:
    explicit DogsFileRepositoryException(string error): errors{move(error)} {}
    string get_errors() {
        return errors;
    }
    friend ostream& operator<<(ostream& out, const DogsFileRepositoryException& except);
};

class DogsFileRepository : public DogsRepository {
private:
    std::string filename;
    Dog get_element(int position);
    void read_data();
    void write_data();
public:
    DogsFileRepository() = default;
    explicit DogsFileRepository(std::string filename);
    /**
     * adding a new dog to the repo
     * return: the dog if the dog was successfully added
     *         throwing an exception otherwise
     */
    Dog add_dog(const Dog&) override;
    /**
     * removing dog to the repo
     * return: the dog if the dog was successfully removed
     *         throwing an exception otherwise
     */
    Dog remove_dog(const std::string&) override;
    /**
     * updating dog to the repo
     * return: the dog if the dog was successfully updated
     *         throwing an exception otherwise
     */
    Dog update_dog(const Dog&) override;
    /**
    * getting the size of the repo
    */
    int get_size() override;
    /**
    * getting all the dogs in the repo
    */
    std::vector<Dog> get_all_dogs() override;
};

#endif //A67_912_BUIGA_ANDREEA_DOGS_FILE_REPOSITORY_H
