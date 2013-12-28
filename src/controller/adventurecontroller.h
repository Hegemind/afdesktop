#ifndef ADVENTURECONTROLLER_H
#define ADVENTURECONTROLLER_H

#include <QMap>
#include "src/business/adventure.h"

class AdventureController
{
    QMap<QString, Adventure*> aventuras;

public:
    AdventureController();

    void nuevaAventura(QString nombre)
    {
        if(!aventuras.contains(nombre))
            aventuras.insert(nombre, new Adventure());
    }
    Adventure* getAventura(QString nombre){ return aventuras[nombre]; }
};

#endif // ADVENTURECONTROLLER_H
