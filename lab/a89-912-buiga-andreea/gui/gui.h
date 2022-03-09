/**
           .•° ✿ °•.
     created on 09-may-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A89_912_BUIGA_ANDREEA_GUI_H
#define A89_912_BUIGA_ANDREEA_GUI_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qbuttongroup.h>
#include <QRadioButton>
#include <QPixmap>
#include <QPainter>
#include <vector>
#include <algorithm>
#include "../validator/validator.h"
#include "../file_repository/dogs_file_repository.h"
#include "../service/dogs_service.h"
#include "../adoption_list/adoption_list.h"
#include "../csv_adoption_list/csv_adoption_list.h"
#include "../html_adoption_list/html_adoption_list.h"
#include "../dogs_table_model/dogs_table_model.h"

class GUI : public QWidget {
Q_OBJECT

public:
    explicit GUI(QWidget* parent = nullptr);
    ~GUI() override;
private:
    DogsService* dogs_service;
    AdoptionList* adoption_list;

    QListWidget* dogs_repository_list_widget;
    QListWidget* viewed_dogs_list_widget;
    QListWidget* adoption_list_widget;

    QHBoxLayout* main_layout;
    QWidget* left_widget_admin;
    QWidget* left_widget_user;
    QWidget* right_widget;
    QVBoxLayout* left_side_admin;
    QVBoxLayout* left_side_user;
    QVBoxLayout* right_side;

    QWidget* dog_data_widget;
    QFormLayout* form_layout;

    QWidget* filter_widget;
    QFormLayout* filter_form_layout;

    QWidget* log_in_buttons_widget;
    QHBoxLayout* log_in_buttons;

    QWidget* buttons_widget;
    QGridLayout* grid_layout;

    QLineEdit* breed_dog_input;
    QLineEdit* f_breed_dog_input;
    QLineEdit* name_dog_input;
    QLineEdit* age_dog_input;
    QLineEdit* f_age_dog_input;
    QLineEdit* photograph_dog_input;

    QWidget* file_buttons_widget;
    QHBoxLayout* file_buttons;
    QRadioButton* csv_button;
    QRadioButton* html_button;

    QPushButton* admin_button;
    QPushButton* user_button;

    QPushButton* add_button;
    QPushButton* remove_button;
    QPushButton* update_button;

    QWidget* user_buttons_widget;
    QGridLayout* user_grid_layout;
    QPushButton* adopt_button;
    QPushButton* next_button;
    QPushButton* view_adoption_list_button;
    QPushButton* filter_button;

    std::vector<Dog> all_dogs;
    std::vector<Dog> adopted_dogs;
    std::vector<Dog> filtered_dogs;
    void set_up_gui();
    int get_selected_dog();
    void list_all_dogs();
    void list_adopted_dogs();
    void connect_signals_and_slots();
    Dog get_current_dog_gui();
private slots:
    void add_dog_gui();
    void remove_dog_gui();
    void update_dog_gui();
    void selected_dog_changed();
    void change_colour_admin();
    void change_colour_user();
    void change_to_csv();
    void change_to_html();
    void get_dog_one_by_one();
    void see_adoption_list();
    void adopt_dog_gui();
    void go_to_next_dog();
    void filter_list();
};

#endif //A89_912_BUIGA_ANDREEA_GUI_H
