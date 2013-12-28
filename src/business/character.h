#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

class Character
{
    double _id;
    QString _name;
    bool _isNPC;

public:
    Character(int _id);

    double getId(){ return _id; }
    QString getName(){ return _name; }
    bool isNPC(){ return _isNPC; }

    void setName(QString& pName){ _name = pName; }
    void isNPC(bool pIsNPC){ _isNPC = pIsNPC; }
};

#endif // CHARACTER_H
