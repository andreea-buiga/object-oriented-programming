/**
           .•° ✿ °•.
     created on 19-mar-2021
        @author: andreea
           °•. ✿ .•°
*/

/**
 * • credits •
 * dog ascii: https://ascii.co.uk/art/dog
 * computer ascii art: https://www.asciiart.eu/computers/computers
 */

#include "ui.h"

void UI::print_menu() {
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

void UI::print_menu_user() {
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

void UI::print_log_in_menu() {
    string log_in;
    log_in += "             ________________________________________________\n"
              "            /                                                \\\n"
              "           |    _________________________________________     |\n"
              "           |   |                                         |    |\n"
              "           |   |  C:\\> administrator                    |    |\n"
              "           |   |  C:\\> user                             |    |\n"
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

void UI::get_all_dogs_ui() {
    std::cout << "\n";
    DynamicArray<Dog> to_print = this->dog_service.get_all_dogs_service();
    if(to_print.get_size() == 0)
        std::cout << "the dog list is empty!\n";
    else {
        int i;
        for(i = 0; i < to_print.get_size(); i++)
            std::cout << i + 1 << " | " << to_print[i] << "\n";
    }
    std::cout << "\n";
}

void UI::get_adoption_list_ui() {
    std::cout << "\n";
    DynamicArray<Dog> adoption = this->dog_service.get_adoption_list_service();
    if(adoption.get_size() == 0)
        std::cout << "the dog adoption list is empty!\n";
    else {
        int i;
        for(i = 0; i < adoption.get_size(); i++)
            std::cout << i + 1 << " | " << adoption[i] << "\n";
    }
    std::cout << "\n";
}

bool is_integer(const std::string& to_check){
    if(to_check[0] == '0' && to_check.size() != 1){
        return false;
    }
    for(const auto& elem: to_check){
        if(elem < '0' || elem  > '9'){
            return false;
        }
    }
    return true;
}

int make_integer(const std::string& str){
    int num = 0;
    for(const auto& elem: str){
        num = num * 10 + (elem - '0');
    }
    return num;
}

int read_int(const std::string& prompt) {
    std::string line;
    while(true) {
        std::cout << prompt;
        std::cin >> line;
        if(is_integer(line)){
            return make_integer(line);
        }
        std::cout << "\n\nplease give an integer!\n\n";
    }
}

void read_dog(string &breed, string &name, int &age, string &photograph) {
    std::cout << "\nthe dog's breed: ";
    //getline(std::cin, breed);
    std::cin >> breed;
    std::cout << "\nthe dog's name: ";
    //getline(std::cin, name);
    std::cin >> name;
    /*std::cout << "\nthe dog's age: ";
    std::cin >> age;*/
    age = read_int("\nthe dog's age: ");
    std::cout << "\nthe dog's photograph:  ";
    //getline(std::cin, photograph);
    std::cin >> photograph;
}

void read_dog_update(string &breed, string &name, int &age, string &photograph) {
    std::cout << "\nthe dog's name: ";
    std::cin >> name;
    std::cout << "\nthe dog's new breed: ";
    std::cin >> breed;
    age = read_int("\nthe dog's new age: ");
    std::cout << "\nthe dog's new photograph:  ";
    std::cin >> photograph;
}

void print_errors(vector<std::string>& errs){
    std::cout << '\n';
    for(const auto& elem: errs){
        std::cout << elem << '\n';
    }
}

void UI::add_dog_ui() {
    string breed, name, photograph;
    int age = {0};
    read_dog(breed, name, age, photograph);
    try {
        this->dog_service.add_dog_service(breed, name, age, photograph);
        std::cout << "\nthe dog was added!\n\n";
    }
    catch (ValidatorException &except) {
        auto errors = except.get_errors();
        print_errors(errors);
    }
    catch (DogRepositoryException &dre) {
        std::cout << "\nthe dog already exists!\n\n";
    }
}

void UI::remove_dog_ui() {
    string breed, name, photograph;
    int age = {0};
    read_dog(breed, name, age, photograph);
    try {
        this->dog_service.remove_dog_service(breed, name, age, photograph);
        std::cout << "\nthe dog was removed!\n";
    }
    catch (ValidatorException &except) {
        auto errors = except.get_errors();
        print_errors(errors);
    }
    catch (DogRepositoryException &dre) {
        std::cout << "\nthe dog does not exist!\n";
    }
}

void UI::update_dog_ui() {
    string breed, name, photograph;
    int age = {0};
    read_dog_update(breed, name, age, photograph);
    try {
        this->dog_service.update_dog_service(breed, name, age, photograph);
        std::cout << "\nthe dog was updated!\n";
    }
    catch (ValidatorException &except) {
        auto errors = except.get_errors();
        print_errors(errors);
    }
    catch (DogRepositoryException &dre) {
        std::cout << "\nthe dog does not exist!\n";
    }
}

void UI::populate_ui() {
    this->dog_service.add_dog_service("ShibaInu", "LaoTz", 18, "https://something.com");
    this->dog_service.add_dog_service("AkitaInu", "Tai", 6, "https://sg.com");
    this->dog_service.add_dog_service("AkitaInu", "TziomPing", 12, "https://sfdg.com");
    this->dog_service.add_dog_service("ChowChow", "Bear", 6, "https://asd.com");
    this->dog_service.add_dog_service("ShihTzu", "Delamain", 116, "http://qwer.com");
    this->dog_service.add_dog_service("Pug", "Doug", 4, "http://udfg.ro");
    this->dog_service.add_dog_service("GermanShepard", "Sasha", 6, "http://tre.ro");
    this->dog_service.add_dog_service("Bulldog", "MikeHawk", 69, "http://iuyi.ro");
    this->dog_service.add_dog_service("Pug", "Edgar", 8, "https://tdfgdre.br");
    this->dog_service.add_dog_service("Pug", "Maya", 9, "https://tdfgdre.br");
    this->dog_service.add_dog_service("Pitbull", "MrWorldwide", 23, "https://tdfgdre.net");
}

void UI::dog_one_by_one_ui(int &position) {
    std::cout << "\n";
    DynamicArray<Dog> all_dogs = this->dog_service.get_all_dogs_service();
    if(all_dogs.get_size() == 0)
        std::cout << "\nthe dog list is empty!\n";
    else {
        if(position == all_dogs.get_size()) {
            position = 0;
            std::cout << "\nthe index for viewing one by one reached the limit! reseted it to 0.\n\n";
        }
        string adopt;
        std::cout << this->dog_service.get_dog_one_by_one(position);
        std::cout << "\n\ndo you want to adopt " << this->dog_service.get_dog_one_by_one(position).get_name_dog() << "?\n";
        std::cout << "yes or no: ";
        std::cin >> adopt;
        if(adopt == "yes") {
            try {
                this->dog_service.add_dog_to_adoption_list(position);
                std::cout << "\nthe dog was added to adoption list!\n";
            }
            catch (AdoptionListException &ale) {
                std::cout << "\nthe dog was already adopted!\n\n";
            }
        }
        position = position + 1;
    }
    std::cout << "\n";
}

void UI::filter_dogs_ui() {
    DynamicArray<Dog> filtered_dogs;
    int age;
    string breed;
    std::cout << "\nplease choose a breed: ";
    std::cin >> breed;
    if(breed == "none") {
        std::cout << "\nplease give an age: ";
        std::cin >> age;
        filtered_dogs = this->dog_service.filter_breed_and_age_service("none", age);
    }
    else {
        std::cout << "\nplease give an age: ";
        std::cin >> age;
        filtered_dogs = this->dog_service.filter_breed_and_age_service(breed, age);
    }
    if(filtered_dogs.get_size() == 0)
        std::cout << "\nthe dog list is empty!\n";
    else {
        int index;
        std::cout << "\n";
        for(index = 0; index < filtered_dogs.get_size(); index++)
            std::cout << index + 1 << " | " << filtered_dogs[index] << "\n";
        std::cout << "\n";
        int i = 0;
        string adopt;
        while(i < filtered_dogs.get_size()) {
            std::cout << this->dog_service.get_dog_one_by_one_filter(i, breed, age);
            std::cout << "\n\ndo you want to adopt " << this->dog_service.get_dog_one_by_one_filter(i, breed, age).get_name_dog() << "?\n";
            std::cout << "yes or no: ";
            std::cin >> adopt;
            if(adopt == "yes") {
                try {
                    this->dog_service.add_dog_to_adoption_list_filter(i, breed, age);
                    std::cout << "\nthe dog was added to adoption list!\n";
                }
                catch (AdoptionListException &ale) {
                    std::cout << "\nthe dog was already adopted!\n\n";
                }
            }
            else
                if(adopt == "exit")
                    break;
            i = i + 1;
            if(i == filtered_dogs.get_size()) {
                i = 0;
                std::cout << "\nthe index for viewing one by one reached the limit! reseted it to 0.\n\n";
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

void UI::show_ui() {
    int administrator_command, user_command;
    string who_to_log_in_as;
    this->populate_ui();
    this->print_log_in_menu();
    while(true) {
        std::cout << "\n\nlog in as: ";
        std::cin >> who_to_log_in_as;
        if(who_to_log_in_as == "administrator") {
            this->print_menu();
            while(true) {
                std::cout << "\nadministrator command: ";
                std::cin >> administrator_command;
                switch(administrator_command) {
                    case 0:
                        std::cout << "\nthank for using the app! arrivederci!\n";
                        return;
                    case 1:
                        add_dog_ui();
                        break;
                    case 2:
                        remove_dog_ui();
                        break;
                    case 3:
                        update_dog_ui();
                        break;
                    case 4:
                        std::cout << "\n= all the dogs =\n";
                        get_all_dogs_ui();
                        break;
                    default:
                        std::cout << "\n wrong command! try again!\n";
                }
            }
        }
        else
            if(who_to_log_in_as == "user") {
                this->print_menu_user();
                int position = 0;
                while(true) {
                    std::cout << "\nuser command: ";
                    std::cin >> user_command;
                    switch(user_command) {
                        case 0:
                            std::cout << "\nthank for using the app! arrivederci!\n";
                            return;
                        case 1:
                            dog_one_by_one_ui(position);
                            break;
                        case 2:
                            filter_dogs_ui();
                            break;
                        case 3:
                            std::cout << "\n= adoption list =\n";
                            get_adoption_list_ui();
                            break;
                        default:
                            std::cout << "\n wrong command! try again!\n";
                    }
                }
            }
            else
                if(who_to_log_in_as == "0")
                    break;
                else
                    std::cout << "\n wrong option! try again!\n";
    }
}