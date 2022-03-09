/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include <iostream>
#include "adoption_list/adoption_list.h"
#include "csv_adoption_list/csv_adoption_list.h"
#include "html_adoption_list/html_adoption_list.h"
#include "file_repository/dogs_file_repository.h"
#include "validator/validator.h"
#include "service/dogs_service.h"
#include "ui/ui.h"

int main() {
    DogsFileRepository dogs_file_repo{"C:/Users/andre/Documents/GitHub/a67-912-buiga-andreea/dogs.txt"};
    DogValidator dog_validator;
    DogsService dogs_service{dogs_file_repo, dog_validator};
    AdoptionList* adoption_list;
    while(true) {
        std::string adoption_list_type;
        std::cout << "\n\nchoose adoption list file type (csv/html): ";
        std::cin >> adoption_list_type;
        if(adoption_list_type == "csv") {
                adoption_list = new CSVAdoptionList();
                break;
            }
        else
            if(adoption_list_type == "html") {
                adoption_list = new HTMLAdoptionList;
                break;
            }
            else
                std::cout << "\nbad command!\n";
    }
    UI ui{dogs_service, adoption_list};
    ui.run_app();
    delete adoption_list;
    return 0;
}