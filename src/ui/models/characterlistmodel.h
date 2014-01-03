#ifndef CHARACTERLISTMODEL_H
#define CHARACTERLISTMODEL_H

#include <QAbstractListModel>
#include "src/business/character.h"

class CharacterListModel : public QAbstractListModel
{
    Q_OBJECT

    QList<Character*> lista;

public:
    explicit CharacterListModel(const QList<Character*>& pList, QObject *parent = 0) :
        lista(pList),
        QAbstractListModel(parent)
    {

    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const
    {
        return lista.size();
    }

//    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
//    {
//        if (!index.isValid() || index.row() >= lista.size())
//            return QVariant();

//        if (role == Qt::DisplayRole)
//            return lista.at(index.row());
//        else
//            return QVariant();
//    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal)
            return QString("Column %1").arg(section);
        else
            return QString("Row %1").arg(section);
    }

    //Qt::ItemFlags flags(const QModelIndex &index) const { return QAbstractListModel::flags() | Qt::ItemIsEditable; }

//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)
//    {
//        // ... = value
//        emit dataChanged(topLeft, bottomRight);
//    }

//    bool insertRows(int row, int count, const QModelIndex &parent)
//    {
//        beginInsertRows(parent, first, last);
//        // insertar data en el backend
//        endInsertRows();
//    }

//    bool removeRows(int row, int count, const QModelIndex &parent)
//    {
//        beginRemoveRows(parent, first, last);
//        // quitar data del backend
//        endRemoveRows();
//    }

signals:

public slots:
};

#endif // CHARACTERLISTMODEL_H
