/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "ui.h"

void UI::print_log_in_menu() {
    string log_in;
    log_in += "             ________________________________________________\n"
              "            /                                                 \\\n"
              "           |    _________________________________________     |\n"
              "           |   |                                         |    |\n"
              "           |   |  C:\\> admin                             |    |\n"
              "           |   |  C:\\> user                              |    |\n"
              "           |   |                                         |    |\n"
              "           |   |                                         |    |\n"
              "           |   |                                         |    |\n"
              "           |   |                                         |    |\n"
              "           |   |                                         |    |\n"
              "           |   |                                         |    |\n"
              "           |   |                                         |    |\n"
              "           |   |                                         |    |\n"
              "           |   |_________________________________________|    |\n"
              "           |                                                  |\n"
              "            \\_________________________________________________/\n"
              "                   \\___________________________________/\n"
              "                ___________________________________________\n"
              "             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n"
              "          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n"
              "       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n"
              "    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n"
              " _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n"
              ":-------------------------------------------------------------------------:\n"
              "`---._.-------------------------------------------------------------._.---'";

    std::cout << log_in;
}

void UI::print_admin_menu() {
    string menu;
    menu += "\t                              \n"
            "\t                            __\n"
            "\t     ,                    ,\" e`--o\n"
            "\t    ((                   (  | __,'\n"
            "\t     \\\\~----------------' \\_;/\n"
            "\t     (                      /\n"
            "\t     /) ._______________.  )\n"
            "\t    (( (               (( (\n"
            "\t     ``-'               ``-'\n\n"
            "\n\t___________________________________________\n"
            "\t|                               - | ";
    menu += (char)254;
    menu += " | x |\n"
            "\t-------------------------------------------\n"
            "\t|      keep  calm  and  adopt  a  pet     |\n"
            "\t-------------------------------------------\n"
            "\t| 1 | add a new dog.                      |\n"
            "\t-------------------------------------------\n"
            "\t| 2 | delete a dog.                       |\n"
            "\t-------------------------------------------\n"
            "\t| 3 | update a dog's attributes.          |\n"
            "\t-------------------------------------------\n"
            "\t| 4 | list all the dogs.                  |\n"
            "\t-------------------------------------------\n"
            "\t| 0 | exit the program.                   |\n"
            "\t-------------------------------------------\n";
    std::cout << menu;
}

void UI::print_user_menu() {
    string menu;
    menu += "\t                              \n"
            "\t                            __\n"
            "\t     ,                    ,\" e`--o\n"
            "\t    ((                   (  | __,'\n"
            "\t     \\\\~----------------' \\_;/\n"
            "\t     (                      /\n"
            "\t     /) ._______________.  )\n"
            "\t    (( (               (( (\n"
            "\t     ``-'               ``-'\n\n"
            "\n\t___________________________________________\n"
            "\t|                               - | ";
    menu += (char)254;
    menu += " | x |\n"
            "\t-------------------------------------------\n"
            "\t|      keep  calm  and  adopt  a  pet     |\n"
            "\t-------------------------------------------\n"
            "\t| 1 | view dog one by one.                |\n"
            "\t-------------------------------------------\n"
            "\t| 2 | filter dogs by breed and age.       |\n"
            "\t-------------------------------------------\n"
            "\t| 3 | see adoption list.                  |\n"
            "\t-------------------------------------------\n"
            "\t| 0 | exit the program.                   |\n"
            "\t-------------------------------------------\n";
    std::cout << menu;
}

void UI::run_admin_mode() {
    this->print_admin_menu();
    while(true) {
        std::cout << "\nadmin command: ";
        std::string admin_command;
        std::cin >> admin_command;
        if(admin_command == "0")
            break;
        if(admin_command == "1") {
            this->add_dog_ui();
            continue;
        }
        if(admin_command == "2") {
            this->remove_dog_ui();
            continue;
        }
        if(admin_command == "3") {
            this->update_dog_ui();
            continue;
        }
        if(admin_command == "4") {
            this->get_all_dogs_ui();
            continue;
        }
        std::cout << "\nbad command!\n";
    }
}

void UI::run_user_mode() {
    this->print_user_menu();
    while(true) {
        std::cout << "\nuser command: ";
        std::string user_command;
        std::cin >> user_command;
        if(user_command == "0")
            break;
        if(user_command == "1") {
            this->dog_one_by_one_ui();
            continue;
        }
        if(user_command == "2") {
            this->filter_dogs_ui();
            continue;
        }
        if(user_command == "3") {
            this->get_adoption_list_ui();
            continue;
        }
        std::cout << "\nbad command!\n";
    }
}

void UI::run_app() {
    this->print_log_in_menu();
    while(true) {
        std::string log_in_as;
        std::cout << "\n\nlog in as: ";
        std::cin >> log_in_as;
        if(log_in_as == "exit"){
            std::cout << "\nthanks for using the app! arrivederci!\n";
            break;
        }
        else
            if(log_in_as == "admin") {
                std::cout << "\nhello admin!~~\n";
                run_admin_mode();
                std::cout << "\narrivederci admin!~~\n";
            }
            else
                if(log_in_as == "user") {
                    std::cout << "\nhello user!~~\n";
                    run_user_mode();
                    std::cout << "\narrivederci user!~~\n";
                }
                else
                    std::cout << "\nbad command!\n";
    }
}

void print_errors(vector<std::string>& errs){
    std::cout << '\n';
    for(const auto& elem: errs){
        std::cout << elem << '\n';
    }
}

void UI::add_dog_ui() {
    string breed, name, photograph, string_age;
    int age = 0;
    std::cout << "\nthe dog's breed: ";
    std::cin >> breed;
    std::cout << "\nthe dog's name: ";
    std::cin >> name;
    std::cout <<  "\nthe dog's age: ";
    std::cin >> string_age;
    try {
        age = stoi(string_age);
    }
    catch(exception& exc) {
        std::cout << "\nthe age should be an integer! (> 0)\n";
    }
    std::cout << "\nthe dog's photograph:  ";
    std::cin >> photograph;
    try {
        this->dogs_service.add_dog_service(breed, name, age, photograph);
        std::cout << "\nthe dog with the name " + name + " was added!\n\n";
    }
    catch (ValidatorException &except) {
        auto errors = except.get_errors();
        print_errors(errors);
    }
    catch (const DogsFileRepositoryException &dfre) {
        std::cout << dfre << "\n";
    }
}

void UI::remove_dog_ui() {
    std::string name;
    std::cout << "\nthe dog's name you want to remove: ";
    std::cin >> name;
    try {
        this->dogs_service.remove_dog_service(name);
        std::cout << "\nthe dog with the name " + name + " was removed!\n\n";
    }
    catch (const DogsFileRepositoryException &dfre) {
        std::cout << dfre << "\n";
    }
}

void UI::update_dog_ui() {
    string breed, name, photograph, string_age;
    int age = 0;
    std::cout << "\nthe dog's name you want to update: ";
    std::cin >> name;
    std::cout << "\nthe dog's new breed: ";
    std::cin >> breed;
    std::cout <<  "\nthe dog's new age: ";
    std::cin >> string_age;
    try {
        age = stoi(string_age);
    }
    catch(exception& exc) {
        std::cout << "\nthe age should be an integer! (> 0)\n";
    }
    std::cout << "\nthe dog's new photograph:  ";
    std::cin >> photograph;
    try {
        this->dogs_service.update_dog_service(breed, name, age, photograph);
        std::cout << "\nthe dog with the name " + name + " was updated!\n\n";
    }
    catch (ValidatorException &except) {
        auto errors = except.get_errors();
        print_errors(errors);
    }
    catch (const DogsFileRepositoryException &dfre) {
        std::cout << dfre << "\n";
    }
}

void UI::get_all_dogs_ui() {
    vector<Dog> all_dogs = this->dogs_service.get_all_dogs_service();
    if(all_dogs.empty())
        std::cout << "\nthe dog list is empty!\n";
    else {
        std::cout << "\n\t= the dog list =\n";
        for(const auto& dog:all_dogs)
            std::cout << " breed: " << dog.get_breed_dog() << " | name: " << dog.get_name_dog()
            << " | age: " << dog.get_age_dog() << " | photograph: " << dog.get_photograph_dog() << "\n";
    }
}

void UI::dog_one_by_one_ui() {
    vector<Dog> all_dogs = this->dogs_service.get_all_dogs_service();
    if(all_dogs.empty())
        std::cout << "\nthe dog list is empty!\n";
    else {
        std::cout << "\n\t= the dogs list =\n";
            for (const auto &dog:all_dogs)
                std::cout << "breed: " << dog.get_breed_dog() << " | name: " << dog.get_name_dog()
                          << " | age: " << dog.get_age_dog() << " | photograph: " << dog.get_photograph_dog() << "\n";

        while(true) {
            Dog dog = this->dogs_service.get_current_dog(all_dogs);
            //dog.show_photograph();
            std::cout << "\n\n breed: " << dog.get_breed_dog() << " | name: " << dog.get_name_dog()
                      << " | age: " << dog.get_age_dog() << " | photograph: " << dog.get_photograph_dog() << "\n";
            std::cout << "\nnext / adopt / exit\n";
            std::cout << "\nyou want to: ";
            std::string what_to_do;
            std::cin >> what_to_do;
            if (what_to_do == "exit")
                break;
            if (what_to_do == "next")
                this->dogs_service.next_dog(all_dogs);
            if (what_to_do == "adopt") {
                try {
                    this->adoption_list->add_dog_adoption_list(dog);
                    std::cout << "\nthe dog with the name " + dog.get_name_dog() + " was adopted!\n";
                }
                catch (const AdoptionListException &ale) {
                    std::cout << ale << "\n";
                }
            }
            this->dogs_service.next_dog(all_dogs);
        }
    }
    this->adoption_list->write_to_file();
}

void UI::filter_dogs_ui() {
    std::string breed, string_age;
    int age;
    std::cout << "\nthe dog's breed: ";
    std::cin >> breed;
    std::cout <<  "\nthe dog's age: ";
    std::cin >> string_age;
    try {
        age = stoi(string_age);
    }
    catch(exception& exc) {
        std::cout << "\nthe age should be an integer! (> 0)\n";
    }
    vector<Dog> all_dogs = this->dogs_service.get_all_dogs_service();
    if(all_dogs.empty())
        std::cout << "\nthe dog list is empty!\n";
    else {
        vector<Dog> filtered_dogs;
        if(breed != "none") {
            copy_if(all_dogs.begin(), all_dogs.end(), back_inserter(filtered_dogs), [&breed, &age](const Dog& dog){
                return dog.get_breed_dog() == breed && dog.get_age_dog() < age;
            });
        }
        else {
            copy_if(all_dogs.begin(), all_dogs.end(), back_inserter(filtered_dogs), [&age](const Dog& dog){
                return dog.get_age_dog() < age;
            });
        }
        if(filtered_dogs.empty())
            std::cout << "\nthe filtered list is empty!\n";
        else {
            std::cout << "\n\t= the filtered list =\n";
            for (const auto &dog:filtered_dogs)
                std::cout << "breed: " << dog.get_breed_dog() << " | name: " << dog.get_name_dog()
                          << " | age: " << dog.get_age_dog() << " | photograph: " << dog.get_photograph_dog() << "\n";

            while(true) {
                Dog dog = this->dogs_service.get_current_dog(filtered_dogs);
                //dog.show_photograph();
                std::cout << "\n\n breed: " << dog.get_breed_dog() << " | name: " << dog.get_name_dog()
                          << " | age: " << dog.get_age_dog() << " | photograph: " << dog.get_photograph_dog() << "\n";
                std::cout << "\nnext / adopt / exit\n\n";
                std::cout << "\nyou want to: ";
                std::string what_to_do;
                std::cin >> what_to_do;
                if(what_to_do == "exit")
                    break;
                if(what_to_do == "next")
                    this->dogs_service.next_dog(filtered_dogs);
                if(what_to_do == "adopt") {
                    try {
                        this->adoption_list->add_dog_adoption_list(dog);
                        std::cout << "\nthe dog with the name " + dog. get_name_dog() + " was adopted!\n";
                    }
                    catch(const AdoptionListException& ale) {
                        std::cout << ale << "\n";
                    }
                }
                this->dogs_service.next_dog(filtered_dogs);
            }
        }
    }
    this->adoption_list->write_to_file();
}

void UI::get_adoption_list_ui() {
    vector<Dog> adopted_dogs = this->adoption_list->get_all_dogs_adoption_list();
    if(adopted_dogs.empty()) {
        std::cout << "\nthe adoption list is empty!\n";
        this->adoption_list->open_in_app();
    }
    else {
        std::cout << "\n\t= the adoption list =\n";
        for(const auto& dog:adopted_dogs)
            std::cout << " breed: " << dog.get_breed_dog() << " | name: " << dog.get_name_dog()
                      << " | age: " << dog.get_age_dog() << " | photograph: " << dog.get_photograph_dog() << "\n";
        this->adoption_list->open_in_app();
    }
}
