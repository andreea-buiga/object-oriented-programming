/**
           .•° ✿ °•.
     created on 17-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "csv_adoption_list.h"

void CSVAdoptionList::write_to_file() {
    ofstream out_file("c:/Users/andre/Documents/GitHub/a89-912-buiga-andreea/dogs_csv.csv");
    for(const auto& dog: this->adoption_list)
        out_file << dog;
    out_file.close();
}

void CSVAdoptionList::open_in_app() {
    this->write_to_file();
    system("notepad.exe c:/Users/andre/Documents/GitHub/a89-912-buiga-andreea/dogs_csv.csv");
}
