#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H

#include <QObject>
#include <QMap>

#include "src/controller/server.h"
#include "src/business/character.h"

class CharacterController : public QObject
{
    Q_OBJECT

    CharacterController();
    ~CharacterController();
    static CharacterController* instancia;

    Server* server;

    typedef QMap<int, Character*> CharacterCache;
    CharacterCache* cache;

    QList<Character*> getAllCharacters(bool PCness);
public:
    static CharacterController* get();
    void doRefresh();

    QList<Character*> search(QString text);
    QList<Character*> getAllNPC(){ return getAllCharacters(false); }
    QList<Character*> getAllPC(){ return getAllCharacters(true); }

    void              insert(Character* c) { cache->insert(c->getId(), c); }
    Character*        get(double id)       { return cache->value(id); }
    QList<Character*> getAll()             { return cache->values(); }
    int               count()              { return cache->size(); }


public slots:
    void requestRefresh();
    void refreshResponse(QByteArray data);

signals:
    void refresh();
    void refreshCompleted();

};

#endif // CHARACTERCONTROLLER_H
