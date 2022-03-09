/**
           .•° ✿ °•.
     created on 17-may-2021
        @author: andreea
           °•. ✿ .•°
*/

#include "dogs_table_model.h"
#include <QFont>
#include <QBrush>

DogsTableModel::DogsTableModel(DogsRepository& r, QObject* parent) : QAbstractTableModel{ parent }, repo{ r } {
}

DogsTableModel::~DogsTableModel() {
}

int DogsTableModel::rowCount(const QModelIndex & parent) const {
    int dogs_number = this->repo.get_size();
    return dogs_number + 1;
}

int DogsTableModel::columnCount(const QModelIndex & parent) const {
    return 4;
}

QVariant DogsTableModel::data(const QModelIndex & index, int role) const {
    int row = index.row();
    int column = index.column();
    std::vector<Dog> dogs = this->repo.get_all_dogs();

    if (row == dogs.size()) {
        return QVariant();
    }

    Dog dog = dogs[row];

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (column) {
            case 0:
                return QString::fromStdString(dog.get_breed_dog());
            case 1:
                return QString::fromStdString(dog.get_name_dog());
            case 2:
                return QString::fromStdString(to_string(dog.get_age_dog()));
                case 3:
                return QString::fromStdString(dog.get_photograph_dog());

            default:
                break;
        }
    }
    if (role == Qt::FontRole) {
        QFont font("Times", 15, 10, true);
        font.setItalic(false);
        return font;
    }
    if (role == Qt::BackgroundRole) {
        if (row % 2 == 1) {
            return QBrush{ QColor{0, 250, 154} };
        }
    }
    return QVariant{};
}

QVariant DogsTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole)     {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString{ "dog breed" };
                case 1:
                    return QString{ "dog name" };
                case 2:
                    return QString{ "dog age" };
                case 3:
                    return QString{ "dog photograph" };
                default:
                    break;
            }
        }
    }
    if (role == Qt::FontRole) {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

bool DogsTableModel::setData(const QModelIndex & index, const QVariant & value, int role) {
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    int dog_index = index.row();

    std::vector<Dog> dogs = this->repo.get_all_dogs();

    if (dog_index == dogs.size()) {
        this->beginInsertRows(QModelIndex{}, dog_index, dog_index);
        switch (index.column()) {
            case 0:
                this->repo.add_dog(Dog{ value.toString().toStdString(), "", 0, "" });
                break;
            case 1:
                this->repo.add_dog(Dog{ "", value.toString().toStdString(), 0, ""});
                break;
            case 2:
                this->repo.add_dog(Dog{ "", "", value.toString().toInt(), "" });
                break;
            case 3:
                this->repo.add_dog(Dog{ "", "", 0,value.toString().toStdString() });
                break;
        }

        this->endInsertRows();
        return true;
    }

    Dog& current_dog = dogs[dog_index];
    switch (index.column()) {
        case 0:
            current_dog.set_breed_dog(value.toString().toStdString());
            break;
        case 1:
            //current_dog.set_name_dog(value.toString().toStdString());
            break;
        case 2:
            current_dog.set_age_dog(stoi(value.toString().toStdString()));
        case 3:
            current_dog.set_photograph_dog(value.toString().toStdString());
    }
    this->repo.update_dog(current_dog);

    emit dataChanged(index, index);

    return true;
}

Qt::ItemFlags DogsTableModel::flags(const QModelIndex & index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}