/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A67_912_BUIGA_ANDREEA_UI_H
#define A67_912_BUIGA_ANDREEA_UI_H

#include <string>
#include <utility>
#include "../adoption_list/adoption_list.h"
#include "../file_repository/dogs_file_repository.h"
#include "../service/dogs_service.h"

class UI {
private:
    DogsService& dogs_service;
    AdoptionList* adoption_list;
    static void print_log_in_menu();

    static void print_admin_menu();
    void run_admin_mode();
    void add_dog_ui();
    void remove_dog_ui();
    void update_dog_ui();
    void get_all_dogs_ui();

    static void print_user_menu();
    void run_user_mode();
    void dog_one_by_one_ui();
    void filter_dogs_ui();
    void get_adoption_list_ui();
public:
    explicit UI(DogsService& dogs_service, AdoptionList* adoption_list): dogs_service{dogs_service}, adoption_list{adoption_list} {}
    ~UI() = default;

    void run_app();
};

#endif //A67_912_BUIGA_ANDREEA_UI_H
