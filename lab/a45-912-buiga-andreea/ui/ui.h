/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A45_912_BUIGA_ANDREEA_UI_H
#define A45_912_BUIGA_ANDREEA_UI_H

#include "ui.h"
#include "../service/dog_service.h"
#include "../validator/validator.h"

/**
 * • credits •
 * dog ascii: https://ascii.co.uk/art/dog
 * computer ascii art: https://www.asciiart.eu/computers/computers
 */

class UI {
private:
    DogService &dog_service;
    static void print_log_in_menu();
    static void print_menu();
    void add_dog_ui();
    void remove_dog_ui();
    void update_dog_ui();
    void get_all_dogs_ui();
    void populate_ui();

    static void print_menu_user();
    void dog_one_by_one_ui(int &position);
    void filter_dogs_ui();
    void get_adoption_list_ui();

public:
    explicit UI(DogService &dog_service):dog_service(dog_service) {}
    void show_ui();
};

#endif //A45_912_BUIGA_ANDREEA_UI_H
