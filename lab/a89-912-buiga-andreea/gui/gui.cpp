/**
           .•° ✿ °•.
     created on 09-may-2021
        @author: andreea
           °•. ✿ .•°
*/

/**
 * dog adoption logo credits: https://stock.adobe.com/nz/search/images?k=animal+rescue+logo&asset_id=112613854
 * https://as1.ftcdn.net/v2/jpg/01/12/61/38/1000_F_112613854_pw8ZkYdUo0zD4za7Fk1IcoXknuFNhdGM.jpg
 */

#include "gui.h"

using namespace std;

GUI::GUI(QWidget* parent) :  QWidget{ parent } {
    this->set_up_gui();
    DogsFileRepository* dogs_repository = new DogsFileRepository("C:/Users/andre/Documents/GitHub/a89-912-buiga-andreea/dogs.txt");;
    DogValidator* dog_validator;
    this->dogs_service = new DogsService{dogs_repository, dog_validator};
    this->all_dogs = this->dogs_service->get_all_dogs_service();
    this->list_all_dogs();
}

GUI::~GUI() {
    delete adoption_list;
    delete dogs_service;
}

void GUI::set_up_gui() {
    this->setWindowTitle("keep calm and adopt a pet");
    this->setWindowIcon(QIcon("../images/dog_adoption_logo.jpg"));
    this->main_layout = new QHBoxLayout{this};
    this->left_widget_admin = new QWidget{};
    this->left_side_admin = new QVBoxLayout{this->left_widget_admin};

    this->dogs_repository_list_widget = new QListWidget{};
    this->dogs_repository_list_widget->setSelectionMode(QAbstractItemView::SingleSelection);

    this->dog_data_widget = new QWidget{};
    this->form_layout = new QFormLayout{this->dog_data_widget};
    this->breed_dog_input = new QLineEdit{};
    this->breed_dog_input->setPlaceholderText(QString::fromStdString("great dane"));
    this->name_dog_input = new QLineEdit{};
    this->name_dog_input->setPlaceholderText(QString::fromStdString("scooby doo"));
    this->age_dog_input = new QLineEdit{};
    this->age_dog_input->setPlaceholderText(QString::fromStdString("7"));
    this->photograph_dog_input = new QLineEdit{};
    this->photograph_dog_input->setPlaceholderText(QString::fromStdString("https://something.com"));

    this->form_layout->addRow("&dog breed*", breed_dog_input);
    this->form_layout->addRow("&dog name*", name_dog_input);
    this->form_layout->addRow("&dog age*", age_dog_input);
    this->form_layout->addRow("&dog photograph*", photograph_dog_input);

    this->buttons_widget = new QWidget{};
    this->grid_layout = new QGridLayout{buttons_widget};
    this->add_button = new QPushButton("add a dog");
    this->remove_button = new QPushButton("delete a dog");
    this->update_button = new QPushButton("update a dog");

    this->grid_layout->addWidget(this->add_button, 0, 0);
    this->grid_layout->addWidget(this->remove_button, 0, 1);
    this->grid_layout->addWidget(this->update_button, 0, 2);

    this->left_side_admin->addWidget(new QLabel{"all dogs"});
    this->left_side_admin->addWidget(this->dogs_repository_list_widget);
    this->left_side_admin->addWidget(this->dog_data_widget);
    this->left_side_admin->addWidget(this->buttons_widget);

    this->right_widget = new QWidget{};
    this->right_side = new QVBoxLayout{this->right_widget};

    this->log_in_buttons_widget = new QWidget{};
    this->log_in_buttons = new QHBoxLayout{this->log_in_buttons_widget};

    this->admin_button = new QPushButton("admin");
    this->user_button = new QPushButton("user");
    this->log_in_buttons->addWidget(this->admin_button);
    this->log_in_buttons->addWidget(this->user_button);

    this->right_side->addWidget(this->log_in_buttons_widget);

    this->left_widget_user = new QWidget{};
    this->left_side_user = new QVBoxLayout{this->left_widget_user};

    this->file_buttons_widget = new QWidget{};
    this->file_buttons = new QHBoxLayout{this->file_buttons_widget};
    this->left_side_user->addWidget(new QLabel{"choose file type"});
    this->csv_button = new QRadioButton{"csv"};
    this->html_button = new QRadioButton{"html"};
    this->file_buttons->addWidget(this->csv_button);
    this->file_buttons->addWidget(this->html_button);
    this->left_side_user->addWidget(this->file_buttons_widget);

    this->viewed_dogs_list_widget = new QListWidget{};
    this->viewed_dogs_list_widget->setSelectionMode(QAbstractItemView::SingleSelection);

    this->filter_widget = new QWidget{};
    this->filter_form_layout = new QFormLayout{this->filter_widget};
    this->f_breed_dog_input = new QLineEdit{};
    this->f_breed_dog_input->setPlaceholderText(QString::fromStdString("great dane"));
    this->f_age_dog_input = new QLineEdit{};
    this->f_age_dog_input->setPlaceholderText(QString::fromStdString("7"));
    this->filter_form_layout->addRow("&dog breed", f_breed_dog_input);
    this->filter_form_layout->addRow("&dog age", f_age_dog_input);

    this->user_buttons_widget = new QWidget{};
    this->user_grid_layout = new QGridLayout{user_buttons_widget};
    this->adopt_button = new QPushButton("adopt");
    this->next_button = new QPushButton("next");
    this->view_adoption_list_button = new QPushButton("open adoption list");
    this->filter_button = new QPushButton("filter list");

    this->adoption_list_widget = new QListWidget{};
    this->adoption_list_widget->setSelectionMode(QAbstractItemView::SingleSelection);

    this->left_side_user->addWidget(new QLabel{"filter list"});
    this->left_side_user->addWidget(this->filter_widget);
    this->left_side_user->addWidget(new QLabel{"current dog"});
    this->left_side_user->addWidget(this->viewed_dogs_list_widget);
    this->left_side_user->addWidget(new QLabel{"adoption list"});
    this->left_side_user->addWidget(this->adoption_list_widget);
    this->user_grid_layout->addWidget(this->adopt_button, 0, 0);
    this->user_grid_layout->addWidget(this->next_button, 0, 1);
    this->user_grid_layout->addWidget(this->view_adoption_list_button, 1, 0);
    this->user_grid_layout->addWidget(this->filter_button, 1, 1);
    this->left_side_user->addWidget(this->user_buttons_widget);

    this->main_layout->addWidget(this->left_widget_admin);
    this->main_layout->addWidget(this->left_widget_user);
    this->main_layout->addWidget(this->right_widget);
    this->left_widget_admin->hide();
    this->left_widget_user->hide();
    this->connect_signals_and_slots();
}

void GUI::list_all_dogs() {
    if (this->dogs_repository_list_widget->count() != 0)
        this->dogs_repository_list_widget->clear();
    for (auto dog : all_dogs) {
        QString item = QString::fromStdString(dog.to_string_dog());
        QListWidgetItem* list_item_widget = new QListWidgetItem(item);
        this->dogs_repository_list_widget->addItem(list_item_widget);
    }
    if(!this->all_dogs.empty())
        this->dogs_repository_list_widget->setCurrentRow(0);
}

void GUI::list_adopted_dogs() {
    if (this->adoption_list_widget->count() != 0)
        this->adoption_list_widget->clear();
    for (auto dog : adopted_dogs) {
        QString item = QString::fromStdString(dog.to_string_dog());
        QListWidgetItem* list_item_widget = new QListWidgetItem(item);
        this->adoption_list_widget->addItem(list_item_widget);
    }
    if(!this->adopted_dogs.empty())
        this->adoption_list_widget->setCurrentRow(0);
}

int GUI::get_selected_dog() {
    if (dogs_repository_list_widget->count() == 0)
        return -1;
    QModelIndexList index_list = this->dogs_repository_list_widget->selectionModel()->selectedIndexes();
    if(index_list.empty()) {
        breed_dog_input->clear();
        name_dog_input->clear();
        age_dog_input->clear();
        photograph_dog_input->clear();

        return -1;
    }
    int index = index_list.at(0).row();
    return index;
}

void GUI::selected_dog_changed() {
    int i = this->get_selected_dog();
    if(i == -1)
        return;
    std::vector<Dog> dogs = this->dogs_service->get_all_dogs_service();
    if(i >= all_dogs.size())
        return;

    Dog dog = dogs[i];
    this->breed_dog_input->setText(QString::fromStdString(dog.get_breed_dog()));
    this->name_dog_input->setText(QString::fromStdString(dog.get_name_dog()));
    this->age_dog_input->setText(QString::fromStdString(to_string(dog.get_age_dog())));
    this->photograph_dog_input->setText(QString::fromStdString(dog.get_photograph_dog()));
}

void GUI::add_dog_gui() {
    std::string breed = breed_dog_input->text().toStdString();
    std::string name = name_dog_input->text().toStdString();
    int age = age_dog_input->text().toInt();
    std::string photograph = photograph_dog_input->text().toStdString();
    std::string dog_string = breed + ',' + name + ',' + to_string(age) + ',' + photograph;

    std::stringstream stream{dog_string};

    try {
        Dog dog;
        stream >> dog;
        this->dogs_service->add_dog_service(dog.get_breed_dog(), dog. get_name_dog(), dog.get_age_dog(), dog.get_photograph_dog());
        all_dogs = this->dogs_service->get_all_dogs_service();
        this->list_all_dogs();
    }
    catch (DogsFileRepositoryException& exc) {
        QMessageBox message_box;
        message_box.critical(nullptr, "error", QString::fromStdString("the dog already exists!"));
    }
    catch (ValidatorException& val_exc) {
        auto errors = val_exc.get_errors();
        QMessageBox message_box;
        message_box.critical(nullptr, "error", QString::fromStdString("invalid dog data!"));
    }
}
void GUI::remove_dog_gui() {
    std::string breed = breed_dog_input->text().toStdString();
    std::string name = name_dog_input->text().toStdString();
    std::string age = age_dog_input->text().toStdString();
    std::string photograph = photograph_dog_input->text().toStdString();
    std::string dog_string = breed + ',' + name + ',' + age + ',' + photograph;

    std::stringstream stream{dog_string};

    try {
        Dog dog;
        stream >> dog;
        this->dogs_service->remove_dog_service(dog.get_name_dog());
        all_dogs = this->dogs_service->get_all_dogs_service();
        this->list_all_dogs();
    }
    catch (DogsFileRepositoryException& exc) {
        QMessageBox message_box;
        message_box.critical(nullptr, "error", QString::fromStdString("the dog doesn't exists!"));
    }
    catch (ValidatorException& val_exc) {
        auto errors = val_exc.get_errors();
        QMessageBox message_box;
        message_box.critical(nullptr, "error", QString::fromStdString("invalid dog data!"));
    }
}

void GUI::update_dog_gui() {
    std::string breed = breed_dog_input->text().toStdString();
    std::string name = name_dog_input->text().toStdString();
    std::string age = age_dog_input->text().toStdString();
    std::string photograph = photograph_dog_input->text().toStdString();
    std::string dog_string = breed + ',' + name + ',' + age + ',' + photograph;

    std::stringstream stream{dog_string};

    try {
        Dog dog;
        stream >> dog;
        this->dogs_service->update_dog_service(dog.get_breed_dog(), dog. get_name_dog(), dog.get_age_dog(), dog.get_photograph_dog());
        all_dogs = this->dogs_service->get_all_dogs_service();
        this->list_all_dogs();
    }
    catch (DogsFileRepositoryException& exc) {
        QMessageBox message_box;
        message_box.critical(nullptr, "error", QString::fromStdString("the dog doesn't exists!"));
    }
    catch (ValidatorException& val_exc) {
        auto errors = val_exc.get_errors();
        QMessageBox message_box;
        message_box.critical(nullptr, "error", QString::fromStdString("invalid dog data!"));
    }
}

void GUI::connect_signals_and_slots() {
    QObject::connect(this->dogs_repository_list_widget, SIGNAL(itemSelectionChanged()), this, SLOT(selected_dog_changed()));
    QObject::connect(this->add_button, SIGNAL(clicked()), this, SLOT(add_dog_gui()));
    QObject::connect(this->remove_button, SIGNAL(clicked()), this, SLOT(remove_dog_gui()));
    QObject::connect(this->update_button, SIGNAL(clicked()), this, SLOT(update_dog_gui()));
    QObject::connect(this->admin_button, SIGNAL(clicked()), this, SLOT(change_colour_admin()));
    QObject::connect(this->user_button, SIGNAL(clicked()), this, SLOT(change_colour_user()));
    QObject::connect(this->csv_button, SIGNAL(pressed()), this, SLOT(change_to_csv()));
    QObject::connect(this->html_button, SIGNAL(pressed()), this, SLOT(change_to_html()));
    QObject::connect(this->next_button, SIGNAL(clicked()), this, SLOT(go_to_next_dog()));
    QObject::connect(this->adopt_button, SIGNAL(clicked()), this, SLOT(adopt_dog_gui()));
    QObject::connect(this->filter_button, SIGNAL(clicked()), this, SLOT(filter_list()));
    QObject::connect(this->view_adoption_list_button, SIGNAL(clicked()), this, SLOT(see_adoption_list()));
}

void GUI::change_colour_admin() {
    this->setWindowTitle("keep calm and adopt a pet/admin");
    this->admin_button->setStyleSheet("background: rgb(132, 210, 246)");
    this->user_button->setStyleSheet("background: rgb(178, 191, 208)");
    this->left_widget_admin->show();
    this->left_widget_user->hide();
}

void GUI::change_colour_user() {
    this->setWindowTitle("keep calm and adopt a pet/user");
    this->admin_button->setStyleSheet("background: rgb(178, 191, 208)");
    this->user_button->setStyleSheet("background: rgb(132, 210, 246)");
    this->left_widget_admin->hide();
    this->left_widget_user->show();
}

void GUI::change_to_csv() {
    this->adoption_list = new CSVAdoptionList;
    this->html_button->setDisabled(true);
}

void GUI::change_to_html() {
    this->adoption_list = new HTMLAdoptionList;
    this->csv_button->setDisabled(true);
}

void GUI::get_dog_one_by_one() {
    Dog current_dog = this->get_current_dog_gui();
    this->viewed_dogs_list_widget->clear();
    QString item = QString::fromStdString(current_dog.to_string_dog());
    QListWidgetItem* list_item_widget = new QListWidgetItem(item);
    this->viewed_dogs_list_widget->addItem(list_item_widget);
    current_dog.show_photograph();
}

void GUI::see_adoption_list() {
    this->adoption_list->open_in_app();
}

void GUI::adopt_dog_gui() {
    Dog current_dog = this->get_current_dog_gui();
    this->dogs_service->remove_dog_service(current_dog.get_name_dog());
    all_dogs = this->dogs_service->get_all_dogs_service();
    this->adoption_list->add_dog_adoption_list(current_dog);
    this->adopted_dogs = this->adoption_list->get_all_dogs_adoption_list();
    this->list_adopted_dogs();
    this->adoption_list->write_to_file();
    this->list_all_dogs();
}

Dog GUI::get_current_dog_gui() {
    Dog current_dog;
    std::string breed = this->f_breed_dog_input->text().toStdString();
    std::string age = this->f_age_dog_input->text().toStdString();
    if(!breed.empty() || !age.empty()) {
        this->filter_list();
        current_dog = this->dogs_service->get_current_dog(this->filtered_dogs);
    }
    else {
        current_dog = this->dogs_service->get_current_dog(this->all_dogs);
    }
    return current_dog;
}

void GUI::go_to_next_dog() {
    std::string breed = this->f_breed_dog_input->text().toStdString();
    std::string age = this->f_age_dog_input->text().toStdString();
    if(!breed.empty() || !age.empty()) {
        this->filter_list();
        this->dogs_service->next_dog(this->filtered_dogs);
    }
    else {
        this->dogs_service->next_dog(this->all_dogs);
    }
    this->get_dog_one_by_one();
}

void GUI::filter_list() {
    std::string breed = this->f_breed_dog_input->text().toStdString();
    int age = this->f_age_dog_input->text().toInt();
    if(!breed.empty()) {
        copy_if(all_dogs.begin(), all_dogs.end(), back_inserter(filtered_dogs), [&breed, &age](const Dog& dog){
            return dog.get_breed_dog() == breed && dog.get_age_dog() < age;
        });
    }
    else {
        this->filtered_dogs = all_dogs;
    }
}

