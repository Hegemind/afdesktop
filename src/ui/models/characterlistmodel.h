#ifndef CHARACTERLISTMODEL_H
#define CHARACTERLISTMODEL_H

#include <QAbstractListModel>
#include "src/business/character.h"

class CharacterListModel : public QAbstractListModel
{
    Q_OBJECT

    typedef QList<Character*> CharacterList;
    CharacterList lista;

public:
    explicit CharacterListModel(const QList<Character*>& pList, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const { return lista.size(); }
    QVariant data(const QModelIndex &index, int role) const
    {
//        if (!index.isValid())
//            return QVariant();

//        if (index.row() >= lista.size())
//            return QVariant();

//        if (role == Qt::DisplayRole)
//            return lista.at(index.row());
//        else
//            return QVariant();
    }
    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal)
            return QString("Column %1").arg(section);
        else
            return QString("Row %1").arg(section);
    }
signals:

public slots:
};

#endif // CHARACTERLISTMODEL_H
