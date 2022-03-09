/**
           .•° ✿ °•.
     created on 08-apr-2021
        @author: andreea
           °•. ✿ .•°
*/

#include <iostream>
#include <QtWidgets/QApplication>
#include "adoption_list/adoption_list.h"
#include "csv_adoption_list/csv_adoption_list.h"
#include "html_adoption_list/html_adoption_list.h"
#include "file_repository/dogs_file_repository.h"
#include "validator/validator.h"
#include "service/dogs_service.h"
#include "ui/ui.h"
#include "gui/gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GUI w;
    w.show();
    return a.exec();
}