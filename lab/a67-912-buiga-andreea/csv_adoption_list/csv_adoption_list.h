/**
           .•° ✿ °•.
     created on 17-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A67_912_BUIGA_ANDREEA_CSV_ADOPTION_LIST_H
#define A67_912_BUIGA_ANDREEA_CSV_ADOPTION_LIST_H

#include <fstream>
#include "../adoption_list/adoption_list.h"

using namespace std;

class CSVAdoptionList: public AdoptionList {
public:
    ~CSVAdoptionList() override = default;
    void write_to_file() override;
    void open_in_app() override;
};

#endif //A67_912_BUIGA_ANDREEA_CSV_ADOPTION_LIST_H
