/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/


#ifndef A45_912_BUIGA_ANDREEA_TESTS_H
#define A45_912_BUIGA_ANDREEA_TESTS_H

class Tests {
public:
    static void run_all_tests();
private:
    static void test_dog();
    static void test_dynamic_array();
    static void test_dog_repository();
    static void test_adoption_list();
    static void test_dog_service();
    static void test_service();
};

void test_create_dog();

void test_setters_dog();

void test_print_operator();

void test_dog_validator();

void test_store_dog_repo();

void test_remove_dog_repo();

void test_update_dog();

#endif //A45_912_BUIGA_ANDREEA_TESTS_H
