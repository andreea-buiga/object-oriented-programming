/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#include <cassert>
#include <sstream>
#include "../adoption_list/adoption_list.h"
#include "../domain/dog.h"
#include "../validator/validator.h"
#include "../dynamic_array/dynamic_array.h"
#include "../repository/dog_repository.h"
#include "../service/dog_service.h"
#include "tests.h"

void Tests::run_all_tests() {
    Tests::test_dog();
    Tests::test_dynamic_array();
    Tests::test_dog_repository();
    Tests::test_adoption_list();
    Tests::test_dog_service();
    //Tests::test_service();
}

void Tests::test_dog() {
    test_create_dog();
    test_setters_dog();
    test_print_operator();
    test_dog_validator();
}

void test_create_dog() {
    Dog dog("Something", "Bubico", 11, "https://dog_picture.com");
    assert(dog.get_name_dog() == "Bubico");
    assert(dog.get_breed_dog() == "Something");
    assert(dog.get_age_dog() == 11);
    assert(dog.get_photograph_dog() == "https://dog_picture.com");
    Dog dog_2(dog);
}

void test_setters_dog() {
    Dog dog("Something", "Bubico", 11, "https://dog_picture.com");
    string new_breed = "Bichon";
    int new_age = 5;
    string new_photograph = "https://new_doggy.com";
    dog.set_breed(new_breed);
    dog.set_age(new_age);
    dog.set_photograph(new_photograph);
    assert(dog.get_breed_dog() == new_breed);
    assert(dog.get_age_dog() == new_age);
    assert(dog.get_photograph_dog() == new_photograph);
}

void test_print_operator() {
    Dog dog("Something", "Bubico", 11, "https://dog_picture.com");
    string test;
    string breed;
    std::stringstream f(test);
    f << dog;
    f >> breed;
    assert(breed == "breed:");
}

void test_dog_validator() {
    Dog dog("Something", "Bubico", 11, "https://dog_picture.com");

    try {
        DogValidator::validate_dog(dog);
        static_assert(true, "");
    }
    catch (ValidatorException &errors) {
        assert(false);
    }

    Dog bad_dog("", "", -11, "");
    try {
        DogValidator::validate_dog(bad_dog);
        assert(false);
    }
    catch (ValidatorException &error) {
        auto errors = error.get_errors();
        assert(errors.size() == 5);
    }

    Dog dog_invalid_photograph("Random", "Name", 11, "htt//:da.rwf");
    try {
        DogValidator::validate_dog(dog_invalid_photograph);
        assert(false);
    }
    catch (ValidatorException &error) {
        auto errors = error.get_errors();
        assert(errors.size() == 1);
    }
}

void Tests::test_dynamic_array() {
    DynamicArray<int> vector;
    int i;
    for(i = 0; i < 10; i++)
        vector.add_element(i + 2);
    assert(vector.get_size() == 10);
    vector.add_element(1);
    vector.add_element(1);
    vector.remove_element(2);
    vector.remove_element(2);
    assert(vector[1] == 3);
    vector.remove_element(0);
    vector.remove_element(0);
    DynamicArray<int> vector2(vector);
    DynamicArray<int> vector3;
    vector3 = vector;
}

void Tests::test_dog_repository() {
    test_store_dog_repo();
    test_remove_dog_repo();
    test_update_dog();
}

void test_store_dog_repo() {
    DogRepository dog_repository;
    Dog dog_1("as","qw", 1, "https://d.com");
    int val = dog_repository.add_dog(dog_1);
    dog_repository.get_all_dogs_repo();
    assert(val == 1);
    try {
        dog_repository.add_dog(dog_1);
        assert(false);
    }
    catch (DogRepositoryException &dre) {
        assert(true);
    }
}

void test_remove_dog_repo() {
    DogRepository dog_repository;
    Dog dog_1("as","qw", 1, "https://d.com");
    dog_repository.add_dog(dog_1);
    dog_repository.remove_dog(dog_1);
    try {
        dog_repository.remove_dog(dog_1);
        assert(false);
    }
    catch (DogRepositoryException &dre) {
        assert(true);
    }
}

void test_update_dog() {
    DogRepository dog_repository;
    Dog dog_1("as","qw", 1, "https://d.com");
    dog_repository.add_dog(dog_1);
    Dog dog_2("aaa","qw", 1, "https://er.com");
    dog_repository.update_dog(dog_2);
    Dog dog_3("aaa","dasd", 1, "https://er.com");
    try {
        dog_repository.update_dog(dog_3);
        assert(false);
    }
    catch (DogRepositoryException &dre) {
        assert(true);
    }
}

void Tests::test_adoption_list() {
    AdoptionList adoption_list;
    Dog dog("A", "B", 1, "https://asd.com");
    adoption_list.add_to_adoption_list(dog);
    try {
        adoption_list.add_to_adoption_list(dog);
        assert(false);
    }
    catch (AdoptionListException &ale) {
        assert(true);
    }
    adoption_list.get_adoption_list();
}


void Tests::test_dog_service() {
    DogRepository dog_repo;
    DogValidator dog_val;
    AdoptionList adoption_list;
    DogService dog_srv(dog_repo,dog_val,adoption_list);
    string breed = "A";
    string name = "Af";
    int age = 10;
    string photograph = "https://as.com";
    Dog dog(breed, name, age, photograph);
    int val = dog_srv.add_dog_service(breed, name, age, photograph);
    assert(val == 1);
    dog_srv.remove_dog_service(breed, name, age, photograph);
    dog_srv.add_dog_service(breed, name, age, photograph);
    assert(dog_srv.get_dog_one_by_one(0) == dog);
    val = dog_srv.update_dog_service("sa", name, 11, photograph);
    assert(val == 1);
    DynamicArray<Dog> doggies = dog_srv.get_all_dogs_service();
    dog_srv.get_adoption_list_service();
    dog_srv.add_dog_to_adoption_list(0);
    dog_srv.add_dog_service(breed, name, 24, photograph);
    DynamicArray<Dog> doggs = dog_srv.filter_breed_and_age_service("none", 12);
    assert(doggs.get_size() == 1);
    dog_srv.add_dog_service(breed, name, age, photograph);
    DynamicArray<Dog> dd = dog_srv.get_all_dogs_service();
    assert(dd.get_size() == 3);
    assert(dog_srv.get_dog_one_by_one(1).get_name_dog() == "Af");
    DynamicArray<Dog> doggs_2 = dog_srv.filter_breed_and_age_service("sa", 12);
    try {
        dog_srv.add_dog_service("", "", -11, "das.com");
        assert(false);
    }
    catch (ValidatorException &ve) {
        assert(true);
    }
    dog_srv.filter_breed_and_age_service("none", 1);
    dog_srv.add_dog_to_adoption_list(1);
    dog_srv.get_dog_one_by_one(1);
    dog_srv.get_dog_one_by_one_filter(0, "none", 1);
    dog_srv.add_dog_to_adoption_list_filter(1, "none", 12);
}

/*
void Tests::test_service() {
    DogRepository dog_repo;
    DogValidator dog_val;
    AdoptionList adoption_list;
    Service dog_srv(dog_repo,dog_val,adoption_list);
    string breed = "A";
    string name = "Af";
    int age = 10;
    string photograph = "https://as.com";
    Dog dog(breed, name, age, photograph);
    int val = dog_srv.add_dog_service(breed, name, age, photograph);
    assert(val == 1);
}
*/