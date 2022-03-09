/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "tests.h"

void Tests::run_all_tests() {
    this->run_test_dog();
}

void Tests::run_test_dog() {
    Dog dog_1;
    assert(dog_1.get_breed_dog().empty());
    assert(dog_1.get_name_dog().empty());
    assert(dog_1.get_age_dog() == -1);
    assert(dog_1.get_photograph_dog().empty());
    Dog dog_2{"Pug", "Jeff", 2, "https://doggie.com"};
    assert(dog_2.get_breed_dog() == "Pug");
    assert(dog_2.get_name_dog() == "Jeff");
    assert(dog_2.get_age_dog() == 2);
    assert(dog_2.get_photograph_dog() == "https://doggie.com");
    const Dog& dog_3{dog_2};
    assert(dog_3.get_name_dog() == "Jeff");
    assert(dog_3.get_age_dog() == 2);
    assert(dog_3 == dog_2);
    Dog dog_4;
    dog_4 = dog_2;
    assert(dog_4.get_name_dog() == "Jeff");
    assert(dog_4.get_age_dog() == 2);
    dog_4.set_breed_dog("Husky");
    dog_4.set_age_dog(4);
    dog_4.set_photograph_dog("https://dog.ro");
    assert(dog_4.get_breed_dog() == "Husky");
    assert(dog_4.get_age_dog() == 4);
    assert(dog_4.get_photograph_dog() == "https://dog.ro");
}
