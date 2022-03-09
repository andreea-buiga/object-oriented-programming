/**
           .•° ✿ °•.
     created on 17-may-2021
        @author: andreea
           °•. ✿ .•°
*/

#ifndef A89_912_BUIGA_ANDREEA_DOGS_TABLE_MODEL_H
#define A89_912_BUIGA_ANDREEA_DOGS_TABLE_MODEL_H

#include <QAbstractTableModel>
#include "../domain/dog.h"
#include "../file_repository/dogs_file_repository.h"


class DogsTableModel: public QAbstractTableModel {
private:
    DogsRepository& repo;

public:
    DogsTableModel(DogsRepository& r, QObject* parent = NULL);
    ~DogsTableModel();

    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex & index) const override;
};

#endif //A89_912_BUIGA_ANDREEA_DOGS_TABLE_MODEL_H
